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

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_SVORAK] = LAYOUT_preonic_grid(
  KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,   KC_Y,    KC_F,    KC_G,   KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,    KC_D,    KC_H,   KC_T,    KC_N,    KC_S,    CB_MINS,
  KC_LSFT, KC_.:,   KC_Q,    KC_J,    KC_K,   KC_X,    KC_B,    KC_M,   KC_W,    KC_V,    KC_Z,    CB_COMM,
  XXXXXXX, XXXXXXX, CB_TABP, CB_TABN, CB_AT,  CB_HASH, CB_PIPE, CB_DLR, KC_PGDN, KC_PGUP, CB_PLUS, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, CB_LPRM, KC_SPC, KC_SPC,  KC_ENT,  KC_ENT, SYMBOLS, NUMBERS, XXXXXXX, XXXXXXX
),

[_SYMBOLS] = LAYOUT_preonic_grid(
  _______, CB_SLSH, CB_BSLS, CB_LBRC, CB_RBRC, CB_QUES,    CB_AMPR, CB_QUOT, BSP_WRD, XXXXXXX, DEL_WRD, KC_DEL,
  _______, CB_LCBR, CB_RCBR, CB_LPRN, CB_RPRN, KC_EXLM,    CB_ASTR, CB_DQUO, LFT_WRD, KC_UP,   RGT_WRD, CB_CIRC,
  _______, CB_COLN, CB_EQL,  CB_LABK, CB_RABK, KC_PERC,    CB_ACUT, CB_GRV,  KC_LEFT, KC_DOWN, KC_RGHT, CB_TILD,
  _______, _______, CB_M_SW, CB_M_SE, CB_M_W,  G(KC_DOWN), CB_M_N,  CB_M_E,  KC_HOME, KC_PSCR, KC_END, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
),

[_NUMBERS] = LAYOUT_preonic_grid(
  QK_RBT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,        KC_F6,      KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_F11,
  EE_CLR,  KC_1,    KC_2,    KC_3,    KC_4,         KC_5,         KC_6,       KC_7,         KC_8,    KC_9,    KC_0,    KC_F12,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,      KC_MPRV, KC_MPLY, KC_MNXT, CB_RPRM,
  _______, ______,  KC_BRID, KC_BRIU, MEH(KC_LEFT), MEH(KC_DOWN), MEH(KC_UP), MEH(KC_RGHT), KC_VOLD, KC_MUTE, KC_VOLU, _______,
  _______, _______, _______, _______, _______,      _______,      _______,    _______,      _______, _______, _______, _______
)
};
/* clang-format on */
