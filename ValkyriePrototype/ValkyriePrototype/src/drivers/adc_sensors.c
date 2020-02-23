/*
 * adc_sensors.c
 *
 * Created: 2/22/2020 3:05:36 PM
 *  Author: quaz9
 */ 

#include "adc_sensors.h"

void adc_init(ADC_t* adc, uint8_t ch_mask, uint8_t pos)
{
	struct adc_config adc_conf;
	struct adc_channel_config adcch_conf;
	adc_read_configuration(adc, &adc_conf);
	adcch_read_configuration(adc, ch_mask, &adcch_conf);
	adc_set_conversion_parameters(&adc_conf, ADC_SIGN_OFF, ADC_RES_12,
	ADC_REF_BANDGAP);
	adc_set_conversion_trigger(&adc_conf, ADC_TRIG_MANUAL, 1, 0);
	adc_set_clock_rate(&adc_conf, 200000UL);
	adcch_set_input(&adcch_conf, pos, ADCCH_NEG_NONE, 1);
	
	adc_set_gain_impedance_mode(&adc_conf, ADC_GAIN_HIGHIMPEDANCE);
	adc_enable_internal_input(&adc_conf, ADC_INT_BANDGAP);


	adc_write_configuration(adc, &adc_conf);
	adcch_write_configuration(adc, ch_mask, &adcch_conf);
	
	
}

float getADCRead(ADC_t* adc, uint8_t ch_mask)
{
	adc_enable(adc);
	
	
	adc_start_conversion(adc, ch_mask);
	adc_wait_for_interrupt_flag(adc, ch_mask);
	uint32_t adcReading = adc_get_result(adc, ch_mask);
	//printf("ADC reading = %u\n", adcReading);
	//float voltage = adcReading/4096.0*2;	//We have to find these numbers by applying differing voltage, printing ADC readings, and solve equation
	//printf("voltage: %f \n", voltage);
	
	adc_disable(adc);
	return adcReading;
	
}





void thermistor_init(void)
{
	adc_init(&THERM_ADC,THERM_ADC_CH,THERM_POS);
	
	printf("Thermistor Initialized.\n");
}


float getTemperature(void)
{
	float adc_val = getADCRead(&THERM_ADC,THERM_ADC_CH);
	//printf("\n%f\n",resistance);
	float vol = adc_val/4096-0.04;
	float resistance = 1000*(3.3/vol-1);
	float temperature = 1.0/(1.0/(25+273.15) + 1.0/3380.0*log(resistance/10000));
	//float temperature = (3380.0*(25+273.15))/(3380.0+(25+273.15)*log(resistance/10000));
	//uint32_t temperature = (adc_val );
	printf("temp: %3.2f\n", (float) temperature-273.15);
	//printf("Voltage: %f\n", resistance);

	return (temperature - 273.15);
	
}