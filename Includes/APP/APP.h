#ifndef _APP_H_
#define _APP_H_

#include "MKL46Z4.h"
#include "stdio.h"
#include "stdint.h"
#include <string.h>
#include "../Includes/DRIVER/DRIVER_SIM.h"
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/DRIVER/DRIVER_GPIO.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "../Includes/DRIVER/DRIVER_ADC.h"
#include "../Includes/DRIVER/DRIVER_Systick.h"
#include "../Includes/DRIVER/DRIVER_Software_timer.h"
#include "../Includes/DRIVER/DRIVER_PIT.h"
#include "../Includes/DRIVER/DRIVER_UART.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LED_GREEN_PIN 5U /** Define pin number for the green LED */
#define LED_RED_PIN 29U  /** Define pin number for the red LED */

#define PTA1_UART0_RX 1U /** Define pin number for UART0 RX (Receive) */
#define PTA2_UART0_TX 2U /** Define pin number for UART0 TX (Transmit) */

#define MAX_STRING_LENGTH 255U   /** Maximum length for command strings */
#define SELECT_BAUD_RATE 115200U /** Baud rate for UART communication */
#define DEFAULT_MCG 20971520U    /** Default MCG (Multiply Clock Generator) frequency */
#define OVER_SAMPLING_RATIO 16U  /** UART oversampling ratio */

#define LED_STATUS_CMD 1U /** Command code for querying LED status */
#define RED_ON_CMD 2U     /** Command code for turning the red LED on */
#define RED_OFF_CMD 3U    /** Command code for turning the red LED off */
#define GREEN_ON_CMD 4U   /** Command code for turning the green LED on */
#define GREEN_OFF_CMD 5U  /** Command code for turning the green LED off */
#define HELP_CMD 6U       /** Command code for displaying help information */
#define INVALID_CMD -1U   /** Command code for invalid commands */

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/** Global buffer to store received commands */
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

/**
 * @brief Initializes UART0
 */
void init_UART0(void);

/**
 * @brief Sends a help message with available commands via UART
 *
 */
void APP_command_help(void);

/**
 * @brief Get a command from UART and executes it
 *
 */
void APP_getCommand(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _APP_H_ */
