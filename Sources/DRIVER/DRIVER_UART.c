#include "../Includes/DRIVER/DRIVER_UART.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/** Function prototypes for sending and receiving characters via UART */
static void DRIVER_UART_SendChar(UART_Handle_t *uartHandle, char data);
static char DRIVER_UART_GetChar(UART_Handle_t *uartHandle);

UART0_callback_t UART0_callback = NULL; /** Callback function for UART0 */

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Sends a single character via UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @param data The character to be sent
 */
static void DRIVER_UART_SendChar(UART_Handle_t *uartHandle, char data)
{
    HAL_UART_sendData(uartHandle->UARTx, data);  /** Send data using the HAL function */
    while (!(HAL_UART_S1_TC(uartHandle->UARTx))) /** Wait until transmission is complete */
    {
    };
}

/**
 * @brief Get a single character from UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @return char The received character
 */
static char DRIVER_UART_GetChar(UART_Handle_t *uartHandle)
{
    /** Wait until data is received */
    while (!(HAL_UART_S1_RDRF(uartHandle->UARTx)))
    {
    };

    return HAL_UART_getData(uartHandle->UARTx); /** Read and return the received data */
}

/**
 * @brief Initializes the UART peripheral
 *
 * @param uartHandle Pointer to the UART handle structure
 */
void DRIVER_INIT_UART(UART_Handle_t *uartHandle)
{
    /** Calculate the UART baud rate setting value */
    uint16_t baud_SBR = (uint16_t)((uartHandle->clockFreq) / (uartHandle->baudRate * uartHandle->oversamplingRatio) + 1);

    DRIVER_PORT_Init(uartHandle->port, uartHandle->rxPin, uartHandle->pin_mux); /** Initialize UART RX pins */
    DRIVER_PORT_Init(uartHandle->port, uartHandle->txPin, uartHandle->pin_mux); /** Initialize UART TX pins */

    HAL_UART_BDH_SBR(uartHandle->UARTx, baud_SBR); /** config SBR by baud rate */
    HAL_UART_BDL_SBR(uartHandle->UARTx, baud_SBR); /** config SBR by baud rate */

    HAL_UART_C2_TE(uartHandle->UARTx, uartHandle->trans_interrupt_status);    /** Configure UART for transmit */
    HAL_UART_C2_RE(uartHandle->UARTx, uartHandle->receiver_interrupt_status); /** Configure UART for receive */

    HAL_UART_C2_RIE(uartHandle->UARTx, uartHandle->hardware_interrupt_status); /** Enable receive  interrupts for UART*/
    HAL_EnableIRQ(uartHandle->select_IRQn);                                    /** Enable UART interrupts */
}

/**
 * @brief Sends a string of characters via UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @param string The string to be sent
 */
void DRIVER_SendData(UART_Handle_t *uartHandle, const char *string)
{
    while (*string != '\0')
    {
        DRIVER_UART_SendChar(uartHandle, *string++);
    }
}

/**
 * @brief Receives a command string from UART
 *
 * @param uartHandle Pointer to the UART handle structure
 * @param buffer Buffer to store the received command string
 * @param maxLength Maximum length of the buffer
 */
void DRIVER_GetCommand(UART_Handle_t *uartHandle, char *buffer, uint16_t maxLength)
{
    char receivedChar;
    uint16_t i = 0;
    bool checkReceived = true;

    do
    {
        receivedChar = DRIVER_UART_GetChar(uartHandle);
        buffer[i] = receivedChar;

        /** Stop receiving if newline character is detected or buffer is full */
        if ((receivedChar == '\0') || (i >= maxLength - 1))
        {
            checkReceived = false;
        }

        i++;
    } while (checkReceived);

    /** Null-terminate the buffer */
    buffer[i] = '\0';
}

/**
 * @brief Sets the UART0 callback function
 *
 * @param callback callback Pointer to the callback function
 */
void DRIVER_Callback(UART0_callback_t callback)
{
    UART0_callback = callback;
}

/**
 * @brief UART0 interrupt handler
 *
 */
void UART0_IRQHandler(void)
{
    if (UART0_callback != NULL)
    {
        UART0_callback();
    }
}
