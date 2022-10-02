/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"

enum layers {
    _SVORAK,
    _NUM,
    _SYM1,
    _SYM2,
    _FN
};

enum custom_keycodes {
    // CLEVER DIACRITIC MARKS:
    // Default: Behaves like macro mark+space.
    // Shift: Behaves like mark alone.
    //
    // This simplifies entering them in terminal and code, at the expense of writing
    // French etc. (which I rarely do).
    CB_CIRC = SAFE_RANGE, // ^
    CB_TILD,              // ~
    CB_GRV,               // `

    GIT_CMP, // GoLand compare with branch (default: master, shifted: user chooses)

    SYM1, // Symbols and arrows
    SYM2, // Symbols and word step arrows
    LFN,
    RFN,

    CB_BOOT,

    MAG_CTR,
    MAG_LFT,
    MAG_RGT,
    MAG_1_3,
    MAG_2_3,
    MAG_3_3,

    RGB_STD,
    RGB_X
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_SVORAK] = LAYOUT_moonlander(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    XXXXXXX,    XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_PPLS,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    XXXXXXX,    XXXXXXX, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
        KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
        KC_LCTL, LFN,     CB_NUM,  KC_LALT, KC_LGUI,          XXXXXXX,    XXXXXXX,          SYM1,    SYM2,    XXXXXXX, RFN,     KC_RGUI,
                                            KC_SPC,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_ENT
    ),

    [_SYM1] = LAYOUT_moonlander(
        _______, _______,   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_PIPE, _______,    _______, CB_ACUT, BSP_WRD, DEL_WRD, KC_DEL,  KC_EXLM, CB_QUES,
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,   _______,    KC_PPLS, CB_GRV,  LFT_WRD, KC_UP,   RGT_WRD, CB_DQUO, CB_QUOT,
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC,                      CB_ASTR, KC_LEFT, KC_DOWN, KC_RGHT, CB_AMPR, CB_HASH,
        _______, _______,   _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, CB_TILD,
                                              _______, _______, _______,    _______, _______, _______
    ),
    [_SYM2] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, BSP_LNE, DEL_LNE, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, LFT_LNE, KC_PGUP, RGT_LNE, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, KC_PGDN, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    [_NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, _______,    _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        _______, _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, _______,    _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,
        _______, _______, _______, KC_LEFT, KC_RGHT, _______,                      _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          KC_P0,   CB_DOT,  CB_COMM, KC_PSLS, _______,
                                            RGB_VAI, RGB_VAD, _______,    _______, RGB_SAD, RGB_SAI
    ),

    [_FN] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, _______,    _______, MAG_1_3, MAG_2_3, MAG_3_3, KC_MPRV, KC_MPLY, KC_MNXT,
        CB_BOOT, _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, _______,    _______, MAG_LFT, MAG_CTR, MAG_RGT, KC_VOLD, KC_MUTE, CB_VOLU,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, KC_BRID, XXXXXXX, KC_BRIU,
        _______, _______, _______, _______, _______,          RGB_X,      RGB_STD, _______, _______, _______, _______, _______,
                                            RGB_VAI, RGB_VAD, RGB_HUD,    RGB_HUI, RGB_SAD, RGB_SAI
    )
};

// Magnet ----------------------------------------------------------------------

void process_magnet(uint8_t state) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL | MOD_MASK_ALT);

    switch (state) {
        // clang-format off
        case MAG_LEFT_12:      tap_code(KC_LEFT); break;
        case MAG_RIGHT_12:     tap_code(KC_RGHT); break;
        case MAG_CENTER:       tap_code(KC_SPC);  break;
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
            // clang-format on
    }

    set_mods(original_mods);
    return;
}

uint8_t magnet_state;

// Process input ---------------------------------------------------------------

bool    sym1down;
uint8_t fn_down;
#define LFN_DOWN 1
#define RFN_DOWN 2

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            // Note: These are implemented as exact stroke sequences and not using using
            // set_mod_mask because the latter does not produce the desired result.
            case CB_CIRC:
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_RBRC);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_RBRC);
                    unregister_code(KC_LSFT);
                    tap_code(KC_SPC);
                }
                break;
            case CB_TILD:
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_RBRC);
                } else {
                    register_code(KC_RALT);
                    tap_code(KC_RBRC);
                    unregister_code(KC_RALT);
                    tap_code(KC_SPC);
                }
                break;
            case CB_GRV:
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_EQL);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_EQL);
                    unregister_code(KC_LSFT);
                    tap_code(KC_SPC);
                }
                break;

            case GIT_CMP: {
                uint8_t original_mods = get_mods();
                set_mods(MOD_MASK_CSAG);
                tap_code(KC_G);
                if (!(original_mods & MOD_MASK_SHIFT)) {
                    set_mods(0);
                    SEND_STRING(SS_DELAY(300) "master" SS_TAP(X_ENT));
                }
                set_mods(original_mods);
                break;
            }

            case SYM1:
                sym1down = true;
                layer_on(_SYM1);
                break;
            case SYM2:
                layer_on(_SYM1);
                layer_on(_SYM2);
                break;
            case LFN:
                fn_down |= LFN_DOWN;
                layer_on(_FN);
                break;
            case RFN:
                fn_down |= RFN_DOWN;
                layer_on(_FN);
                break;
            case CB_BOOT:
                if (fn_down == (LFN_DOWN | RFN_DOWN)) {
                    reset_keyboard();
                }
                return false;

            // clang-format off
            case MAG_LFT: magnet_state |= MAG_LEFT_12;   break;
            case MAG_CTR: magnet_state |= MAG_CENTER;    break;
            case MAG_RGT: magnet_state |= MAG_RIGHT_12;  break;
            case MAG_1_3: magnet_state |= MAG_LEFT_13;   break;
            case MAG_2_3: magnet_state |= MAG_CENTER_13; break;
            case MAG_3_3: magnet_state |= MAG_RIGHT_13;  break;
                // clang-format on
        }
    } else {
        switch (keycode) {
            case SYM1:
                sym1down = false;
                if (!layer_state_is(_SYM2)) {
                    layer_off(_SYM1);
                }
                break;
            case SYM2:
                if (!sym1down) {
                    layer_off(_SYM1);
                }
                layer_off(_SYM2);
                break;
            case LFN:
                fn_down &= ~LFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                break;
            case RFN:
                fn_down &= ~RFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                break;

            case MAG_LFT:
            case MAG_RGT:
            case MAG_CTR:
            case MAG_1_3:
            case MAG_2_3:
            case MAG_3_3:
                process_magnet(magnet_state);
                magnet_state = 0;
                break;
        }
    }
    return true;
};


// RGB Matrix ---------------------------------------------------------------
// https://knoopx.github.io/qmk-rgb-matrix-configurator/
// https://github.com/ijprest/keyboard-layout-editor/pull/300/files

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {34,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {219,255,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {219,255,255}, {34,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {188,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {219,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {34,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {34,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [4] = { {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {112,255,255}, {112,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {34,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {188,255,255}, {34,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {34,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void set_no_color(void) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, 0, 0, 0 );
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) return;

  // assign colors if the matrix is on and the current mode
  // is SOLID COLORS => No animations running
  if (rgblight_get_mode() != 1) return;

  uint8_t layer = biton32(layer_state);
  if (layer > 4) return;

  if (layer == 0) set_no_color();
  else set_layer_color(layer);
}
