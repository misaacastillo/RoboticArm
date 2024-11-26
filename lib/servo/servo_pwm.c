#include "servo_pwm.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "pico/stdlib.h"

void servo_init(uint8_t gpio_pin) {
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);                 // Configura el pin como PWM
    uint8_t slice = pwm_gpio_to_slice_num(gpio_pin);            // Obtiene el slice para el pin
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0);                      // Configura el divisor del reloj
    pwm_config_set_wrap(&config,20000);                        // Ajusta la frecuencia a 50 Hz
    pwm_init(slice, &config, true);
    pwm_set_gpio_level(gpio_pin, SERVO_MIN);                    // Posición inicial
}

void set_servo_angle(uint8_t gpio_pin, float angle) {
    uint16_t pulse_width = SERVO_MIN + (angle / 270) * (SERVO_MAX - SERVO_MIN);
    pwm_set_gpio_level(gpio_pin, pulse_width);
}
