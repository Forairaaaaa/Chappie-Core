#ifndef _CTP_DRIVER_HPP_
#define _CTP_DRIVER_HPP_

#include "../HARDWARE-PORT/HARDWARE_PORT.h"
#include "Arduino.h"

/* Hardware config */
#define CTP_DEV_ADDR 0x15
#define CTP_INT_PIN     3
/* Software config */
#define CTP_REVERS_XPOS 0
#define CTP_REVERS_YPOS 1
#define CTP_REVERS_XY   0


class CTP : public I2C_PORT {
    private:
        int _x_pos;
        int _y_pos;

        /* CTP init */
        void _init() {
            /* Reset coordinate */
            _reset_coor();

            /* Shut down auto sleep */
            _I2C_write1Byte(0xFE, 0xFF);
            Serial.println("[CTP] auto sleep shut down");

            /* Setup INT PIN */
            // pinMode(CTP_INT_PIN, INPUT);
            // Serial.println("[CTP] set int-pin input");
            // _I2C_write1Byte(0xFA, 0B01000001);
            // _I2C_write1Byte(0xED, 0xC8);
        }

        void _reset_coor() {
            _x_pos = -1;
            _y_pos = -1;
        }

        void _update_coor() {
            // coor_x = _I2C_read12Bit(0x03);
            // coor_y = _I2C_read12Bit(0x05);

            uint8_t buff[4];
            _I2C_readBuff(0x03, 4, buff);
            // _x_pos = ((buff[0]&0x0F)<<8)|buff[1];
            // _y_pos = ((buff[2]&0x0F)<<8)|buff[3];

            #if CTP_REVERS_XY
                _y_pos = ((buff[0]&0x0F)<<8)|buff[1];
                _x_pos = ((buff[2]&0x0F)<<8)|buff[3];
                #if CTP_REVERS_XPOS
                    _x_pos = -(_x_pos ) + 280;
                #endif
                #if CTP_REVERS_YPOS
                    _y_pos = -(_y_pos ) + 240;
                #endif
            #else
                _x_pos = ((buff[0]&0x0F)<<8)|buff[1];
                _y_pos = ((buff[2]&0x0F)<<8)|buff[3];
            #endif
        }


    public:
        /* CTP begin */
        void begin(TwoWire * wire) {
            _I2C_init(wire, CTP_DEV_ADDR);
            /* Hold until init done */
            while (_I2C_checkDevAvl()) {
                Serial.println("[CTP] please touch screen to activate it");
                delay(500);
            }
            Serial.println("[CTP] init successful");
            _init();
        }

        bool is_touched() {
            // return !digitalRead(CTP_INT_PIN);
            return _I2C_read8Bit(0x02) ? true : false;
        }

        void get_touch_pos(int * x_pos, int * y_pos) {
            _update_coor();
            *x_pos = _x_pos;
            *y_pos = _y_pos;
        }

        void print_coordinate() {
            if (is_touched()) {
                _update_coor();
            } else {
                _reset_coor();
            }
            // _update_coor();
            Serial.printf("X:%d Y:%d\r\n", _x_pos, _y_pos);
        }

};


#endif