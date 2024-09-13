#ifndef _HAL_NVIC_H_
#define _HAL_NVIC_H_

#include "MKL46Z4.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enable interrupt for a specific IRQ
 *
 * @param irq_number The IRQ number to be enabled
 */
void HAL_EnableIRQ(IRQn_Type irq_number);

void HAL_NVIC_setPriority(IRQn_Type irq_number,uint8_t number);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** HAL_NVIC_H */
