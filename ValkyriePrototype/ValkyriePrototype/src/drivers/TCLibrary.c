/*
 * TCLibrary.c
 *
 * Created: 2/22/2020 2:17:38 PM
 *  Author: natha
 */ 
#include <asf.h>
#include "drivers/TCLibrary.h"



void TCInit(TCdef settings)//Initializes a timer counter http://asf.atmel.com/docs/latest/xmegaau/html/xmega_tc_quickstart.html
{
	pmic_init();//init stuff asf does
	tc_enable(settings.TC);//enables the timer counter 
	tc_set_overflow_interrupt_callback(settings.TC, settings.FunHandle);//sets the callback function to the function handle in the struct
	tc_set_wgm(settings.TC, TC_WG_NORMAL);//IDK what this does asf wants it though
	tc_write_period(settings.TC, settings.period);//sets the number that the timer counter counts to before the interupt is triggered
	tc_set_overflow_interrupt_level(settings.TC, TC_INT_LVL_LO);//sets the interrupt level
	cpu_irq_enable();// enables something or other
	tc_write_clock_source(settings.TC, settings.prescale);//sets the prescaler which divides the main clock of 32MG by the value in the settings
}
void TC_period_shift(TCdef settings)
{
	tc_write_period(settings.TC, settings.period);//sets the number that the timer counter counts to before the interupt is triggered
}

void TC_off(TCdef tc)//turns the Timer counter off by setting the interupt level to low
{
	tc_set_overflow_interrupt_level(tc.TC, TC_INT_LVL_OFF);
}
void TC_on(TCdef tc)//turns the timer counter back on
{
	tc_set_overflow_interrupt_level(tc.TC, TC_INT_LVL_LO);
}
void exampleTC(void)//testing the timer counter code by blinking led on microchip at 1Hz
{
	PORTQ.DIR|=0x08;
	TCdef examplestruct={
		.port=&PORTE,
		.TC=&TCE0,
		.period=31250,
		.FunHandle=example_handle,
		.prescale=TC_CLKSEL_DIV1024_gc
	};
	TCInit(examplestruct);
	delay_s(5);
	TC_off(examplestruct);
	delay_s(5);
	TC_on(examplestruct);
	delay_s(5);
	TC_off(examplestruct);
	examplestruct.period=31250/2;
	TC_period_shift(examplestruct);
	delay_s(5);
	TC_on(examplestruct);
	
}
void example_handle(void)
{
	PORTQ.OUT^=0x08; //toggles port q on and off pin 3
}