/*
 * TCLibrary.h
 *
 * Created: 2/22/2020 2:18:06 PM
 *  Author: natha
 */ 


#ifndef TCLIBRARY_H_
#define TCLIBRARY_H_
typedef struct{
	PORT_t * port;
	TC0_t * TC;
	uint16_t period;
	void (*FunHandle)(void);
	uint16_t prescale;
}TCdef;

void TCInit(TCdef settings);
void exampleTC(void);
void example_handle(void);
void TC_period_shift(TCdef settings);
void TC_on(TCdef tc);
void TC_off(TCdef tc);

#endif /* TCLIBRARY_H_ */