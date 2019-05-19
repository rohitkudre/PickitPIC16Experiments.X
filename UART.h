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

#define UART_BUFFER_SIZE    128
#define UART_TX TXREG
#define UART_RX RCREG

extern volatile uint8_t uartRX;
extern uint8_t fullWordReceived;

extern char UARTRxBuff[];
void UARTinit(void);
void UARTprocess(void);
uint8_t UARTTx(char *);
void UARTRx(void);
#endif	/* UART_H */

