#include "pico/stdlib.h"
#include <stdio.h>
#include "servo.h"

void set_servo_angle(uint slicenum , uint servopin , float angulo) {

uint16_t calc_angle = SERVO_MIN + (angulo / 270)*(SERVO_MAX - SERVO_MIN);

}
