#include "MKL46Z4.h"
#include "core_cm0plus.h"
#include <string.h>
#include "../Includes/APP/APP.h"
#define UART0_RX (1 << 1)
#define UART0_TX (1 << 2)

#define MAX_STRING_LENGTH 256
#define BAUD_RATE 115200

/* LED definitions */
#define RED_LED_PIN 29	// PortE pin for Red LED
#define GREEN_LED_PIN 5 // PortD pin for Green LED

/* Function Prototypes */
void init_clk_and_pin_UART0(void);
void init_UART0(void);
void send_bytes(char data);
void send_string(const char *string);
char UART0_GetChar(void);
void get_string(char *buffer, int maxLength);
void process_command(const char *command);

void init_clk_and_pin_UART0(void)
{
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;	 /* Enable clock gate for UART0 */
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;	 /* Enable clock gate for PortA (TX RX) */
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); /* Selects the clock source for UART0 as MCGFLLCLK */

	PORTA->PCR[1] = PORT_PCR_MUX(2); /* Set PTA1 as UART0_RX */
	PORTA->PCR[2] = PORT_PCR_MUX(2); /* Set PTA2 as UART0_TX */
}

void init_UART0(void)
{
	uint32_t baud_SBR = (uint32_t)((20971520) / (BAUD_RATE * 16));
	UART0->BDH = (baud_SBR >> 8) & UART_BDH_SBR_MASK;
	UART0->BDL = baud_SBR & UART_BDL_SBR_MASK;

	UART0->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

void send_bytes(char data)
{
	UART0->D = data;
	while (!(UART0->S1 & UART_S1_TC_MASK))
		;
}

void send_string(const char *string)
{
	while (*string != '\0')
	{
		send_bytes(*string++);
	}
}

char UART0_GetChar()
{
	while (!(UART0->S1 & UART_S1_RDRF_MASK))
		;
	return UART0->D;
}

void get_string(char *buffer, int maxLength)
{
	char receivedChar;
	int i = 0;

	do
	{
		receivedChar = UART0_GetChar();
		buffer[i] = receivedChar;

		if (receivedChar == '\0' || i >= maxLength - 1)
		{
			break;
		}

		i++;
	} while (1);

	buffer[i] = '\0'; // Null-terminate the string
}

void process_command(const char *command)
{
	if (strcmp(command, "LED STATUS") == 0)
	{
		send_string("\r\nRed LED: ");
		if (GPIOE->PDOR & (1 << RED_LED_PIN))
		{
			send_string("OFF\r\n");
		}
		else
		{
			send_string("ON\r\n");
		}

		send_string("Green LED: ");
		if (GPIOD->PDOR & (1 << GREEN_LED_PIN))
		{
			send_string("OFF\r\n");
		}
		else
		{
			send_string("ON\r\n");
		}
	}
	else if (strcmp(command, "RED ON") == 0)
	{
		DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 1);
		send_string("\r\nRed LED turned ON\r\n");
	}
	else if (strcmp(command, "RED OFF") == 0)
	{
		DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 0);
		send_string("\r\nRed LED turned OFF\r\n");
	}
	else if (strcmp(command, "GREEN ON") == 0)
	{
		DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 1);
		send_string("\r\nGreen LED turned ON\r\n");
	}
	else if (strcmp(command, "GREEN OFF") == 0)
	{
		DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 0);
		send_string("\r\nGreen LED turned OFF\r\n");
	}
	else if (strcmp(command, "HELP") == 0)
	{
		send_string("\r\nCommands:\r\n");
		send_string("LED STATUS - Get the current status of the LEDs\r\n");
		send_string("RED ON     - Turn on the Red LED\r\n");
		send_string("RED OFF    - Turn off the Red LED\r\n");
		send_string("GREEN ON   - Turn on the Green LED\r\n");
		send_string("GREEN OFF  - Turn off the Green LED\r\n");
		send_string("HELP       - Show this help message\r\n");
	}
	else
	{
		send_string("\r\nCommand not available\r\n");
	}
}

int main(void)
{
	char commandBuffer[MAX_STRING_LENGTH];

	init_clk_and_pin_UART0();
	init_UART0();
	Init_LED_Green();
	Init_LED_Red();

	send_string("\r\nCommands:\r\n");
	send_string("LED STATUS - Get the current status of the LEDs\r\n");
	send_string("RED ON     - Turn on the Red LED\r\n");
	send_string("RED OFF    - Turn off the Red LED\r\n");
	send_string("GREEN ON   - Turn on the Green LED\r\n");
	send_string("GREEN OFF  - Turn off the Green LED\r\n");
	send_string("HELP       - Show this help message\r\n");
	while (1)
	{
		get_string(commandBuffer, MAX_STRING_LENGTH);
		// send_string(commandBuffer);
		process_command(commandBuffer);
	}

	return 0;
}
