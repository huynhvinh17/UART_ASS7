#include "../Includes/APP/APP.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

static uint8_t APP_get_CMD(const char *command);
static void led_status_command(void);
static void APP_execute_command(const char *command);

UART_Handle_t uartHandleMember =
    {

        .UARTx = (UART_Type *)UART0,                            /** UART peripheral base address*/
        .port = PORTA,                                          /** Port for UART pins */
        .baudRate = SELECT_BAUD_RATE,                           /** UART baud rate */
        .clockFreq = DEFAULT_MCG,                               /** Clock frequency */
        .oversamplingRatio = OVER_SAMPLING_RATIO,               /** Oversampling ratio */
        .txPin = PTA2_UART0_TX,                                 /** TX pin number */
        .rxPin = PTA1_UART0_RX,                                 /** RX pin number */
        .pin_mux = Pin_ALT2,                                    /** Pin multiplexer setting */
        .trans_interrupt_status = transmitter_enable,           /** Transmitter interrupt status */
        .receiver_interrupt_status = receiver_enable,           /** Receiver interrupt status */
        .hardware_interrupt_status = hardware_interrupt_enable, /** Hardware interrupt status */
        .select_IRQn = UART0_IRQn,                              /** UART interrupt number */
};

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Converts a command string into a command status code
 *
 * @param command The command string to be evaluated
 * @return uint8_t The command status code
 */
static uint8_t APP_get_CMD(const char *command)
{
    int CMD_status;

    /** Compare the command string and set the corresponding status code */

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
        CMD_status = INVALID_CMD; /** Default to invalid command if no match */
    }

    return CMD_status;
}

/**
 * @brief Sends the current status of the LEDs via UART
 */
static void led_status_command(void)
{

    /** if LED LED is OFF */
    if (DRIVER_GPIO_PinStatus(GPIOE, LED_RED_PIN))
    {
        DRIVER_SendData(&uartHandleMember, "\r\nRed LED: OFF\r\n");
    }
    else
    {
        DRIVER_SendData(&uartHandleMember, "\r\nRed LED: ON\r\n");
    }

    /** if green LED is OFF */
    if (DRIVER_GPIO_PinStatus(GPIOD, LED_GREEN_PIN))
    {
        DRIVER_SendData(&uartHandleMember, "Green LED: OFF\r\n");
    }
    else
    {
        DRIVER_SendData(&uartHandleMember, "Green LED: ON\r\n");
    }
}

/**
 * @brief Executes a command based on the command string
 *
 * @param command The command string to be executed
 */
static void APP_execute_command(const char *command)
{
    int get_CMD = 0;
    get_CMD = APP_get_CMD(command); /** Convert command string to command status code */

    switch (get_CMD)
    {
    case LED_STATUS_CMD:
        led_status_command(); /** Display the status of the LEDs */
        break;

    case RED_ON_CMD:

        /** Turn on the red LED */
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 1);
        DRIVER_SendData(&uartHandleMember, "\r\nRed LED turned ON\r\n");
        break;

    case RED_OFF_CMD:

        /** Turn off the red LED */
        DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, 0);
        DRIVER_SendData(&uartHandleMember, "\r\nRed LED turned OFF\r\n");
        break;

    case GREEN_ON_CMD:

        /** Turn on the Green LED */
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 1);
        DRIVER_SendData(&uartHandleMember, "\r\nGreen LED turned ON\r\n");
        break;

    case GREEN_OFF_CMD:

        /** Turn off the Green LED */
        DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, 0);
        DRIVER_SendData(&uartHandleMember, "\r\nGreen LED turned OFF\r\n");
        break;

    case HELP_CMD:
        APP_command_help(); /** Display help information */
        break;

    case INVALID_CMD:
        DRIVER_SendData(&uartHandleMember, "\r\nCommand not available\r\n");
        break;

    default:
        DRIVER_SendData(&uartHandleMember, "\r\nCommand not available\r\n");
        break;
    }
}

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

/**
 * @brief Initializes UART0
 */
void init_UART0(void)
{
    DRIVER_SIM_SCGC4_EnableClock(UART0_clockEnable); /** Enable clock for UART0*/
    DRIVER_SIM_SCGC5_EnableClock(PORTA_clockEnable); /** Enable clock for PORTA */

    DRIVER_SIM_SOPT2_EnableClock(UART0__clockEnable); /** Configure UART0 options */
    DRIVER_INIT_UART(&uartHandleMember);              /**  Initialize UART0 with the provided settings*/
}

/**
 * @brief Sends a help message with available commands via UART
 *
 */
void APP_command_help(void)
{
    DRIVER_SendData(&uartHandleMember, "\r\nCommands:\r\n");
    DRIVER_SendData(&uartHandleMember, "LED STATUS - Get the current status of the LEDs\r\n");
    DRIVER_SendData(&uartHandleMember, "RED ON     - Turn on the Red LED\r\n");
    DRIVER_SendData(&uartHandleMember, "RED OFF    - Turn off the Red LED\r\n");
    DRIVER_SendData(&uartHandleMember, "GREEN ON   - Turn on the Green LED\r\n");
    DRIVER_SendData(&uartHandleMember, "GREEN OFF  - Turn off the Green LED\r\n");
    DRIVER_SendData(&uartHandleMember, "HELP       - Show this help message\r\n");
    DRIVER_SendData(&uartHandleMember, "*Note: Please add '#000' at the end of command line example: RED ON#000\r\n");
    DRIVER_SendData(&uartHandleMember, "*Note: if you already sent a command without '#000', send '#000' to finish previous command\r\n");
}

/**
 * @brief Get a command from UART and executes it
 *
 */
void APP_getCommand(void)
{
    DRIVER_GetCommand(&uartHandleMember, commandBuffer, MAX_STRING_LENGTH); /** Read command from UART */
    APP_execute_command(commandBuffer);                                     /** Execute the command */
}
