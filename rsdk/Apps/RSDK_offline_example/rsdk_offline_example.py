import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D # 导入3D绘图工具
import os
import sys

# Constants
HW_PLATFORM = 'S32R41'
ENDIAN = '>' # Big Endian (S32R standard)

def load_dat_file(filepath, dtype, count=-1):
    """Load binary data from file."""
    if not os.path.exists(filepath):
        print(f"Warning: File not found: {filepath}")
        return None
    
    # Set endianness
    if ENDIAN == '>':
        dt = np.dtype(dtype).newbyteorder('>')
    else:
        dt = np.dtype(dtype).newbyteorder('<')
        
    try:
        with open(filepath, 'rb') as f:
            data = np.fromfile(f, dtype=dt, count=count)
        return data
    except Exception as e:
        print(f"Error reading {filepath}: {e}")
        return None

def interleaved_to_complex(data):
    """Convert interleaved (Real, Imag, ...) data to complex."""
    if data is None: return None
    if data.size % 2 != 0:
        data = data[:data.size-1]
        
    cplx = data[0::2].astype(np.float32) + 1j * data[1::2].astype(np.float32)
    return cplx

def char_stream_to_int(data_bytes, bytes_per_int=4):
    """Convert byte stream to integers (Big Endian)."""
    if data_bytes is None: return None
    
    rem = data_bytes.size % bytes_per_int
    if rem != 0:
        data_bytes = data_bytes[:-rem]
        
    if bytes_per_int == 4:
        dt = np.dtype(np.uint32).newbyteorder(ENDIAN)
    elif bytes_per_int == 2:
        dt = np.dtype(np.uint16).newbyteorder(ENDIAN)
    else:
        dt = np.dtype(np.uint32).newbyteorder(ENDIAN)
        
    data_int = np.frombuffer(data_bytes.tobytes(), dtype=dt)
    return data_int

def det_tag_unformat(indices, nr_rows, nr_cols):
    """Reconstruct a bitmap from a list of linear indices."""
    if indices is None: return None
    
    bitmap = np.zeros((nr_rows, nr_cols), dtype=np.float32)
    bitmap_flat = bitmap.flatten()
    
    valid_indices = indices[indices < bitmap_flat.size]
    bitmap_flat[valid_indices] = 1.0
    
    bitmap = bitmap_flat.reshape((nr_rows, nr_cols))
    return bitmap

def rfft_out_unformat(data_mem, nr_range, nr_chirps, nr_ant):
    """Unformat Range FFT output."""
    if data_mem is None: return None
    cplx_data = interleaved_to_complex(data_mem)
    expected_size = nr_range * nr_chirps * nr_ant
    if cplx_data.size != expected_size:
        return None
    # Shape: (Range, Chirps, Antennas)
    cube = cplx_data.reshape((nr_range, nr_chirps, nr_ant))
    return cube

def dfft_out_unformat(data_mem, nr_range, nr_doppler, nr_ant):
    """Unformat Doppler FFT output."""
    if data_mem is None: return None
    cplx_data = interleaved_to_complex(data_mem)
    expected_size = nr_range * nr_doppler * nr_ant
    if cplx_data.size != expected_size:
         return None
    cube = cplx_data.reshape((nr_range, nr_doppler, nr_ant))
    return cube

def rd_mag_unformat(data_mem, nr_range, nr_doppler):
    """Unformat NCC output (Magnitude)."""
    if data_mem is None: return None
    matrix = data_mem.reshape((nr_range, nr_doppler))
    return matrix

def plot_surface_3d(data, title_str, xlabel_str, ylabel_str, is_log=False):
    """Plot 3D Surface (like MATLAB surf)."""
    if data is None: return
    
    # Data preprocessing
    Z = data
    if is_log:
        Z = 20 * np.log10(np.abs(data) + 1e-6)
    else:
        Z = np.abs(data) # Ensure magnitude for complex inputs
        
    rows, cols = Z.shape
    
    # Generate Grid
    # x corresponds to cols, y corresponds to rows
    x = np.arange(cols)
    y = np.arange(rows)
    X, Y = np.meshgrid(x, y)
    
    fig = plt.figure(figsize=(10, 7))
    ax = fig.add_subplot(111, projection='3d')
    
    # Plot Surface
    # rstride/cstride control downsampling for performance (set to 2 for 256x128 gives decent speed)
    surf = ax.plot_surface(X, Y, Z, cmap='jet', linewidth=0, antialiased=False, rstride=2, cstride=2)
    
    ax.set_title(title_str)
    ax.set_xlabel(xlabel_str)
    ax.set_ylabel(ylabel_str)
    
    fig.colorbar(surf, ax=ax, shrink=0.5, aspect=10, label='Magnitude')
    
    print(f"Displayed 3D plot: {title_str}")

