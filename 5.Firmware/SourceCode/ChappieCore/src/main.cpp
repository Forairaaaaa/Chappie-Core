#include <Arduino.h>
#include "lvgl.h"
#include "ChappieCore/ChappieCore.h"

ChappieCore Chappie;

void setup() {
    /* Init Chappie Core */
    Chappie.begin();
    Chappie.lvgl_demo();
}

void loop() {
    #if CHAPPIE_CORE_USE_LVGL
    lv_timer_handler();
    delay(5);
    #endif
}

