#include "MKL46Z4.h"
#include "core_cm0plus.h"

#include "../Includes/APP/APP.h"

void UART0_IRQHandler(void)
{
	UART0_get_string(commandBuffer, MAX_STRING_LENGTH);
	UART0_access_command(commandBuffer);
}

int main(void)
{

	Init_LED_Green();
	Init_LED_Red();
	init_UART0();
	UART0_command_help();

	while (1)
	{
	}

	return 0;
}
