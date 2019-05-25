#include "UART.h"
#include <string.h>
#include <stdio.h>

char uartFifoBuff[UART_BUFFER_SIZE] = {0};
static uint8_t fifoHead;
static uint8_t fifoTail;


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
    
    fifoHead = 0;
    fifoTail = 0;
    uData.currentState = UART_IDLE;
}

void UARTprocess()
{
    uint8_t actionStatus = 0, i = 0;
    char receivedString[32] = {0};
    char *receivePtr;
    switch (uData.currentState)
    {
        case UART_IDLE:
            if (uartRX)
            {
                uData.currentState = UART_PUSH;
            }
            break;
        case UART_PUSH:
//            actionStatus = fifoWrite(UART_RX);
//            if (!actionStatus)
//            {
//                uData.currentState = FIFO_FULL;
//            }
            break;
        case UART_READ:
            receivePtr = fifoRead();
            while (receivePtr)
            {
                receivedString[i] = *receivePtr;
                receivePtr = fifoRead();
                i++;
            }
            UARTTx("Received String: \n");
            UARTTx(receivedString);
            UARTTx("\n");
            if (!checkUartEmpty())
            {
                uData.currentState = UART_READ;
            }
            else
            {
                uData.currentState = UART_IDLE;
            }
            break;
        case FIFO_FULL:
            UARTTx("Fifo Full!! \n");
            break;
        case FIFO_EMPTY:
            UARTTx("Fifo Empty!! \n");
    }
}

uint8_t UARTTx(char *sendString)
{
    while (*sendString)
    {
        while (!TRMT);  //  Wait till TSR is full
        UART_TX = *sendString;
        sendString ++;
    }
    return 1;
}

//void UARTRx()
//{
//    
//    if (uartRX)
//    {
//        UARTTx("Received Data: \n");
//        receivedString[0] = UART_RX;
//        receivedString[1] = '\0';
//        UARTTx(receivedString);
//    }
//}

uint8_t fifoWrite()
{
    char letter = UART_RX;
    if (!checkUartFull())
    {
        if (letter == '\n' || letter == '\r' || letter == '\0')
        {
            letter = '\0';
            uData.currentState = UART_READ;
        }
        uartFifoBuff[fifoHead] = letter;
        fifoHead = (fifoHead + 1) % UART_BUFFER_SIZE;
        return 1;
    } 
    else 
    {
        uData.currentState = FIFO_FULL;
        return 0;
    }
}

char *fifoRead()
{
    uint8_t returnIndex;
    if (checkUartEmpty())
    {
        return NULL;
    }
    else 
    {
        returnIndex = fifoTail;
        fifoTail = (fifoTail + 1) % UART_BUFFER_SIZE;
        return (&uartFifoBuff[returnIndex]);
    }
}

uint8_t checkUartFull()
{
    if ((fifoHead + 1) % UART_BUFFER_SIZE == fifoTail)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

uint8_t checkUartEmpty()
{
    if (fifoHead == fifoTail)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}