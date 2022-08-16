#ifndef _GPIO_PORT_H_
#define _GPIO_PORT_H_

#ifdef ARDUINO
#include "Arduino.h"
#endif

/* GPIO functions config */
#define ENABLE_GPIO_WRITTE 0
#define ENABLE_GPIO_READ   0
#define ENABLE_GPIO_PWM    1

/* PWM config */
#define PWM_FREQ       5000
#define PWM_RESOLUTION 8

/* GPIO port class */
class GPIO_PORT {
    protected:
        #if ENABLE_GPIO_WRITTE | ENABLE_GPIO_READ
        void _GPIO_init(uint8_t pin);
        #if ENABLE_GPIO_WRITTE
        void _GPIO_write(uint8_t pin, uint8_t state);
        #endif
        #if ENABLE_GPIO_READ
        bool _GPIO_read(uint8_t pin);
        #endif
        #endif
        #if ENABLE_GPIO_PWM
        void _GPIO_PWM_init(uint8_t pin, uint8_t channel);
        void _GPIO_PWM_setDuty(uint8_t channel, uint8_t duty);
        #endif
};

#endif
