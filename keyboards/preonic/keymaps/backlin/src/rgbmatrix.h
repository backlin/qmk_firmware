#pragma once
#include "backlin.h"

#define LEDMAP const uint8_t PROGMEM
extern LEDMAP ledmap[][DRIVER_LED_TOTAL][3];

void keyboard_post_init_user(void);
void rgb_matrix_indicators_user(void);
void set_layer_color(int layer, bool show_qmk);
