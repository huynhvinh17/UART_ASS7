#ifndef _HAL_UART_BDH_H_
#define _HAL_UART_BDH_H_

#include "MKL46Z4.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for Break Detection Interrupt Enable (LBKDIE) configuration in the BDH register.
 *
 */
typedef enum BDH_LBKDIE_enable
{
    Hardware_interrupt_disable, /**< Disable Detection Interrupt */
    Hardware_interrupt_enable,  /**< Enable Detection Interrupt */
} HAL_UART_BDH_LBKDIE_enable_t;

/**
 * @brief Typedef for Receive Edge Interrupt Enable (RXEDGIE) configuration in the BDH register.
 *
 */
typedef HAL_UART_BDH_LBKDIE_enable_t HAL_UART_BDH_RXEDGIE_enable_t;

/**
 * @brief Enumeration for Number of Stop Bits (SBNS) configuration in the BDH register.
 *
 */
typedef enum BDH_SBNS
{
    One_stop_bit, /** Configure UART for 1 stop bit */
    Two_stop_bit, /** Configure UART for 2 stop bits */
} HAL_UART_BDH_SBNS_t;

/**
 * @brief Set the Break Detection Interrupt Enable (LBKDIE) bit in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param status The desired state for LBKDIE: enable or disable.
 */
void HAL_UART_BDH_LBKDIE(UART_Type *UART_number, HAL_UART_BDH_LBKDIE_enable_t status);

/**
 * @brief Set the Receive Edge Interrupt Enable (RXEDGIE) bit in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance (e.g., UART0, UART1).
 * @param status Thestate for RXEDGIE: enable or disable.
 */
void HAL_UART_BDH_RXEDGIE(UART_Type *UART_number, HAL_UART_BDH_RXEDGIE_enable_t status);

/**
 * @brief Set the Number of Stop Bits (SBNS) configuration in the BDH register.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param bitConfig The desired number of stop bits configuration: 1 or 2 stop bits.
 */
void HAL_UART_BDH_SBNS(UART_Type *UART_number, HAL_UART_BDH_SBNS_t bitConfig);

/**
 * @brief Set the Baud Rate Divider High (BDH) register for UART.
 *
 * @param UART_number Pointer to the UART peripheral instance.
 * @param SBR The baud rate setting to be written to the BDH register.
 */
void HAL_UART_BDH_SBR(UART_Type *UART_number, uint16_t BDH_SBR);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_UART_BDH_H_ */
