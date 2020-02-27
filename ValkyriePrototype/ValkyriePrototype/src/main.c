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
int main (void)
{
	board_init();
	sysclk_init();
	uart_terminal_init();
	
	pmic_init();
	//pmic_set_scheduling(PMIC_SCH_ROUND_ROBIN);
	//cpu_irq_enable();
	
	printf("y are u Gay?\n");
	//serv1_init();
	//spi_init_pins();
	//thermistor_init();
	exampleTC();
	/* Insert application code here, after the board has been initialized. */
	/* This skeleton code simply sets the LED to the state of the button. */
	while (1) {
		//long pressure = getPressure();
		//int tempura = getTemperature();
	}
}
