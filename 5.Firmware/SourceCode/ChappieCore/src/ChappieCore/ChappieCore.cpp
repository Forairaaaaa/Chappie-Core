#include "ChappieCore.h"


/**
 * @brief Init Chappie Core
 * 
 * @param delayTime Delay ms before init
 */
void ChappieCore::begin(uint32_t delayTime) {
    /* Hold a second */
    delay(delayTime);

    /* Init serial port */
    Serial.begin(115200);
    printLOGO();
    Serial.println("[ChappieCore] Hi!");
    Serial.printf("[ChappieCore] version: %s\r\n", CHAPPIE_CORE_VERSION);
    Serial.println("[ChappieCore] author: Forairaaaaa");
    Serial.println("[ChappieCore] https://github.com/Forairaaaaa/Chappie-Core");

    /* Init I2C BUS */
    Wire.begin(11, 12);

    /* Init lvgl */
    #if CHAPPIE_CORE_USE_LVGL
    Serial.println("[ChappieCore] init lvgl...");
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    #endif

    /* Init SD card */
    SD_init();
}


/**
 * @brief Init SD card
 * 
 */
void ChappieCore::SD_init() {
    /* Check if SD card exist */
    pinMode(17, INPUT);
    if (digitalRead(17)) {
        Serial.println("[ChappieCore] no SD card dectected");
        return;
    }
    Serial.print("[ChappieCore] SD card dectected: ");

    /* Init SD spi */
    static SPIClass* sd_spi = new SPIClass(FSPI);
    sd_spi->begin(15, 16, 6, 5);
    SD.begin(5, *sd_spi, 40000000);

    /* Get SD card info */
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_MMC)
        Serial.print("MMC");
    else if(cardType == CARD_SD)
        Serial.print("SDSC");
    else if(cardType == CARD_SDHC)
        Serial.print("SDHC");
    else
        Serial.print("-ERROR-");
    Serial.printf(" %dGB\r\n", (SD.cardSize() / 1073741824));

    /* List root dir */
    // SD_ls("/");
}


/**
 * @brief Check if SD card is exist
 * 
 * @return true 
 * @return false 
 */
bool ChappieCore::SD_isExist() {
    return digitalRead(17) ? false : true;
}


/**
 * @brief List path from SD card
 * 
 * @param path e.g. "/memes"
 */
void ChappieCore::SD_ls(const char *path) {
    Serial.printf("[ChappieCore] ls %s\r\n", path);
    File root = SD.open(path);
    File file = root.openNextFile();
    while (file) {
        Serial.printf("-- %s  (%d)\r\n", file.name(), file.size());
        file = root.openNextFile();
    }
    file.close();
    root.close();
}


/**
 * @brief Run lvgl demo
 * 
 */
void ChappieCore::lvgl_demo() {
    lv_demo_widgets();
    // lv_demo_benchmark();
    // lv_demo_music();
}


/**
 * @brief Print logo on serial port
 * 
 */
void ChappieCore::printLOGO() {
    /* LOGO */
    const char ChappieCore_logo[] {
    "\r\n ______  __  __  ______  ______ ______ __  ______\r\n"
    "/\\  ___\\/\\ \\_\\ \\/\\  __ \\/\\  == /\\  == /\\ \\/\\  ___\\\r\n"
    "\\ \\ \\___\\ \\  __ \\ \\  __ \\ \\  _-\\ \\  _-\\ \\ \\ \\  __\\\r\n"
    " \\ \\_____\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\  \\ \\_\\  \\ \\_\\ \\_____\\\r\n"
    "  \\/_____/\\/_/\\/_/\\/_/\\/_/\\/_/   \\/_/   \\/_/\\/_____/\r\n"
    " ______  ______  ______  ______\r\n"
    "/\\  ___\\/\\  __ \\/\\  == \\/\\  ___\\\r\n"
    "\\ \\ \\___\\ \\ \\/\\ \\ \\  __<\\ \\  __\\\r\n"
    " \\ \\_____\\ \\_____\\ \\_\\ \\_\\ \\_____\\\r\n"
    "  \\/_____/\\/_____/\\/_/ /_/\\/_____/\r\n"
    };
    /* Print out */
    Serial.println(ChappieCore_logo);
}

