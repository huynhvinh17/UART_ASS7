#include "../Includes/HAL/HAL_UART/HAL_UART_BDH.h"

void HAL_UART_BDH_LBKDIE(UART_Type *UART_number, HAL_UART_BDH_LBKDIE_enable_t status)
{
    UART_number->BDH |= UART_BDH_LBKDIE(status);
}
void HAL_UART_BDH_RXEDGIE(UART_Type *UART_number, HAL_UART_BDH_RXEDGIE_enable_t status)
{
    UART_number->BDH |= UART_BDH_RXEDGIE(status);
}
void HAL_UART_BDH_SBNS(UART_Type *UART_number, HAL_UART_BDH_SBNS_t bitConfig)
{
    UART_number->BDH |= UART_BDH_SBNS(bitConfig);
}
void HAL_UART_BDH_SBR(UART_Type *UART_number, uint16_t SBR)
{
    UART_number->BDH = ((SBR >> 8) & UART_BDH_SBR_MASK);
}
