/*
 * Servo90Driver.h
 *
 * Created: 2/22/2020 10:33:59 PM
 *  Author: natha
 */ 


#ifndef SERVO90DRIVER_H_
#define SERVO90DRIVER_H_
//constants
#define SERVO1_90_DEGREE_PER 30
#define SERVO1_MINUS90_DEGREE_PER 62
#define SERVO_INCREMENT 5.625
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
void servo_90degree_init(uint8_t pos,servo_def servo);
void move_servo(uint8_t degree, servo_def serv);
uint16_t s90_degree2period (uint8_t degree);
void serv1_init();
void serv1handle();
uint16_t myround(float num);
#endif /* SERVO90DRIVER_H_ */