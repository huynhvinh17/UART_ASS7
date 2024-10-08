#ifndef _DRIVER_SIM_H_
#define _DRIVER_SIM_H_

#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_SIM.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

typedef HAL_SOPT2_clock_control_t DRIVER_SOPT2_clock_control_t;           /** defined as an alias for the type `HAL_SOPT2_clock_control_t */
typedef HAL_SCGC4_clock_control_t DRIVER_SCGC4_clock_control_t;           /** defined as an alias for the type `HAL_SCGC4_clock_control_t */
typedef HAL_port_SCGC5_clock_control_t DRIVER_port_SCGC5_clock_control_t; /** defined as an alias for the type `HAL_port_SCGC5_clock_control_t */
typedef HAL_SCGC6_clock_control_t DRIVER_SCGC6_clock_control_t;           /** defined as an alias for the type `HAL_SCGC6_clock_control_t */

/**
 * @brief Enables the clock for a specific peripheral  using the SOPT2 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SOPT2_EnableClock(DRIVER_SOPT2_clock_control_t clockEnable);

/**
 * @brief Enables the clock for a specific peripheral  using the SCGC4 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC4_EnableClock(DRIVER_SCGC4_clock_control_t clockEnable);

/**
 * @brief Enables the clock for a specific peripheral port using the SCGC5 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC5_EnableClock(DRIVER_port_SCGC5_clock_control_t clockEnable);

/**
 * @brief Enables the clock for a specific peripheral  using the SCGC6 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC6_EnableClock(DRIVER_SCGC6_clock_control_t clockEnable);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_SIM_H_ */
