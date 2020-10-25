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
#include "keymap_swedish.h"

// Changes not updated in the oled and comments
//  - Thumb cluster arrows
//  - Comma and semicolon in layer 1
//  - Alt and ctrl swap

enum layers {
    _SVORAK = 0,
    _QWERTY,
    _SYMB,
    _NUMB,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 * Base layer: SVORAK (Swedish Dvorak)
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  Tab |   Å  |   Ä  |   Ö  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Esc |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  Del |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |LShift|   .  |   Q  |   J  |   K  |   X  |      | Numb |  | Numb |      |   B  |   M  |   W  |   V  |   Z  |RShift|
 * |  , ; |      |      |      |      |      | Space|      |  |      | Enter|      |      |      |      |      |  - _ |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |  Alt |  GUI | LCtrl|      | Symb |  | Symb |      | RCtrl|  GUI | AltGr|
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
      KC_TAB,          SE_AA,  SE_AE, SE_OSLH, KC_P, KC_Y,                                                             KC_F,  KC_G,  KC_C,  KC_R,  KC_L,  KC_BSPC,
      KC_ESC,          KC_A,   KC_O,  KC_E,    KC_U, KC_I,                                                             KC_D,  KC_H,  KC_T,  KC_N,  KC_S,  KC_DEL,
      LSFT_T(SE_COMM), SE_DOT, KC_Q,  KC_J,    KC_K, KC_X,   XXXXXXX, MO(_NUMB),        MO(_NUMB),          XXXXXXX,   KC_B,  KC_M,  KC_W,  KC_V,  KC_Z,  RSFT_T(SE_MINS),
                                  KC_LALT, KC_LGUI, KC_LCTL, KC_SPC,  LT(_SYMB, KC_UP), LT(_SYMB, KC_DOWN), KC_ENT,  KC_RCTL, KC_RGUI, KC_RALT
    ),

