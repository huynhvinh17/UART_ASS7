#ifndef _HAL_UART_C2_H_
#define _HAL_UART_C2_H_

#include "MKL46Z4.h"

typedef enum C2_TIE
{
    hardware_interrupt_disable,
    hardware_interrupt_enable
} HAL_UART_C2_TIE_t;

typedef HAL_UART_C2_TIE_t HAL_UART_C2_TCIE_t ;

typedef HAL_UART_C2_TCIE_t HAL_UART_C2_RIE_t;
typedef HAL_UART_C2_TCIE_t HAL_UART_C2_ILIE_t;


typedef enum C2_TE
{
    transmitter_disable,
    transmitter_enable,
} HAL_UART_C2_TE_t;

typedef enum C2_RE
{
    receiver_disable,
    receiver_enable,
} HAL_UART_C2_RE_t;

typedef enum C2_RWU
{
    receiver_normal,
    wait_for_wakeup
} HAL_UART_C2_RWU_t;

typedef enum C2_SBK
{
    normal_transmitter,
    queue_break_to_sent
} HAL_UART_C2_SBK_t;

void HAL_UART_C2_TIE(UART_Type *UART_number, HAL_UART_C2_TIE_t trans_interrupt_status);

void HAL_UART_C2_TCIE(UART_Type *UART_number, HAL_UART_C2_TCIE_t trans_complete_interrupt_status);

void HAL_UART_C2_RIE(UART_Type *UART_number, HAL_UART_C2_RIE_t receiver_interrupt_status);

void HAL_UART_C2_ILIE(UART_Type *UART_number, HAL_UART_C2_ILIE_t idle_status);

void HAL_UART_C2_TE(UART_Type *UART_number, HAL_UART_C2_TE_t transmitter_status);

void HAL_UART_C2_RE(UART_Type *UART_number, HAL_UART_C2_RE_t receiver_status);

void HAL_UART_C2_RWU(UART_Type *UART_number, HAL_UART_C2_RWU_t receiver_wakeup_control);

void HAL_UART_C2_SBK(UART_Type *UART_number, HAL_UART_C2_SBK_t send_break);


#endif /** _HAL_UART_C2_H_ */
