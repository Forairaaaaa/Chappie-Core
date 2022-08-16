#ifndef _I2C_PORT_H_
#define _I2C_PORT_H_

#ifdef ARDUINO
#include <Arduino.h>
#include "Wire.h"
#endif

/* I2C device scan function */
#define ENABLE_I2C_DEV_SCAN 0

/* I2C_PORT base class */
class I2C_PORT {
    private:
        uint8_t _dev_addr;
        #ifdef ARDUINO
        TwoWire * _wire;
        #endif
    protected:
        /* Port interface */
        #ifdef ARDUINO
        void     _I2C_init(TwoWire * wire, uint8_t dev_addr);
        bool     _I2C_checkDevAvl();
        #else
        void     _I2C_init(uint8_t dev_addr);
        void     _I2C_checkDevAvl();
        #endif
        void     _I2C_write1Byte(uint8_t addr, uint8_t data);
        void     _I2C_write16Bit(uint8_t addr, uint8_t data_1, uint8_t data_2);
        uint8_t  _I2C_read8Bit(uint8_t addr);
        uint16_t _I2C_read12Bit(uint8_t addr);
        uint16_t _I2C_read13Bit(uint8_t addr);
        uint16_t _I2C_read16Bit(uint8_t addr);
        uint16_t _I2C_read16Bit_lowFirst(uint8_t addr);
        uint32_t _I2C_read24Bit(uint8_t addr);
        uint32_t _I2C_read32Bit(uint8_t addr);
        void     _I2C_readBuff(uint8_t addr, int size, uint8_t buff[]);
    public:
        int I2C_dev_scan();
};

#endif