#include "../Includes/HAL/HAL_NVIC.h"

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
