#include "../Includes/DRIVER/DRIVER_SIM.h"

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
 * @brief Enables the clock for a specific peripheral  using the SOPT2 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SOPT2_EnableClock(DRIVER_SOPT2_clock_control_t clockEnable)
{
    HAL_SIM_SOPT2_EnableClock(clockEnable); /** Enable clock for specific peripheral  */
}

/**
 * @brief Enables the clock for a specific peripheral  using the SCGC4 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC4_EnableClock(DRIVER_SCGC4_clock_control_t clockEnable)
{
    HAL_SIM_SCGC4_EnableClock(clockEnable); /** Enable clock for specific peripheral  */
}

/**
 * @brief Enables the clock for a specific peripheral port using the SCGC5 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC5_EnableClock(DRIVER_port_SCGC5_clock_control_t clockEnable)
{
    HAL_SIM_SCGC5_EnableClock(clockEnable); /** Enable clock for specific peripheral port */
}

/**
 * @brief Enables the clock for a specific peripheral  using the SCGC6 register.
 *
 * @param clockEnable The clock control configuration for enabling the clock.
 */
void DRIVER_SIM_SCGC6_EnableClock(DRIVER_SCGC6_clock_control_t clockEnable)
{
    HAL_SIM_SCGC6_EnableClock(clockEnable); /** Enable clock for specific peripheral  */
}
