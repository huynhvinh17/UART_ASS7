#include "../Includes/HAL/HAL_UART/HAL_UART_S1.h"

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
 * @brief Checks if the Transmit Data Register (TDR) is Empty
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if TDR is empty, false otherwise
 */
bool HAL_UART_S1_TDRE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_TDRE_MASK);
}

/**
 * @brief Checks if Transmission is Complete
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if transmission is complete, false otherwise
 */
bool HAL_UART_S1_TC(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_TC_MASK);
}

/**
 * @brief Checks if the Receive Data Register (RDR) is Full
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if RDR is full, false otherwise
 */
bool HAL_UART_S1_RDRF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_RDRF_MASK);
}

/**
 * @brief Checks if the UART is Idle
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if UART is idle, false otherwise
 */
bool HAL_UART_S1_IDLE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_IDLE_MASK);
}

/**
 * @brief Checks if an Overrun Error has occurred
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if an overrun error occurred, false otherwise
 */
bool HAL_UART_S1_OR(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_OR_MASK);
}

/**
 * @brief Checks if a Noise Error has occurred
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if a noise error occurred, false otherwise
 */
bool HAL_UART_S1_NF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_NF_MASK);
}

/**
 * @brief Checks if a Framing Error has occurred
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if a framing error occurred, false otherwise
 */
bool HAL_UART_S1_FE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_FE_MASK);
}

/**
 * @brief Checks if a Parity Error has occurred
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @return true if a parity error occurred, false otherwise
 */
bool HAL_UART_S1_PF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_PF_MASK);
}
