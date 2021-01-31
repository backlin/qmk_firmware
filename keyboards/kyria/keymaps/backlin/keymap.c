/* Copyright 2020 Thomas Baart <thomas@splitkb.com>
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

// Layers
#define SYMBOLS MO(_SYMB)
#define SYMBOL2 MO(_SYMB2)
#define SYMBOL3 MO(_SYMB3)
#define NUMBERS MO(_NUMB)
#define HYPER   MO(_HYPER)
#define MAG_FUN MO(_FUNC)

// Print screen (Mac)
#define CB_SCRC S(C(G(KC_4))) // Region to clipboard
#define CB_SCRF S(G(KC_4))    // Region to file

// Small volume increment (Mac)
#define CB_VOLU LSA(KC_VOLU)
#define CB_VOLD LSA(KC_VOLD)

// Magnet center
#define MAG_CTR LCA(KC_SPC)

// Rarely used symbols (Mac)
#define CB_PRGF 192
#define CB_DGRE LSA(KC_Q)
#define CB_MU   A(KC_Y)
#define CB_PI   A(KC_P)
#define CB_SIGM LSA(KC_S) // Capital sigma
#define CB_DELT LSA(KC_D) // Capital delta
#define CB_MDDT A(KC_Q)   // Mid dot
#define CB_APRX A(KC_X)

#define MOD_MASK_RSHIFT MOD_BIT(KC_RSHIFT) // NOT IN USE

enum layers {
    _SVORAK = 0,
    _QWERTY,
    _FACTORIO,

		// Toggleable
    _NUMB,
    _FUNC,
		_MAGN,
		_HYPR,

		// Non-toggleable
    _SYMB,
    _ARW1,
    _ARW2,
    _ARW3
};

enum custom_keycodes {
    CB_CIRC = SAFE_RANGE,
    CB_TILD,
    CB_GRV, // Backtick without hitting space

		CHROME,
    FINDER,
    FIREFOX,
    GOLAND,
		SLACK,
    SPOTIFY,
    SUBLIME,
    TERM,

		MAG_LFT,
		MAG_RGT,
		MAG_TOP,
		MAG_BTM,
		MAG_1_3,
		MAG_2_3,
		MAG_3_3,

    CB_2222 // For Factorio sandbox
};

extern rgblight_config_t rgblight_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 * Base layer: SVORAK (Swedish Dvorak)
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  Tab |   Å  |   Ä  |   Ö  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Esc |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  Del |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |LShift| LCtrl|   Q  |   J  |   K  |   X  |      | Func |  | Hyper|      |   B  |   M  |   W  |   V  |   Z  |Arrow1|
 * |  , ; |  . : |      |      |      |      | Space|      |  |      | Enter|      |      |      |      |      |  - _ |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      | LAlt | LCmd | Symb |      | Numb |  |Magnet|      |Arrow2| RCmd | RAlt |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
      KC_TAB,          SE_AA,          SE_AE, SE_OSLH, KC_P, KC_Y,                                             KC_F,  KC_G,  KC_C,  KC_R,  KC_L,  KC_BSPC,
      KC_ESC,          KC_A,           KC_O,  KC_E,    KC_U, KC_I,                                             KC_D,  KC_H,  KC_T,  KC_N,  KC_S,  KC_DEL,
      LSFT_T(SE_COMM), LCTL_T(SE_DOT), KC_Q,  KC_J,    KC_K, KC_X,   XXXXXXX, TT(_FUNC), TT(_HYPR), XXXXXXX,   KC_B,  KC_M,  KC_W,  KC_V,  KC_Z,  LT(_ARW1, SE_MINS),
                                        KC_LALT, KC_LCMD, MO(_SYMB), KC_SPC,  TT(_NUMB), TT(_MAGN), KC_ENT, MO(_ARW2), KC_RCMD, KC_RALT
    ),

/* 
 * Alternative base layer: QWERTY (Swedish)
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |  , ; | Bksp |  Del |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I,   KC_O,    KC_P,    SE_AA,
      _______, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K,   KC_L,    SE_OSLH, SE_AE,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, _______, _______, XXXXXXX, KC_N, KC_M, SE_DOT, KC_BSPC, KC_DEL,  _______,
                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Factorio
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  Tab |   Q  | 20 m2|   -  |   +  |  Alt |                              |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Esc |   A  |   W  |   E  |   R  |   T  |                              |   1  |   2  |   3  |   4  |   5  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   S  |   D  |   F  |   G  |      | Copy |  |      |      |      |      |      |      |      |      |
 * `--------------------+------+------+------+ Space+------|  |------+      +------+------+------+--------------------'
 *                      | Blue |Destrc| Ctrl |      |  Cut |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_FACTORIO] = LAYOUT(
        _______, KC_Q, CB_2222, KC_PMNS, KC_PPLS, KC_LALT,                                      KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, KC_A, KC_W,    KC_E,    KC_R,    KC_T,                                         KC_1, KC_2, KC_3, KC_4, KC_5, _______,
        _______, KC_Z, KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX, G(KC_C), _______, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                               A(KC_B), A(KC_D), KC_LCTL, _______, G(KC_X), _______, _______, _______, _______, _______
    ),

/* 
 * Symbol and arrow layers
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   /  |   \  |   [  |   ]  |   |  |                              |   !  |   ?  |   ´  |   °  |   ~  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |                              |   *  |   "  |   `  |   '  |   $  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |   =  |   <  |   >  |   %  |      |      |  |      |      |   &  |   #  |   ^  |   •  |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SYMB] = LAYOUT(
        _______, SE_SLSH,     SE_BSLS_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                 KC_EXLM, SE_QUES, SE_ACUT, CB_DGRE, SE_TILD, _______,
        _______, SE_LCBR_MAC, SE_RCBR_MAC, SE_LPRN,     SE_RPRN,     SE_AT,                                       SE_ASTR, SE_DQUO, CB_GRV,  SE_QUOT, SE_DLR,  _______,
        _______, _______,     SE_EQL,      SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, SE_AMPR, SE_HASH, CB_CIRC, CB_MDDT, KC_PPLS, _______,
                                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ARW1] = LAYOUT(
        _______,   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_BSPC,
        TG(_ARW1), _______, _______, _______, _______, _______,                                     _______, _______, _______, KC_UP,   KC_RGHT, KC_DEL,
        _______,   _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, _______, _______,
                                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ARW2] = LAYOUT(
        _______,   SPOTIFY, SUBLIME, FINDER,  FIREFOX, CB_SCRF,                                     _______, _______, _______,    _______, _______,    A(KC_BSPC),
        TG(_ARW2), SLACK,   GOLAND,  TERM,    CHROME,  CB_SCRC,                                     _______, _______, _______,    KC_UP,   A(KC_RGHT), A(KC_DEL),
        _______,   _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, A(KC_LEFT), KC_DOWN, _______,    _______,
                                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ARW3] = LAYOUT(
        _______,   KC_BTN1, KC_BTN3, _______, _______, _______,                                     _______, _______, _______,    _______, _______,    G(KC_BSPC),
        TG(_ARW3), KC_MS_L, KC_MS_U, KC_BTN2, _______, _______,                                     _______, _______, _______,    KC_PGUP, G(KC_RGHT), C(KC_K),
        _______,   _______, KC_MS_D, KC_MS_R, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, G(KC_LEFT), KC_PGDN, _______,    _______,
                                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MAGN] = LAYOUT(
        _______,   _______, KC_MPLY, KC_MPRV, KC_MNXT, _______,                                     _______, _______, _______, MAG_2_3, MAG_3_3, _______,
        TG(_MAGN), _______, KC_MUTE, CB_VOLD, CB_VOLU, _______,                                     _______, MAG_CTR, MAG_1_3, MAG_TOP, MAG_RGT, _______,
        _______,   _______, _______, KC_BRID, KC_BRIU, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, MAG_LFT, MAG_BTM, _______, _______,
                                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Launch apps and Numpad
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |   π  |   µ  |                              |      |   7  |   8  |   9  |   ∆  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |      |                              |   *  |   4  |   5  |   6  |   ∑  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |   =  |   ≠  |   ≈  |   %  |      |      |  |      |      |   /  |   1  |   2  |   3  |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |   0  |   .  |   :  |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_NUMB] = LAYOUT(
        _______,   _______, _______, _______,   CB_PI,   CB_MU,                                       _______, KC_7, KC_8, KC_9, CB_DELT, _______,
				TG(_NUMB), _______, _______, SE_LPRN,   SE_RPRN, _______,                                     SE_ASTR, KC_4, KC_5, KC_6, CB_SIGM, _______,
        _______,   _______, KC_EQL,  S(KC_EQL), CB_APRX, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, SE_SLSH, KC_1, KC_2, KC_3, KC_PPLS, _______,
                                       _______, _______, _______, _______, _______, _______, _______, KC_0, SE_DOT, S(SE_DOT)
    ),
    [_FUNC] = LAYOUT(
        _______,   RGB_SPD,  RGB_SPI, RGB_HUD, RGB_HUI, _______,                                     _______, KC_F7, KC_F8, KC_F9, _______, _______, 
        TG(_FUNC), RGB_RMOD, RGB_MOD, RGB_SAD, RGB_SAI, _______,                                     _______, KC_F4, KC_F5, KC_F6, _______, _______, 
        _______,   RGB_TOG,  RGB_TOG, RGB_VAD, RGB_VAI, _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_F1, KC_F2, KC_F3, _______, _______, 
                                      _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12
    ),
    [_HYPR] = LAYOUT(
      _______,   HYPR(SE_AA),  HYPR(SE_AE), HYPR(SE_OSLH), HYPR(KC_P), HYPR(KC_Y),                                     HYPR(KC_F), HYPR(KC_G), HYPR(KC_C), HYPR(KC_R), HYPR(KC_L),  _______,
      TG(_HYPR), HYPR(KC_A),   HYPR(KC_O),  HYPR(KC_E),    HYPR(KC_U), HYPR(KC_I),                                     HYPR(KC_D), HYPR(KC_H), HYPR(KC_T), HYPR(KC_N), HYPR(KC_S),  _______,
      _______,   HYPR(SE_DOT), HYPR(KC_Q),  HYPR(KC_A),    HYPR(KC_A), HYPR(KC_A), XXXXXXX, _______, _______, XXXXXXX, HYPR(KC_B), HYPR(KC_M), HYPR(KC_W), HYPR(KC_V), HYPR(KC_Z),  _______,
                                                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Template
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
};

void process_magnet(uint8_t state) {
	uint8_t original_mods = get_mods();
	set_mods(MOD_MASK_CTRL | MOD_MASK_SHIFT);

	switch (state) {
		case  1: tap_code(KC_LEFT); break; // Left
		case  2: tap_code(KC_RGHT); break; // Right
		case  3: tap_code(KC_ENT);  break; // Full (left & right)
		case  4: tap_code(KC_UP);   break; // Top
		case  5: tap_code(KC_U);    break; // Top left
		case  6: tap_code(KC_I);    break; // Top right
		case  8: tap_code(KC_DOWN); break; // Bottom
		case  9: tap_code(KC_J);    break; // Bottom left
		case 10: tap_code(KC_K);    break; // Bottom right
		case 16: tap_code(KC_D);    break; // Left 1/3
		case 32: tap_code(KC_F);    break; // Mid 1/3
		case 48: tap_code(KC_E);    break; // Left 2/3
		case 64: tap_code(KC_G);    break; // Right 1/3
		case 80: tap_code(KC_E);    tap_code(KC_SPC); break; // Center 2/3 (left 1/3 & right 1/3)
		case 96: tap_code(KC_T);    break; // Right 2/3
	}

	set_mods(original_mods);
	return;
}

bool show_slave;
uint8_t magnet_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		if (record->event.pressed) {
				// when key is pressed
				switch (keycode) {
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


						case MAG_LFT: magnet_state |=  1; process_magnet(magnet_state); break;
						case MAG_RGT: magnet_state |=  2; process_magnet(magnet_state); break;
						case MAG_TOP: magnet_state |=  4; process_magnet(magnet_state); break;
						case MAG_BTM: magnet_state |=  8; process_magnet(magnet_state); break;
						case MAG_1_3: magnet_state |= 16; process_magnet(magnet_state); break;
						case MAG_2_3: magnet_state |= 32; process_magnet(magnet_state); break;
						case MAG_3_3: magnet_state |= 64; process_magnet(magnet_state); break;
	

						case CHROME:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "chrome\n" ); break;
						case FINDER:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "finder\n" ); break;
						case FIREFOX: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "firefox\n"); break;
						case GOLAND:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "goland\n" ); break;
						case SLACK:   SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "slack\n" ); break;
						case SPOTIFY: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "spotify\n"); break;
						case SUBLIME: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "sublime\n"); break;
						case TERM:    SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "term\n"   ); break;


						case CB_2222: SEND_STRING(
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
              SS_TAP(X_BTN2)
            ); break;

            case KC_LALT:
							show_slave = false;
							break;
            case KC_RALT:
							show_slave = true;
							break;
				}
		} else { // when Key is released
				switch (keycode) {
						case MAG_LFT: magnet_state &=  ~1; break;
						case MAG_RGT: magnet_state &=  ~2; break;
						case MAG_TOP: magnet_state &=  ~4; break;
						case MAG_BTM: magnet_state &=  ~8; break;
						case MAG_1_3: magnet_state &= ~16; break;
						case MAG_2_3: magnet_state &= ~32; break;
						case MAG_3_3: magnet_state &= ~64; break;
				}
		}
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _ARW1, _ARW2, _ARW3);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

// generated by Makefile
static void render_svorak_left(void) {
  static const char PROGMEM svorak_left[] = {
    1, 2, 3, 32, 32, 134, 32, 132, 32, 148, 32, 112, 32, 121, 10,
    10,
    4, 5, 6, 32, 32, 97, 32, 111, 32, 101, 32, 117, 32, 105, 10,
    10,
    32, 16, 17, 32, 32, 138, 32, 113, 32, 106, 32, 107, 32, 120, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 92, 115, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 35, 32, 49, 32, 32, 32, 20, 21, 0,
  };
  oled_write_P(svorak_left, false);
}

// generated by Makefile
static void render_svorak_right(void) {
  static const char PROGMEM svorak_right[] = {
    32, 32, 32, 32, 102, 32, 103, 32, 99, 32, 114, 32, 108, 32, 32, 7, 8, 9,
    10,
    32, 32, 32, 32, 100, 32, 104, 32, 116, 32, 110, 32, 115, 32, 32, 11, 14, 15,
    10,
    32, 32, 32, 32, 98, 32, 109, 32, 119, 32, 118, 32, 122, 32, 32, 16, 17, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 32, 92, 110, 10,
    20, 21, 32, 32, 32, 49, 32, 35, 32, 22, 10, 0,
  };
  oled_write_P(svorak_right, false);
}

// generated by Makefile
static void render_qwerty_left(void) {
  static const char PROGMEM qwerty_left[] = {
    1, 2, 3, 32, 32, 113, 32, 119, 32, 101, 32, 114, 32, 116, 10,
    10,
    4, 5, 6, 32, 32, 97, 32, 115, 32, 100, 32, 102, 32, 103, 10,
    10,
    32, 16, 17, 32, 32, 122, 32, 120, 32, 99, 32, 118, 32, 98, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 92, 115, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 35, 32, 49, 32, 32, 32, 20, 21, 0,
  };
  oled_write_P(qwerty_left, false);
}

// generated by Makefile
static void render_qwerty_right(void) {
  static const char PROGMEM qwerty_right[] = {
    32, 32, 32, 32, 121, 32, 117, 32, 105, 32, 111, 32, 112, 32, 32, 134, 10,
    10,
    32, 32, 32, 32, 104, 32, 106, 32, 107, 32, 108, 32, 148, 32, 32, 132, 10,
    10,
    32, 32, 32, 32, 110, 32, 109, 32, 138, 7, 8, 9, 11, 14, 15, 16, 17, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 32, 92, 110, 10,
    20, 21, 32, 32, 32, 49, 32, 35, 32, 22, 10, 0,
  };
  oled_write_P(qwerty_right, false);
}

// generated by Makefile
static void render_symbols_left(void) {
  static const char PROGMEM symbols_left[] = {
    1, 2, 3, 32, 32, 47, 32, 92, 32, 91, 32, 93, 32, 124, 10,
    10,
    4, 5, 6, 32, 32, 123, 32, 125, 32, 40, 32, 41, 32, 64, 10,
    10,
    32, 16, 17, 32, 32, 61, 32, 150, 32, 60, 32, 62, 32, 37, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 92, 115, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 35, 32, 49, 32, 32, 32, 20, 21, 0,
  };
  oled_write_P(symbols_left, false);
}

// generated by Makefile
static void render_symbols_right(void) {
  static const char PROGMEM symbols_right[] = {
    32, 32, 32, 32, 35, 32, 38, 32, 36, 32, 94, 32, 126, 32, 32, 7, 8, 9,
    10,
    32, 32, 32, 32, 42, 32, 34, 32, 39, 32, 130, 32, 131, 32, 32, 11, 14, 15,
    10,
    32, 32, 32, 32, 33, 32, 63, 32, 128, 32, 129, 32, 43, 32, 32, 16, 17, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 32, 92, 110, 10,
    20, 21, 32, 32, 32, 49, 32, 35, 32, 22, 10, 0,
  };
  oled_write_P(symbols_right, false);
}

// generated by Makefile
static void render_numeric_left(void) {
  static const char PROGMEM numeric_left[] = {
    1, 2, 3, 10,
    10,
    4, 5, 6, 32, 32, 32, 32, 104, 32, 121, 32, 112, 32, 101, 32, 114, 10,
    10,
    32, 16, 17, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 92, 115, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 35, 32, 49, 32, 32, 32, 20, 21, 0,
  };
  oled_write_P(numeric_left, false);
}

// generated by Makefile
static void render_numeric_right(void) {
  static const char PROGMEM numeric_right[] = {
    32, 32, 32, 32, 149, 32, 55, 32, 56, 32, 57, 32, 133, 32, 32, 7, 8, 9,
    10,
    32, 32, 32, 32, 42, 32, 52, 32, 53, 32, 54, 32, 96, 32, 32, 11, 14, 15,
    10,
    32, 32, 32, 32, 31, 32, 49, 32, 50, 32, 51, 32, 43, 32, 32, 16, 17, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 32, 92, 110, 10,
    20, 21, 32, 32, 32, 48, 32, 46, 32, 58, 10, 0,
  };
  oled_write_P(numeric_right, false);
}

/*
// generated by Makefile
static void render_func_left(void) {
  static const char PROGMEM func_left[] = {
    183, 184, 185, 176, 166, 162, 32, 32, 32, 160, 182, 178, 183, 187, 162, 160, 186, 185,
    10,
    167, 168, 169, 176, 179, 162, 160, 180, 162, 160, 181, 178, 176, 163, 162, 160, 164, 178,
    10,
    32, 16, 17, 214, 215, 216, 214, 215, 216, 32, 32, 32, 167, 171, 162, 160, 170, 169,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 160, 165, 162, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 128, 32, 131, 32, 32, 32, 20, 21, 0,
  };
  oled_write_P(func_left, false);
}
*/

