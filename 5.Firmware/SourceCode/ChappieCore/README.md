#### 编译该源码需要注意 src/ChappieCore/replacement/  中的两个替换文件
- lv_conf.h  放在lvgl库文件夹的同一目录：  .pio/libdeps/esp32s3box
- lv_fs_fatfs.c  放在：  .pio/libdeps/esp32s3box/lvgl/src/extra/libs/fsdrv  替换原文件

##### 最近发现esp32s3box这个板子的工程编译会报sdkconfig.h not found错误，如果有arduino工程需求，最好先选用别的esp32s3开发板：

- 将 platformio.ini 里的 board = esp32s3box 改为 board = esp32-s3-devkitc-1 等
- 更改开发板后psram会申请失败，需要将 src/ChappieCore/ChappieCore_config.h 里的 \#define CHAPPIE_CORE_LVGL_USE_PSRAM     1 改成0

