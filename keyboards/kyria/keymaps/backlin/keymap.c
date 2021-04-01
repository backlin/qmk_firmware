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

#define FREE XXXXXXX
#define GIT_CMP HYPR(KC_G) // GoLand compare with branch

// Print screen (Mac)
#define CB_SCRC S(C(G(KC_4))) // Region to clipboard
#define CB_SCRF S(G(KC_4))    // Region to file

// Small volume increment (Mac)
#define CB_VOLU LSA(KC_VOLU)
#define CB_VOLD LSA(KC_VOLD)

// Magnet center
#define MAG_CTR LCA(KC_SPC)

// Shift hack to enable left shift to behave as expected when right shift (arrow 2) is held
#define SFT_HACK LSFT_T(S(SE_COMM))

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
    _SVORAK = 0, // Layout
    _ARW2,
    _ARW1,
    _ARW3,
    _NUMB,
    _FUNC,
		_MAGN
};

enum custom_keycodes {
    CB_CIRC = SAFE_RANGE,
    CB_TILD,
    CB_GRV, // Backtick without hitting space

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
 * |LShift|  . : |   Q  |   J  |   K  |   X  |      |Layout|  | Hyper|      |   B  |   M  |   W  |   V  |   Z  |Arrow2|
 * |  , ; |      |      |      |      |      | Space|      |  |      | Enter|      |      |      |      |      |  - _ |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      | LAlt | LCmd | Numb |      | Ctrl |  | Ctrl |      |Arrow1| RCmd | RAlt |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
        KC_TAB,          SE_AA,  SE_AE, SE_OSLH, KC_P, KC_Y,                                           KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
        KC_ESC,          KC_A,   KC_O,  KC_E,    KC_U, KC_I,                                           KC_D, KC_H, KC_T, KC_N, KC_S, KC_DEL,
        LSFT_T(SE_COMM), SE_DOT, KC_Q,  KC_J,    KC_K, KC_X,   XXXXXXX, FREE,      GIT_CMP, XXXXXXX,   KC_B, KC_M, KC_W, KC_V, KC_Z, LSFT_T(SE_MINS),
                                    KC_LCTL, KC_LALT, KC_LCMD, KC_SPC,  MO(_NUMB), KC_RCTL, KC_ENT, MO(_ARW3), MO(_ARW2), MO(_ARW1)
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
/*
    [_QWERTY] = LAYOUT(
      _______, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I,   KC_O,    KC_P,    SE_AA,
      _______, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K,   KC_L,    SE_OSLH, SE_AE,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, _______, _______, XXXXXXX, KC_N, KC_M, SE_DOT, KC_BSPC, KC_DEL,  _______,
                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
*/

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
/*
    [_FACTORIO] = LAYOUT(
        _______, KC_Q, CB_2222, KC_PMNS, KC_PPLS, KC_LALT,                                      KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, KC_A, KC_W,    KC_E,    KC_R,    KC_T,                                         KC_1, KC_2, KC_3, KC_4, KC_5, _______,
        _______, KC_Z, KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX, G(KC_C), _______, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                               A(KC_B), A(KC_D), KC_LCTL, _______, G(KC_X), _______, _______, _______, _______, _______
    ),
*/

/* 
 * Symbol and arrow layers
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   /  |   \  |   [  |   ]  |   |  |                              |   !  |   ?  |   ´  |   '  |   ~  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |                              |   *  |   "  |   `  |  up  | right|      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |   =  |   <  |   >  |   %  |      |      |  |      |      |   &  |   #  | left | down |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      | Func |  |Magnet|      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_ARW1] = LAYOUT( // Symbols + arrows
        _______, SE_SLSH,     SE_BSLS_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                   KC_EXLM, SE_QUES, SE_ACUT, SE_QUOT, CB_TILD, _______,
        _______, SE_LCBR_MAC, SE_RCBR_MAC, SE_LPRN,     SE_RPRN,     SE_AT,                                         SE_ASTR, SE_DQUO, CB_GRV,  KC_UP,   KC_RGHT, _______,
        _______, S(SE_DOT),   SE_EQL,      SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, _______, _______,   XXXXXXX, SE_AMPR, SE_HASH, KC_LEFT, KC_DOWN, KC_PPLS, _______,
                                                   _______, _______, _______, _______, _______, MO(_MAGN), _______, _______, _______, _______
    ),
    [_ARW2] = LAYOUT( // Symbols + arrows
        S(KC_TAB),  S(SE_AA),  S(SE_AE), S(SE_OSLH), S(KC_P), S(KC_Y),                                       S(KC_F), S(KC_G), S(KC_C),    S(KC_R), S(KC_L),    A(KC_BSPC),
        S(KC_ESC),  S(KC_A),   S(KC_O),  S(KC_E),    S(KC_U), S(KC_I),                                       S(KC_D), S(KC_H), S(KC_T),    KC_UP,   A(KC_RGHT), A(KC_DEL),
        S(SE_COMM), S(SE_DOT), S(KC_Q),  S(KC_J),    S(KC_K), S(KC_X), XXXXXXX, _______, _______,   XXXXXXX, S(KC_B), S(KC_M), A(KC_LEFT), KC_DOWN, S(KC_Z),    _______,
                                            _______, _______, _______, _______, _______, MO(_MAGN), _______, _______, _______, _______
    ),
    [_ARW3] = LAYOUT(
        _______,  KC_BTN1, KC_BTN3, _______, CB_SCRF, _______,                                         _______, _______, _______,    _______, _______,    G(KC_BSPC),
        _______,  KC_MS_L, KC_MS_U, KC_BTN2, CB_SCRC, _______,                                         _______, _______, _______,    KC_PGUP, G(KC_RGHT), C(KC_K),
        SFT_HACK, _______, KC_MS_D, KC_MS_R, _______, _______, XXXXXXX, _______,   _______, XXXXXXX,   _______, _______, G(KC_LEFT), KC_PGDN, _______,    _______,
                                             _______, _______, _______, TO(_ARW3), _______, MO(_MAGN), _______, _______, _______, _______
    ),
    [_MAGN] = LAYOUT(
        _______,   _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MPLY,                                       _______, _______, _______, MAG_2_3, MAG_3_3, _______,
        TG(_MAGN), _______, KC_MUTE, CB_VOLD, CB_VOLU, KC_MUTE,                                       _______, MAG_CTR, MAG_1_3, MAG_TOP, MAG_RGT, _______,
        _______,   _______, _______, KC_BRID, KC_BRIU, _______, XXXXXXX,   _______, _______, XXXXXXX, _______, _______, MAG_LFT, MAG_BTM, _______, _______,
                                     _______, _______, _______, TO(_MAGN), _______, _______, _______, _______, _______, _______
    ),

/* 
 * Launch apps and Numpad
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |   °  |   7  |   8  |   9  |   ^  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      |   Symbols   |      |      |                              |   *  |   4  |   5  |   6  |   $  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   :  |      |      |      |      |      |      |  |      |      |   /  |   1  |   2  |   3  |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |   0  |   .  |   :  |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_NUMB] = LAYOUT(
        _______,   SE_SLSH,     SE_BSLS_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                       CB_DGRE, KC_7, KC_8, KC_9, CB_CIRC, _______,
				TG(_NUMB), SE_LCBR_MAC, SE_RCBR_MAC, SE_LPRN,     SE_RPRN,     SE_AT,                                             SE_ASTR, KC_4, KC_5, KC_6, SE_DLR,  _______,
        _______,   S(SE_DOT),   SE_EQL,      SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, _______,   _______,   XXXXXXX,   SE_SLSH, KC_1, KC_2, KC_3, KC_PPLS, _______,
                                                     _______, _______, _______, _______, MO(_FUNC), _______, A(KC_ENT), KC_0, SE_DOT, S(SE_DOT)
    ),
    [_FUNC] = LAYOUT(
        _______,   RGB_SPD,  RGB_SPI, RGB_HUD, RGB_HUI, _______,                                       _______, KC_F7, KC_F8, KC_F9, _______, _______, 
        TG(_FUNC), RGB_RMOD, RGB_MOD, RGB_SAD, RGB_SAI, _______,                                       _______, KC_F4, KC_F5, KC_F6, _______, _______, 
        _______,   RGB_TOG,  RGB_TOG, RGB_VAD, RGB_VAI, _______, XXXXXXX, _______, _______, XXXXXXX,   _______, KC_F1, KC_F2, KC_F3, _______, _______, 
                                      _______, _______, _______, _______, _______, _______, TO(_FUNC), KC_F10, KC_F11, KC_F12
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
	set_mods(MOD_MASK_CTRL | MOD_MASK_ALT);

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
    case 12: tap_code(KC_LEFT); tap_code(KC_SPC); break; // Center 1/2 (top & bottom)
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
  //set_single_persistent_default_layer(_SVORAK);
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

            case KC_LCTRL:
            case KC_LALT:
							show_slave = false;
							break;
            case KC_RCTRL:
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

/*
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _ARW1, _ARW2, _ARW3);
}
*/

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

/*
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
*/

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
    oled_write_P(PSTR("rgb+f1:12   hyper\n\nnum  sound+magnet\n"), false);
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
		case _NUMB:
			if (show_slave) {
        render_numeric_right();
			} else {
        render_symbols_left();
			}
			break;
		case _ARW1:
		case _ARW2:
		case _ARW3:
			if (show_slave) {
        render_symbols_right();
			} else {
        render_symbols_left();
			}
			break;
    case _MAGN:
      oled_write_P(PSTR("sound & magnet\n\n\n\n\n\n\n\n"), false);
			break;
		case _SVORAK:
		default:
			if (show_slave) {
        render_svorak_right();
			} else {
        render_svorak_left();
			}
	}
}

#endif
