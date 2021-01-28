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
// Sticky layers
#define NUMB_ST TG(_NUMB_STICK)
#define HYPE_ST TG(_HYPER_STICK)
#define FUNC_ST TG(_FUNC_STICK)
#define RGB_ST  TG(_RGB_STICK)

// Magnet shortcuts
#define MAG_1_3 LCA(KC_D)
#define MAG_2_3 LCA(KC_F)
#define MAG_3_3 LCA(KC_G)
#define MAG_123 LCA(KC_E)
#define MAG_233 LCA(KC_T)
#define MAG_LFT LCA(KC_LEFT)
#define MAG_RGT LCA(KC_RGHT)
#define MAG_CTR LCA(KC_SPC)
#define MAG_FUL LCA(KC_ENT)
#define MAG_TOP LCA(KC_UP)
#define MAG_BTM LCA(KC_DOWN)
#define MAG_T_L LCA(KC_U)
#define MAG_T_R LCA(KC_I)
#define MAG_B_L LCA(KC_J)
#define MAG_B_R LCA(KC_K)
#define MAG_S_L LCAG(KC_LEFT)
#define MAG_S_R LCAG(KC_RGHT)
#define DSK_LFT C(KC_LEFT)
#define DSK_RGT C(KC_RGHT)

// Print screen (Mac)
#define CB_SCRC S(C(G(KC_4))) // Region to clipboard
#define CB_SCRF S(G(KC_4))    // Region to file

// Small volume increment (Mac)
#define CB_VOLU LSA(KC_VOLU)
#define CB_VOLD LSA(KC_VOLD)

// Rarely used symbols (Mac)
#define CB_PRGF 192
#define CB_DGRE S(CB_PRGF)
#define CB_MICR A(KC_Y)
#define CB_MDDT A(KC_Q)
#define CB_APRX A(KC_X)

#define MOD_MASK_RSHIFT MOD_BIT(KC_RSHIFT)

enum layers {
    _SVORAK = 0,
    _QWERTY,
    _FACTORIO,
    _NUMB_STICK,
		_HYPER_STICK,
    _FUNC_STICK,
    _RGB_STICK,
    _SYMB,
    _SYMB2,
    _SYMB3,
    _NUMB,
		_HYPER,
    _FUNC
};

enum custom_keycodes {
		CHROME = SAFE_RANGE,
    FINDER,
    FIREFOX,
    GOLAND,
		SLACK,
    SPOTIFY,
    SUBLIME,
    TERM,

    CB_BSPC,
    CB_DEL,
    CB_UP,
    CB_DOWN,
    CB_LEFT,
    CB_RGHT,

