#include QMK_KEYBOARD_H

#include "config.h"
#include "magnet.h"

uint8_t magnet_down(uint8_t state, uint16_t keycode) {
    // clang-format off
    switch (keycode) {
        case MAG_CTR: return state |= MAG_CENTER;
        case MAG_LFT: return state |= MAG_LEFT_12;
        case MAG_RGT: return state |= MAG_RIGHT_12;
        case MAG_1_3: return state |= MAG_LEFT_13;
        case MAG_2_3: return state |= MAG_CENTER_13;
        case MAG_3_3: return state |= MAG_RIGHT_13;
    }
    // clang-format on

    return state;
}

void magnet_up(uint8_t state) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL | MOD_MASK_ALT);

    // clang-format off
    switch (state) {
        case MAG_CENTER:       tap_code(KC_SPC);  break;
        case MAG_LEFT_12:      tap_code(KC_LEFT); break;
        case MAG_RIGHT_12:     tap_code(KC_RGHT); break;
        case MAG_LEFT_13:      tap_code(KC_D);    break;
        case MAG_CENTER_13:    tap_code(KC_F);    break;
        case MAG_RIGHT_13:     tap_code(KC_G);    break;

        case MAG_FULL:         tap_code(KC_ENT);  break;

        case MAG_TOP_LEFT:     tap_code(KC_U);    break;
        case MAG_TOP_RIGHT:    tap_code(KC_I);    break;
        case MAG_BOTTOM_LEFT:  tap_code(KC_J);    break;
        case MAG_BOTTOM_RIGHT: tap_code(KC_K);    break;

        case MAG_CENTER_12_1:
        case MAG_CENTER_12_2:  tap_code(KC_LEFT); tap_code(KC_SPC); break;
        case MAG_LEFT_23:      tap_code(KC_E);    break;
        case MAG_RIGHT_23:     tap_code(KC_T);    break;
        case MAG_CENTER_23:    tap_code(KC_E);    tap_code(KC_SPC); break;

        case MAG_TOP:          tap_code(KC_UP);   break;
        case MAG_BOTTOM:       tap_code(KC_DOWN); break;
    }
    // clang-format on

    set_mods(original_mods);
    return;
}

uint8_t magnet_state;

void process_magnet(uint16_t keycode, bool down) {
    if (down) {
        magnet_state = magnet_down(magnet_state, keycode);
    } else {
        magnet_up(magnet_state);
        magnet_state = 0;
    }
}
