#include "GPIO_PORT.h"


#ifdef ARDUINO
#if ENABLE_GPIO_WRITTE | ENABLE_GPIO_READ
/**
 * @brief GPIO init
 * 
 * @param pin 
 */
inline void GPIO_PORT::_GPIO_init(uint8_t pin) {
    pinMode(pin, OUTPUT);
}

#if ENABLE_GPIO_WRITTE
/**
 * @brief Set GPIO output
 * 
 * @param pin 
 * @param state 
 */
inline void GPIO_PORT::_GPIO_write(uint8_t pin, uint8_t state) {
    digitalWrite(pin, state);
}
#endif
#endif

#if ENABLE_GPIO_PWM
/**
 * @brief GPIO pwm init
 * 
 * @param pin 
 */
void GPIO_PORT::_GPIO_PWM_init(uint8_t pin, uint8_t channel) {
    ledcAttachPin(pin, channel);
    ledcSetup(channel, PWM_FREQ, PWM_RESOLUTION);
    ledcWrite(channel, 0);
}

/**
 * @brief Set GPIO PWM duty
 * 
 * @param duty 
 */
void GPIO_PORT::_GPIO_PWM_setDuty(uint8_t channel, uint8_t duty) {
    ledcWrite(channel, duty);
}

#endif
#endif