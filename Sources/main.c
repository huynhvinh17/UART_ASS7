
#include "../Includes/APP/APP.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

int main(void)
{

	Init_LED_Green(); /** Initialize the green LED */
	Init_LED_Red();	  /** Initialize the red LED */
	init_UART0();	  /** Initialize UART0 */

	APP_command_help();				 /** Display help information */
	DRIVER_Callback(APP_getCommand); /** APP_getCommand function to be called */

	while (1)
	{
	}

	return 0;
}
