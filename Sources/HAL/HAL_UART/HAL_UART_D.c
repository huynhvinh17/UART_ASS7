#include "../Includes/HAL/HAL_UART/HAL_UART_D.h"

char UART_data(UART_Type *UART_number)
{
    return UART_number->D;
}


