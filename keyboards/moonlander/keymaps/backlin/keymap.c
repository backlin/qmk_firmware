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

#include "config.h"
#include "magnet.h"
#include "rgbmatrix.h"

bool    sym1down;
uint8_t fn_down;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_SVORAK] = LAYOUT_moonlander(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TX_JOIN,  TX_BREK, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    CB_HASH,  TX_UP,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_PPLS,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    CB_AT,    TX_DOWN, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
        KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,                       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
        KC_LCTL, LFN,     CB_NUM,  KC_LALT, KC_LGUI,          TX_SESS,    KC_MUTE,        SYM1,    SYM2,    MO(_NUM),RFN,     KC_RGUI,
                                            KC_SPC,  TX_PREV, TX_NEXT,    C(KC_PGUP), C(KC_PGDN), KC_ENT
    ),

    [_SYM1] = LAYOUT_moonlander(
        _______, _______,   _______, _______, _______, _______, _______,    _______, _______, CB_ACUT, _______, _______, _______, KC_DEL,
        _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_QUES, CB_DLR,     _______, CB_AMPR, CB_QUOT, BSP_WRD, DEL_WRD, RGT_WRD, CB_CIRC,
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, KC_EXLM, CB_PIPE,    _______, CB_ASTR, CB_DQUO, LFT_WRD, KC_UP,   KC_RGHT, CB_TILD,
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC,                      KC_PPLS, CB_GRV,  KC_LEFT, KC_DOWN, KC_F2,   _______,
        _______, _______,   _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                              _______, _______, _______,    _______, _______, _______
    ),
    [_SYM2] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, BSP_LNE, DEL_LNE, RGT_LNE, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, LFT_LNE, KC_PGUP, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, KC_PGDN, _______, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    [_NUM] = LAYOUT_moonlander(
        _______,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, _______,    _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, KC_PPLS,
        TG(_NUM), _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, _______,    _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, KC_PMNS,
        _______,  _______, _______, KC_LEFT, KC_RGHT, GIT_CMP,                      _______, KC_P1,   KC_P2,   KC_P3,   _______, KC_PAST,
        _______,  _______, _______, _______, _______,          RGB_SEL,    RGB_MOD,          KC_P0,   CB_DOT,  CB_COMM, _______, KC_PSLS,
                                             _______, G(KC_C), G(KC_V),    RGB_VAD, RGB_VAI, _______
    ),

    [_FN] = LAYOUT_moonlander(
        QK_RBT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        EE_CLR,  _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, _______,    KC_MPRV, KC_MPLY, KC_MNXT, MAG_1_3, MAG_2_3, MAG_3_3, G(KC_PPLS),
        QK_BOOT, _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, _______,    KC_VOLD, KC_MUTE, CB_VOLU, MAG_LFT, MAG_CTR, MAG_RGT, G(CB_MINS),
        _______, _______, _______, KC_LEFT, KC_RGHT, GIT_CMP,                      KC_BRID, KC_BRIU, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            MAG_S_L, G(KC_C), G(KC_V),    _______, _______, MAG_S_R
    ),

    [_RGB] = LAYOUT_moonlander(
        0,  1,  2,  3,  4,  5,  0,    0,  6,  7,  8,  9, 10,  0,
        0, 11, 12, 13, 14, 15,  0,    0, 16, 17, 18, 19, 20,  0,
        0, 21, 22, 23, 24, 25,  0,    0, 26, 27, 28, 29, 30,  0,
        0, 31, 32, 33, 34, 35,           36, 37, 38, 39, 40,  0,
        0, 41, 42, 43, 44,      0,    0,     45, 46, 47, 48,  0,
                        0,  0,  0,    0,  0,  0
    )
};

// RGB matrix ------------------------------------------------------------------

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(1);
    // rgb_matrix_set_flags(LED_FLAG_NONE);
    // rgb_matrix_set_color_all(0, 0, 0);
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) return;

    // assign colors if the matrix is on and the current mode
    // is SOLID COLORS => No animations running
    if (rgb_matrix_get_mode() != 1) return;

    uint8_t layer = biton32(layer_state);
    if (layer > 5) return;

    if (layer == 0)
        rgb_matrix_set_color_all(0, 0, 0);
    else
        set_layer_color(layer, layer == _FN && fn_down != BOTH_FN_DOWN);
}


// Tmux ------------------------------------------------------------------------

void tmux_command(uint8_t mods, uint16_t keycode) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL);
    tap_code(KC_B);
    set_mods(mods);
    tap_code(keycode);
    set_mods(original_mods);
}

