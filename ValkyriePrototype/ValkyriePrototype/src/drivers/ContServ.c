/*
 * ContServ.c
 *
 * Created: 2/26/2020 6:32:16 PM
 *  Author: natha
 */
#include <asf.h> 
#include "drivers/ContServ.h"
servo_def continueous_servo1;

void cont_servo_init(servo_def serv)//initializes a continuous rotation servo
{
	(*serv.port).DIR|=serv.pin;
	TCInit(serv.tc);
	Servo_off(serv);
}
void set_speed(servo_def serv, uint8_t speed)//accepts speeds from 0(full speed backwards) to 180(full speed forwards)
{
	//serv.tc.period=(uint16_t)(ADDNUM+((float)speed)*MULTNUM);//calculates the necessary period for a given speed
	serv.tc.period=ADDNUM;
	TC_period_shift(serv.tc);
	Servo_on(serv);
}
void cont_serv1_init()
{
		continueous_servo1.pin=CONT_SERVO1_PIN;
		continueous_servo1.port=CONT_SERVO1_PORT;
		TCdef MYTC= {
			.TC=CONT_SERVO1_TC,
			.port=CONT_SERVO1_TCPORT,
			.FunHandle=cont_servo1_handle,
			.prescale=TC_CLKSEL_DIV256_gc
		};
		continueous_servo1.tc=MYTC;
		cont_servo_init(continueous_servo1);
}
void cont_servo1_handle()
{
	(*continueous_servo1.port).OUT^=continueous_servo1.pin;
	printf("you are gay\n");
}