/* 
 * Alternative base layer: QWERTY (Swedish)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |  , ; | Bksp |  Del |        |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I, KC_O, KC_P, SE_AA,
      _______, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, SE_OSLH, SE_AE,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, _______, _______, XXXXXXX, KC_N, KC_M, SE_COMM, KC_BSPC, KC_DEL, _______,
                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Symbol Layer
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   {  |   }  |   [  |   ]  |   |  |                              |   &  |   $  |   @  |   #  |   ~  |   ´  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   \  |   /  |   (  |   )  |   ^  |                              |   *  |   "  |   '  |  Up  | Right|   `  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |  no  |   <  |   >  |   %  |      | PgUp |  | PgUp |      |   !  |   ?  | Left | Down |   =  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      | PgDn |  | PgDn |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SYMB] = LAYOUT(
        _______, SE_LCBR_MAC, SE_RCBR_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                 SE_AMPR, SE_DLR,  SE_AT,   KC_HASH, SE_TILD, SE_ACUT,
        _______, SE_SLSH,     SE_BSLS_MAC, SE_LPRN,     SE_RPRN,     SE_CIRC,                                     SE_ASTR, SE_DQUO, SE_QUOT, KC_UP,   KC_RGHT, SE_GRV,
        _______, _______,     XXXXXXX,     SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, KC_PGUP, KC_PGUP, XXXXXXX, KC_EXLM, SE_QUES, KC_LEFT, KC_DOWN, SE_EQL,  _______,
                                           _______,     _______,     _______, _______, KC_PGDN, KC_PGDN, _______, _______, _______, _______
    ),

/* 
 * Numeric Layer
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |  F5  |  F6  |  F7  |  F8  |  F9  |                              |   7  |   8  |   9  |   +  | Vol+ |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                              |   4  |   5  |   6  |   -  | Vol- |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  no  |      |      |  |      |      |   1  |   2  |   3  |   *  | Mute |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |   0  |   .  |   /  |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_NUMB] = LAYOUT(
        _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_F9,                                             KC_7, KC_8, KC_9, KC_PPLS, CB_VOLU, _______,
        _______, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,                                             KC_4, KC_5, KC_6, KC_PMNS, CB_VOLD, _______,
        _______, KC_F9, KC_F10, KC_F10, KC_F10, XXXXXXX,   XXXXXXX, TG(_RGB), TG(_RGB), XXXXXXX,   KC_1, KC_2, KC_3, KC_PAST, KC_MUTE, _______,
                                _______, _______, _______, _______, _______,  _______,  _______, KC_0, SE_DOT, KC_PSLS
    ),

/* 
 * Navigation Layer
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |Qwerty| Mode+|Speed+| Hue+ | Sat+ | Val+ |                              | Home |  End |  no  |  no  |Mouse2|  no  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | Mode-|Speed-| Hue- | Sat- | Val- |                              | PgUp | PgDn |Mouse1| MUp  |MRight|  no  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |Insert|PrntSc|CapLck|NumLck|ScrLck|      |Brght+|  |  Off |      |  no  |  no  | MLeft| Mdown|  no  |      |
 * `--------------------+------+------+------+  RGB +------|  |------+  Off +------+------+------+--------------------'
 *                      |      |      |      |Toggle|Brght-|  |  Off |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_RGB] = LAYOUT(
        TG(_QWERTY), RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                                          KC_HOME, KC_END,  XXXXXXX, XXXXXXX, KC_BTN2, XXXXXXX,
        _______,     RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,                                          KC_PGUP, KC_PGDN, KC_BTN1, KC_MS_U, KC_MS_R, XXXXXXX,
        _______,     KC_INS,  KC_PSCR, KC_CAPS, KC_NLCK,  KC_SLCK,   XXXXXXX, KC_BRIU, TG(_RGB), XXXXXXX,   XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, XXXXXXX, _______,
                                         _______, _______,  _______, RGB_TOG, KC_BRID, TG(_RGB), TG(_RGB), _______, _______, _______
    ),

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

// generated by Makefile
static void render_svorak_left(void) {
  static const char PROGMEM svorak_left[] = {
    1, 2, 3, 32, 134, 32, 32, 132, 32, 32, 148, 32, 32, 112, 32, 32, 121, 10,
    10,
    4, 5, 6, 32, 97, 32, 32, 111, 32, 32, 101, 32, 32, 117, 32, 32, 105, 10,
    10,
    217, 218, 219, 32, 46, 32, 32, 113, 32, 32, 106, 32, 32, 107, 32, 32, 120, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 147,
    32, 32, 32, 32, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 32, 161, 162, 163,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 58, 32, 177, 178, 179, 0,
  };
  oled_write_P(svorak_left, false);
}

// generated by Makefile
static void render_svorak_right(void) {
  static const char PROGMEM svorak_right[] = {
    32, 102, 32, 32, 103, 32, 32, 99, 32, 32, 114, 32, 32, 108, 32, 7, 8, 9,
    10,
    32, 100, 32, 32, 104, 32, 32, 116, 32, 32, 110, 32, 32, 115, 32, 11, 14, 15,
    10,
    32, 98, 32, 32, 109, 32, 32, 119, 32, 32, 118, 32, 32, 122, 32, 217, 218, 219,
    149, 150, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 59,
    165, 166, 167, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 10,
    181, 182, 183, 32, 32, 46, 58, 0,
  };
  oled_write_P(svorak_right, false);
}

// generated by Makefile
static void render_qwerty_left(void) {
  static const char PROGMEM qwerty_left[] = {
    1, 2, 3, 32, 113, 32, 32, 119, 32, 32, 101, 32, 32, 114, 32, 32, 116, 10,
    10,
    4, 5, 6, 32, 97, 32, 32, 115, 32, 32, 100, 32, 32, 102, 32, 32, 103, 10,
    10,
    217, 218, 219, 32, 122, 32, 32, 120, 32, 32, 99, 32, 32, 118, 32, 32, 98, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 147,
    32, 32, 32, 32, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 32, 161, 162, 163,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 58, 32, 177, 178, 179, 0,
  };
  oled_write_P(qwerty_left, false);
}

// generated by Makefile
static void render_qwerty_right(void) {
  static const char PROGMEM qwerty_right[] = {
    32, 121, 32, 32, 117, 32, 32, 105, 32, 32, 111, 32, 32, 112, 32, 32, 134, 10,
    10,
    32, 104, 32, 32, 106, 32, 32, 107, 32, 32, 108, 32, 32, 148, 32, 32, 132, 10,
    10,
    32, 110, 32, 32, 109, 32, 32, 44, 32, 7, 8, 9, 11, 14, 15, 217, 218, 219,
    149, 150, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 59,
    165, 166, 167, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 10,
    181, 182, 183, 32, 32, 46, 58, 0,
  };
  oled_write_P(qwerty_right, false);
}

// generated by Makefile
static void render_symbols_left(void) {
  static const char PROGMEM symbols_left[] = {
    32, 32, 32, 32, 123, 32, 32, 125, 32, 32, 91, 32, 32, 93, 32, 32, 124, 10,
    10,
    32, 32, 32, 32, 47, 32, 32, 92, 32, 32, 40, 32, 32, 41, 32, 32, 94, 10,
    10,
    217, 218, 219, 32, 46, 32, 32, 32, 32, 32, 60, 32, 32, 62, 32, 32, 37, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 152, 153, 154,
    32, 32, 32, 32, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 32, 168, 169, 170,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 58, 32, 184, 185, 186, 0,
  };
  oled_write_P(symbols_left, false);
}

// generated by Makefile
static void render_symbols_right(void) {
  static const char PROGMEM symbols_right[] = {
    32, 35, 32, 32, 42, 32, 32, 38, 32, 32, 64, 32, 32, 43, 32, 32, 126, 10,
    10,
    32, 36, 32, 32, 34, 32, 32, 39, 32, 32, 96, 32, 32, 45, 32, 32, 95, 10,
    10,
    32, 61, 32, 32, 33, 32, 32, 63, 32, 32, 32, 32, 32, 32, 32, 217, 218, 219,
    155, 156, 157, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 59,
    171, 172, 173, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 10,
    187, 188, 189, 32, 32, 46, 58, 0,
  };
  oled_write_P(symbols_right, false);
}

// generated by Makefile
static void render_numeric_left(void) {
  static const char PROGMEM numeric_left[] = {
    65, 78, 79, 65, 80, 81, 65, 82, 83, 84, 85, 86, 84, 87, 88, 84, 89, 90,
    10,
    65, 66, 67, 65, 68, 69, 65, 70, 71, 65, 72, 73, 65, 74, 75, 65, 76, 77,
    10,
    217, 218, 219, 202, 203, 204, 202, 208, 209, 32, 26, 32, 205, 206, 204, 205, 210, 209,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 158, 159,
    32, 32, 32, 32, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 32, 207, 174, 175,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 58, 32, 177, 190, 191, 0,
  };
  oled_write_P(numeric_left, false);
}

// generated by Makefile
static void render_numeric_right(void) {
  static const char PROGMEM numeric_right[] = {
    32, 53, 32, 32, 54, 32, 32, 55, 32, 32, 56, 32, 32, 57, 32, 32, 61, 10,
    10,
    32, 48, 32, 32, 49, 32, 32, 50, 32, 32, 51, 32, 32, 52, 32, 32, 46, 10,
    10,
    32, 43, 32, 32, 45, 32, 32, 42, 32, 32, 31, 32, 32, 105, 32, 217, 218, 219,
    160, 192, 151, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 59,
    176, 193, 194, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 10,
    177, 178, 183, 32, 32, 46, 58, 0,
  };
  oled_write_P(numeric_right, false);
}

// generated by Makefile
static void render_navigation_left(void) {
  static const char PROGMEM navigation_left[] = {
    23, 24, 25, 32, 43, 104, 32, 43, 115, 32, 43, 116, 32, 43, 109, 10,
    10,
    32, 32, 32, 32, 45, 32, 32, 45, 32, 32, 45, 32, 32, 45, 10,
    10,
    217, 218, 219, 211, 212, 213, 214, 215, 216, 220, 221, 222, 223, 224, 225, 226, 227, 228,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 145, 146, 164,
    32, 32, 32, 32, 32, 19, 20, 21, 32, 22, 32, 16, 17, 18, 32, 195, 196, 180,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 58, 32, 177, 178, 183, 0,
  };
  oled_write_P(navigation_left, false);
}

// generated by Makefile
static void render_navigation_right(void) {
  static const char PROGMEM navigation_right[] = {
    32, 127, 128, 129, 130, 129, 129, 131, 129, 129, 133, 129, 129, 135, 129, 136, 137, 10,
    32, 138, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 140, 10,
    32, 32, 32, 32, 141, 32, 32, 142, 32, 32, 143, 32, 32, 144, 10,
    10,
    32, 32, 32, 32, 27, 32, 32, 30, 32, 32, 29, 32, 32, 28, 32, 217, 218, 219,
    197, 198, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 59,
    199, 200, 201, 32, 16, 17, 18, 32, 22, 32, 19, 20, 21, 10,
    177, 229, 32, 32, 32, 46, 58, 0,
  };
  oled_write_P(navigation_right, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _RGB:
                render_navigation_left();
                break;
            case _NUMB:
                render_numeric_left();
                break;
            case _SYMB:
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
				case _RGB:
            render_navigation_right();
						break;
				case _NUMB:
						render_numeric_right();
						break;
				case _SYMB:
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

