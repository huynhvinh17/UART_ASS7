#ifndef _HAL_UART_BDL_H_
#define _HAL_UART_BDL_H_

#include "MKL46Z4.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Set the Baud Rate Divider (BDL) register for UART.
 *
 * @param UART_number Pointer to the UART peripheral
 * @param SBR The baud rate setting to be written to the BDL register
 */
void HAL_UART_BDL_SBR(UART_Type *UART_number, uint16_t SBR);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_UART_BDL_H_ */
