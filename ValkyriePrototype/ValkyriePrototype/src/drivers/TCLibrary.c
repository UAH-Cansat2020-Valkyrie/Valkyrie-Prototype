/*
 * TCLibrary.c
 *
 * Created: 2/22/2020 2:17:38 PM
 *  Author: natha
 */ 
#include <asf.h>
#include "drivers/TCLibrary.h"



void TCInit(TCdef settings)
{
	pmic_init();
	tc_enable(settings.TC);
	tc_set_overflow_interrupt_callback(settings.TC, settings.FunHandle);
	tc_set_wgm(settings.TC, TC_WG_NORMAL);
	tc_write_period(settings.TC, settings.period);
	tc_set_overflow_interrupt_level(settings.TC, TC_INT_LVL_LO);
	cpu_irq_enable();
	tc_write_clock_source(settings.TC, TC_CLKSEL_DIV1024_gc);
}
void exampleTC(void)//testing the timer counter code by blinking led on microchip at 1Hz
{
	PORTQ.DIR|=0x08;
	TCdef examplestruct={
		.port=&PORTE,
		.TC=&TCE0,
		.period=31250,
		.FunHandle=example_handle
	};
	TCInit(examplestruct);
}
void example_handle(void)
{
	PORTQ.OUT^=0x08; //toggles port q on and off pin 3
}