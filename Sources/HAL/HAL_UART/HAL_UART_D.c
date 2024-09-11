#include "../Includes/HAL/HAL_UART/HAL_UART_D.h"

char HAL_UART_data(UART_Type *UART_number)
{
    return UART_number->D;
}

void HAL_UART_data_assign(UART_Type *UART_number, char data)
{
    UART_number->D = data;
}