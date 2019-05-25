/* 
 * File:   UART.h
 * Author: rohit
 *
 * Created on May 19, 2019, 11:25 AM
 */

#ifndef UART_H
#define	UART_H
#include <xc.h>
#include <stdint.h>

typedef enum UARTStates
{
    UART_IDLE = 0,
    UART_PUSH,
    UART_READ,
    FIFO_FULL,
    FIFO_EMPTY
} UARTStates;

typedef struct uartData 
{
    UARTStates currentState;
} uartData;

uartData uData;

#define UART_BUFFER_SIZE    256
#define UART_TX TXREG
#define UART_RX RCREG

extern char uartFifoBuff[UART_BUFFER_SIZE];
extern volatile uint8_t uartRX;
uint8_t fullWordReceived;

extern char UARTRxBuff[];

void UARTinit(void);
void UARTprocess(void);


uint8_t UARTTx(char *);
void UARTRx(void);


uint8_t fifoWrite(void );
char *fifoRead(void );

uint8_t checkUartFull(void );
uint8_t checkUartEmpty(void );
void fifoPurge(void );
#endif	/* UART_H */

