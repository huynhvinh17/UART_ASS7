/**
 * @file APP.c
 * @author huynhvinh17@gmail.com
 * @brief Application layer for initializing LEDs and switches, and handling interrupts.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/APP/APP.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LED_STATUS_CMD 1
#define RED_ON_CMD 2
#define RED_OFF_CMD 3
#define GREEN_ON_CMD 4
#define GREEN_OFF_CMD 5
#define HELP_CMD 6
#define INVALID_CMD -1

/*******************************************************************************
 * Prototype
 ******************************************************************************/

static void UART0_SendChar(char data);
static char UART0_GetChar(void);
static uint8_t UART0_get_CMD(const char *command);
static void led_status_command(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTD_clockEnable);          /** Enable the clock for PORTD */
    DRIVER_PORT_Init(PORTD, LED_GREEN_PIN, Pin_GPIO);         /** Initialize PORTD for GPIO functionaliy */
    DRIVER_GPIO_Init(GPIOD, LED_GREEN_PIN, configPinOutput);  /** Set the green LED pin as an output*/
    DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinLow); /** Set the green LED pin to low (led off) */
}

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTE_clockEnable);        /** Enable the clock for PORTE */
    DRIVER_PORT_Init(PORTE, LED_RED_PIN, Pin_GPIO);         /** Initialize PORTE for GPIO functionality */
    DRIVER_GPIO_Init(GPIOE, LED_RED_PIN, configPinOutput);  /** Set the red LED pin as an output */
    DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinLow); /** Set the red LED pin to low (LED off) */
}

void init_UART0(void)
{
    DRIVER_SIM_SCGC4_EnableClock(UART0_clockEnable);
    DRIVER_SIM_SCGC5_EnableClock(PORTA_clockEnable);
    DRIVER_SIM_SOPT2_EnableClock(UART0__clockEnable);

    DRIVER_PORT_Init(PORTA, PTA1_UART0_RX, Pin_ALT2);
    DRIVER_PORT_Init(PORTA, PTA2_UART0_TX, Pin_ALT2);
    DRIVER_NVIC_EnableIRQ(UART0_IRQn);

    uint32_t baud_SBR = (uint32_t)((DEFAULT_MCG) / (BAUD_RATE * OVER_SAMPLING_RATIO));
    DRIVER_UART_BDH(UART0, baud_SBR);
    DRIVER_UART_BDL(UART0, baud_SBR);
    DRIVER_UART_C2(UART0, transmitter_enable, receiver_enable);
    DRIVER_UART_C2_interruptStatus(UART0, hardware_interrupt_enable);
}

static void UART0_SendChar(char data)
{
    HAL_UART_data_assign(UART0, data);

    while (!(HAL_UART_S1_TC(UART0)))
        ;
}

static char UART0_GetChar(void)
{
    while (!(HAL_UART_S1_RDRF(UART0)))
        ;
    return HAL_UART_data(UART0);
}

static uint8_t UART0_get_CMD(const char *command)
{
    uint8_t CMD_status;

    if (0 == strcmp(command, "LED STATUS"))
    {
        CMD_status = LED_STATUS_CMD;
    }
    else if (0 == strcmp(command, "RED ON"))
    {
        CMD_status = RED_ON_CMD;
    }
    else if (0 == strcmp(command, "RED OFF"))
    {
        CMD_status = RED_OFF_CMD;
    }
    else if (0 == strcmp(command, "GREEN ON"))
    {
        CMD_status = GREEN_ON_CMD;
    }
    else if (0 == strcmp(command, "GREEN OFF"))
    {
        CMD_status = GREEN_OFF_CMD;
    }
    else if (0 == strcmp(command, "HELP"))
    {
        CMD_status = HELP_CMD;
    }
    else
    {
        CMD_status = INVALID_CMD;
    }

    return CMD_status;
}

