#include "../Includes/HAL/HAL_UART/HAL_UART_C1.h"

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
 * @brief Configures the loop mode in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param mode Mode to set for loop operation
 */
void HAL_UART_C1_LOOPS(UART_Type *UART_number, HAL_UART_LOOP_mode_t mode)
{
    UART_number->C1 |= UART_C1_LOOPS(mode);
}

/**
 * @brief Configures the doze mode enable status in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param status Status to set for doze mode enable
 */
void HAL_UART_C1_DOZEEN(UART_Type *UART_number, HAL_UART_Doze_enable_t status)
{
    UART_number->C1 |= UART0_C1_DOZEEN(status);
}

/**
 * @brief Configures the source select for UART in control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param source_select Source select to set for UART operation
 */
void HAL_UART_C1_RSRC(UART_Type *UART_number, HAL_UART_RSRC_source_select_t source_select)
{
    UART_number->C1 |= UART_C1_RSRC(source_select);
}


/**
 * @brief Configures the bit data mode in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param bit_data Bit data mode to set
 */
void HAL_UART_C1_M(UART_Type *UART_number, HAL_UART_bit_data_mode_t bit_data)
{
    UART_number->C1 |= UART_C1_M(bit_data);
}

/**
 * @brief Configures the wake-up method in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param data_mode Data mode to set for wake-up
 */
void HAL_UART_C1_WAKE(UART_Type *UART_number, HAL_UART_bit_data_mode_t data_mode)
{
    UART_number->C1 |= UART_C1_WAKE(data_mode);
}


/**
 * @brief Configures the idle line type in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param type Idle line type to set
 */
void HAL_UART_C1_ILT(UART_Type *UART_number, HAL_UART_Idle_line_type_t type)
{
    UART_number->C1 |= UART_C1_ILT(type);
}

/**
 * @brief Configures the parity enable status in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param parity_status Status to set for parity enable
 */
void HAL_UART_C1_PE(UART_Type *UART_number, HAL_UART_parity_status_t parity_status)
{
    UART_number->C1 |= UART_C1_PE(parity_status);
}

/**
 * @brief Configures the parity type in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param parity_type Parity type to set
 */
void HAL_UART_C1_PT(UART_Type *UART_number, HAL_UART_parity_type_t parity_type)
{
    UART_number->C1 |= UART_C1_PT(parity_type);
}
