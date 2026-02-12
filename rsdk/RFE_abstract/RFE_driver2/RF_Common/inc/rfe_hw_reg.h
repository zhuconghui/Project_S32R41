#ifndef RFE_HW_REG_H
#define RFE_HW_REG_H

#include <stdint.h>
#include <stdbool.h>

#include "rfe_error.h"

/**
 * \file
 *
 * Register Access software unit for accessing bus registers.
 */

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/**
 * Base address for hardware peripherals.
 */
typedef uint32_t    rfeHwReg_base_t;

/**
 * Register offset for hardware peripherals.
 */
typedef uint16_t    rfeHwReg_offset_t;

/**
 * Register value for hardware peripherals.
 */
typedef uint32_t    rfeHwReg_register32_t;

/**
 * Register bit value for hardware peripherals.
 */
typedef uint8_t    rfeHwReg_registerBit_t;

/**
 * The least-significant bit of the register offset determines the register access mode.
 * Normal write and read will be used if the least-significant bit is false.
 * FuSa write-read-compare and read-read-compare will be used if the least-significant bit is true.
 * Use this define in the register map to indicate that the FuSa behavior should be used.
 */
#define RFE_HW_REG_OFFSET_FUSA_MODE_BIT         ( ( rfeHwReg_offset_t ) ( 1ul<<0 ) )

/**
 * Number of bits in rfeHwReg_register32_t.
 */
#define RFE_HW_REG_REGISTER32_NUMBER_OF_BITS	( 32ul)


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief Writes a 32-bit value to an AHB hardware register.
 *
 * \param base     The base address of the peripheral to write.
 * \param offset   The address offset of the register to write.
 * \param value    The value to write.
 * \param [in,out] rfe___error___pointer Error parameter.
 */
void rfeHwReg_write(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_register32_t   value,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Reads a 32-bit value from a hardware register.
 *
 * \param base     The base address of the peripheral to read.
 * \param offset   The address offset of the register to read.
 * \param [in,out] rfe___error___pointer Error parameter.
 *
 * \return The value read from the AHB hardware register.
 */
rfeHwReg_register32_t rfeHwReg_read(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Modifies a hardware register.
 *
 * \param base     The base address of the peripheral to modify.
 * \param offset   The address offset of the register to modify.
 * \param value    The new value for the masked bits.
 * \param mask     Mask indicating which bits should be replaced in the hardware register with the bits in value.
 * \param [in,out] rfe___error___pointer Error parameter.
 */
void rfeHwReg_modify(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_register32_t   mask,
    rfeHwReg_register32_t   value,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Modifies a single bit value in a hardware register.
 *
 * \param base     The base address of the peripheral to modify.
 * \param offset   The address offset of the register to modify.
 * \param bit      The bit to modify.
 * \param value    The value to write.
 * \param [in,out] rfe___error___pointer Error parameter.
 */
void rfeHwReg_modifyBit(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_registerBit_t  bit,
    bool                    value,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Sets a single bit value in a hardware register.
 *
 * \param base     The base address of the peripheral to set.
 * \param offset   The address offset of the register to set.
 * \param bit      The bit to set.
 * \param [in,out] rfe___error___pointer Error parameter.
 */
void rfeHwReg_setBit(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_registerBit_t  bit,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Clears a single bit value in a hardware register.
 *
 * \param base     The base address of the peripheral to clear.
 * \param offset   The address offset of the register to clear.
 * \param bit      The bit to clear.
 * \param [in,out] rfe___error___pointer Error parameter.
 */
void rfeHwReg_clearBit(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_registerBit_t  bit,
    rfe_error_t* rfe___error___pointer
);

/**
 * \brief Reads a single bit value from a hardware register.
 *
 * \param base     The base address of the peripheral to read.
 * \param offset   The address offset of the register to read.
 * \param bit      The bit to read.
 * \param [in,out] rfe___error___pointer Error parameter.
 *
 * \return The bit read from the AHB hardware register.
 */
bool rfeHwReg_readBit(
    rfeHwReg_base_t         base,
    rfeHwReg_offset_t       offset,
    rfeHwReg_registerBit_t  bit,
    rfe_error_t* rfe___error___pointer
);


/******************************************************************************
 *                              UTILITIES
 *****************************************************************************/

/**
 * \brief Returns the bit mask for a specific bit.
 *
 * \param bit    The bit to modify.
 *
 * \return The bit mask for a specific bit.
 */
static inline rfeHwReg_register32_t rfeHwReg_util_bitMask(
    rfeHwReg_registerBit_t  bit
)
{
    return ( (rfeHwReg_register32_t)( 1ul << bit ) );
}

/**
 * \brief Sets a single bit value in an offline register value.
 *
 * \param reg    The offline register value.
 * \param bit    The bit to set.
 *
 * \return The value of the offline register with the specified bit set.
 */
static inline rfeHwReg_register32_t rfeHwReg_util_setBit(
    rfeHwReg_register32_t   reg,
    rfeHwReg_registerBit_t  bit
)
{
    return reg | rfeHwReg_util_bitMask( bit );
}

/**
 * \brief Clears a single bit value in an offline register value.
 *
 * \param reg    The offline register value.
 * \param bit    The bit to clear.
 *
 * \return The value of the offline register with the specified bit cleared.
 */
static inline rfeHwReg_register32_t rfeHwReg_util_clearBit(
    rfeHwReg_register32_t   reg,
    rfeHwReg_registerBit_t  bit
)
{
    return reg & ~rfeHwReg_util_bitMask( bit );
}

/**
 * \brief Modifies a single bit value in an offline register value.
 *
 * \param reg    The offline register value.
 * \param bit    The bit to modify.
 * \param value  The new value.
 *
 * \return The value of the offline register with the specified bit modified.
 */
static inline rfeHwReg_register32_t rfeHwReg_util_modifyBit(
    rfeHwReg_register32_t   reg,
    rfeHwReg_registerBit_t  bit,
    bool                    value
)
{
    rfeHwReg_register32_t result;

    if ( value )
    {
        result = rfeHwReg_util_setBit( reg, bit );
    }
    else
    {
        result = rfeHwReg_util_clearBit( reg, bit );
    }

    return result;
}

/**
 * \brief Gets a single bit value from an offline register value.
 *
 * \param reg    The offline register value.
 * \param bit    The bit to get.
 *
 * \return The value for the bit to get.
 */
static inline bool rfeHwReg_util_getBit(
    rfeHwReg_register32_t   reg,
    rfeHwReg_registerBit_t  bit
)
{
    rfeHwReg_register32_t bitMask = rfeHwReg_util_bitMask( bit );
    return ( reg & bitMask ) == bitMask;
}

#endif // !RFE_HW_REG_H
