#ifndef _HAL_PIT_H_
#define _HAL_PIT_H_

#include <stdbool.h>
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

typedef enum PIT_clock_timer {
    PIT_clock_enable,
    PIT_clock_disable
} HAL_PIT_clock_timer_t;

typedef enum PIT_channel
{
    channel_0,
    channel_1
} HAL_PIT_channel_t;

typedef enum PIT_chain_mode
{
    notChain,
    chain
} HAL_PIT_chain_mode_t;

typedef enum PIT_timer_interrupt
{
    disable,
    enable
} HAL_PIT_timer_interrupt_t;

typedef HAL_PIT_timer_interrupt_t HAL_PIT_timer_t;

void HAL_PIT_clock(HAL_PIT_clock_timer_t status);

void HAL_PIT_LDVAL(HAL_PIT_channel_t channel, uint16_t loadValue);

void HAL_PIT_timer_control(HAL_PIT_channel_t channel, HAL_PIT_chain_mode_t chain_mode, HAL_PIT_timer_interrupt_t interrupt_status, HAL_PIT_timer_t timer_status);

void HAL_PIT_timer_Enable(HAL_PIT_channel_t channel, HAL_PIT_timer_t timer_status);

void HAL_PIT_timer_clear_flag(HAL_PIT_channel_t channel);

bool HAL_PIT_timer_flag_isSet(HAL_PIT_channel_t channel);

#endif /** _HAL_PIT_H */