    CB_CIRC,
    CB_TILD,
    CB_GRV, // Backtick without hitting space
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
 * |LShift| LCtrl|   Q  |   J  |   K  |   X  |      |  Alt |  |  Alt |      |   B  |   M  |   W  |   V  |   Z  |RShift|
 * |  , ; |   .  |      |      |      |      | Space|      |  |      | Enter|      |      |      |      |      |  - _ |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      | Ctrl | Numb | Symb |      | Ctrl |  | Ctrl |      | Symb | Hyper| Ctrl |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SVORAK] = LAYOUT(
      KC_TAB,          SE_AA,          SE_AE, SE_OSLH, KC_P, KC_Y,                                         KC_F,  KC_G,  KC_C,  KC_R,  KC_L,  KC_BSPC,
      KC_ESC,          KC_A,           KC_O,  KC_E,    KC_U, KC_I,                                         KC_D,  KC_H,  KC_T,  KC_N,  KC_S,  KC_DEL,
      LSFT_T(SE_COMM), LCTL_T(SE_DOT), KC_Q,  KC_J,    KC_K, KC_X,   XXXXXXX, KC_LALT, KC_RALT, XXXXXXX,   KC_B,  KC_M,  KC_W,  KC_V,  KC_Z,  RSFT_T(SE_MINS),
                                          KC_LCTL, NUMBERS, SYMBOLS, KC_SPC,  KC_LCMD, KC_RCMD, KC_ENT, SYMBOL2, HYPER, KC_RCTL
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
 * Symbol Layer
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   /  |   \  |   [  |   ]  |   |  |                              |   #  |   &  |   $  |   ^  |   ~  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |                              |   *  |   "  |   '  |  Up  | Right|      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   =  |   ≈  |   <  |   >  |   %  |      |      |  | PgUp |      |   !  |   ?  | Left | Down |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |PgDown|      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SYMB] = LAYOUT(
        _______, SE_SLSH,     SE_BSLS_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                 SE_HASH, SE_AMPR, SE_DLR,  SE_CIRC, SE_TILD, _______,
        _______, SE_LCBR_MAC, SE_RCBR_MAC, SE_LPRN,     SE_RPRN,     SE_AT,                                       SE_ASTR, SE_DQUO, SE_QUOT, KC_UP,   KC_RGHT, _______,
        _______, SE_EQL,      CB_APRX,     SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, KC_EXLM, SE_QUES, KC_LEFT, KC_DOWN, KC_PPLS, _______,
                                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYMB2] = LAYOUT( // Same appart from arrows, backpace, and delete
        _______, SE_SLSH,        SE_BSLS_MAC, SE_LBRC,     SE_RBRC,     SE_PIPE_MAC,                                 SE_HASH, SE_AMPR, SE_DLR,     CB_CIRC, CB_TILD,    A(KC_BSPC),
        _______, SE_LCBR_MAC,    SE_RCBR_MAC, SE_LPRN,     SE_RPRN,     SE_AT,                                       SE_ASTR, SE_DQUO, SE_QUOT,    KC_UP,   A(KC_RGHT), A(KC_DEL),
        _______, LCTL_T(SE_EQL), CB_APRX,     SE_LESS_MAC, SE_GRTR_MAC, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, KC_EXLM, SE_QUES, A(KC_LEFT), KC_DOWN, KC_PPLS, SYMBOL3,
                                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYMB3] = LAYOUT( // Same appart from arrows, backpace, and delete
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______,    _______, _______,    G(KC_BSPC),
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______,    KC_PGUP, G(KC_RGHT), C(KC_K),
        _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, G(KC_LEFT), KC_PGDN, _______,    _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Launch apps and Numpad
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |Spotfy|Sublim|Finder|FireFx|      |                              |   °  |   7  |   8  |   9  |   ´  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Off | Slack|GoLand| Term |Chrome|      |                              |   *  |   4  |   5  |   6  |   `  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |   /  |   1  |   2  |   3  |   +  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |   0  |   .  |   :  |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_NUMB] = LAYOUT(
        _______, SPOTIFY, SUBLIME, FINDER,  FIREFOX, XXXXXXX,                                         CB_DGRE, KC_7, KC_8, KC_9, SE_ACUT, _______,
				_______, SLACK,   GOLAND,  TERM,    CHROME,  XXXXXXX,                                         SE_ASTR, KC_4, KC_5, KC_6, CB_GRV,  _______,
        _______, XXXXXXX, XXXXXXX, CB_SCRF, CB_SCRC, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX,   SE_SLSH, KC_1, KC_2, KC_3, KC_PPLS, _______,
                                     _______, _______, _______, _______, _______, _______, _______, KC_0, SE_DOT, S(SE_DOT)
    ),
    [_NUMB_STICK] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         CB_DGRE, KC_7, KC_8, KC_9, SE_ACUT, _______,
        NUMB_ST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         SE_ASTR, KC_4, KC_5, KC_6, CB_GRV,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX,   SE_SLSH, KC_1, KC_2, KC_3, KC_PPLS, _______,
                                     _______, _______, _______, _______, _______, _______, _______, KC_0, SE_DOT, S(SE_DOT)
    ),


/* 
 * Hyper and Sticky
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |                                  |                              |  Fx  |      |      |  RGB |Factor|      |
 * |------+                                  |                              |------+------+------+------+------+------|
 * |  Off |              Hyper               |                              |      | Hyper|      |Numpad| Sound|      |
 * |------+                                  +-------------.  ,-------------+------+------+------+------+------+------|
 * |      |                                  |      |      |  |      |      |      | Mouse|      |      |Qwerty|      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_HYPER] = LAYOUT(
        _______, HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E),                                     FUNC_ST, XXXXXXX, XXXXXXX, RGB_ST,  TG(_FACTORIO), _______,
        _______, HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), HYPR(KC_J),                                     XXXXXXX, HYPE_ST, XXXXXXX, NUMB_ST, FUNC_ST,       _______,
        _______, HYPR(KC_K), HYPR(KC_L), HYPR(KC_M), HYPR(KC_N), HYPR(KC_O), XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, RGB_ST,  XXXXXXX, XXXXXXX, TG(_QWERTY),   _______,
                                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_HYPER_STICK] = LAYOUT(
        _______, HYPR(KC_A), HYPR(KC_B), HYPR(KC_C), HYPR(KC_D), HYPR(KC_E),                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        HYPE_ST, HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_I), HYPR(KC_J),                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, HYPR(KC_K), HYPR(KC_L), HYPR(KC_M), HYPR(KC_N), HYPR(KC_O), XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* 
 * Magnet and function
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      | 12/3 | 12/3 | 23/3 | TopL | TopR |                              | Vol+ |  F7  |  F8  |  F9  |PlyNxt|Brght+|
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Off |  1/3 |  2/3 |  3/3 | Left | Rght |                              | Vol- |  F4  |  F5  |  F6  |PlyPrv|Brght-|
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |  no  |Print-|Screen| BtmL | BtmR |      |  Top |  |      |      | Mute |  F1  |  F2  |  F3  |PlyPau|      |
 * `--------------------+------+------+------+Center+------|  |------+ Full +------+------+------+--------------------'
 *                      |      |      |      |      |Bottom|  |      |      |  F10 |  F11 |  F12 |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
        _______, MAG_1_3, MAG_2_3, CB_SCRF, MAG_T_L, MAG_T_R,                                         CB_VOLU, KC_F7, KC_F8, KC_F9, KC_MNXT, KC_BRIU, 
        _______, MAG_LFT, MAG_TOP, MAG_3_3, MAG_123, MAG_233,                                         CB_VOLD, KC_F4, KC_F5, KC_F6, KC_MPRV, KC_BRID, 
        _______, CB_SCRC, MAG_BTM, MAG_RGT, MAG_B_L, MAG_B_R,   XXXXXXX, _______, _______, XXXXXXX,   KC_MUTE, KC_F1, KC_F2, KC_F3, KC_MPLY, _______, 
                                     _______, _______, _______, MAG_CTR, _______, _______, MAG_FUL, KC_F10, KC_F11, KC_F12
    ),
    [_FUNC_STICK] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         CB_VOLU, KC_F7, KC_F8, KC_F9, KC_MNXT, KC_BRIU, 
        FUNC_ST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         CB_VOLD, KC_F4, KC_F5, KC_F6, KC_MPRV, KC_BRID, 
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX,   KC_MUTE, KC_F1, KC_F2, KC_F3, KC_MPLY, _______, 
                                     _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12
    ),

