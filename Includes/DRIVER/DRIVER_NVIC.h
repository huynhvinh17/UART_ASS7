#ifndef _DRIVER_NVIC_
#define _DRIVER_NVIC_

#include "MKL46Z4.h"
#include "stdint.h"
#include "../Includes/HAL/HAL_NVIC.h"
#include "../Includes/DRIVER/DRIVER_PIT.h"
#include "stddef.h"
#include "stdbool.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef void (*PIT_callback_t)(void);

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enables the interrupt for a IRQ number
 *
 * @param irq_number The IRQ number to be enable
 */
void DRIVER_NVIC_EnableIRQ(IRQn_Type irq_number);

void DRIVER_NVIC_setPriority(IRQn_Type irq_number, uint8_t number);

void DRIVER_PIT0_Callback(PIT_callback_t callback);

void DRIVER_PIT1_Callback(PIT_callback_t callback);


/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_NVIC_ */
