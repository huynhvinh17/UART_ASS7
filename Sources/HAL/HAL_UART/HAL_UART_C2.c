#include "../Includes/HAL/HAL_UART/HAL_UART_C2.h"

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
 * @brief Sets the transmitter interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param trans_interrupt_status Status to set for transmitter interrupt enable (TIE)
 */
void HAL_UART_C2_TIE(UART_Type *UART_number, HAL_UART_C2_TIE_t trans_interrupt_status)
{
    UART_number->C2 |= UART_C2_TIE(trans_interrupt_status);
}

/**
 * @brief Sets the transmitter complete interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param trans_complete_interrupt_status Status to set for transmitter complete interrupt enable (TCIE)
 */
void HAL_UART_C2_TCIE(UART_Type *UART_number, HAL_UART_C2_TCIE_t trans_complete_interrupt_status)
{
    UART_number->C2 |= UART_C2_TCIE(trans_complete_interrupt_status);
}

/**
 * @brief Sets the receiver interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_interrupt_status Status to set for receiver interrupt enable (RIE)
 */
void HAL_UART_C2_RIE(UART_Type *UART_number, HAL_UART_C2_RIE_t receiver_interrupt_status)
{
    UART_number->C2 |= UART_C2_RIE(receiver_interrupt_status);
}

/**
 * @brief Sets the idle line interrupt enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param idle_status Status to set for idle line interrupt enable (ILIE)
 */
void HAL_UART_C2_ILIE(UART_Type *UART_number, HAL_UART_C2_ILIE_t idle_status)
{
    UART_number->C2 |= UART_C2_ILIE(idle_status);
}

/**
 * @brief Sets the transmitter enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param transmitter_status Status to set for transmitter enable (TE)
 */
void HAL_UART_C2_TE(UART_Type *UART_number, HAL_UART_C2_TE_t transmitter_status)
{
    UART_number->C2 |= UART_C2_TE(transmitter_status);
}

/**
 * @brief Sets the receiver enable status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_status Status to set for receiver enable (RE)
 */
void HAL_UART_C2_RE(UART_Type *UART_number, HAL_UART_C2_RE_t receiver_status)
{
    UART_number->C2 |= UART_C2_RE(receiver_status);
}

/**
 * @brief Sets the receiver wakeup control status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param receiver_wakeup_control Status to set for receiver wakeup control (RWU)
 */
void HAL_UART_C2_RWU(UART_Type *UART_number, HAL_UART_C2_RWU_t receiver_wakeup_control)
{
    UART_number->C2 |= UART_C2_RWU(receiver_wakeup_control);
}

/**
 * @brief Sets the send break status in UART control register C2
 *
 * @param UART_number Pointer to the UART peripheral base address
 * @param send_break Status to set for send break (SBK)
 */
void HAL_UART_C2_SBK(UART_Type *UART_number, HAL_UART_C2_SBK_t send_break)
{
    UART_number->C2 |= UART_C2_SBK(send_break);
}
