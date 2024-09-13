#include "../Includes/DRIVER/DRIVER_NVIC.h"

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

