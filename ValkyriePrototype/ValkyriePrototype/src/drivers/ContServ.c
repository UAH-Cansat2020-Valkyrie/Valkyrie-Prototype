/*
 * ContServ.c
 *
 * Created: 2/26/2020 6:32:16 PM
 *  Author: natha
 */
#include <asf.h> 
#include "drivers/ContServ.h"


void cont_servo_init(servo_def serv)
{
	(*serv.port).DIR|=serv.pin;
	TCInit(serv.tc);
	Servo_off(serv);
}
void set_speed(servo_def serv, uint8_t speed)//accepts speeds from 0(full speed backwards) to 180(full speed forwards)
{
	serv.tc.period=(uint16_t)(ADDNUM+((float)speed)*MULTNUM);//calculates the necessary period for a given speed
	TC_period_shift(serv.tc);
	Servo_on(serv);
}