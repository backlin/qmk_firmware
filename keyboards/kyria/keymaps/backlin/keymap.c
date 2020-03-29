/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _SVORAK = 0,
    _QWERTY,
    _LSYMB,
    _RSYMB,
    _LNUMB,
    _RNUMB,
    _LNAVI,
    _RNAVI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 * Base layer: SVORAK (Swedish Dvorak)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Å  |   Ä  |   Ö  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc   |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  Del   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   :  |   Q  |   J  |   K  |   X  |      |Navigt|  |Navigt|      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * |        |      |      |      |      |      |Symbol| Down |  |  Up  |Symbol|      |      |      |      |      |  ; :   |
 * `----------------------+------+------+------+Space +------|  |------+Enter +------+------+------+----------------------'
 *                        | LCtrl| GUI  | Alt  |      |Numric|  |Numric|      |AltGr | GUI  | RCtrl|
 *                        |      |      | , <  |      | Left |  |Right |      | . >  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
      KC_TAB,   RALT(KC_W), RALT(KC_Q), RALT(KC_P), KC_P,    KC_Y,                                                                                   KC_F,  KC_G,  KC_C,  KC_R,  KC_L,  KC_BSPC,
      KC_ESC,   KC_A,       KC_O,       KC_E,       KC_U,    KC_I,                                                                                   KC_D,  KC_H,  KC_T,  KC_N,  KC_S,  KC_DEL,
      KC_LSFT,  KC_COLN,    KC_Q,       KC_J,       KC_K,    KC_X,  XXXXXXX,            LT(_LNAVI, KC_DOWN), LT(_RNAVI, KC_UP),  XXXXXXX,            KC_B,  KC_M,  KC_W,  KC_V,  KC_Z,  RSFT_T(KC_SCLN),
                                 KC_LCTL, KC_LGUI, LALT_T(KC_COMM), LT(_LSYMB, KC_SPC), LT(_NUMB, KC_LEFT),  LT(_NUMB, KC_RGHT), LT(_RSYMB, KC_ENT), RALT_T(KC_DOT), KC_RGUI, KC_RCTL
    ),

/* 
 * Alternative base layer: QWERTY (Swedish)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |  , < |  . > |  - _ |        |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I, KC_O, KC_P, RALT(KC_W),
      _______, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, RALT(KC_P), RALT(KC_Q),
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, _______, _______, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_MINS, _______,
                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Symbol Layer
 * ------------
 * Left and right layers are identical except the key used to trigger the layer.
 * This enables mapping left thumb > right thumb to a non-layer key and
 * right > left to a different non-layer key.
 *
 * The thumb cluster is mapped to function keys that are used for common
 * refactoring actions in the IntelliJ editors.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   no   |   {  |   }  |  [ { |  ] } |   |  |                              |   #  |   *  |   &  |   @  |   +  |   ~    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   no   |  \ | |  / ? |   (  |   )  |   ^  |                              |   $  |   "  |  ' " |  ` ~ |  - _ |   _    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  no  |  no  |  no  |   %  |      |  F2  |  |  F8  |      |  = + |  no  |  no  |  no  |  no  |        |
 * `----------------------+------+------+------+  F4  +------|  |------+  F6  +------+------+------+----------------------'
 *                        |      |      |      |      |  F1  |  |  F7  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LSYMB] = LAYOUT(
        KC_NO,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,                                 KC_HASH, KC_ASTR, KC_AMPR, KC_AT,  KC_PLUS, KC_TILD,
        KC_NO,   KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_CIRC,                                 KC_DLR,  KC_DQUO, KC_QUOT, KC_GRV, KC_MINS, KC_UNDS,
        _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_PERC, XXXXXXX, KC_F2, KC_F8, XXXXXXX, KC_EQL,  KC_NO,   KC_NO,   KC_NO,  KC_NO,   _______,
                                   _______, _______, _______, _______, KC_F1, KC_F7, KC_F6,   _______, _______, _______
    ),
    [_RSYMB] = LAYOUT(
        KC_NO,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,                                 KC_HASH, KC_ASTR, KC_AMPR, KC_AT,  KC_PLUS, KC_TILD,
        KC_NO,   KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_CIRC,                                 KC_DLR,  KC_DQUO, KC_QUOT, KC_GRV, KC_MINS, KC_UNDS,
        _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_PERC, XXXXXXX, KC_F2, KC_F8, XXXXXXX, KC_EQL,  KC_NO,   KC_NO,   KC_NO,  KC_NO,   _______,
                                   _______, _______, _______, KC_F4,   KC_F1, KC_F7, _______, _______, _______, _______
    ),

/* 
 * Numeric Layer
 * -------------
 * Left and right layers are identical except the key used to trigger the layer.
 * This enables mapping left thumb > right thumb to a non-layer key and
 * right > left to a different non-layer key.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   no   |  F1  |  F2  |  F3  |  F4  |   +  |                              |   /  |  1 ! |  2 @ |  3 # |  4 $ |   no   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   no   |  F5  |  F6  |  F7  |  F8  |   -  |                              |   =  |  5 % |  6 ^ |  7 & |  8 * |   no   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |   *  |      | Next |  | Vol+ |      |   .  |  9 ( |  0 ) |  no  |  no  |        |
 * `----------------------+------+------+------+ Play +------|  |------+ Mute +------+------+------+----------------------'
 *                        |      |      |      |      | Prev |  | Vol- |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LNUMB] = LAYOUT(
        KC_NO,   KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_PPLS,                                     KC_PSLS, KC_1, KC_2, KC_3,  KC_4,  KC_NO,
        KC_NO,   KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_PMNS,                                     KC_PEQL, KC_5, KC_6, KC_7,  KC_8   KC_NO,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  KC_PAST, XXXXXXX, KC_MFFD, KC_VOLU, XXXXXXX, KC_PENT, KC_9, KC_0, KC_NO, KC_NO, _______,
                                _______, _______, _______, KC_MPLY, _______, KC_VOLD, KC_MUTE, _______, _______, _______
    ),
    [_RNUMB] = LAYOUT(
        KC_NO,   KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_PPLS,                                     KC_PSLS, KC_1, KC_2, KC_3,  KC_4,  KC_NO,
        KC_NO,   KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_PMNS,                                     KC_PEQL, KC_5, KC_6, KC_7,  KC_8   KC_NO,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  KC_PAST, KC_NO,   KC_MFFD, KC_VOLU, KC_NO,   KC_PENT, KC_9, KC_0, KC_NO, KC_NO, _______,
                                _______, _______, _______, KC_MPLY, KC_MRWD, _______, KC_MUTE, _______, _______, _______
    ),

