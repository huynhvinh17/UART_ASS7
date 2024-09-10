#include "../Includes/HAL/HAL_UART/HAL_UART_D.h"

uint16_t UART_data(UART_Type *UART_number)
{
    return UART_number->D;
}


