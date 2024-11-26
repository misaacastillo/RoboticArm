#include <stdio.h>
#include "pico/stdlib.h"
#include "servo_pwm.h"
#include "adc_input.h"
#include "proyect.h"
#include "servo_pwm.h"

int main() {
    stdio_init_all();
    
    // Inicializar los pines de los servos
    servo_init(SERVO_PIN1);
    servo_init(SERVO_PIN2);
    servo_init(SERVO_PIN3);
    servo_init(SERVO_PIN4);
    servo_init(SERVO_PIN5);

    gate_init(GATE_PIN);

    // Inicializar los pines de los potenciómetros
    uint8_t adc_pins[] = {POT_PIN1, POT_PIN2, POT_PIN3, POT_PIN4};
    adc_init_inputs(adc_pins, 4);

    while (true) {
        // Lee y convierte el valor de cada potenciómetro, y ajusta el servo correspondiente
        set_servo_angle(SERVO_PIN1, adc_to_angle(adc_read_value(0)));
        set_servo_angle(SERVO_PIN2, adc_to_angle(adc_read_value(1)));
        set_servo_angle(SERVO_PIN3, adc_to_angle(adc_read_value(2)));
        set_servo_angle(SERVO_PIN4, adc_to_angle(adc_read_value(3)));

        sleep_ms(20); // Pequeño retardo para estabilizar el movimiento del servo

        if (SW_PIN == 0) {

            set_servo_angle(SERVO_PIN4, 270);

    }

    return 0;
}
