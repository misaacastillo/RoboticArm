#ifndef SERVO_PWM_H
#define SERVO_PWM_H

#include <stdint.h>

#define MATCH 1000
#define WRAP 2000

#define SERVO_MIN 500
#define SERVO_MAX 2500


void gate_init(uint8_t gate_pin);                       // Inicializa PWM en un pin
void set_servo_angle(uint8_t gpio_pin, float angle);     // Configura el ángulo del servo

#endif // SERVO_PWM_H
