#include "gate.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "pico/stdlib.h"



void gate_init(uint8_t GATE_PIN) {
    gpio_set_function(GATE_PIN, GPIO_FUNC_PWM);           
    uint8_t slice = pwm_gpio_to_slice_num(GATE_PIN);            
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 1.25);                   
    pwm_config_set_wrap(&config, WRAP);                        
    pwm_init(slice, &config, true);
    pwm_set_gpio_level(GATE_PIN, MATCH);                    
}
