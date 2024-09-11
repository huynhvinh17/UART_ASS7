#include "MKL46Z4.h"
#include "core_cm0plus.h"
#include <string.h>
#include "../Includes/APP/APP.h"
#include "../Includes/DRIVER/DRIVER_UART.h"

#define PTA1_UART0_RX 1
#define PTA2_UART0_TX 2

#define MAX_STRING_LENGTH 256
#define BAUD_RATE 115200
#define DEFAULT_MCG 20971520
#define OVER_SAMPLING_RATIO 16

#define RED_LED_PIN 29
#define GREEN_LED_PIN 5

char commandBuffer[MAX_STRING_LENGTH];

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
	DRIVER_SIM_SCGC4_EnableClock(UART0_clockEnable);
	DRIVER_SIM_SCGC5_EnableClock(PORTA_clockEnable);
	DRIVER_SIM_SOPT2_EnableClock(UART0__clockEnable);

	DRIVER_PORT_Init(PORTA, PTA1_UART0_RX, Pin_ALT2);
	DRIVER_PORT_Init(PORTA, PTA2_UART0_TX, Pin_ALT2);
	DRIVER_NVIC_EnableIRQ(UART0_IRQn);
}

void init_UART0(void)
{
	uint32_t baud_SBR = (uint32_t)((DEFAULT_MCG) / (BAUD_RATE * OVER_SAMPLING_RATIO));
	DRIVER_UART_BDH(UART0, baud_SBR);
	DRIVER_UART_BDL(UART0, baud_SBR);
	DRIVER_UART_C2(UART0, transmitter_enable, receiver_enable);
	HAL_UART_C2_RIE(UART0, hardware_interrupt_enable);
}

void send_bytes(char data)
{

	UART0->D = data;
	// UART_data(UART0) = data;

	while (!(UART0->S1 & UART_S1_TC_MASK))
		;
	//		while (!(HAL_UART_S1_TC(UART0)))
	//			;
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
	//	while (!(HAL_UART_S1_RDRF(UART0)))
	//		;
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

	buffer[i] = '\0';
}

void access_command(const char *command)
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

void UART0_IRQHandler(void)
{

	get_string(commandBuffer, MAX_STRING_LENGTH);
	access_command(commandBuffer);
}

int main(void)
{

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
	}

	return 0;
}
