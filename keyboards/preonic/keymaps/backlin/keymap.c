/* Copyright 2015-2021 Jack Humbert
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

KEYMAP keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// clang-format off
[_SVORAK] = LAYOUT_preonic_2x2u(
  KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
  KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
  KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PPLS,
  TT(_NUM),LFN,     KC_LALT, KC_LGUI, KC_SPC,           KC_ENT,           SYM1,    SYM2,    RFN,     KC_RGUI
),

// TODO: Move !? to the right of left-hand block?
[_SYM1] = LAYOUT_preonic_2x2u(
  CB_QUES, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_HASH, CB_AMPR, CB_QUOT, BSP_WRD, DEL_WRD, KC_DEL,  CB_CIRC,
  KC_EXLM, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,   CB_ASTR, CB_DQUO, LFT_WRD, KC_UP,   RGT_WRD, CB_TILD,
  _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, CB_PIPE, KC_PPLS, CB_GRV,  KC_LEFT, KC_DOWN, KC_RGHT, KC_F2,
  _______, _______,   _______, _______, KC_PERC, CB_DLR,  _______, CB_ACUT, _______, _______, _______, _______,
  _______, _______,   _______, _______, _______,          _______,          _______, _______, _______, _______
),

[_SYM2] = LAYOUT_preonic_2x2u(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, BSP_LNE, DEL_LNE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, LFT_LNE, KC_PGUP, RGT_LNE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______
),

[_NUM] = LAYOUT_preonic_2x2u(
  _______, _______, JB_SHOW, JB_TO,   JB_CONT, CB_SCRF, _______, KC_P7,   KC_P8,   KC_P9,   _______, KC_PPLS,
  TG(_NUM),_______, JB_OUT,  JB_IN,   JB_STEP, CB_SCRC, _______, KC_P4,   KC_P5,   KC_P6,   _______, KC_PMNS,
  _______, _______, _______, KC_LEFT, KC_RGHT, JB_DIFF, _______, KC_P1,   KC_P2,   KC_P3,   _______, KC_PAST,
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, CB_COMM, _______, KC_PSLS,
  _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______
),

[_FN] = LAYOUT_preonic_2x2u(
  _______, _______, JB_SHOW, JB_TO,   JB_CONT, CB_SCRF, KC_MPRV, KC_MPLY, KC_MNXT, MAG_1_3, MAG_2_3, MAG_3_3,
  QK_BOOT, _______, JB_OUT,  JB_IN,   JB_STEP, CB_SCRC, KC_VOLD, KC_MUTE, CB_VOLU, MAG_LFT, MAG_CTR, MAG_RGT,
  _______, _______, _______, KC_LEFT, KC_RGHT, JB_DIFF, XXXXXXX, KC_BRID, KC_BRIU, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, LCAG(KC_LEFT),    LCAG(KC_RGHT),    _______, _______, _______, KC_F12
)

};
