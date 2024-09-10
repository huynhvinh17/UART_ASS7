/**
 * @file DRIVER_SIM.c
 * @author huynhvinh17@gmail.com
 * @brief Driver for System Integration Module (SIM) to control clock settings.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

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


void DRIVER_SIM_SOPT2_EnableClock(DRIVER_SOPT2_clock_control_t clockEnable)
{
    HAL_SIM_SOPT2_EnableClock(clockEnable); /** Enable clock for specific peripheral port */
}

void DRIVER_SIM_SCGC4_EnableClock(DRIVER_SCGC4_clock_control_t clockEnable)
{
    HAL_SIM_SCGC4_EnableClock(clockEnable); /** Enable clock for specific peripheral port */
}

void DRIVER_SIM_SCGC5_EnableClock(DRIVER_port_SCGC5_clock_control_t clockEnable)
{
    HAL_SIM_SCGC5_EnableClock(clockEnable); /** Enable clock for specific peripheral port */
}

void DRIVER_SIM_SCGC6_EnableClock(DRIVER_SCGC6_clock_control_t clockEnable)
{
    HAL_SIM_SCGC6_EnableClock(clockEnable);
}