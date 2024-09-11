#include "../Includes/DRIVER/DRIVER_UART.h"


void DRIVER_UART_BDH( UART_Type *UART_number, uint16_t SBR)
{
    HAL_UART_BDH_SBR(UART_number, SBR);
}
void DRIVER_UART_BDL(UART_Type *UART_number, uint16_t SBR)
{
    HAL_UART_BDL_SBR(UART_number, SBR);
}

void DRIVER_UART_C2(UART_Type *UART_number, DRIVER_UART_C2_TE_t transmitter_status, DRIVER_UART_C2_RE_t receiver_status)
{
    HAL_UART_C2_TE(UART_number, transmitter_status);
    HAL_UART_C2_RE(UART_number, receiver_status);
}

void DRIVER_UART_C2_interruptStatus(UART_Type *UART_number, DRIVER_UART_C2_RIE_t receiver_interrupt_status)
{
    HAL_UART_C2_RIE(UART_number,receiver_interrupt_status);
}