#ifndef _HAL_UART_S1_H_
#define _HAL_UART_S1_H_

#include "MKL46Z4.h"
#include <stdbool.h>

bool HAL_UART_S1_TDRE(UART_Type *UART_number);
bool HAL_UART_S1_TC(UART_Type *UART_number);
bool HAL_UART_S1_RDRF(UART_Type *UART_number);
bool HAL_UART_S1_IDLE(UART_Type *UART_number);
bool HAL_UART_S1_OR(UART_Type *UART_number);
bool HAL_UART_S1_NF(UART_Type *UART_number);
bool HAL_UART_S1_PE(UART_Type *UART_number);
bool HAL_UART_S1_PF(UART_Type *UART_number);


#endif /** _HAL_UART_S1_H_ */
