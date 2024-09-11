#ifndef _APP_H_
#define _APP_H_

#include "MKL46Z4.h"
#include "../Includes/DRIVER/DRIVER_SIM.h"
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/DRIVER/DRIVER_GPIO.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "../Includes/DRIVER/DRIVER_ADC.h"
#include "../Includes/DRIVER/DRIVER_Systick.h"
#include "../Includes/DRIVER/DRIVER_Software_timer.h"
#include "../Includes/DRIVER/DRIVER_PIT.h"
#include "../Includes/DRIVER/DRIVER_UART.h"
#include "stdio.h"
#include "stdint.h"
#include <string.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LED_GREEN_PIN 5 /** Define pin number for led green */
#define LED_RED_PIN 29  /** Define pin number for led red */

#define PTA1_UART0_RX 1
#define PTA2_UART0_TX 2

#define MAX_STRING_LENGTH 255
#define BAUD_RATE 115200
#define DEFAULT_MCG 20971520
#define OVER_SAMPLING_RATIO 16

/*******************************************************************************
 * Prototype
 ******************************************************************************/

char commandBuffer[MAX_STRING_LENGTH];

/**
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void);

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void);

void init_UART0(void);

void UART0_send_string(const char *string);

void UART0_get_string(char *buffer, uint16_t maxLength);

void UART0_access_command(const char *command);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _APP_H_ */
