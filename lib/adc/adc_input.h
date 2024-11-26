#ifndef ADC_INPUT_H
#define ADC_INPUT_H

#include <stdint.h>

void adc_init_inputs(uint8_t adc_pins[], int num_pins);  // Inicializa el ADC en múltiples pines
uint16_t adc_read_value(uint8_t channel);                // Lee el valor ADC en un canal específico
float adc_to_angle(uint16_t adc_value);                  // Convierte el valor ADC a ángulo

#endif // ADC_INPUT_H
