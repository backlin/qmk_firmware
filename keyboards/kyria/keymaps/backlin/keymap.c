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
 * | LShift |  . < |   Q  |   J  |   K  |   X  |      |Navigt|  |Navigt|      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * |    :   |      |      |      |      |      |Symbol| Down |  |  Up  |Symbol|      |      |      |      |      |  ; :   |
 * `----------------------+------+------+------+Space +------|  |------+Enter +------+------+------+----------------------'
 *                        | LCtrl| GUI  | Alt  |      |Numric|  |Numric|      |AltGr | GUI  | RCtrl|
 *                        | RecSt|      | , <  |      | Left |  |Right |      | . >  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
      KC_TAB,     RALT(KC_W), RALT(KC_Q), RALT(KC_P), KC_P,    KC_Y,                                                                                    KC_F,  KC_G,  KC_C,  KC_R,  KC_L,  KC_BSPC,
      KC_ESC,     KC_A,       KC_O,       KC_E,       KC_U,    KC_I,                                                                                    KC_D,  KC_H,  KC_T,  KC_N,  KC_S,  KC_DEL,
      S(KC_COLN), KC_DOT,     KC_Q,       KC_J,       KC_K,    KC_X,  XXXXXXX,            LT(_LNAVI, KC_DOWN), LT(_RNAVI, KC_UP),   XXXXXXX,            KC_B,  KC_M,  KC_W,  KC_V,  KC_Z,  RSFT_T(KC_SCLN),
                                C(DM_RSTP), KC_LGUI, LALT_T(KC_COMM), LT(_LSYMB, KC_SPC), LT(_LNUMB, KC_LEFT), LT(_RNUMB, KC_RGHT), LT(_RSYMB, KC_ENT), RALT_T(KC_DOT), KC_RGUI, KC_RCTL
    ),

/* 
 * Alternative base layer: QWERTY (Swedish)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |  , < | Bksp |  Del |        |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I, KC_O, KC_P, RALT(KC_W),
      _______, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, RALT(KC_P), RALT(KC_Q),
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, _______, _______, XXXXXXX, KC_N, KC_M, KC_COMM, KC_BSPC, KC_DEL, _______,
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
 * |        |      |  no  |   <  |   >  |   %  |      |  F2  |  |  F8  |      |  = + |   !  |   ?  |  no  |  no  |        |
 * `----------------------+------+------+------+  F4  +------|  |------+  F6  +------+------+------+----------------------'
 *                        |      |      |      |      |  F1  |  |  F7  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LSYMB] = LAYOUT(
        XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,                                 KC_HASH, KC_ASTR, KC_AMPR, KC_AT,   KC_PLUS, KC_TILD,
        XXXXXXX, KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_CIRC,                                 KC_DLR,  KC_DQUO, KC_QUOT, KC_GRV,  KC_MINS, KC_UNDS,
        _______, _______, XXXXXXX, KC_LT,   KC_GT,   KC_PERC, XXXXXXX, KC_F2, KC_F8, XXXXXXX, KC_EQL,  KC_EXLM, KC_QUES, XXXXXXX, XXXXXXX, _______,
                                   _______, _______, _______, _______, KC_F1, KC_F7, KC_F6,   _______, _______, _______
    ),
    [_RSYMB] = LAYOUT(
        XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,                                 KC_HASH, KC_ASTR, KC_AMPR, KC_AT,   KC_PLUS, KC_TILD,
        XXXXXXX, KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_CIRC,                                 KC_DLR,  KC_DQUO, KC_QUOT, KC_GRV,  KC_MINS, KC_UNDS,
        _______, _______, XXXXXXX, KC_LT,   KC_GT,   KC_PERC, XXXXXXX, KC_F2, KC_F8, XXXXXXX, KC_EQL,  KC_EXLM, KC_QUES, XXXXXXX, XXXXXXX, _______,
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
 * |  Rec1  |  F1  |  F2  |  F3  |  F4  |   +  |                              |   /  |  1 ! |  2 @ |  3 # |  4 $ |  Rec2  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Play1 |  F5  |  F6  |  F7  |  F8  |   -  |                              |   =  |  5 % |  6 ^ |  7 & |  8 * |  Play2 |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |   *  |      | Next |  | Vol+ |      |   .  |  9 ( |  0 ) |  no  |  no  |        |
 * `----------------------+------+------+------+ Play +------|  |------+ Mute +------+------+------+----------------------'
 *                        |      |      |      |      | Prev |  | Vol- |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LNUMB] = LAYOUT(
        DM_REC1, KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_PPLS,                                     KC_PSLS, KC_1, KC_2, KC_3,    KC_4,    DM_REC2,
        DM_PLY1, KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_PMNS,                                     KC_PEQL, KC_5, KC_6, KC_7,    KC_8,    DM_PLY2,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  KC_PAST, XXXXXXX, KC_MFFD, KC_VOLU, XXXXXXX, KC_PENT, KC_9, KC_0, XXXXXXX, XXXXXXX, _______,
                                _______, _______, _______, KC_MPLY, _______, KC_VOLD, KC_MUTE, _______, _______, _______
    ),
    [_RNUMB] = LAYOUT(
        DM_REC1, KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_PPLS,                                     KC_PSLS, KC_1, KC_2, KC_3,    KC_4,    DM_REC1,
        DM_PLY1, KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_PMNS,                                     KC_PEQL, KC_5, KC_6, KC_7,    KC_8,    DM_PLY1,
        _______, KC_F9, KC_F10, KC_F11,  KC_F12,  KC_PAST, XXXXXXX, KC_MFFD, KC_VOLU, XXXXXXX, KC_PENT, KC_9, KC_0, XXXXXXX, XXXXXXX, _______,
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
 * | Qwerty |  RGB |  RGB |  RGB |  RGB |  no  |                              |Mouse1| MLeft| MDown| MUp  |MRight| Mouse2 |
 * |        | hue+ | sat+ |speed+| mode+|      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   no   | hue- | sat- |speed-| mode-|  no  |                              |  no  | Left | Down |  Up  | Right|   no   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |Insert|PrntSc|CapLck|NumLck|ScrLck|      | Val+ |  |Brght+|      |  no  | Home | PgDn | PgUp | End  |        |
 * `----------------------+------+------+------+  RGB +------|  |------+  no  +------+------+------+----------------------'
 *                        |      |      |      |Toggle| Val- |  |Brght-|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LNAVI] = LAYOUT(
        TG(_QWERTY), RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD,  XXXXXXX,                                     KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
        XXXXXXX,     RGB_HUD, RGB_SAD, RGB_SPD, RGB_RMOD, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        _______,     KC_INS,  KC_PSCR, KC_CAPS, KC_NLCK,  KC_SLCK, XXXXXXX, _______, KC_BRIU, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                       _______, _______,  _______, RGB_TOG, RGB_VAD, KC_BRID, XXXXXXX, _______, _______, _______
    ),
    [_RNAVI] = LAYOUT(
        TG(_QWERTY), RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD,  XXXXXXX,                                     KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2,
        XXXXXXX,     RGB_HUD, RGB_SAD, RGB_SPD, RGB_RMOD, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        _______,     KC_INS,  KC_PSCR, KC_CAPS, KC_NLCK,  KC_SLCK, XXXXXXX, RGB_VAI, _______, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                       _______, _______,  _______, RGB_TOG, RGB_VAD, KC_BRID, XXXXXXX, _______, _______, _______
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

static void render_svorak_left(void) {
  static const char PROGMEM svorak_left[] = {
    1, 2, 3, 32, 134, 32, 32, 132, 32, 32, 148, 32, 32, 112, 32, 32, 121, 32, 10, 10, 4, 5, 6, 32, 97, 32, 32, 111, 32, 32, 101, 32, 32, 117, 32, 32, 105, 32, 10, 10, 217, 218, 219, 32, 46, 32, 32, 113, 32, 32, 106, 32, 32, 107, 32, 32, 120, 32, 10, 32, 58, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 147, 10, 32, 32, 32, 32, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 32, 161, 162, 163, 10, 32, 32, 32, 32, 32, 32, 26, 32, 32, 32, 32, 32, 44, 32, 32, 177, 178, 179, 0};
  oled_write_P(svorak_left, false);
}

static void render_svorak_right(void) {
  static const char PROGMEM svorak_right[] = {
    32, 102, 32, 32, 103, 32, 32, 99, 32, 32, 114, 32, 32, 108, 32, 7, 8, 9, 10, 10, 32, 100, 32, 32, 104, 32, 32, 116, 32, 32, 110, 32, 32, 115, 32, 11, 14, 15, 10, 10, 32, 98, 32, 32, 109, 32, 32, 119, 32, 32, 118, 32, 32, 122, 32, 217, 218, 219, 10, 149, 150, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 59, 32, 10, 165, 166, 167, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 10, 181, 182, 183, 32, 32, 46, 32, 0
  };
  oled_write_P(svorak_right, false);
}

static void render_qwerty_left(void) {
  static const char PROGMEM qwerty_left[] = {
    1, 2, 3, 32, 113, 32, 32, 119, 32, 32, 101, 32, 32, 114, 32, 32, 116, 32, 10, 10, 4, 5, 6, 32, 97, 32, 32, 115, 32, 32, 100, 32, 32, 102, 32, 32, 103, 32, 10, 10, 217, 218, 219, 32, 122, 32, 32, 120, 32, 32, 99, 32, 32, 118, 32, 32, 98, 32, 10, 32, 58, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 147, 10, 32, 32, 32, 32, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 32, 161, 162, 163, 10, 32, 32, 32, 32, 32, 32, 26, 32, 32, 32, 32, 32, 44, 32, 32, 177, 178, 179, 0
  };
  oled_write_P(qwerty_left, false);
}

static void render_qwerty_right(void) {
  static const char PROGMEM qwerty_right[] = {
    32, 121, 32, 32, 117, 32, 32, 105, 32, 32, 111, 32, 32, 112, 32, 32, 134, 32, 10, 10, 32, 104, 32, 32, 106, 32, 32, 107, 32, 32, 108, 32, 32, 148, 32, 32, 132, 32, 10, 10, 32, 110, 32, 32, 109, 32, 32, 44, 32, 7, 8, 9, 11, 14, 15, 217, 218, 219, 10, 149, 150, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 59, 32, 10, 165, 166, 167, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 10, 181, 182, 183, 32, 32, 46, 32, 0
  };
  oled_write_P(qwerty_right, false);
}

static void render_symbols_left(void) {
  static const char PROGMEM symbols_left[] = {
    32, 32, 32, 32, 123, 32, 32, 125, 32, 32, 91, 32, 32, 93, 32, 32, 124, 32, 10, 10, 32, 32, 32, 32, 92, 32, 32, 47, 32, 32, 40, 32, 32, 41, 32, 32, 94, 32, 10, 10, 217, 218, 219, 32, 46, 32, 32, 32, 32, 32, 60, 32, 32, 62, 32, 32, 37, 32, 10, 32, 58, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 152, 153, 154, 10, 32, 32, 32, 32, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 32, 168, 169, 170, 10, 32, 32, 32, 32, 32, 32, 26, 32, 32, 32, 32, 32, 44, 32, 32, 184, 185, 186, 0
  };
  oled_write_P(symbols_left, false);
}

static void render_symbols_right(void) {
  static const char PROGMEM symbols_right[] = {
    32, 35, 32, 32, 42, 32, 32, 38, 32, 32, 64, 32, 32, 43, 32, 32, 126, 32, 10, 10, 32, 36, 32, 32, 34, 32, 32, 39, 32, 32, 96, 32, 32, 45, 32, 32, 95, 32, 10, 10, 32, 61, 32, 32, 33, 32, 32, 63, 32, 32, 32, 32, 32, 32, 32, 217, 218, 219, 10, 155, 156, 157, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 59, 32, 10, 171, 172, 173, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 10, 187, 188, 189, 32, 32, 46, 32, 0
  };
  oled_write_P(symbols_right, false);
}

static void render_numeric_left(void) {
  static const char PROGMEM numeric_left[] = {
    202, 203, 204, 65, 66, 67, 65, 68, 69, 65, 70, 71, 65, 72, 73, 32, 43, 32, 10, 10, 205, 206, 204, 65, 74, 75, 65, 76, 77, 65, 78, 79, 65, 80, 81, 32, 45, 32, 10, 10, 217, 218, 219, 65, 82, 83, 84, 85, 86, 84, 87, 88, 84, 89, 90, 32, 42, 32, 10, 32, 58, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 158, 159, 10, 32, 32, 32, 32, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 32, 207, 174, 175, 10, 32, 32, 32, 32, 32, 32, 26, 32, 32, 32, 32, 32, 44, 32, 32, 177, 190, 191, 0
  };
  oled_write_P(numeric_left, false);
}

static void render_numeric_right(void) {
  static const char PROGMEM numeric_right[] = {
    32, 31, 32, 32, 49, 32, 32, 50, 32, 32, 51, 32, 32, 52, 32, 202, 208, 209, 10, 10, 32, 61, 32, 32, 53, 32, 32, 54, 32, 32, 55, 32, 32, 56, 32, 205, 210, 209, 10, 10, 32, 46, 32, 32, 57, 32, 32, 48, 32, 32, 32, 32, 32, 32, 32, 217, 218, 219, 10, 160, 192, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 59, 32, 10, 176, 193, 194, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 10, 177, 178, 183, 32, 32, 46, 32, 0
  };
  oled_write_P(numeric_right, false);
}

static void render_navigation_left(void) {
  static const char PROGMEM navigation_left[] = {
    23, 24, 25, 32, 43, 104, 32, 43, 115, 32, 43, 116, 32, 43, 109, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 45, 32, 32, 45, 32, 32, 45, 32, 32, 45, 32, 32, 32, 32, 10, 10, 217, 218, 219, 211, 212, 213, 214, 215, 216, 220, 221, 222, 223, 224, 225, 226, 227, 228, 10, 32, 58, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 164, 10, 32, 32, 32, 32, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 32, 195, 196, 180, 10, 32, 32, 32, 32, 32, 32, 26, 32, 32, 32, 32, 32, 44, 32, 32, 177, 178, 183, 0
  };
  oled_write_P(navigation_left, false);
}

static void render_navigation_right(void) {
  static const char PROGMEM navigation_right[] = {
    32, 127, 128, 129, 130, 129, 129, 131, 129, 129, 133, 129, 129, 135, 129, 136, 137, 32, 10, 32, 138, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 140, 32, 10, 32, 32, 32, 32, 141, 32, 32, 142, 32, 32, 143, 32, 32, 144, 32, 10, 10, 32, 32, 32, 32, 27, 32, 32, 30, 32, 32, 29, 32, 32, 28, 32, 217, 218, 219, 10, 197, 198, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 59, 32, 10, 199, 200, 201, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 10, 177, 229, 32, 32, 32, 46, 32, 0
  };
  oled_write_P(navigation_right, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _LNAVI:
            case _RNAVI:
                render_navigation_left();
                break;
            case _LNUMB:
            case _RNUMB:
                render_numeric_left();
                break;
            case _LSYMB:
            case _RSYMB:
                render_symbols_left();
                break;
            case _QWERTY:
                render_qwerty_left();
                break;
            case _SVORAK:
            default:
                render_svorak_left();
        }
				return;
    }

		switch (get_highest_layer(layer_state)) {
				case _LNAVI:
				case _RNAVI:
						render_navigation_right();
						break;
				case _LNUMB:
				case _RNUMB:
						render_numeric_right();
						break;
				case _LSYMB:
				case _RSYMB:
						render_symbols_right();
						break;
				case _QWERTY:
						render_qwerty_right();
						break;
				case _SVORAK:
				default:
						render_svorak_right();
		}
}

#endif

