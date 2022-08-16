// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenDoge;
lv_obj_t * ui_Image1;
lv_obj_t * ui_ScreenYSXB;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Label1;
lv_obj_t * ui_ScreenPID;
lv_obj_t * ui_ChartPID;
lv_obj_t * ui_ButtonPID;
lv_obj_t * ui_SliderP;
lv_obj_t * ui_SliderI;
lv_obj_t * ui_SliderD;
lv_obj_t * ui_LabelP;
lv_obj_t * ui_LabelI;
lv_obj_t * ui_LabelD;
lv_obj_t * ui_LabelAE;
lv_obj_t * ui_LabelAS;
lv_obj_t * ui_LabelERROR;
lv_obj_t * ui_LabelOUTPUT;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_ButtonPID(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        _ui_state_modify(ui_SliderD, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        _ui_state_modify(ui_SliderI, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        _ui_state_modify(ui_SliderP, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        BTN_Checked_CB(e);
    }
    if(event == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        _ui_state_modify(ui_SliderD, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_SliderI, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
        _ui_state_modify(ui_SliderP, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
        BTN_UnChecked_CB(e);
    }
}
static void ui_event_SliderP(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        SliderP_CB(e);
    }
}
static void ui_event_SliderI(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        SliderI_CB(e);
    }
}
static void ui_event_SliderD(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        SliderD_CB(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_ScreenDoge_screen_init(void)
{

    // ui_ScreenDoge

    ui_ScreenDoge = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenDoge, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ScreenDoge, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenDoge, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image1

    ui_Image1 = lv_img_create(ui_ScreenDoge);

    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, 20);

    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

}
void ui_ScreenYSXB_screen_init(void)
{

    // ui_ScreenYSXB

    ui_ScreenYSXB = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenYSXB, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Image3

    ui_Image3 = lv_img_create(ui_ScreenYSXB);
    lv_img_set_src(ui_Image3, &ui_img_1660177607938_png);

    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image3, 0);
    lv_obj_set_y(ui_Image3, -34);

    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Label1

    ui_Label1 = lv_label_create(ui_ScreenYSXB);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, 2);
    lv_obj_set_y(ui_Label1, 99);

    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label1, "Lap... Drink time!!");

    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScreenPID_screen_init(void)
{

    // ui_ScreenPID

    ui_ScreenPID = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenPID, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ChartPID

    ui_ChartPID = lv_chart_create(ui_ScreenPID);

    lv_obj_set_width(ui_ChartPID, 234);
    lv_obj_set_height(ui_ChartPID, 176);

    lv_obj_set_x(ui_ChartPID, 0);
    lv_obj_set_y(ui_ChartPID, -49);

    lv_obj_set_align(ui_ChartPID, LV_ALIGN_CENTER);

    // ui_ButtonPID

    ui_ButtonPID = lv_btn_create(ui_ScreenPID);

    lv_obj_set_width(ui_ButtonPID, 28);
    lv_obj_set_height(ui_ButtonPID, 60);

    lv_obj_set_x(ui_ButtonPID, 101);
    lv_obj_set_y(ui_ButtonPID, 77);

    lv_obj_set_align(ui_ButtonPID, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonPID, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPID, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPID, ui_event_ButtonPID, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPID, lv_color_hex(0xE56C6C), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ButtonPID, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_SliderP

    ui_SliderP = lv_slider_create(ui_ScreenPID);
    lv_slider_set_range(ui_SliderP, 1, 200);
    lv_slider_set_value(ui_SliderP, 123, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SliderP) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SliderP, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_SliderP, 180);
    lv_obj_set_height(ui_SliderP, 10);

    lv_obj_set_x(ui_SliderP, -17);
    lv_obj_set_y(ui_SliderP, 52);

    lv_obj_set_align(ui_SliderP, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_SliderP, ui_event_SliderP, LV_EVENT_ALL, NULL);

    // ui_SliderI

    ui_SliderI = lv_slider_create(ui_ScreenPID);
    lv_slider_set_range(ui_SliderI, 0, 100);
    lv_slider_set_value(ui_SliderI, 20, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SliderI) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SliderI, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_SliderI, 180);
    lv_obj_set_height(ui_SliderI, 10);

    lv_obj_set_x(ui_SliderI, -17);
    lv_obj_set_y(ui_SliderI, 86);

    lv_obj_set_align(ui_SliderI, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_SliderI, ui_event_SliderI, LV_EVENT_ALL, NULL);

    // ui_SliderD

    ui_SliderD = lv_slider_create(ui_ScreenPID);
    lv_slider_set_range(ui_SliderD, 0, 100);
    lv_slider_set_value(ui_SliderD, 35, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SliderD) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SliderD, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_SliderD, 180);
    lv_obj_set_height(ui_SliderD, 10);

    lv_obj_set_x(ui_SliderD, -17);
    lv_obj_set_y(ui_SliderD, 120);

    lv_obj_set_align(ui_SliderD, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_SliderD, ui_event_SliderD, LV_EVENT_ALL, NULL);

    // ui_LabelP

    ui_LabelP = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelP, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelP, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelP, -82);
    lv_obj_set_y(ui_LabelP, 29);

    lv_obj_set_align(ui_LabelP, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelP, "P:123");

    lv_obj_set_style_text_color(ui_LabelP, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelP, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelP, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelI

    ui_LabelI = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelI, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelI, 0);
    lv_obj_set_y(ui_LabelI, 29);

    lv_obj_set_align(ui_LabelI, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelI, "I:2");

    lv_obj_set_style_text_color(ui_LabelI, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelI, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelD

    ui_LabelD = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelD, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelD, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelD, 82);
    lv_obj_set_y(ui_LabelD, 29);

    lv_obj_set_align(ui_LabelD, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelD, "D:0.5");

    lv_obj_set_style_text_color(ui_LabelD, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelD, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelD, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelAE

    ui_LabelAE = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelAE, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelAE, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelAE, -61);
    lv_obj_set_y(ui_LabelAE, -111);

    lv_obj_set_align(ui_LabelAE, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelAE, "Exp: 1.688");

    lv_obj_set_style_text_color(ui_LabelAE, lv_color_hex(0xE14848), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAE, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAE, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelAS

    ui_LabelAS = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelAS, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelAS, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelAS, -61);
    lv_obj_set_y(ui_LabelAS, -126);

    lv_obj_set_align(ui_LabelAS, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelAS, "Sen: 0.000");

    lv_obj_set_scrollbar_mode(ui_LabelAS, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_text_color(ui_LabelAS, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAS, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_align(ui_LabelAS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_LabelERROR

    ui_LabelERROR = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelERROR, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelERROR, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelERROR, 66);
    lv_obj_set_y(ui_LabelERROR, -111);

    lv_obj_set_align(ui_LabelERROR, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelERROR, "Err:-2.333");

    lv_obj_set_style_text_color(ui_LabelERROR, lv_color_hex(0xFFA148), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelERROR, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelERROR, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelERROR, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelOUTPUT

    ui_LabelOUTPUT = lv_label_create(ui_ScreenPID);

    lv_obj_set_width(ui_LabelOUTPUT, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelOUTPUT, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelOUTPUT, 57);
    lv_obj_set_y(ui_LabelOUTPUT, -126);

    lv_obj_set_align(ui_LabelOUTPUT, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelOUTPUT, "Out:2048");

    lv_obj_set_style_text_color(ui_LabelOUTPUT, lv_color_hex(0x53AB5D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOUTPUT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOUTPUT, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOUTPUT, &ui_font_Font14, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenDoge_screen_init();
    ui_ScreenYSXB_screen_init();
    ui_ScreenPID_screen_init();
    lv_disp_load_scr(ui_ScreenDoge);
}