def main():
    print(f"--- RSDK Offline Example (Python 3D) for {HW_PLATFORM} ---")
    
    base_dir = os.path.dirname(os.path.abspath(__file__))
    out_folder = os.path.join(base_dir, 'data', 'out', HW_PLATFORM)
    ref_folder = os.path.join(base_dir, 'data', 'ref', HW_PLATFORM)
    
    # Priority: data/out -> data/ref
    work_folder = ref_folder
    if os.path.exists(out_folder) and os.path.exists(os.path.join(out_folder, 'rfft_out.dat')):
        work_folder = out_folder
        print(f"Using Output folder: {work_folder}")
    else:
        print(f"Output folder empty/missing. Using Reference folder: {work_folder}")
        
    # Configuration
    nr_samples = 512
    nr_chirps = 128
    nr_ant = 4
    
    nr_range_bins = nr_samples // 2
    nr_doppler_bins = nr_chirps
    
    # 1. Range FFT Output
    rfft_mem = load_dat_file(os.path.join(work_folder, 'rfft_out.dat'), np.int16)
    if rfft_mem is not None:
        rfft_out = rfft_out_unformat(rfft_mem, nr_range_bins, nr_chirps, nr_ant)
        if rfft_out is not None:
            # MATLAB: surf(abs(rfftOut(:,:,1))) -> Linear magnitude
            plot_surface_3d(rfft_out[:, :, 0], 'Range FFT output (Antenna 0)', 'Chirps', 'Range bins', is_log=False)

    # 2. Doppler FFT Output
    dfft_mem = load_dat_file(os.path.join(work_folder, 'dfft_out.dat'), np.int16)
    if dfft_mem is not None:
        dfft_out = dfft_out_unformat(dfft_mem, nr_range_bins, nr_doppler_bins, nr_ant)
        if dfft_out is not None:
             plot_surface_3d(dfft_out[:, :, 0], 'Doppler FFT output (Antenna 0)', 'Doppler bins', 'Range bins', is_log=False)

    # 3. NCC Output
    rd_mag_mem = load_dat_file(os.path.join(work_folder, 'ncc_out.dat'), np.uint16)
    if rd_mag_mem is not None:
        rd_mag = rd_mag_unformat(rd_mag_mem, nr_range_bins, nr_doppler_bins)
        if rd_mag is not None:
            # MATLAB: surf(rdMag), title('... "Log2 Mag2" format')
            # Assuming data is already log-like or user wants to see raw values as per MATLAB
            plot_surface_3d(rd_mag, 'RD-Magnitude (NCC Output)', 'Doppler bins', 'Range bins', is_log=False)

    # 4. Peak Search Output
    ps_stream = load_dat_file(os.path.join(work_folder, 'ps_out.dat'), np.uint8)
    if ps_stream is not None:
        ps_mem = char_stream_to_int(ps_stream, 4)
        ps_tag = det_tag_unformat(ps_mem, nr_range_bins, nr_doppler_bins)
        if ps_tag is not None:
             plot_surface_3d(ps_tag, 'SPT Peak Search', 'Doppler bins', 'Range bins', is_log=False)

    # 5. DSP CFAR Output
    cfar_stream = load_dat_file(os.path.join(work_folder, 'caCfar_bmp_out.dat'), np.uint8)
    if cfar_stream is not None:
        cfar_mem = char_stream_to_int(cfar_stream, 4)
        cfar_tag = det_tag_unformat(cfar_mem, nr_doppler_bins, nr_range_bins)
        if cfar_tag is not None:
            # Transpose to match RDM dims
            plot_surface_3d(cfar_tag.T, 'DSP Peak Search (CFAR)', 'Doppler bins', 'Range bins', is_log=False)

    plt.show()

if __name__ == "__main__":
    main()

