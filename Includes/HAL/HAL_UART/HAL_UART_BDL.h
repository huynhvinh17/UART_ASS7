#ifndef _HAL_UART_BDL_H_
#define _HAL_UART_BDL_H_

#include "MKL46Z4.h"
#include <stdint.h>

void HAL_UART_BDL_SBR(UART_Type *UART_number, uint16_t SBR);

#endif /** _HAL_UART_BDL_H_ */