void process_tmux(uint16_t keycode) {
    switch (keycode) {
        case TX_PREV:
            if (get_mods())
                tmux_command(0, KC_C); // Create window
            else
                tmux_command(0, KC_P); // Previous window
            return;
        case TX_NEXT:
            if (get_mods())
                tmux_command(0, KC_C); // Create window
            else
                tmux_command(0, KC_N); // Next window
            return;
        case TX_SESS: {
            uint8_t original_mods = get_mods();
            if (original_mods) {
                set_mods(MOD_MASK_CTRL);
                tap_code(KC_B);
                set_mods(MOD_MASK_SHIFT);
                tap_code(KC_DOT);
                set_mods(0);
                SEND_STRING("new" SS_TAP(X_ENT)); // New session
                set_mods(original_mods);
            } else
                tmux_command(MOD_MASK_SHIFT, KC_S); // List sessions
            return;
        }
        case TX_UP:
            if (get_mods()) tmux_command(MOD_MASK_SHIFT, KC_2);
            tmux_command(0, KC_UP);
            return;
        case TX_DOWN:
            if (get_mods())
                tmux_command(MOD_MASK_SHIFT, KC_2);
            else
                tmux_command(0, KC_DOWN);
            return;
        case TX_JOIN:
            tmux_command(0, KC_J);
            return;
        case TX_BREK:
            tmux_command(0, KC_B);
            return;
    }
}

// Macros ----------------------------------------------------------------------

void simple_macro(uint16_t modcode, uint16_t keycode) {
    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(keycode);
    } else {
        // This is implemented as exact stroke sequences and not using using
        // set_mod_mask because the latter does not produce the desired result
        register_code(modcode);
        tap_code(keycode);
        unregister_code(modcode);
        tap_code(KC_SPC);
    }
}

void process_macro(uint16_t keycode) {
    switch (keycode) {
        case CB_CIRC:
            simple_macro(KC_LSFT, KC_RBRC);
            return;
        case CB_TILD:
            simple_macro(KC_RALT, KC_RBRC);
            return;
        case CB_GRV:
            simple_macro(KC_LSFT, KC_EQL);
            return;

        case GIT_CMP: {
            uint8_t original_mods = get_mods();
            set_mods(MOD_MASK_CSAG);
            tap_code(KC_G);
            if (!(original_mods & MOD_MASK_SHIFT)) {
                set_mods(0);
                SEND_STRING(SS_DELAY(300) "master" SS_TAP(X_ENT));
            }
            set_mods(original_mods);
            return;
        }
    }
}

// Process input ---------------------------------------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (biton32(layer_state) == _RGB) {
        if (keycode == 1) { // To test conversion from code in layout to uint8_t
            rgb_matrix_mode(1);
        } else if (keycode > 0) {
            rgb_matrix_mode((uint8_t)keycode);
        } else {
            rgb_matrix_mode(1);
        }
        layer_off(_RGB);
        return false;
    }

    switch (keycode) {
        case CB_CIRC ... GIT_CMP:
            if (record->event.pressed) {
                process_macro(keycode);
            }
            return false;
        case MAG_CTR ... MAG_3_3:
            process_magnet(keycode, record->event.pressed);
            return false;
        case TX_SESS ... TX_BREK:
            process_tmux(keycode);
            return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case SYM1:
                sym1down = true;
                layer_on(_SYM1);
                return false;
            case SYM2:
                layer_on(_SYM1);
                layer_on(_SYM2);
                return false;
            case LFN:
                fn_down |= LFN_DOWN;
                layer_on(_FN);
                return false;
            case RFN:
                fn_down |= RFN_DOWN;
                layer_on(_FN);
                return false;

            case QK_RBT:
            case EE_CLR:
            case QK_BOOT:
                if (fn_down != BOTH_FN_DOWN) {
                    return false;
                }
                return true;

            case RGB_SEL:
                rgb_matrix_mode(1);
                if (rgb_matrix_is_enabled())
                    layer_on(_RGB);
                else
                    rgb_matrix_enable();
                return false;
            case RGB_MOD:
                rgb_matrix_enable();
                return true;
        }
    } else {
        switch (keycode) {
            case SYM1:
                sym1down = false;
                if (!layer_state_is(_SYM2)) {
                    layer_off(_SYM1);
                }
                return false;
            case SYM2:
                if (!sym1down) {
                    layer_off(_SYM1);
                }
                layer_off(_SYM2);
                return false;
            case LFN:
                fn_down &= ~LFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                return false;
            case RFN:
                fn_down &= ~RFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                return false;
        }
    }
    return true;
};
