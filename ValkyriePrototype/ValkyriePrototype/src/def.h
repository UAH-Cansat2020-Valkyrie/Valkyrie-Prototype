/*
 * def.h
 *
 * Created: 2/22/2020 2:07:55 PM
 *  Author: quaz9
 */ 


#ifndef DEF_H_
#define DEF_H_


#include <asf.h>

#include <math.h>
#include "drivers/OpenLog.h"
#include "drivers/ContServ.h"
#include "drivers/m_ms5607.h"
#include "drivers/adc_sensors.h"
#include "drivers/uart.h"
#include "drivers/TCLibrary.h"
#include "drivers/Servo90Driver.h"
#include "drivers/m_gps.h"
// If the preprocessor setting DEBUG is defined in visual studio
//   Set up so this occurs in debug but not release builds
//   used for displaying simple debug output to the console.
// Syntax is a suboptimal, but overloading the ',' operator to perform insertions
//   seemed too complex for this assignment
//
// Use: insertion operator with parens. eg: m_log("text"<<"other text"<< variableName);
#ifdef DEBUG
#define m_log(txt) vprintf("%s",txt);  //replaces m_log with a print statement
#else
#define m_log(txt) {}				//replaces m_log with the void of space
#endif






#endif /* DEF_H_ */