/* 
 * RGB and mouse
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  no  | Mode+|Speed+| Hue+ | Sat+ | Val+ |                              |  no  |  no  |Repeat|Mouse3|Mouse2|  no  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Off | Mode-|Speed-| Hue- | Sat- | Val- |                              |  no  |  no  |Mouse1| MUp  |MRight|  no  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |  no  |  no  |  no  |  no  |  no  |  no  |      |      |  |      |      |  no  |  no  | MLeft| Mdown|  no  |      |
 * `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_RGB_STICK] = LAYOUT(
        _______, RGB_SPD,  RGB_SPI, RGB_HUD, RGB_HUI, XXXXXXX,                                         XXXXXXX, XXXXXXX, CB_2222, KC_BTN3, KC_BTN2, _______,
        RGB_ST,  RGB_RMOD, RGB_MOD, RGB_SAD, RGB_SAI, XXXXXXX,                                         XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_MS_R, _______,
        _______, RGB_TOG,  RGB_TOG, RGB_VAD, RGB_VAI, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, XXXXXXX, _______,
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

bool show_slave;

//char intro_page; // NOT IN USE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		if (record->event.pressed) {
				// when key is pressed
				switch (keycode) {
						case CHROME:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "chrome\n" ); break;
						case FINDER:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "finder\n" ); break;
						case FIREFOX: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "firefox\n"); break;
						case GOLAND:  SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "goland\n" ); break;
						case SLACK:   SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "slack\n" ); break;
						case SPOTIFY: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "spotify\n"); break;
						case SUBLIME: SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "sublime\n"); break;
						case TERM:    SEND_STRING( SS_LCMD(" ") SS_DELAY(100) "term\n"   ); break;

            case CB_UP:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                tap_code(KC_PGUP);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                tap_code(KC_UP);
              }
              break;
            case CB_DOWN:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                tap_code(KC_PGDN);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                tap_code(KC_DOWN);
              }
              break;
            case CB_LEFT:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                register_code(KC_LCMD);
                tap_code(KC_LEFT);
                unregister_code(KC_LCMD);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                unregister_code(KC_LALT);
              }
              break;
            case CB_RGHT:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                register_code(KC_LCMD);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCMD);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                register_code(KC_LALT);
                tap_code(KC_RIGHT);
                unregister_code(KC_LALT);
              }
              break;
            case CB_BSPC:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                register_code(KC_LCMD);
                tap_code(KC_BSPC);
                unregister_code(KC_LCMD);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                register_code(KC_LALT);
                tap_code(KC_BSPC);
                unregister_code(KC_LALT);
              }
              break;
            case CB_DEL:
              if (get_mods() & MOD_MASK_RSHIFT) {
								del_mods(MOD_MASK_RSHIFT);
                register_code(KC_LCTL);
                tap_code(KC_K);
                unregister_code(KC_LCTL);
								add_mods(MOD_MASK_RSHIFT);
              } else {
                register_code(KC_LALT);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
              }
              break;


            case CB_CIRC:
              register_code(KC_LSFT);
              tap_code(KC_RBRC);
              unregister_code(KC_LSFT);
              tap_code(KC_SPC);
              break;
            case CB_TILD:
              register_code(KC_RALT);
              tap_code(KC_RBRC);
              unregister_code(KC_RALT);
              tap_code(KC_SPC);
              break;
            case CB_GRV:
              register_code(KC_LSFT);
              tap_code(KC_EQL);
              unregister_code(KC_LSFT);
              tap_code(KC_SPC);
              break;

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

            //case KC_ESC: // NOT IN USE
						//	if (intro_page < 255) intro_page = -1;
						//	break;
            case KC_LGUI:
							show_slave = false;
							//if (intro_page < 255) intro_page = intro_page + 1; // NOT IN USE
							break;
            case KC_RGUI:
							show_slave = true;
							break;
						case KC_LALT:
							//if (intro_page < 255 && intro_page > 0) intro_page = intro_page - 1; // NOT IN USE
							break;
				}
		} // else: when Key is released
    return true;
};


layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t mask12a = (1UL << _SYMB) | (1UL << _NUMB);
  layer_state_t mask12b = (1UL << _SYMB2) | (1UL << _HYPER);
  layer_state_t mask3  = 1UL << _FUNC;
  return ((state & mask12a) == mask12a) || ((state & mask12b) == mask12b)
    ? (state | mask3)
    : (state & ~mask3);
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

/* NOT IN USE
bool oled_intro_page(void) {
  switch (intro_page) {
    case 0:
      oled_write_P(PSTR("intoduction\n\nchange page\nusing left\nthumb keys.\n\n\n\n"), false);
      break;
    case 1:
      oled_write_P(PSTR("layers (1/3)\n\nchange with\nwhite keys.\ndisplay shows\ncurrent layout\n(cmd switches\ndisplayed side).\n"), false);
      break;
    case 2:
      oled_write_P(PSTR("layers (2/3)\n\nbase: letters\n\ninner: symbols\n  & arrow keys\nright side uses\narrows+alt\n"), false);
      break;
    case 3:
      oled_write_P(PSTR("layers (3/3)\n\nleft outer:\n  apps | numpad\n\nright outer:\n  hyper |\n  sticky & conf\n"), false);
      break;
    case 4:
      oled_write_P(PSTR("hyper =\n  ctrl+shift+cmd\n  see qmk docs\n\nsticky:\n  disable sticky\n  layer with esc\n\n"), false);
      break;
    case 5:
      oled_write_P(PSTR("magnet:\n  https://magnet\n  .crowdcafe.com/\n\ncursor: mouse\n\n\n\n"), false);
      break;
		case 255:
			return false;
    default:
      intro_page = 5;
  }
	return true;
}
*/

