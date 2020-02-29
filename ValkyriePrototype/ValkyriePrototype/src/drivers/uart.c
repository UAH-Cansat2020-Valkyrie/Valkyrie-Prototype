/*
 * uart.c
 *
 * Created: 2/22/2020 4:02:43 PM
 *  Author: quaz9
 */ 

#include "uart.h"
void uart_init(uart_device* P_device)

{
	//initializes struct containing all the options for uart communication
	static usart_serial_options_t usart_options = {
		.baudrate = 115200,
		.charlength = USART_CHSIZE_8BIT_gc,
		.paritytype = USART_PMODE_DISABLED_gc,
		.stopbits = true
	};
	usart_options.baudrate=P_device->Baud;//sets the baud rate to baud rate passed in with the struct
	

	//sets the direction of Tx to out and sets it to high. sets the direction of Rx to input
	P_device->Port->DIR|=P_device->tx;
	P_device->Port->OUT|=P_device->tx;
	P_device->Port->DIR&=~P_device->rx;
	
	sysclk_enable_peripheral_clock(P_device->Usart);//enables peripheral clock for uart
	
	usart_serial_init(P_device->Usart, &usart_options);//asf function for initializing uart with the options from the struct we defined
	
	
	
}
void UARTReadArray(uart_device device,char * data)
{
	usart_serial_read_packet(device.Usart,data,sizeof(data));
}
void UARTWriteArray(uart_device device, char * data)//uses usart to write an array of data to the specified device
{
	usart_serial_write_packet(device.Usart,data,sizeof(data));
}

void openlog_init(uart_device * openLog)
{
	openLog->Baud=115200;
	openLog->Port=&PORTC;
	openLog->Usart=&USARTC1;
	openLog->tx=0b10000000;
	openLog->rx=0b01000000;
}

void gps_init(uart_device *gps)
{
	gps->Baud=GPS_BAUD;
	gps->Port=&GPS_PORT;
	gps->Usart=&GPS_USART;
	gps->tx=GPS_SEND_PIN;
	gps->rx=GPS_RECIEVE_PIN;
}


uint8_t uart_read(uart_device * device)
{
	
	while(device->Usart->STATUS>>7);//wait for data to be read
	return device->Usart->DATA;
	
}
void uart_write(uart_device * device,uint8_t data)
{
	while(!(device->Usart->STATUS&0b00100000));//wait for transmition buffer to clear
	device->Usart->DATA=data;
	while((device->Usart->STATUS&0b01000000));//wait for data to be sent
}

void uart_terminal_init()
{
	sysclk_enable_peripheral_clock(UART_TERMINAL_SERIAL);	// enable the USART's clock
	// initialize a configuration struct with USART settings
	static usart_serial_options_t usart_config = {
		.baudrate	=	UART_TERMINAL_SERIAL_BAUDRATE,
		.charlength =	UART_TERMINAL_SERIAL_CHAR_LEN,
		.paritytype =	UART_TERMINAL_SERIAL_PARITY,
		.stopbits	=	UART_TERMINAL_SERIAL_STOP_BIT
	};
	
	UART_TERMINAL_PORT.DIR |= UART_TERMINAL_TX_PIN;	// set the USART transmit pin to output
	
	stdio_serial_init(UART_TERMINAL_SERIAL, &usart_config); // function maps the serial output to printf
	
	
	if(DEBUG) {
		printf("\n\n\n\n\nCansat Valkyrie Initializing...\n");
		printf("UART Initialized\n");
	}
	}
	
	
	
