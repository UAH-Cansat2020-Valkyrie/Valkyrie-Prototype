/*
 * Servo90Driver.c
 *
 * Created: 2/22/2020 10:33:03 PM
 *  Author: natha
 */ 
#include <asf.h>
#include "drivers/Servo90Driver.h"
static servo_def serv1, serv2, serv3;

void servo_90degree_init(servo_def servo)//takes the struct with all the servo info and initializes it
{
	(*servo.port).DIR|=servo.pin;
	TCInit((TCdef)servo.tc);
	Servo_off(servo);
}
void move_servo(uint8_t degree, servo_def serv)//moves servo to specified position from 0 to 180
{
	serv.tc.period= s90_degree2period(degree);
	TC_period_shift(serv.tc);
	Servo_on(serv);
}
uint16_t s90_degree2period (uint8_t degree)//converts the a degree position to a number the timer counter can use
{
	uint16_t per=(uint16_t)((((float)degree)*SERVO_INCREMENT+SERVO1_MINUS90_DEGREE_PER));
	return per;
}

void serv1_init()//initializes the first servo
{
	serv1.pin=SERVO1_90_PIN;
	serv1.port=SERVO1_90_PORT;
	TCdef TC1= {
		.TC=SERVO1_TC,
		.port=SERVO1_TCPORT,
		.FunHandle=serv1handle,
		.prescale=TC_CLKSEL_DIV256_gc
	};
	serv1.tc=TC1;
	servo_90degree_init(serv1);
	move_servo(0,serv1);
}
void serv1handle()
{
	printf("hello there\n\s");
	(*serv1.port).OUT^=serv1.pin;
}
void Servo_off(servo_def serv)
{
	TC_off(serv.tc);//turn timer counter off
	(*serv.port).OUT&=~serv.pin;//clear pin
}
void Servo_on(servo_def serv)
{
	TC_on(serv.tc);//re enables the servo by turning it on
}