// generated by Makefile
static void render_func_right(void) {
  static const char PROGMEM func_right[] = {
    135, 136, 43, 65, 78, 79, 65, 80, 81, 65, 82, 83, 144, 144, 151, 152, 43, 10,
    10,
    32, 32, 45, 65, 72, 73, 65, 74, 75, 65, 76, 77, 145, 145, 32, 32, 45, 10,
    10,
    32, 32, 137, 65, 66, 67, 65, 68, 69, 65, 70, 71, 144, 146, 32, 16, 17, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 176, 177, 178, 10,
    20, 21, 84, 85, 86, 84, 87, 88, 84, 89, 90, 10, 0,
  };
  oled_write_P(func_right, false);
}

// Not auto-generated
static void render_rgb_left(void) {
  const char rgb_left[] = {
    1, 2, 3, 32, 32, 115, 112, 101, 101, 100, 32, 48 + (rgblight_config.speed % 10), 32, 32, 104, 117, 101, 10,
    10,
    4, 5, 6, 32, 32, 109, 111, 100, 101, 32, 48 + rgblight_config.mode / 10, 48 + rgblight_config.mode % 10, 32, 32, 115, 97, 116, 10,
    10,
    32, 16, 17, 32, 32, 116, 111, 103, 103, 108, 101, 32, 32, 32, 118, 97, 108, 10,
    32, 44, 59, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 18, 19,
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 92, 115, 10,
    32, 32, 32, 32, 32, 32, 32, 32, 22, 32, 35, 32, 49, 32, 32, 32, 20, 21, 0,
  };
  oled_write(rgb_left, false);
}

