#include "../Includes/DRIVER/DRIVER_UART_checkData.h"

typedef enum
{
    HAL_UART_SUCCESS = 0,
    HAL_UART_PARITY_ERROR,
    HAL_UART_OVERRUN_ERROR,
    HAL_UART_FRAME_ERROR,
    HAL_UART_NOISE_ERROR,
    HAL_UART_UNKNOWN_ERROR
} HAL_UART_Status;

HAL_UART_Status HAL_UART_D_send(UART_Type *UART_number, char data)
{

    if (UART_number->S1 & UART_S1_OR_MASK)
    {
        return HAL_UART_OVERRUN_ERROR;
    }
    if (UART_number->S1 & UART_S1_FE_MASK)
    {
        return HAL_UART_FRAME_ERROR;
    }
    if (UART_number->S1 & UART_S1_NF_MASK)
    {
        return HAL_UART_NOISE_ERROR;
    }

    UART_number->D = data;

    while (!(UART_number->S1 & UART_S1_TDRE_MASK))
    {
    }

    return HAL_UART_SUCCESS;
}

HAL_UART_Status HAL_UART_D_receiver(UART_Type *UART_number, char data)
{

    if (UART_number->S1 & UART_S1_OR_MASK)
    {
        return HAL_UART_OVERRUN_ERROR;
    }
    if (UART_number->S1 & UART_S1_FE_MASK)
    {
        return HAL_UART_FRAME_ERROR;
    }
    if (UART_number->S1 & UART_S1_NF_MASK)
    {
        return HAL_UART_NOISE_ERROR;
    }

    while (!(UART0->S1 & UART_S1_RDRF_MASK))
        ;
    UART_number->D = data;

    return HAL_UART_SUCCESS;
}
