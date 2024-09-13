#ifndef _HAL_UART_D_H_
#define _HAL_UART_D_H_

#include "MKL46Z4.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Reads a byte of data from the UART data register
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return The data byte read from the UART data register
 */
char HAL_UART_getData(UART_Type *UART_number);

/**
 * @brief Writes a byte of data to the UART data register
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param data The byte of data to be sent via UART
 */
void HAL_UART_sendData(UART_Type *UART_number, char data);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_UART_BDH_H_ */
