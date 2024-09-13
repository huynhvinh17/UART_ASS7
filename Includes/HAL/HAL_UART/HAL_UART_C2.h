#ifndef _HAL_UART_C2_H_
#define _HAL_UART_C2_H_

#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/



/**
 * @brief Enum for configuring the transmitter interrupt enable status in UART control register C2
 *
 */
typedef enum C2_TIE
{
    hardware_interrupt_disable,
    hardware_interrupt_enable
} HAL_UART_C2_TIE_t;

typedef HAL_UART_C2_TIE_t HAL_UART_C2_TCIE_t; /** Typedef for configuring the transmitter complete interrupt enable status */
typedef HAL_UART_C2_TIE_t HAL_UART_C2_RIE_t;  /** Typedef for configuring the receiver interrupt enable status*/
typedef HAL_UART_C2_TIE_t HAL_UART_C2_ILIE_t; /** Typedef for configuring the idle line interrupt enable status*/

/**
 * @brief Enum for configuring the transmitter enable status in UART control register C2
 *
 */
typedef enum C2_TE
{
    transmitter_disable,
    transmitter_enable,
} HAL_UART_C2_TE_t;

/**
 * @brief Enum for configuring the receiver enable status in UART control register C2
 *
 */
typedef enum C2_RE
{
    receiver_disable,
    receiver_enable,
} HAL_UART_C2_RE_t;

/**
 * @brief Enum for configuring the receiver wake-up control in UART control register C2
 *
 */
typedef enum C2_RWU
{
    receiver_normal,
    wait_for_wakeup
} HAL_UART_C2_RWU_t;

/**
 * @brief Enum for configuring the send break status in UART control register C2
 *
 */
typedef enum C2_SBK
{
    normal_transmitter,
    queue_break_to_sent
} HAL_UART_C2_SBK_t;

/**
 * @brief Sets the transmitter interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param trans_interrupt_status Status to set for transmitter interrupt enable (TIE)
 */
void HAL_UART_C2_TIE(UART_Type *UART_number, HAL_UART_C2_TIE_t trans_interrupt_status);

/**
 * @brief Sets the transmitter complete interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param trans_complete_interrupt_status Status to set for transmitter complete interrupt enable (TCIE)
 */
void HAL_UART_C2_TCIE(UART_Type *UART_number, HAL_UART_C2_TCIE_t trans_complete_interrupt_status);

/**
 * @brief Sets the receiver interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_interrupt_status Status to set for receiver interrupt enable (RIE)
 */
void HAL_UART_C2_RIE(UART_Type *UART_number, HAL_UART_C2_RIE_t receiver_interrupt_status);

/**
 * @brief Sets the idle line interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param idle_status Status to set for idle line interrupt enable (ILIE)
 */
void HAL_UART_C2_ILIE(UART_Type *UART_number, HAL_UART_C2_ILIE_t idle_status);

/**
 * @brief Sets the transmitter enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param transmitter_status Status to set for transmitter enable (TE)
 */
void HAL_UART_C2_TE(UART_Type *UART_number, HAL_UART_C2_TE_t transmitter_status);

/**
 * @brief Sets the receiver enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_status Status to set for receiver enable (RE)
 */
void HAL_UART_C2_RE(UART_Type *UART_number, HAL_UART_C2_RE_t receiver_status);

/**
 * @brief Sets the receiver wakeup control status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_wakeup_control Status to set for receiver wakeup control (RWU)
 */
void HAL_UART_C2_RWU(UART_Type *UART_number, HAL_UART_C2_RWU_t receiver_wakeup_control);

/**
 * @brief Sets the send break status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param send_break Status to set for send break (SBK)
 */
void HAL_UART_C2_SBK(UART_Type *UART_number, HAL_UART_C2_SBK_t send_break);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_UART_C2_H_ */
