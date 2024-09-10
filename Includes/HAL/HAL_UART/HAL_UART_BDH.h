#ifndef _HAL_UART_BDH_H_
#define _HAL_UART_BDH_H_

#include "MKL46Z4.h"
#include <stdint.h>

typedef enum BDH_LBKDIE_enable
{
    Hardware_interrupt_disable,
    Hardware_interrupt_enable,
} HAL_UART_BDH_LBKDIE_enable_t;

typedef HAL_UART_BDH_LBKDIE_enable_t HAL_UART_BDH_RXEDGIE_enable_t;

typedef enum BDH_SBNS
{
    One_stop_bit,
    Two_stop_bit,
}HAL_UART_BDH_SBNS_t;

void HAL_UART_BDH_LBKDIE(UART_Type *UART_number, HAL_UART_BDH_LBKDIE_enable_t status);
void HAL_UART_BDH_RXEDGIE(UART_Type *UART_number, HAL_UART_BDH_RXEDGIE_enable_t status);
void HAL_UART_BDH_SBNS(UART_Type *UART_number, HAL_UART_BDH_SBNS_t bitConfig );
void HAL_UART_BDH_SBR(UART_Type *UART_number, uint16_t BDH_SBR);

#endif /** _HAL_UART_BDH_H_ */