void oled_task_user(void) {
	if (!is_keyboard_master()) {
  oled_write_P(PSTR("magnet, func\n\napps, numpad\n  hyper & sticky\n\nbrack,symb,arrow\n\nletters"), false);
		return;
	}

  /* NOT IN USE
	if (oled_intro_page()) {
		return;
	}
  */

	switch (get_highest_layer(layer_state)) {
		case _RGB_STICK:
			if (show_slave) {
				render_rgb_right();
			} else {
				render_rgb_left();
			}
			break;
    case _FUNC:
			if (show_slave) {
				render_func_right();
			} else {
        render_func_left();
			}
			break;
    case _FUNC_STICK:
      render_func_right();
			break;
		case _HYPER:
			if (show_slave) {
        oled_write_P(PSTR("f: f1 -- f12\nh: hyper\nl: factorio\nm: mouse & macro\nn: numpad\nr: rgb\ns: sound\nz: qwerty\n"), false);
			} else {
        render_numeric_left(); // Hyper
			}
			break;
		case _HYPER_STICK:
      render_numeric_left(); // Hyper
			break;
		case _NUMB:
			if (show_slave) {
        render_numeric_right();
			} else {
          oled_write_P(PSTR(" u: chrome\n e: term\n o: goland\n a: slack\n p: firefox\noe: finder\nae: sublime\naa: spotify\n"), false);
			}
			break;
		case _NUMB_STICK:
      render_numeric_right();
			break;
		case _SYMB:
		case _SYMB2:
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
