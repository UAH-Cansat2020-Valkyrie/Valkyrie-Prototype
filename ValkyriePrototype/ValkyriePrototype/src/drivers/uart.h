/*
 * uart.h
 *
 * Created: 2/22/2020 4:02:12 PM
 *  Author: quaz9
 */ 


#ifndef UART_H_
#define UART_H_
#include "def.h"


//defines a struct to hold all the information about each uart device
typedef struct uart_device{
	PORT_t * Port;
	USART_t * Usart;
	uint8_t rx;
	uint8_t tx;
	uint32_t Baud;
} uart_device;

void openlog_init(uart_device * openLog);
void gps_init(uart_device * gps);
void uart_init(uart_device* P_device);
uint8_t uart_read(uart_device * device);
void uart_write(uart_device * device,uint8_t data);
void UARTWriteArray(uart_device device, char * data);
void UARTReadArray(uart_device device,char * data);

#define UART_TERMINAL_SERIAL			&USARTE0
#define UART_TERMINAL_SERIAL_BAUDRATE	115200
#define UART_TERMINAL_SERIAL_CHAR_LEN	USART_CHSIZE_8BIT_gc
#define UART_TERMINAL_SERIAL_PARITY		USART_PMODE_DISABLED_gc
#define UART_TERMINAL_SERIAL_STOP_BIT	true



#define UART_TERMINAL_TX_PIN			PIN3_bm
#define UART_TERMINAL_PORT				PORTE

void uart_terminal_init(void);
#define UART_H_







#endif /* UART_H_ */