/* 
 * Navigation Layer
 * ----------------
 * Left and right layers are identical except the key used to trigger the layer.
 * This enables mapping left thumb > right thumb to a non-layer key and
 * right > left to a different non-layer key.
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Qwerty | Rec1 | Rec2 |Insert| Home | PgUp |                              |Mouse1| MLeft| MDown| MUp  |MRight| Mouse2 |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | RecStop| Play1| Play2|PrntSc| End  |PgDown|                              |  no  | Left | Down |  Up  | Right|   no   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  no  | Pause|CapLck|NumLck|ScrLck|      | BL+  |  |Brght+|      |  no  |  no  |  no  |  no  |  no  |        |
 * `----------------------+------+------+------+Breath+------|  |------+  no  +------+------+------+----------------------'
 *                        |      |      |      |      | BL-  |  |Brght-|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LNAVI] = LAYOUT(
        TG(_QWERTY),  DYN_REC_START1,  DYN_REC_START2,  KC_INS,  KC_HOME, KC_PGUP,                                     KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
        DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_PSCR, KC_END,  KC_PGDN,                                     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        _______,      KC_NO,           KC_PAUS,         KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, _______, KC_BRIU, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
                                                        _______, _______, _______, BL_BRTG, BL_DEC,  KC_BRID, KC_NO,   _______, _______, _______,
    ),
    [_RNAVI] = LAYOUT(
        TG(_QWERTY),  DYN_REC_START1,  DYN_REC_START2,  KC_INS,  KC_HOME, KC_PGUP,                                     KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
        DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_PSCR, KC_END,  KC_PGDN,                                     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        _______,      KC_NO,           KC_PAUS,         KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, BL_INC,  _______, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
                                                        _______, _______, _______, BL_BRTG, BL_DEC,  KC_BRID, KC_NO,   _______, _______, _______,
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/*
// Disabled since I don't want tri-layer switching.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _SVORAK:
            oled_write_P(PSTR("Svorak\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _LSYMB:
        case _RSYMB:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _LNUMB:
        case _RNUMB:
            oled_write_P(PSTR("Numeric\n"), false);
            break;
        case _LNAVI:
        case _RNAVI:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
