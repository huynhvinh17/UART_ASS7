#include "../Includes/HAL/HAL_UART/HAL_UART_D.h"

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
 * @brief Reads a byte of data from the UART data register
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return The data byte read from the UART data register
 */
char HAL_UART_getData(UART_Type *UART_number)
{
    return UART_number->D;
}

/**
 * @brief Writes a byte of data to the UART data register
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param data The byte of data to be sent via UART
 */
void HAL_UART_sendData(UART_Type *UART_number, char data)
{
    UART_number->D = data;
}