/*
 * ContServ.h
 *
 * Created: 2/26/2020 6:32:55 PM
 *  Author: natha
 */ 


#ifndef CONTSERV_H_
#define CONTSERV_H_
#include "drivers/Servo90Driver.h"
#include "drivers/TCLibrary.h"

#define ADDNUM 148
#define MULTNUM 0.8268733
#define CONT_SERVO1_PIN 0x08
#define CONT_SERVO1_PORT (&PORTA)
#define CONT_SERVO1_TC (&TCC0)
#define CONT_SERVO1_TCPORT (&PORTC)
void cont_servo1_handle(void);
void cont_serv1_init(void);
void set_speed(servo_def serv, uint8_t speed);
void cont_servo1_handle(void);
void cont_servo_init(servo_def serv);
extern servo_def continueous_servo1;
#endif /* CONTSERV_H_ */