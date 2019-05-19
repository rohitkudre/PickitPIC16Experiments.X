#include "UART.h"
#include <string.h>

char uartRXBuff[UART_BUFFER_SIZE] = {0};

uint8_t fullWordReceived = 0;
void UARTinit()
{
    TXCKSEL = 1; // TX function on pin RC4
    RXDTSEL = 1; // RX function on pin RC5
    BRG16 = 1; //  BRG16 enabled
    SPBRGL = 0x10; //
    SPBRGH = 0x00; //   Set baud rate of 115200
    
    BRGH = 1; //    Select high baud rate
    TXEN = 1; //    Enable transmitter
    CREN = 1; //    Enable continous receive
    SYNC = 0; //    Asynch mode
    SPEN = 1; //    Serial port enable
}

uint8_t UARTTx(char *sendString)
{
    if (strlen(sendString) > UART_BUFFER_SIZE)
    {
        return 0;   // String too big
    }
    
    while (*sendString)
    {
        while (!TRMT);  //  Wait till TSR is full
        UART_TX = *sendString;
        sendString ++;
    }
    return 1;
}

void UARTRx()
{
    char receivedString[2];
    if (uartRX)
    {
        UARTTx("Received Data: \n");
        receivedString[0] = UART_RX;
        receivedString[1] = '\0';
        UARTTx(receivedString);
    }
}