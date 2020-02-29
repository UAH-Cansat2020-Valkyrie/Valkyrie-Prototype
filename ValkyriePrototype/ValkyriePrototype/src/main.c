/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to board_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */




#include "def.h"

ISR(GPS_RECEIVE_INTERRUPT_VECTOR)
{
	//uint8_t c = GPS_USART.DATA;
	
	//printf("%i", c);
	printf("Hell");
	if(current_sentence == SENTENCE_GPGGA)
	{
		//gpgga_buff[gpgga_index] = c;
		
	}
	
	
}


int main (void)
{
	
	//uart_device*gps = NULL;
	board_init();
	sysclk_init();
	uart_terminal_init();
	
	
	pmic_init();
	pmic_set_scheduling(PMIC_SCH_ROUND_ROBIN);
	cpu_irq_enable();
	
	printf("y are u Gay?\n");
	//serv1_init();
	//spi_init_pins();
	//thermistor_init();
	//exampleTC();
	
	//char* buff[80];
	//gps_init(gps);
	//uart_init(gps);
	//UARTWriteArray(*gps, "");
	//UARTWriteArray(*gps, "$PMTK220,1000*2F");
	//UARTWriteArray(*gps, "$PMTK251,57600*2C");
	//UARTWriteArray(*gps, "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29");
	//
	//UARTWriteArray(*gps, "$PMTK161,0*28");
	//UARTReadArray(*gps,buff);
	//printf(buff);
	/* Insert application code here, after the board has been initialized. */
	/* This skeleton code simply sets the LED to the state of the button. */
	//cont_serv1_init();
	//set_speed(continueous_servo1,0);
	PORTA.DIR|=0x08;
	while (1) {
		PORTA.OUT^=0x08;
		delay_ms(1);
		//long pressure = getPressure();
		//UARTWriteArray(*gps, "$PMTK104*37");
		//UARTWriteArray(*gps, "$PMTK161,0*28");
		//int tempura = getTemperature();
		//UARTReadArray(*gps, buff);
		//printf("%s",buff);
		//printf("HELL");
		
	}
}
