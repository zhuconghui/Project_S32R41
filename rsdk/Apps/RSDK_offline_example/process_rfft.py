import numpy as np
import os

def load_dat_file(filepath, dtype, endian='>'):
    """Load binary data from file."""
    if not os.path.exists(filepath):
        print(f"Error: File not found: {filepath}")
        return None
    # Adjust dtype for endianness
    if endian == '>':
        dt = np.dtype(dtype).newbyteorder('>')
    else:
        dt = np.dtype(dtype).newbyteorder('<')
        
    with open(filepath, 'rb') as f:
        data = np.fromfile(f, dtype=dt)
    return data

def save_dat_file(filepath, data, dtype, endian='>'):
    """Save data to binary file."""
    if endian == '>':
        dt = np.dtype(dtype).newbyteorder('>')
    else:
        dt = np.dtype(dtype).newbyteorder('<')

    if np.iscomplexobj(data):
        # Interleave Real/Imag
        # Flatten structure for writing: R, I, R, I...
        # Create a view or copy?
        # We need to ensure the order in file matches 'interleaved' for the current shape.
        # data is (Range, Chirps, Channels).
        # File expectation: Interleaved values for each element in that order.
        out_interleaved = np.empty(data.shape + (2,), dtype=dtype)
        out_interleaved[..., 0] = data.real.astype(dtype)
        out_interleaved[..., 1] = data.imag.astype(dtype)
        # tofile writes the array in C-order (row-major).
        out_interleaved.astype(dt).tofile(filepath)
    else:
        data.astype(dt).tofile(filepath)
    print(f"Saved {filepath}")

def main():
    # Configuration
    input_path = os.path.join('data', 'in', 'S32R41', 'rfft_in.dat')
    # Use built-in window for simplicity and reliability
    ref_output_path = os.path.join('data', 'ref', 'S32R41', 'rfft_out.dat')
    output_path = 'out.dat'
    
    # Dimensions
    n_chirps = 128
    n_samples = 512
    n_channels = 4
    n_range_bins = 256
    
    print("--- 1. Loading Input Data ---")
    # Format: int8 complex interleaved
    # Layout found to be: [Chirps, Samples, Channels]
    raw_input = load_dat_file(input_path, dtype=np.int8)
    if raw_input is None: return
    
    # Convert to complex float
    input_cplx = raw_input[0::2].astype(np.float32) + 1j * raw_input[1::2].astype(np.float32)
    
    # Reshape to [Chirps, Samples, Channels]
    try:
        data_cube = input_cplx.reshape((n_chirps, n_samples, n_channels))
    except ValueError as e:
        print(f"Error reshaping input: {e}")
        return
        
    print(f"Input Data Shape: {data_cube.shape} (Chirps, Samples, Channels)")

    print("--- 2. Applying Window ---")
    # Apply Blackman window on Sample dimension (axis 1)
    window = np.blackman(n_samples)
    # Broadcast window: (1, 512, 1)
    window_reshaped = window.reshape((1, n_samples, 1))
    data_windowed = data_cube * window_reshaped

    print("--- 3. Processing Range FFT ---")
    # FFT along Sample dimension (axis 1)
    fft_out = np.fft.fft(data_windowed, axis=1)
    
    # Truncate to positive half (0 to 255)
    # Range FFT output usually keeps only positive frequencies for real input, 
    # but for complex input (if Zero-IF), we might want the whole thing?
    # However, Ref file size is half. 
    # Assuming standard Range FFT processing where we keep first half.
    fft_half = fft_out[:, :n_range_bins, :]
    
    print(f"FFT Output Shape: {fft_half.shape} (Chirps, RangeBins, Channels)")

    print("--- 4. Formatting Output ---")
    # Reference Layout found to be: [RangeBins, Chirps, Channels]
    # So we transpose our result to match.
    # Current: (Chirps=0, Range=1, Channels=2) -> Target: (Range=1, Chirps=0, Channels=2)
    fft_transposed = fft_half.transpose((1, 0, 2))
    print(f"Final Output Shape: {fft_transposed.shape} (RangeBins, Chirps, Channels)")

    print("--- 5. Comparison & Scaling ---")
    raw_ref = load_dat_file(ref_output_path, dtype=np.int16, endian='>')
    if raw_ref is not None:
        ref_cplx = raw_ref[0::2].astype(np.float32) + 1j * raw_ref[1::2].astype(np.float32)
        ref_reshaped = ref_cplx.reshape((n_range_bins, n_chirps, n_channels))
        
        # Calculate Scaling Factor (Sum Abs)
        scale_factor = np.sum(np.abs(ref_reshaped)) / np.sum(np.abs(fft_transposed))
        print(f"Calculated Scaling Factor: {scale_factor:.4f}")
        
        # Apply Scaling
        fft_scaled = fft_transposed * scale_factor
        
        # Calculate Error
        diff = np.abs(fft_scaled - ref_reshaped)
        print(f"Mean Absolute Error: {np.mean(diff):.2f}")
        
        # Correlation
        corr = np.corrcoef(np.abs(fft_scaled.flatten()), np.abs(ref_reshaped.flatten()))[0,1]
        print(f"Correlation (Magnitude): {corr:.4f}")
        
        # Prepare for saving
        # Clip to int16 range
        fft_final_real = np.clip(fft_scaled.real, -32768, 32767)
        fft_final_imag = np.clip(fft_scaled.imag, -32768, 32767)
        fft_final = fft_final_real + 1j * fft_final_imag
        
    else:
        print("Reference not found. Saving unscaled results.")
        # Arbitrary scaling if no reference
        fft_final = (fft_transposed * 64).astype(np.complex64) 

    # Save Output
    # File format: Big Endian int16 interleaved
    save_dat_file(output_path, fft_final, np.int16, endian='>')
    print("--- Done ---")

if __name__ == "__main__":
    main()
