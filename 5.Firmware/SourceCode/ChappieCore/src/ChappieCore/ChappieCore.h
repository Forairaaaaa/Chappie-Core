#ifndef _CHAPPIECORE_H_
#define _CHAPPIECORE_H_

#include <Arduino.h>
#include "Wire.h"

/* lvgl */
#include "lvgl.h"
#include "lv_porting/lv_port_disp.h"
#include "lv_porting/lv_port_indev.h"
#include "lv_demos/lv_demos.h"

/* SD card */
#include "FS.h"
#include "SD.h"
#include "SPI.h"

/* Config */
#include "ChappieCore_config.h"


/* ChappieCore class */
class ChappieCore {
    private:

    public:
        /* Basic functions */
        void begin(uint32_t delayTime = 1000);
        void printLOGO();

        /* SD card functions */
        void SD_init();
        bool SD_isExist();
        void SD_ls(const char *path);

        /* lvgl */
        void lvgl_demo();
};

#endif