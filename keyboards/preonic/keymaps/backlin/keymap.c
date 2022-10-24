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
#define _ KC_NO

KEYMAP keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// clang-format off
[_SVORAK] = LAYOUT_preonic_2x2u(
  KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
  KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
  _,       KC_LCTL, KC_LALT, KC_LGUI, TX_PREV, TX_NEXT,    TAB_PRV, TAB_NXT, CB_AT,   CB_HASH, KC_PPLS, _,
  _,       FN_LEFT, MAGNET,  NUMPAD,           KC_SPC,     SYMBOLS,          KC_ENT,  _,       KC_RGUI, _
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |   /  |   \  |   [  |   ]  |   ?  |   &  |   '  |BsWrd |DlWrd | RWrd | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   !  |   *  |   "  | LWrd |  Up  |Right |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   :  |   =  |   <  |   >  |   %  |   +  |   `  | Left | Down |   ;  |  ^   |
 * `------+------+------+------+------+------|------+------+------+------+------+------'
 *        |      |      |      |      |      |      |      |   @  |   #  |   +  |
 *        |------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |             |             |      |      |      |
 *        `-------------------------------------------------------'      `------'
 */
[_SYMBOLS] = LAYOUT_preonic_2x2u(
  _______, CB_SLSH, CB_BSLS, CB_LBRC, CB_RBRC, CB_QUES,    CB_AMPR, CB_QUOT, BSP_WRD, DEL_WRD, RGT_WRD, KC_DEL,
  LOCK,    CB_LCBR, CB_RCBR, CB_LPRN, CB_RPRN, KC_EXLM,    CB_ASTR, CB_DQUO, LFT_WRD, KC_UP,   KC_RGHT, CB_TILD,
  _______, CB_COLN, CB_EQL,  CB_LABK, CB_RABK, KC_PERC,    KC_PPLS, CB_GRV,  KC_LEFT, KC_DOWN, KC_F2,   CB_CIRC,
  _______, _______, _______, _______, CB_DLR,  CB_PIPE,    CB_DLR,  CB_ACUT, _______, _______, _______, _______,
  _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______
),

[_JETBRAINS] = LAYOUT_preonic_2x2u(
  _______, _______, JB_SHOW, JB_TO,   JB_CONT, JB_PRVC,    _______, _______, _______, _______, _______, _______,
  LOCK,    _______, JB_OUT,  JB_IN,   JB_STEP, JB_NXTC,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_LEFT, KC_RGHT, JB_DIFF,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, JB_PRVF, JB_NXTF, _______,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______
),

[_ARROWS] = LAYOUT_preonic_2x2u( //
  _______, _______, _______, _______, _______, _______,    BSP_WRD, LFT_WRD, KC_UP,   RGT_WRD, DEL_WRD, KC_DEL,
  _______, _______, _______, _______, _______, _______,    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  CB_TILD,
  _______, _______, _______, _______, _______, _______,    BSP_LNE, LFT_LNE, _______, RGT_LNE, DEL_LNE, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______
),

[_NUMPAD] = LAYOUT_preonic_2x2u( // Merged with JetBrains
  _______, _______, _______, _______, _______, _______,    _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, KC_P0,   CB_DOT,  CB_COLN, _______, _______,
  _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______
),

[_MAGNET] = LAYOUT_preonic_2x2u( // Merged with JetBrains
  _______, _______, _______, _______, _______, _______,    _______, MAG_1_3, MAG_2_3, MAG_3_3, _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, MAG_LFT, MAG_CTR, MAG_RGT, _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, MAG_S_L, MAG_S_R, XXXXXXX, _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,          MAG_S_L,    MAG_S_R,          _______, _______, _______, _______
),

[_FN] = LAYOUT_preonic_2x2u(
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,    _______, KC_F7,   KC_F8,   KC_F9,   _______, _______,
  QK_BOOT, _______, KC_VOLD, KC_MUTE, CB_VOLU, _______,    _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,
  _______, _______, XXXXXXX, KC_BRID, KC_BRIU, _______,    _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,
  _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______
)

};
