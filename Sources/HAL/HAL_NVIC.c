/**
 * @file HAL_NVIC.c
 * @author huynhvinh17@gmail.com
 * @brief Hardware Abstraction Layer (HAL) for Nested Vectored Interrupt Controller (NVIC) operations.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/HAL/HAL_NVIC.h"
#include "MKL46Z4.h"
#include "core_cm0plus.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Enable interrupt for a specific IRQ
 *
 * @param irq_number The IRQ number to be enabled
 */
void HAL_EnableIRQ(IRQn_Type irq_number)
{
    NVIC_EnableIRQ(irq_number); /** Enable interrupt in the NVIC for irq Number */
}

void HAL_NVIC_setPriority(IRQn_Type irq_number,uint8_t number)
{
    NVIC_SetPriority(irq_number, number);
}
