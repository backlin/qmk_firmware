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

#include "src/backlin.h"

// clang-format off
KEYMAP keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_SVORAK] = LAYOUT_moonlander(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TX_JOIN,    TX_BREK, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    CB_HASH,    TX_UP,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_PPLS,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    CB_AT,      TX_DOWN, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
        KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
        KC_LCTL, LFN,     TT(_NUM),KC_LALT, KC_LGUI,          TX_SESS,    KC_MUTE,          SYM1,    SYM2,    MO(_NUM),RFN,     KC_RGUI,
                                            KC_SPC,  TX_PREV, TX_NEXT,    C(KC_PGUP), C(KC_PGDN), KC_ENT
    ),

    [_SYM1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, CB_ACUT, _______, _______, _______, KC_DEL,
        _______, CB_SLSH, CB_BSLS, CB_LBRC, CB_RBRC, CB_QUES, CB_DLR,     _______, CB_AMPR, CB_QUOT, BSP_WRD, DEL_WRD, RGT_WRD, CB_CIRC,
        _______, CB_LCBR, CB_RCBR, CB_LPRN, CB_RPRN, KC_EXLM, CB_PIPE,    _______, CB_ASTR, CB_DQUO, LFT_WRD, KC_UP,   KC_RGHT, CB_TILD,
        _______, CB_COLN, CB_EQL,  CB_LABK, CB_RABK, KC_PERC,                      KC_PPLS, CB_GRV,  KC_LEFT, KC_DOWN, KC_F2,   _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
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
        _______,  _______, _______, _______, _______, _______, JB_PRVF,    JB_NXTF, _______, _______, _______, _______, _______, _______,
        _______,  _______, JB_SHOW, JB_TO,   JB_CONT, CB_SCRF, _______,    JB_PRVC, _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_PPLS,
        TG(_NUM), _______, JB_OUT,  JB_IN,   JB_STEP, CB_SCRC, _______,    JB_NXTC, _______, KC_P4,   KC_P5,   KC_P6,   KC_PSLS, KC_PMNS,
        _______,  _______, _______, KC_LEFT, KC_RGHT, JB_DIFF,                      _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
        _______,  _______, _______, _______, _______,          RGB_SEL,    RGB_MOD,          KC_P0,   CB_DOT,  CB_COMM, CB_COLN, _______,
                                             _______, G(KC_C), G(KC_V),    RGB_VAD, RGB_VAI, _______
    ),

    [_FN] = LAYOUT_moonlander(
        QK_RBT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        EE_CLR,  _______, JB_SHOW, JB_TO,   JB_CONT, CB_SCRF, _______,    KC_MPRV, KC_MPLY, KC_MNXT, MAG_1_3, MAG_2_3, MAG_3_3, G(KC_PPLS),
        QK_BOOT, _______, JB_OUT,  JB_IN,   JB_STEP, CB_SCRC, _______,    KC_VOLD, KC_MUTE, CB_VOLU, MAG_LFT, MAG_CTR, MAG_RGT, G(CB_MINS),
        _______, _______, _______, KC_LEFT, KC_RGHT, JB_DIFF,                      KC_BRID, KC_BRIU, _______, _______, _______, _______,
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

#define OFF { 0, 0, 0 }
#define WHT { 255, 255, 255 }
#define RED { 245, 0, 0 }
// https://coolors.co/c847ff-ff855c-fee43e-00f5d4-1fb0ff
#define PUR { 130, 0, 255 }
#define ORN { 255, 68, 0 }
#define YLW { 248, 215, 0 }
#define GRN { 0, 245, 40 }
#define BLU { 0, 80, 255 }

LEDMAP ledmap[][DRIVER_LED_TOTAL][3] = {
    [_SYM1] = {
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF,

        OFF, OFF, OFF, OFF, OFF,
        OFF, YLW, WHT, ORN, OFF,
        OFF, PUR, WHT, WHT, OFF,
        OFF, PUR, YLW, WHT, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF
    },

    [_SYM2] = {
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF,

        OFF, OFF, OFF, OFF, OFF,
        OFF, ORN, WHT, ORN, OFF,
        OFF, BLU, YLW, YLW, OFF,
        OFF, BLU, ORN, WHT, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF
    },

    [_NUM] = {
        OFF, OFF, OFF, OFF, OFF,
        OFF, OFF, OFF, OFF, OFF,
        OFF, GRN, GRN, OFF, OFF,
        OFF, GRN, GRN, WHT, OFF,
        OFF, GRN, GRN, WHT, OFF,
        OFF, BLU, BLU, YLW,
        YLW, OFF, OFF,
                  OFF, WHT, WHT,
                            RED,

        OFF, ORN, ORN, OFF, OFF,
        OFF, ORN, ORN, OFF, YLW,
        OFF, WHT, WHT, WHT, YLW,
        OFF, WHT, WHT, WHT, YLW,
        OFF, WHT, WHT, WHT, WHT,
        OFF, OFF, OFF, OFF,
        YLW, YLW, YLW,
                  OFF, GRN, BLU,
                            RED
    },

    [_FN] = {
        YLW, ORN, RED, OFF, OFF, // all OFF unless BOTH_FN_DOWN
        OFF, OFF, OFF, OFF, OFF,
        OFF, GRN, GRN, OFF, OFF,
        OFF, GRN, GRN, WHT, OFF,
        OFF, GRN, GRN, WHT, OFF,
        OFF, BLU, BLU, YLW,
        OFF, OFF, OFF,
                  ORN, WHT, WHT,
                            OFF,

        OFF, OFF, OFF, OFF, OFF,
        OFF, ORN, ORN, OFF, OFF,
        OFF, ORN, ORN, OFF, OFF,
        OFF, ORN, ORN, OFF, OFF,
        OFF, PUR, YLW, WHT, OFF,
        OFF, PUR, YLW, WHT,
        OFF, PUR, YLW,
                  ORN, OFF, OFF,
                            OFF
    },

    [_RGB] = {
        OFF, OFF, OFF, OFF, OFF,
        WHT, YLW, ORN, RED, PUR,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF,

        OFF, OFF, OFF, OFF, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED, OFF,
        WHT, YLW, ORN, RED,
        OFF, OFF, OFF,
                  OFF, OFF, OFF,
                            OFF,
    },
};
