#ifndef _HAL_UART_C1_H_
#define _HAL_UART_C1_H_

#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/



/**
 * @brief Enum for configuring the loop mode in UART control register C1
 *
 */
typedef enum LOOP_mode
{
    normal,              /** Normal operation mode */
    Loop_or_single_mode, /** Loop or single wire mode */
} HAL_UART_LOOP_mode_t;

/**
 * @brief Enum for configuring the Doze mode enable status in UART control register C1
 *
 */
typedef enum Doze_enable
{
    wait_mode_enable, /** Select loop mode operation */
    wait_mode_disable /** Select single wire mode operation */
} HAL_UART_Doze_enable_t;

/**
 * @brief Enum for configuring the bit data mode in UART control register C1
 *
 */
typedef enum RSRC_source_select
{
    select_loop,
    single_wire_mode
} HAL_UART_RSRC_source_select_t;

typedef enum bit_data_mode
{
    mode_8bit, /** 8-bit data mode */
    mode_9bit  /** 9-bit data mode */
} HAL_UART_bit_data_mode_t;

/**
 * @brief Enum for configuring the idle line type in UART control register C1
 *
 */
typedef enum Idle_line_type
{
    bit_count_after_start_bit, /** Idle line detection based on bit count after start bit */
    bit_count_after_stop_bit   /** Idle line detection based on bit count after stop bit */

} HAL_UART_Idle_line_type_t;

/**
 * @brief Enum for configuring the parity checking status in UART control register C1
 *
 */
typedef enum parity_status
{
    no_checking, /** No parity checking */
    enble        /** Enable parity checking */
} HAL_UART_parity_status_t;

/**
 * @brief Enum for configuring the parity type in UART control register C1
 *
 */
typedef enum parity_type
{
    even_parity, /** Even parity checking */
    odd_parity   /** Odd parity checking */
} HAL_UART_parity_type_t;

/**
 * @brief Configures the loop mode in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param mode Mode to set for loop operation
 */
void HAL_UART_C1_LOOPS(UART_Type *UART_number, HAL_UART_LOOP_mode_t mode);

/**
 * @brief Configures the doze mode enable status in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param status Status to set for doze mode enable
 */
void HAL_UART_C1_DOZEEN(UART_Type *UART_number, HAL_UART_Doze_enable_t status);

/**
 * @brief Configures the source select for UART in control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param source_select Source select to set for UART operation
 */
void HAL_UART_C1_RSRC(UART_Type *UART_number, HAL_UART_RSRC_source_select_t source_select);

/**
 * @brief Configures the bit data mode in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param bit_data Bit data mode to set
 */
void HAL_UART_C1_M(UART_Type *UART_number, HAL_UART_bit_data_mode_t bit_data);

/**
 * @brief Configures the wake-up method in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param data_mode Data mode to set for wake-up
 */
void HAL_UART_C1_WAKE(UART_Type *UART_number, HAL_UART_bit_data_mode_t data_mode);

/**
 * @brief Configures the idle line type in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param type Idle line type to set
 */
void HAL_UART_C1_ILT(UART_Type *UART_number, HAL_UART_Idle_line_type_t type);

/**
 * @brief Configures the parity enable status in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param parity_status Status to set for parity enable
 */
void HAL_UART_C1_PE(UART_Type *UART_number, HAL_UART_parity_status_t parity_status);

/**
 * @brief Configures the parity type in UART control register C1
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param parity_type Parity type to set
 */
void HAL_UART_C1_PT(UART_Type *UART_number, HAL_UART_parity_type_t parity_type);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_UART_C1_H_ */
