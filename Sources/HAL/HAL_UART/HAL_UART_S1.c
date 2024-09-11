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

bool HAL_UART_S1_TDRE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_TDRE_MASK);
}

bool HAL_UART_S1_TC(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_TC_MASK);
}

bool HAL_UART_S1_RDRF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_RDRF_MASK);
}

bool HAL_UART_S1_IDLE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_IDLE_MASK);
}

bool HAL_UART_S1_OR(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_OR_MASK);
}

bool HAL_UART_S1_NF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_NF_MASK);
}

bool HAL_UART_S1_FE(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_FE_MASK);
}

bool HAL_UART_S1_PF(UART_Type *UART_number)
{
    return (UART_number->S1 & UART_S1_PF_MASK);
}
