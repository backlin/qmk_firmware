// https://knoopx.github.io/qmk-rgb-matrix-configurator/
// https://github.com/ijprest/keyboard-layout-editor/pull/300/files

#ifdef RGB_MATRIX_ENABLE

#    include "rgbmatrix.h"

extern rgb_config_t rgb_matrix_config;

// clang-format on

void set_layer_color(int layer, bool show_qmk) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if ((!rgb.r && !rgb.g && !rgb.b) || (i < 3 && !show_qmk)) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) return;

    // assign colors if the matrix is on and the current mode
    // is SOLID COLORS => No animations running
    if (rgb_matrix_get_mode() != 1) return;

    uint8_t layer = biton32(layer_state);
    if (layer == 0)
        rgb_matrix_set_color_all(0, 0, 0);
    else
        set_layer_color(layer, layer == _FN && (layer_key_state & FN_PRESSED) == FN_PRESSED);
}

#endif