/*
// generated by Makefile
static void render_rgb_right(void) {
  static const char PROGMEM rgb_right[] = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 109, 51, 32, 109, 50, 10,
    10,
    32, 32, 32, 32, 32, 32, 32, 109, 49, 32, 130, 32, 131, 10,
    10,
    32, 32, 32, 32, 32, 32, 32, 32, 128, 32, 129, 10,
    18, 19, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 45, 95, 10,
    32, 32, 92, 110, 10,
    20, 21, 32, 32, 32, 49, 32, 35, 32, 22, 10, 0,
  };
  oled_write_P(rgb_right, false);
}
*/

void oled_task_user(void) {
	if (!is_keyboard_master()) {
  oled_write_P(PSTR("layout wip"), false);
		return;
	}

	switch (get_highest_layer(layer_state)) {
    case _FUNC:
			if (show_slave) {
				render_func_right();
			} else {
        render_rgb_left();
			}
			break;
		case _HYPR:
			if (show_slave) {
        oled_write_P(PSTR("f: f1 -- f12\nh: hyper\nl: factorio\nm: mouse & macro\nn: numpad\nr: rgb\ns: sound\nz: qwerty\n"), false);
			} else {
        render_numeric_left(); // Hyper
			}
			break;
		case _NUMB:
			if (show_slave) {
        render_numeric_right();
			} else {
          oled_write_P(PSTR(" u: chrome\n e: term\n o: goland\n a: slack\n p: firefox\noe: finder\nae: sublime\naa: spotify\n"), false);
			}
			break;
		case _SYMB:
			if (show_slave) {
        render_symbols_right();
			} else {
        render_symbols_left();
			}
			break;
		case _FACTORIO:
      oled_write_P(PSTR("factorio\n\n\n\n\n\n\n\n"), false);
			break;
		case _QWERTY:
			if (show_slave) {
				render_qwerty_right();
			} else {
				render_qwerty_left();
			}
			break;
		case _SVORAK:
		default:
			if (show_slave) {
        render_svorak_right();
			} else {
        render_svorak_left();
			}
	}
  //oled_advance_page(true);
}

#endif
