#include "../Includes/HAL/HAL_UART/HAL_UART_BDL.h"

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
 * @brief Set the Baud Rate Divider (BDL) register for UART.
 *
 * @param UART_number Pointer to the UART peripheral
 * @param SBR The baud rate setting to be written to the BDL register
 */
void HAL_UART_BDL_SBR(UART_Type *UART_number, uint16_t SBR)
{
    UART_number->BDL = (SBR & UART_BDL_SBR_MASK);
}
