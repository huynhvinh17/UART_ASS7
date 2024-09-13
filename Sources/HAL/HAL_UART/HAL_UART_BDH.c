#include "../Includes/HAL/HAL_UART/HAL_UART_BDH.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Set the Break Detection Interrupt Enable (LBKDIE) bit in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param status The desired state for LBKDIE: enable or disable.
 */
void HAL_UART_BDH_LBKDIE(UART_Type *UART_number, HAL_UART_BDH_LBKDIE_enable_t status)
{
    UART_number->BDH |= UART_BDH_LBKDIE(status);
}

/**
 * @brief Set the Receive Edge Interrupt Enable (RXEDGIE) bit in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance (e.g., UART0, UART1).
 * @param status Thestate for RXEDGIE: enable or disable.
 */
void HAL_UART_BDH_RXEDGIE(UART_Type *UART_number, HAL_UART_BDH_RXEDGIE_enable_t status)
{
    UART_number->BDH |= UART_BDH_RXEDGIE(status);
}

/**
 * @brief Set the Number of Stop Bits (SBNS) configuration in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param bitConfig The desired number of stop bits configuration: 1 or 2 stop bits.
 */
void HAL_UART_BDH_SBNS(UART_Type *UART_number, HAL_UART_BDH_SBNS_t bitConfig)
{
    UART_number->BDH |= UART_BDH_SBNS(bitConfig);
}

/**
 * @brief Set the Baud Rate Divider High (BDH) register for UART.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param SBR The baud rate setting to be written to the BDH register.
 */
void HAL_UART_BDH_SBR(UART_Type *UART_number, uint16_t SBR)
{
    UART_number->BDH = ((SBR >> 8) & UART_BDH_SBR_MASK);
}
