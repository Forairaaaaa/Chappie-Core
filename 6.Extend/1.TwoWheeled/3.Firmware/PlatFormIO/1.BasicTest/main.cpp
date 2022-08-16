#include <Arduino.h>
#include "lvgl.h"
#include "ChappieCore/ChappieCore.h"

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

ChappieCore Chappie;
Adafruit_MPU6050 mpu;

#include "UI/ui.h"


typedef struct {
    int P;
    int I;
    int D;
    float Expect;
    float Error;
    float Sensor;
    float Sensor_filterd;
    int Output;
} pageData_PID;
static pageData_PID pidPageData;

static char disBuff[10];
lv_chart_series_t * lineExp;
lv_chart_series_t * lineSen;
void page_update() {
    /* Update label data */
    sprintf(disBuff, "Sen:%+5.3f", pidPageData.Sensor);
    lv_label_set_text(ui_LabelAS, disBuff);
    sprintf(disBuff, "Exp:%+5.3f", pidPageData.Expect);
    lv_label_set_text(ui_LabelAE, disBuff);
    sprintf(disBuff, "Out:%4d", pidPageData.Output);
    lv_label_set_text(ui_LabelOUTPUT, disBuff);
    sprintf(disBuff, "Err:%+5.3f", pidPageData.Error);
    lv_label_set_text(ui_LabelERROR, disBuff);

    sprintf(disBuff, "P:%03d", pidPageData.P);
    lv_label_set_text(ui_LabelP, disBuff);
    sprintf(disBuff, "I:%03d", pidPageData.I);
    lv_label_set_text(ui_LabelI, disBuff);
    sprintf(disBuff, "D:%03d", pidPageData.D);
    lv_label_set_text(ui_LabelD, disBuff);

    lv_chart_set_next_value(ui_ChartPID, lineExp, (pidPageData.Expect * 1000));
    lv_chart_set_next_value(ui_ChartPID, lineSen, (pidPageData.Sensor * 1000));
}

void data_update(void* param) {
    /* IMU init */
    Wire1.begin(1, 2);
    mpu.begin(MPU6050_I2CADDR_DEFAULT, &Wire1, 0);
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_94_HZ);

    /* Set PID Expect */
    pidPageData.Expect = -1.9f;
    pidPageData.Output = 2048u;

    /* Set chart range */
    lv_chart_set_point_count(ui_ChartPID, 200);
    lv_chart_set_range(ui_ChartPID, LV_CHART_AXIS_PRIMARY_Y, -9000, 9000);
    lv_obj_set_style_size(ui_ChartPID, 0, LV_PART_INDICATOR);
    lv_chart_set_update_mode(ui_ChartPID, LV_CHART_UPDATE_MODE_SHIFT);
    lineExp = lv_chart_add_series(ui_ChartPID, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    lineSen = lv_chart_add_series(ui_ChartPID, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    

    sensors_event_t a, g, temp;
    while (1) {
        /* Get IMU date */
        mpu.getEvent(&a, &g, &temp);

        /* Update datas */
        pidPageData.Sensor = a.acceleration.y;
        pidPageData.Expect = a.acceleration.x;
        pidPageData.Error = pidPageData.Expect - pidPageData.Sensor;
        pidPageData.P = lv_slider_get_value(ui_SliderP);
        pidPageData.I = lv_slider_get_value(ui_SliderI);
        pidPageData.D = lv_slider_get_value(ui_SliderD);
        

        page_update();
        delay(10);
    }
    vTaskDelete(NULL);
}



#define SERVO_PIN_EN    40
#define SERVO_PIN_1     41
#define SERVO_PIN_2     42

static LGFX_ChappieCore tft;
void motor_ctrl(void* param) {

    while (1) {
        for (int i = 0; i < 255; i++) {
            tft.setBrightness(i);
            delay(5);
        }
        delay(4000);
        for (int i = 255; i >= 0; i--) {
            tft.setBrightness(i);
            delay(5);
        }
        delay(4000);
    }


    /* 5V boost enable */
    pinMode(SERVO_PIN_EN, OUTPUT);
    digitalWrite(SERVO_PIN_EN, HIGH);

    /* Servo pwm init */
    ledcAttachPin(SERVO_PIN_1, 1);
    ledcAttachPin(SERVO_PIN_2, 2);

    /* 14bit PWM(0~16384): 0.5ms:409.6  1.5ms:1228.8  2.5ms:2048 */
    ledcSetup(1, 50, 14);
    ledcSetup(2, 50, 14);


    while (1) {
        Serial.println("409.6");
        ledcWrite(1, 1229 - 819);
        ledcWrite(2, 1229 - 819);
        delay(3000);

        Serial.println("1228.8");
        ledcWrite(1, 1229);
        ledcWrite(2, 1229);
        delay(1000);

        Serial.println("2048");
        ledcWrite(1, 1229 + 819);
        ledcWrite(2, 1229 + 819);
        delay(3000);

        Serial.println("1228.8");
        ledcWrite(1, 1229);
        ledcWrite(2, 1229);
        delay(1000);
    }

    vTaskDelete(NULL);
}


void setup() {
    /* Init Chappie Core */
    Chappie.begin();

    // show_pic();
    // Chappie.lvgl_demo();


    /* Load screen */
    ui_init();
    lv_disp_load_scr(ui_ScreenPID);


    xTaskCreate(motor_ctrl, "motor", 4096, NULL, 3, NULL);
    xTaskCreate(data_update, "data", 4096, NULL, 3, NULL);
    delay(1000);
}


void loop() {
    #if CHAPPIE_CORE_USE_LVGL
    lv_timer_handler();
    delay(5);
    #endif
}

