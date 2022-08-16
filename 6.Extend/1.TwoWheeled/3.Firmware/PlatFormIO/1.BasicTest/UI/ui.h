// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_ScreenDoge;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_ScreenYSXB;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_ScreenPID;
extern lv_obj_t * ui_ChartPID;
extern lv_obj_t * ui_ButtonPID;
extern lv_obj_t * ui_SliderP;
extern lv_obj_t * ui_SliderI;
extern lv_obj_t * ui_SliderD;
extern lv_obj_t * ui_LabelP;
extern lv_obj_t * ui_LabelI;
extern lv_obj_t * ui_LabelD;
extern lv_obj_t * ui_LabelAE;
extern lv_obj_t * ui_LabelAS;
extern lv_obj_t * ui_LabelERROR;
extern lv_obj_t * ui_LabelOUTPUT;

void BTN_Checked_CB(lv_event_t * e);
void BTN_UnChecked_CB(lv_event_t * e);
void SliderP_CB(lv_event_t * e);
void SliderI_CB(lv_event_t * e);
void SliderD_CB(lv_event_t * e);

LV_IMG_DECLARE(ui_img_1660177607938_png);    // assets\1660177607938.png


LV_FONT_DECLARE(ui_font_Font14);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
