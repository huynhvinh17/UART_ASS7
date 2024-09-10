#ifndef _DRIVER_UART_H_
#define _DRIVER_UART_H_

#include <MKL46Z4.h>
#include <stdint.h>
#include "../Includes/HAL/HAL_UART/HAL_UART_BDH.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_BDL.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_C1.h"
#include "../Includes/HAL/HAL_UART/HAL_UART_C2.h"

typedef HAL_UART_C2_TE_t DRIVER_UART_C2_TE_t;
typedef HAL_UART_C2_RE_t DRIVER_UART_C2_RE_t;

void DRIVER_UART_BDH(UART_Type *UART_number, uint16_t SBR);
void DRIVER_UART_BDL(UART_Type *UART_number, uint16_t SBR);
void DRIVER_UART_C2(UART_Type *UART_number, DRIVER_UART_C2_TE_t transmitter_status, DRIVER_UART_C2_RE_t receiver_status);

#endif /** _DRIVER_UART_H_*/
