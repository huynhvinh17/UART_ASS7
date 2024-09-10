#include "../Includes/HAL/HAL_UART/HAL_UART_C2.h"

void HAL_UART_C2_TIE(UART_Type *UART_number, HAL_UART_C2_TIE_t trans_interrupt_status)
{
    UART_number->C2 |= UART_C2_TIE(trans_interrupt_status);
}
void HAL_UART_C2_TCIE(UART_Type *UART_number, HAL_UART_C2_TCIE_t trans_complete_interrupt_status)
{
    UART_number->C2 |= UART_C2_TCIE(trans_complete_interrupt_status);
}
void HAL_UART_C2_RIE(UART_Type *UART_number, HAL_UART_C2_RIE_t receiver_interrupt_status)
{
    UART_number->C2 |= UART_C2_RIE(receiver_interrupt_status);
}
void HAL_UART_C2_ILIE(UART_Type *UART_number, HAL_UART_C2_ILIE_t idle_status)
{
    UART_number->C2 |= UART_C2_ILIE(idle_status);
}
void HAL_UART_C2_TE(UART_Type *UART_number, HAL_UART_C2_TE_t transmitter_status)
{
    UART_number->C2 |= UART_C2_TE(transmitter_status);
}
void HAL_UART_C2_RE(UART_Type *UART_number, HAL_UART_C2_RE_t receiver_status)
{
    UART_number->C2 |= UART_C2_RE(receiver_status);
}
void HAL_UART_C2_RWU(UART_Type *UART_number, HAL_UART_C2_RWU_t receiver_wakeup_control)
{
    UART_number->C2 |= UART_C2_RWU(receiver_wakeup_control);
}
void HAL_UART_C2_SBK(UART_Type *UART_number, HAL_UART_C2_SBK_t send_break)
{
    UART_number->C2 |= UART_C2_SBK(send_break);
}
