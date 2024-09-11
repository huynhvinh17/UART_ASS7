#ifndef _DRIVER_PIT_H
#define _DRIVER_PIT_H

#include "../Includes/HAL/HAL_PIT.h"
#include <stdbool.h>
#include <stdint.h>
#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

typedef HAL_PIT_clock_timer_t DRIVER_PIT_clock_timer_t;
typedef HAL_PIT_channel_t DRIVER_PIT_channel_t;
typedef HAL_PIT_chain_mode_t DRIVER_PIT_chain_mode_t;
typedef HAL_PIT_timer_interrupt_t DRIVER_PIT_timer_interrupt_t;
typedef HAL_PIT_timer_t DRIVER_PIT_timer_t;

void DRIVER_PIT_clock(DRIVER_PIT_clock_timer_t status);

void DRIVER_PIT_LDVAL(DRIVER_PIT_channel_t channel, uint16_t loadValue);

void DRIVER_PIT_timer_control(DRIVER_PIT_channel_t channel, DRIVER_PIT_chain_mode_t chain_mode, DRIVER_PIT_timer_interrupt_t interrupt_status, DRIVER_PIT_timer_t timer_status);

void DRIVER_PIT_timer_Enable(DRIVER_PIT_channel_t channel, DRIVER_PIT_timer_t timer_status);

void DRIVER_PIT_timer_clear_flag(DRIVER_PIT_channel_t channel);

bool DRIVER_PIT_timer_flag_isSet(DRIVER_PIT_channel_t channel);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** DRIVER_PIT */