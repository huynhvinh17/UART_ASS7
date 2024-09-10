
#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_PIT.h"

void HAL_PIT_clock(HAL_PIT_clock_timer_t status)
{
	PIT->MCR &= ~PIT_MCR_MDIS_MASK;
    PIT->MCR |= PIT_MCR_MDIS(status);
}

void HAL_PIT_LDVAL(HAL_PIT_channel_t channel, uint16_t loadValue)
{
    PIT->CHANNEL[channel].LDVAL = loadValue - 1;
}

void HAL_PIT_timer_control(HAL_PIT_channel_t channel, HAL_PIT_chain_mode_t chain_mode, HAL_PIT_timer_interrupt_t interrupt_status, HAL_PIT_timer_t timer_status)
{
    PIT->CHANNEL[channel].TCTRL &= ~7;
    PIT->CHANNEL[channel].TCTRL |= PIT_TCTRL_CHN(chain_mode);
    PIT->CHANNEL[channel].TCTRL |= PIT_TCTRL_TIE_MASK;
    PIT->CHANNEL[channel].TCTRL |= PIT_TCTRL_TEN_MASK;
}

void HAL_PIT_timer_Enable(HAL_PIT_channel_t channel, HAL_PIT_timer_t timer_status)
{
    PIT->CHANNEL[channel].TCTRL |= PIT_TCTRL_TEN(timer_status);
}

void HAL_PIT_timer_clear_flag(HAL_PIT_channel_t channel)
{
    PIT->CHANNEL[channel].TFLG |= PIT_TFLG_TIF(1);
}

bool HAL_PIT_timer_flag_isSet(HAL_PIT_channel_t channel)
{
    return (PIT->CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK);
}
