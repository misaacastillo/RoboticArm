#include <stdio.h>
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "proyect.h"
#include "servo.h"

/**
 * @brief Convierte el valor de 12 bits del ADC en un valor
 * para el level del PWM que controla el servo
 * @param adc valor de 12 bits del ADC
 * @return Valor entre 500 y 2500 para setear el gpio level del PWM
*/
uint16_t adc_to_gpio_level(uint16_t adc){
    return (uint16_t)(adc * 2000 / 4095 + 500);
}

int main(){
    
    gpio_init(7);
    
    gpio_set_dir(7,false);

    adc_init();  
    
    adc_gpio_init(POTPIN0);
    
    adc_gpio_init(POTPIN1);
    
    adc_gpio_init(POTPIN2);
    
    adc_gpio_init(POTPIN3);
    

    gpio_set_function(SERVOPIN0, GPIO_FUNC_PWM);
    
    gpio_set_function(SERVOPIN1, GPIO_FUNC_PWM);
    
    gpio_set_function(SERVOPIN2, GPIO_FUNC_PWM);
    
    gpio_set_function(SERVOPIN3, GPIO_FUNC_PWM);
    
    gpio_set_function(SERVOPIN4, GPIO_FUNC_PWM);

    gpio_set_function(GATEPIN, GPIO_FUNC_PWM);

    const uint8_t slice0= pwm_gpio_to_slice_num(SERVOPIN0);
    
    const uint8_t slice1= pwm_gpio_to_slice_num(SERVOPIN1);
    
    const uint8_t slice2= pwm_gpio_to_slice_num(SERVOPIN2);
    
    const uint8_t slice3= pwm_gpio_to_slice_num(SERVOPIN3);
    
    const uint8_t slice4= pwm_gpio_to_slice_num(SERVOPIN4);

    const uint8_t slice5= pwm_gpio_to_slice_num(GATEPIN);

    pwm_config config= pwm_get_default_config();
    
    pwm_config_set_clkdiv(&config, 125);
    
    pwm_config_set_wrap(&config, 20000);

    pwm_init(slice0, &config, true);
    
    pwm_init(slice1, &config, true);
    
    pwm_init(slice2, &config, true);
    
    pwm_init(slice3, &config, true); 
    
    pwm_init(slice4, &config, true);  


    pwm_config config1= pwm_get_default_config();

    pwm_config_set_clkdiv(&config1, 125);



    
    while(true) {

    
        if (gpio_get(7) == 1){
    
        set_servo_angle(2,SERVOPIN4, 270);
    
        } 
        
        else {
        
        set_servo_angle(2,SERVOPIN4, 0.0);  
                
        }


    adc_select_input(0);
    
    uint16_t adc_value0 = adc_read();
     
     adc_select_input(1);
    
    uint16_t adc_value1 = adc_read();
     
     adc_select_input(2);
    
    uint16_t adc_value2 = adc_read();
     
     adc_select_input(3);
    
    uint16_t adc_value3 = adc_read();
        
    uint16_t level1 = adc_to_gpio_level(adc_value0);
    
    pwm_set_gpio_level(SERVOPIN0, level1);
        
    uint16_t level2 = adc_to_gpio_level(adc_value1);
    
    pwm_set_gpio_level(SERVOPIN1, level2);
        
    uint16_t level3 = adc_to_gpio_level(adc_value2);
    
    pwm_set_gpio_level(SERVOPIN2, level3);
        
    uint16_t level4 = adc_to_gpio_level(adc_value3);
    
    pwm_set_gpio_level(SERVOPIN3, level4);
        
        
    sleep_ms(10); 
    
    }

}

