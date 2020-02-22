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
	void (*FunHandle)(void)
}TCdef;
void TCInit(TCdef settings);
void exampleTC(void);
void example_handle(void);



#endif /* TCLIBRARY_H_ */