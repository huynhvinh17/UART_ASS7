#ifndef _HAL_UART_D_H_
#define _HAL_UART_D_H_

#include "MKL46Z4.h"
#include <stdint.h>

char HAL_UART_data(UART_Type *UART_number);

void HAL_UART_data_assign(UART_Type *UART_number, char data);

#endif /** _HAL_UART_BDH_H_ */