static void led_status_command(void)
{
    UART0_send_string("\r\nRed LED: ");
    if (DRIVER_GPIO_PinStatus(GPIOE, LED_RED_PIN))
    {
        UART0_send_string("OFF\r\n");
    }
    else
    {
        UART0_send_string("ON\r\n");
    }

    UART0_send_string("Green LED: ");
    if (DRIVER_GPIO_PinStatus(GPIOD, LED_GREEN_PIN))
    {
        UART0_send_string("OFF\r\n");
    }
    else
    {
        UART0_send_string("ON\r\n");
    }
}

void UART0_command_help(void)
{
    UART0_send_string("\r\nCommands:\r\n");
    UART0_send_string("LED STATUS - Get the current status of the LEDs\r\n");
    UART0_send_string("RED ON     - Turn on the Red LED\r\n");
    UART0_send_string("RED OFF    - Turn off the Red LED\r\n");
    UART0_send_string("GREEN ON   - Turn on the Green LED\r\n");
    UART0_send_string("GREEN OFF  - Turn off the Green LED\r\n");
    UART0_send_string("HELP       - Show this help message\r\n");
}

void UART0_send_string(const char *string)
{
    while (*string != '\0')
    {
        UART0_SendChar(*string++);
    }
}

void UART0_get_string(char *buffer, uint16_t maxLength)
{
    char receivedChar;
    int i = 0;
    bool checkReceived = true;
    do
    {
        receivedChar = UART0_GetChar();
        buffer[i] = receivedChar;

        if ((receivedChar == '\0') || (i >= maxLength - 1))
        {
            checkReceived = false;
        }

        i++;
    } while (checkReceived);

    buffer[i] = '\0';
}

void UART0_access_command(const char *command)
{
    uint8_t get_CMD = 0;
    get_CMD = UART0_get_CMD(command);

    switch (get_CMD)
    {
    case LED_STATUS_CMD:
        led_status_command();
        break;
    case RED_ON_CMD:
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 1);
        UART0_send_string("\r\nRed LED turned ON\r\n");
        break;
    case RED_OFF_CMD:
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 0);
        UART0_send_string("\r\nRed LED turned OFF\r\n");
        break;
    case GREEN_ON_CMD:
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 1);
        UART0_send_string("\r\nGreen LED turned ON\r\n");
        break;
    case GREEN_OFF_CMD:
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 0);
        UART0_send_string("\r\nGreen LED turned OFF\r\n");
        break;
    case HELP_CMD:
        UART0_command_help();
        break;
    case INVALID_CMD:
        UART0_send_string("\r\nCommand not available\r\n");
        break;
    default:
        UART0_send_string("\r\nCommand not available\r\n");
        break;
    }
}

/* void UART0_access_command(const char *command)
{
    if (strcmp(command, "LEDSTATUS") == 0)
    {
        UART0_send_string("\r\nRed LED: ");
        if (DRIVER_GPIO_PinStatus(GPIOE, LED_RED_PIN))
        {
            UART0_send_string("OFF\r\n");
        }
        else
        {
            UART0_send_string("ON\r\n");
        }

        UART0_send_string("Green LED: ");
        if (DRIVER_GPIO_PinStatus(GPIOD, LED_GREEN_PIN))
        {
            UART0_send_string("OFF\r\n");
        }
        else
        {
            UART0_send_string("ON\r\n");
        }
    }
    else if (strcmp(command, "RED ON") == 0)
    {
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 1);
        UART0_send_string("\r\nRed LED turned ON\r\n");
    }
    else if (strcmp(command, "RED OFF") == 0)
    {
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 0);
        UART0_send_string("\r\nRed LED turned OFF\r\n");
    }
    else if (strcmp(command, "GREEN ON") == 0)
    {
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 1);
        UART0_send_string("\r\nGreen LED turned ON\r\n");
    }
    else if (strcmp(command, "GREEN OFF") == 0)
    {
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 0);
        UART0_send_string("\r\nGreen LED turned OFF\r\n");
    }
    else if (strcmp(command, "HELP") == 0)
    {
        UART0_command_help();
    }
    else
    {
        UART0_send_string("\r\nCommand not available\r\n");
    }
}
 */
