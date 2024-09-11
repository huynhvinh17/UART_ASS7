#include "../Includes/HAL/HAL_UART/HAL_UART_C1.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void HAL_UART_C1_LOOPS(UART_Type *UART_number, HAL_UART_LOOP_mode_t mode)
{
    UART_number->C1 |= UART_C1_LOOPS(mode);
}
void HAL_UART_C1_DOZEEN(UART_Type *UART_number, HAL_UART_Doze_enable_t status)
{
    UART_number->C1 |= UART0_C1_DOZEEN(status);
}
void HAL_UART_C1_RSRC(UART_Type *UART_number, HAL_UART_RSRC_source_select_t source_select)
{
    UART_number->C1 |= UART_C1_RSRC(source_select);
}
void HAL_UART_C1_M(UART_Type *UART_number, HAL_UART_bit_data_mode_t bit_data)
{
    UART_number->C1 |= UART_C1_M(bit_data);
}
void HAL_UART_C1_WAKE(UART_Type *UART_number, HAL_UART_bit_data_mode_t data_mode)
{
    UART_number->C1 |= UART_C1_WAKE(data_mode);
}
void HAL_UART_C1_ILT(UART_Type *UART_number, HAL_UART_Idle_line_type_t type)
{
    UART_number->C1 |= UART_C1_ILT(type);
}
void HAL_UART_C1_PE(UART_Type *UART_number, HAL_UART_parity_status_t parity_status)
{
    UART_number->C1 |= UART_C1_PE(parity_status);
}
void HAL_UART_C1_PT(UART_Type *UART_number, HAL_UART_parity_type_t parity_type)
{
    UART_number->C1 |= UART_C1_PT(parity_type);
}
