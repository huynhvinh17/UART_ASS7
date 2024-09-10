

#include "../Includes/DRIVER/DRIVER_PIT.h"

void DRIVER_PIT_clock(DRIVER_PIT_clock_timer_t status)
{
    HAL_PIT_clock(status);
}

void DRIVER_PIT_LDVAL(DRIVER_PIT_channel_t channel, uint16_t loadValue)
{
    HAL_PIT_LDVAL(channel, loadValue);
}

void DRIVER_PIT_timer_control(DRIVER_PIT_channel_t channel, DRIVER_PIT_chain_mode_t chain_mode, DRIVER_PIT_timer_interrupt_t interrupt_status, DRIVER_PIT_timer_t timer_status)
{
    HAL_PIT_timer_control(channel, chain_mode, interrupt_status, timer_status);
}

void DRIVER_PIT_timer_Enable(DRIVER_PIT_channel_t channel, DRIVER_PIT_timer_t timer_status)
{
    HAL_PIT_timer_Enable(channel, timer_status);
}

void DRIVER_PIT_timer_clear_flag(DRIVER_PIT_channel_t channel)
{
    HAL_PIT_timer_clear_flag(channel);
}

bool DRIVER_PIT_timer_flag_isSet(DRIVER_PIT_channel_t channel)
{
    HAL_PIT_timer_flag_isSet(channel);
}
