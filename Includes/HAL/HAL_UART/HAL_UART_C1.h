#ifndef _HAL_UART_C1_H_
#define _HAL_UART_C1_H_

#include "MKL46Z4.h"

typedef enum LOOP_mode
{
    normal,
    Loop_or_single_mode,
} HAL_UART_LOOP_mode_t;

typedef enum Doze_enable
{
    wait_mode_enable,
    wait_mode_disable
} HAL_UART_Doze_enable_t;

typedef enum RSRC_source_select
{
    select_loop,
    single_wire_mode
} HAL_UART_RSRC_source_select_t;

typedef enum bit_data_mode
{
    mode_8bit,
    mode_9bit,
} HAL_UART_bit_data_mode_t;

typedef enum Idle_line_type
{
    bit_count_after_start_bit,
    bit_count_after_stop_bit
} HAL_UART_Idle_line_type_t;

typedef enum parity_status
{
    no_checking,
    enble
} HAL_UART_parity_status_t;

typedef enum parity_type
{
    even_parity,
    odd_parity
} HAL_UART_parity_type_t;

void HAL_UART_C1_LOOPS(UART_Type *UART_number, HAL_UART_LOOP_mode_t mode);
void HAL_UART_C1_DOZEEN(UART_Type *UART_number, HAL_UART_Doze_enable_t status);
void HAL_UART_C1_RSRC(UART_Type *UART_number, HAL_UART_RSRC_source_select_t source_select);
void HAL_UART_C1_M(UART_Type *UART_number, HAL_UART_bit_data_mode_t bit_data);
void HAL_UART_C1_WAKE(UART_Type *UART_number, HAL_UART_bit_data_mode_t data_mode);
void HAL_UART_C1_ILT(UART_Type *UART_number, HAL_UART_Idle_line_type_t type);
void HAL_UART_C1_PE(UART_Type *UART_number, HAL_UART_parity_status_t parity_status);
void HAL_UART_C1_PT(UART_Type *UART_number, HAL_UART_parity_type_t parity_type);


#endif /** _HAL_UART_C1_H_ */
