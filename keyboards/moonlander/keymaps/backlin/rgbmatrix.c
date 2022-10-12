// https://knoopx.github.io/qmk-rgb-matrix-configurator/
// https://github.com/ijprest/keyboard-layout-editor/pull/300/files

#include QMK_KEYBOARD_H
#include "config.h"
#include "rgbmatrix.h"

extern rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_SYM1] = {OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF,

               OFF, OFF, OFF, OFF, OFF, OFF, YLW, WHT, ORN, OFF, OFF, PUR, WHT, WHT, OFF, OFF, PUR, YLW, WHT, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF},
    [_SYM2] = {OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF,

               OFF, OFF, OFF, OFF, OFF, OFF, ORN, WHT, ORN, OFF, OFF, BLU, YLW, YLW, OFF, OFF, BLU, ORN, WHT, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF},
    [_NUM]  = {OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, GRN, GRN, OFF, OFF, OFF, GRN, GRN, WHT, OFF, OFF, GRN, GRN, WHT, OFF, OFF, BLU, BLU, YLW, OFF, OFF, OFF, OFF, WHT, WHT, RED,

              OFF, ORN, ORN, ORN, ORN, OFF, OFF, OFF, OFF, OFF, OFF, WHT, WHT, WHT, YLW, OFF, WHT, WHT, WHT, YLW, OFF, WHT, WHT, WHT, WHT, OFF, OFF, OFF, OFF, OFF, OFF, OFF, OFF, GRN, BLU, RED},
    [_FN]   = {YLW, ORN, RED, OFF, OFF, // all OFF unless BOTH_FN_DOWN
             OFF, OFF, OFF, OFF, OFF, OFF, GRN, GRN, OFF, OFF, OFF, GRN, GRN, WHT, OFF, OFF, GRN, GRN, WHT, OFF, OFF, BLU, BLU, YLW, OFF, OFF, OFF, ORN, WHT, WHT, OFF,

             OFF, OFF, OFF, OFF, OFF, OFF, ORN, ORN, OFF, OFF, OFF, ORN, ORN, OFF, OFF, OFF, ORN, ORN, OFF, OFF, OFF, PUR, YLW, WHT, OFF, OFF, PUR, YLW, WHT, OFF, PUR, YLW, ORN, OFF, OFF, OFF},
    [_RGB] =
        {
            OFF, OFF, OFF, OFF, OFF, WHT, YLW, ORN, RED, PUR, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, OFF, OFF, OFF, OFF, OFF, OFF,

            OFF, OFF, OFF, OFF, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, WHT, YLW, ORN, RED, OFF, OFF, OFF, OFF, OFF, OFF, OFF,
        },
};
// clang-format on

void set_layer_color(int layer, bool hide_qmk) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if ((!rgb.r && !rgb.g && !rgb.b) || (i < 3 && hide_qmk)) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}
