#include "adc_input.h"
#include "hardware/adc.h"

void adc_init_inputs(uint8_t adc_pins[], int num_pins) {
    adc_init();
    for (int i = 0; i < num_pins; i++) {
        adc_gpio_init(adc_pins[i]);                        // Configura cada pin como entrada ADC
    }
}

uint16_t adc_read_value(uint8_t channel) {
    adc_select_input(channel);                             // Selecciona el canal ADC
    return adc_read();                                     // Lee el valor del ADC (0 a 4095)
}

float adc_to_angle(uint16_t adc_value) {
    return (adc_value / 4095.0f) * 270.0f;                 // Convierte el valor ADC a un ángulo de 0 a 270 grados
}
