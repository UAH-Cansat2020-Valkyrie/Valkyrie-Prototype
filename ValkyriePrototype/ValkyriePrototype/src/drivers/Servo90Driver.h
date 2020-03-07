/*
 * Servo90Driver.h
 *
 * Created: 2/22/2020 10:33:59 PM
 *  Author: natha
 */ 


#ifndef SERVO90DRIVER_H_
#define SERVO90DRIVER_H_
#include "drivers/TCLibrary.h"

//constants
#define SERVO1_MINUS90_DEGREE_PER 147
#define SERVO_INCREMENT 0.8269
#define SERVO1_90_PORT &PORTA
#define SERVO1_90_PIN 0x01
#define SERVO1_TC (&TCE1)
#define SERVO1_TCPORT (&PORTE)


typedef struct{
	TCdef tc;
	PORT_t * port;
	uint8_t pin;
	}servo_def;
	
//prototypes
void servo_90degree_init(servo_def servo);
void move_servo(uint8_t degree, servo_def serv);
uint16_t s90_degree2period (uint8_t degree);
void serv1_init(void);
void serv1handle(void);
void Servo_off(servo_def serv);
void Servo_on(servo_def serv);
#endif /* SERVO90DRIVER_H_ */