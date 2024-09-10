#include "../Includes/HAL/HAL_UART/HAL_UART_BDL.h"

void HAL_UART_BDL_SBR(UART_Type *UART_number, uint16_t SBR)
{
    UART_number->BDL = (SBR & UART_BDL_SBR_MASK);
}
