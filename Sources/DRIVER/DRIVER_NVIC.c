/**
 * @file DRIVER_NVIC.c
 * @author huynhvinh17@gmail.com
 * @brief NVIC driver implementation for enabling interrupts
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/DRIVER/DRIVER_NVIC.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

PIT_callback_t PIT0_callback = NULL;
PIT_callback_t PIT1_callback = NULL;

bool PIT0_interruptFlag = false;
bool PIT1_interruptFlag = false;

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Enables the interrupt for a IRQ number
 *
 * @param irq_number The IRQ number to be enable
 */
void DRIVER_NVIC_EnableIRQ(IRQn_Type irq_number)
{
    HAL_EnableIRQ(irq_number); /**  Call the HAL function to enable the interrupt */
}

void DRIVER_NVIC_setPriority(IRQn_Type irq_number, uint8_t number)
{
    HAL_NVIC_setPriority(irq_number, number);
}

