#ifndef _DRIVER_UART_H_
#define _DRIVER_UART_H_

#include <MKL46Z4.h>
#include <stdint.h>
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_BDH.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_BDL.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_C1.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_C2.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_D.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_S1.h"
#include "../Includes/HAL/HAL_PORT.h"
#include "../Includes/HAL/HAL_NVIC.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Type definition for UART0 callback function
 *
 */
typedef void (*UART0_callback_t)(void);

/**
 * @brief Structure to hold UART configuration settings
 */
typedef struct
{
    UART_Type *UARTx;                            /** Pointer to the UART peripheral base address */
    PORT_Type *port;                             /** Pointer to the PORT peripheral base address for pin configuration */
    uint32_t baudRate;                           /** Desired baud rate for UART communication */
    uint32_t clockFreq;                          /** Frequency of the UART clock */
    uint8_t oversamplingRatio;                   /** Oversampling ratio used in UART communication */
    uint8_t txPin;                               /** Pin number for UART transmit */
    uint8_t rxPin;                               /** Pin number for UART receive */
    HAL_pin_mux_control_t pin_mux;               /** Pin multiplexing control settings */
    HAL_UART_C2_TE_t trans_interrupt_status;     /** UART transmit interrupt status */
    HAL_UART_C2_RE_t receiver_interrupt_status;  /** UART receive interrupt status */
    HAL_UART_C2_RIE_t hardware_interrupt_status; /** UART hardware interrupt status */
    IRQn_Type select_IRQn;                       /** Interrupt number for UART */
} UART_Handle_t;

/**
 * @brief Initializes the UART peripheral
 *
 * @param uartHandle Pointer to the UART handle structure
 */
void DRIVER_INIT_UART(UART_Handle_t *uartHandle);

/**
 * @brief Sends a string of characters via UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @param string The string to be sent
 */
void DRIVER_SendData(UART_Handle_t *uartHandle, const char *string);

/**
 * @brief Receives a command string from UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @param buffer Buffer to store the received command string
 * @param maxLength Maximum length of the buffer
 */
void DRIVER_GetCommand(UART_Handle_t *uartHandle, char *buffer, uint16_t maxLength);

/**
 * @brief Sets the UART0 callback function
 *
 * @param callback callback Pointer to the callback function
 */
void DRIVER_Callback(UART0_callback_t callback);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_UART_H_*/
