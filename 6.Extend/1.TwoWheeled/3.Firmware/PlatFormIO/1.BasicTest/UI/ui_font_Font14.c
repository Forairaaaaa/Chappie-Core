/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:\Users\Forairaaaaa\Desktop\ChappieCore_Lovyan\lvgl\assets\OperatorMono-Medium.otf -o C:\Users\Forairaaaaa\Desktop\ChappieCore_Lovyan\lvgl\assets\ui_font_Font14.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
// #include "lvgl/lvgl.h"
#include "lvgl.h"
#endif

#ifndef UI_FONT_FONT14
#define UI_FONT_FONT14 1
#endif

#if UI_FONT_FONT14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfd, 0x50, 0xf0,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xe2,

    /* U+0023 "#" */
    0x24, 0x48, 0x97, 0xf6, 0xcd, 0x3f, 0xa4, 0x48,
    0x90,

    /* U+0024 "$" */
    0xc, 0x11, 0xfe, 0x4f, 0xe, 0x7, 0xf, 0x37,
    0xf8, 0x83, 0x0,

    /* U+0025 "%" */
    0x63, 0xcb, 0xb7, 0x41, 0x86, 0x9, 0xb7, 0x4f,
    0x1c,

    /* U+0026 "&" */
    0x1c, 0x60, 0x60, 0x63, 0x33, 0x7a, 0xce, 0xce,
    0xcf, 0x72,

    /* U+0027 "'" */
    0xff, 0x80,

    /* U+0028 "(" */
    0xc, 0x63, 0x18, 0x63, 0xc, 0x30, 0xc1, 0x86,
    0xc, 0x18, 0x30,

    /* U+0029 ")" */
    0xc1, 0x83, 0x6, 0x18, 0x30, 0xc3, 0xc, 0x61,
    0x8c, 0x63, 0x0,

    /* U+002A "*" */
    0x8, 0x18, 0xff, 0x3e, 0x3c, 0x6c, 0x4,

    /* U+002B "+" */
    0x30, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0xed, 0x68,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x0, 0x0, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30,
    0x18, 0x18, 0xc, 0xc, 0x4, 0x6, 0x2, 0x3,
    0x0,

    /* U+0030 "0" */
    0x38, 0xdb, 0x1e, 0x3d, 0xfe, 0xf9, 0xe3, 0x6c,
    0x70,

    /* U+0031 "1" */
    0x18, 0x31, 0xe0, 0xc1, 0x83, 0x6, 0xc, 0x19,
    0xfc,

    /* U+0032 "2" */
    0x78, 0x18, 0x18, 0x30, 0x61, 0x86, 0x18, 0x61,
    0xfc,

    /* U+0033 "3" */
    0xfe, 0x18, 0x61, 0x87, 0x7, 0x83, 0x83, 0xd,
    0xf0,

    /* U+0034 "4" */
    0x60, 0x60, 0x60, 0x66, 0x66, 0x46, 0x46, 0xff,
    0x6, 0x6,

    /* U+0035 "5" */
    0x7e, 0xc1, 0x83, 0x87, 0xc1, 0xc1, 0x87, 0xfd,
    0xe0,

    /* U+0036 "6" */
    0x8, 0x39, 0xc3, 0xd, 0x9f, 0xf1, 0xe3, 0xe6,
    0x78,

    /* U+0037 "7" */
    0xfe, 0xc, 0x30, 0x61, 0x83, 0xc, 0x18, 0x60,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1f, 0x37, 0x8f, 0xb3, 0xe3, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x3d, 0x9b, 0x1e, 0x3e, 0xe6, 0xc3, 0xc, 0x70,
    0x40,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xd8, 0x1, 0xb6, 0x90,

    /* U+003C "<" */
    0x0, 0x1c, 0x71, 0x8e, 0x18, 0x18, 0x1c, 0x1c,
    0x18,

    /* U+003D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003E ">" */
    0x0, 0xc1, 0xc0, 0xc0, 0xe0, 0xc3, 0x9c, 0x70,
    0xc0,

    /* U+003F "?" */
    0xf3, 0xf0, 0xc3, 0x18, 0x82, 0x0, 0x1, 0x86,
    0x0,

    /* U+0040 "@" */
    0x1e, 0x23, 0x63, 0xcf, 0xfb, 0xf3, 0xf3, 0xf3,
    0xdf, 0xe0, 0x70, 0x3e, 0x0,

    /* U+0041 "A" */
    0x1c, 0x1c, 0x34, 0x36, 0x36, 0x26, 0x7e, 0x63,
    0x63, 0x43,

    /* U+0042 "B" */
    0x1, 0xf3, 0x36, 0x6c, 0xdf, 0x33, 0xe3, 0xc7,
    0xf8, 0x0,

    /* U+0043 "C" */
    0x1e, 0xc3, 0x6, 0xc, 0x18, 0x38, 0x3f, 0x3e,

    /* U+0044 "D" */
    0xf1, 0xfb, 0x3e, 0x3c, 0x78, 0xf1, 0xe3, 0xcd,
    0xf0, 0x0,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xc3, 0xec, 0x30, 0xc3, 0xf0,

    /* U+0046 "F" */
    0xff, 0x83, 0x6, 0xc, 0x1f, 0xb0, 0x60, 0xc1,
    0x80,

    /* U+0047 "G" */
    0x1c, 0xe1, 0x6, 0xc, 0x78, 0xf1, 0xb3, 0x3e,
    0x0,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x33, 0xf0,

    /* U+004A "J" */
    0x7c, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0x1b, 0xc0,

    /* U+004B "K" */
    0xc7, 0x9b, 0x36, 0x4d, 0x9e, 0x36, 0x66, 0xcd,
    0x8c,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xc7, 0x8f, 0xbf, 0x7e, 0xfd, 0xf5, 0xeb, 0xc7,
    0x8c,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbd, 0x7a, 0xf3, 0xe7, 0xcf,
    0x8c,

    /* U+004F "O" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0050 "P" */
    0xf1, 0xfb, 0x1e, 0x3c, 0x79, 0xbe, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe6,
    0x7e, 0x1c, 0xe, 0x0,

    /* U+0052 "R" */
    0x0, 0xfc, 0xce, 0xc6, 0xc6, 0xcc, 0xf8, 0xcc,
    0xc6, 0xc6,

    /* U+0053 "S" */
    0x3c, 0xc3, 0x7, 0x7, 0x83, 0x81, 0x83, 0xfd,
    0xe0,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc4,
    0xf0,

    /* U+0056 "V" */
    0x43, 0x63, 0x63, 0x62, 0x22, 0x36, 0x36, 0x34,
    0x14, 0x1c,

    /* U+0057 "W" */
    0xc7, 0x8f, 0x1e, 0xbd, 0x7a, 0xfb, 0xf7, 0xec,
    0xd8,

    /* U+0058 "X" */
    0x63, 0x63, 0x36, 0x34, 0x1c, 0x1c, 0x3c, 0x36,
    0x63, 0x63,

    /* U+0059 "Y" */
    0xc3, 0x42, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xc, 0x30, 0xc1, 0x86, 0xc, 0x30, 0xc1,
    0xfc,

    /* U+005B "[" */
    0xff, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xc3, 0xf0,

    /* U+005C "\\" */
    0xc0, 0x20, 0x18, 0x6, 0x3, 0x0, 0xc0, 0x60,
    0x18, 0xc, 0x3, 0x1, 0x80, 0x60, 0x30, 0xc,

    /* U+005D "]" */
    0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xf, 0xf0,

    /* U+005E "^" */
    0x10, 0x71, 0xe3, 0x6c, 0x60, 0x0,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0x43, 0xe,

    /* U+0061 "a" */
    0x78, 0x18, 0x19, 0xf6, 0x78, 0xf1, 0xbf,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xec, 0xf8, 0xf1, 0xe3, 0xc7,
    0x9b, 0xe0,

    /* U+0063 "c" */
    0x1e, 0xc3, 0x6, 0xc, 0x1c, 0x1f, 0x86,

    /* U+0064 "d" */
    0x6, 0xc, 0x19, 0xf6, 0x78, 0xf1, 0xe3, 0xc7,
    0xcd, 0xf8,

    /* U+0065 "e" */
    0x3c, 0x8b, 0x1f, 0xfc, 0x18, 0x18, 0x1e,

    /* U+0066 "f" */
    0xe, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x18, 0x30,
    0x63, 0xf0,

    /* U+0067 "g" */
    0x3e, 0xcf, 0x1e, 0x3c, 0x78, 0xf9, 0xbf, 0x6,
    0x39, 0xe0,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xec, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+0069 "i" */
    0x18, 0x18, 0x0, 0x78, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0xff,

    /* U+006A "j" */
    0xc, 0x30, 0x1f, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xb, 0xc0,

    /* U+006B "k" */
    0x1, 0x83, 0x6, 0xc, 0x79, 0xb6, 0x7c, 0xd9,
    0x9b, 0x18,

    /* U+006C "l" */
    0x78, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x33, 0xf8,

    /* U+006D "m" */
    0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,

    /* U+006E "n" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3,

    /* U+006F "o" */
    0x3c, 0xdb, 0x1e, 0x3c, 0x78, 0xdb, 0x1c,

    /* U+0070 "p" */
    0xfd, 0x9f, 0x1e, 0x3c, 0x78, 0xf3, 0x7c, 0xc1,
    0x80, 0x0,

    /* U+0071 "q" */
    0x3e, 0xcf, 0x1e, 0x3c, 0x78, 0xf9, 0xbf, 0x6,
    0xc,

    /* U+0072 "r" */
    0xf6, 0x78, 0xc1, 0x83, 0x6, 0xc, 0x7e,

    /* U+0073 "s" */
    0x3f, 0x8c, 0x1c, 0x1c, 0x31, 0xfc,

    /* U+0074 "t" */
    0x30, 0x63, 0xf9, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x3c,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xbf,

    /* U+0076 "v" */
    0xc7, 0x8f, 0x12, 0x66, 0xcd, 0xe, 0x1c,

    /* U+0077 "w" */
    0xc7, 0x8f, 0x5e, 0xbe, 0xfd, 0xdb, 0x36,

    /* U+0078 "x" */
    0xc6, 0xd9, 0xb1, 0xc3, 0x8d, 0x93, 0x63,

    /* U+0079 "y" */
    0xc7, 0x8d, 0x13, 0x66, 0xc7, 0xe, 0x8, 0x71,
    0xc0,

    /* U+007A "z" */
    0xfe, 0x18, 0x60, 0xc3, 0xc, 0x30, 0x7f,

    /* U+007B "{" */
    0x1c, 0xe6, 0x18, 0x30, 0xce, 0x38, 0x30, 0xc6,
    0x18, 0x38, 0x30,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xe1, 0xe1, 0x86, 0x30, 0xc1, 0xc7, 0x30, 0xe1,
    0x86, 0x73, 0x0,

    /* U+007E "~" */
    0x31, 0x49, 0x46
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 141, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 141, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 141, .box_w = 6, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 7, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 141, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 27, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 141, .box_w = 2, .box_h = 5, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 48, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 59, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 70, .adv_w = 141, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 77, .adv_w = 141, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 84, .adv_w = 141, .box_w = 3, .box_h = 5, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 86, .adv_w = 141, .box_w = 5, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 87, .adv_w = 141, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 141, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 105, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 141, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 177, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 141, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 141, .box_w = 3, .box_h = 10, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 201, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 141, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 214, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 141, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 245, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 265, .adv_w = 141, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 273, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 283, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 141, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 400, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 438, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 497, .adv_w = 141, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 513, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 524, .adv_w = 141, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 530, .adv_w = 141, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 531, .adv_w = 141, .box_w = 5, .box_h = 3, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 533, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 574, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 594, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 141, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 626, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 646, .adv_w = 141, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 141, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 678, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 687, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 141, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 746, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 764, .adv_w = 141, .box_w = 2, .box_h = 14, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 768, .adv_w = 141, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 779, .adv_w = 141, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font14 = {
#else
lv_font_t ui_font_Font14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT14*/

