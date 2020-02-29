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


void cont_servo_init(servo_def serv);
void set_speed(servo_def serv, uint8_t speed);

#endif /* CONTSERV_H_ */