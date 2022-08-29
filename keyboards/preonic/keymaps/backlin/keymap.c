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

#include QMK_KEYBOARD_H
//#include "muse.h"

enum preonic_layers {
  _SVORAK,
  _SYMBOL,
  _FN
};

enum preonic_keycodes {
    // CLEVER DIACRITIC MARKS:
    // Default: Behaves like macro mark+space.
    // Shift: Behaves like mark alone.
    //
    // This simplifies entering them in terminal and code, at the expense of writing
    // French etc. (which I rarely do).
    CB_CIRC = SAFE_RANGE,  // ^
    CB_TILD,               // ~
    CB_GRV,                // `

    GIT_CMP,  // GoLand compare with branch (default: master, shifted: user chooses)

    MAG_LFT,
    MAG_RGT,
    MAG_TOP,
    MAG_BTM,
    MAG_1_3,
    MAG_2_3,
    MAG_3_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Svorak
 * ,-----------------------------------------------------------------------------------.
 * |   1! |  2"  |  3#  |  4€  |  5%  |  6&  |  7/  |  8(  |  9)  |  0=  |  Del | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Å  |   Ä  |   Ö  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  ,;  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -_  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |  Up  |  .:  | // Z moved to left
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl | Alt  | GUI  |    Space    |    Enter    | Symb | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_SVORAK] = LAYOUT_preonic_2x2u(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  KC_BSPC,
  KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    CB_COMM,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
  KC_LSFT, KC_Z,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_UP,   CB_DOT,
  MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,           KC_ENT,       TT(_SYMBOL), KC_LEFT, KC_DOWN, KC_RGHT
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   /  |   \  |   [  |   ]  |   |  |   !  |   ?  |   `  |   ´  |   $  |   +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |   *  |   "  |   '  |   ~  |   ^  |  -_  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   <  |   >  |   :  |   =  |   %  |   #  |   &  |   €  |  Out | Step |  In  |  "<>:=" simplifies <=, >=, :=
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      | Show |  To  | Cont |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_2x2u(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, CB_SLSH, CB_BSLS, CB_LBRC,   CB_RBRC, CB_PIPE, KC_EXLM, CB_QUES, CB_GRV,  CB_ACUT, A(KC_4), KC_PPLS,
  _______, CB_LCBR, CB_RCBR, CB_LPRN,   CB_RPRN, CB_AT,   CB_ASTR, CB_DQUO, CB_QUOT, CB_TILD, CB_CIRC, CB_MINS,
  _______, CB_LABK, CB_RABK, S(CB_DOT), CB_EQL,  KC_PERC, CB_HASH, CB_AMPR, S(KC_4), GL_OUT,  GL_STEP, GL_IN,
  _______, _______, _______, _______,   _______,          _______,          _______, GL_SHOW, GL_TO,   GL_CONT
),

/* Fn = Symbol with different arrows
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |1/3   |  1/3 |   1/3| Vol- | Mute | Vol+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Boot |      |      |      |      |      |Center|  Top | Full | Prev | Play | Next |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |1/2   |Bottom|   1/2| Bri- | PgUp | Bri+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Diff | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_2x2u(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAG_1_3, MAG_2_3, MAG_3_3, CB_VOLD, KC_MUTE, CB_VOLU,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAG_CTR, MAG_TOP, MAG_FUL, KC_VOLD, KC_MPLY, KC_MNXT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAG_LFT, MAG_BTM, MAG_RGT, KC_BRID, KC_PGUP, KC_BRIU,
  _______, _______, _______, _______, XXXXXXX,          XXXXXXX,          GIT_CMP, KC_HOME, KC_PGDN, KC_END
)

};

// Magnet ----------------------------------------------------------------------

void process_magnet(uint8_t state) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL | MOD_MASK_ALT);

    switch (state) {
        // clang-format off
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
            // clang-format on
    }

    set_mods(original_mods);
    return;
}

uint8_t magnet_state;

// Process input ---------------------------------------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            // Note: These are implemented as exact stroke sequences and not using using
            // set_mod_mask because the latter does not produce the desired result.
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

            case GIT_CMP: {
                uint8_t original_mods = get_mods();
                set_mods(MOD_MASK_CSAG);
                tap_code(KC_G);
                if (!(original_mods & MOD_MASK_SHIFT)) {
                    set_mods(0);
                    SEND_STRING(SS_DELAY(300) "master" SS_TAP(X_ENT));
                }
                set_mods(original_mods);
                break;
            }

            // clang-format off
            case MAG_LFT: magnet_state |=  1; break;
            case MAG_RGT: magnet_state |=  2; break;
            case MAG_TOP: magnet_state |=  4; break;
            case MAG_BTM: magnet_state |=  8; break;
            case MAG_1_3: magnet_state |= 16; break;
            case MAG_2_3: magnet_state |= 32; break;
            case MAG_3_3: magnet_state |= 64; break;
                // clang-format on
        }
    } else {
        switch (keycode) {
            case MAG_LFT:
            case MAG_RGT:
            case MAG_TOP:
            case MAG_BTM:
            case MAG_1_3:
            case MAG_2_3:
            case MAG_3_3:
                process_magnet(magnet_state);
                magnet_state = 0;
                break;
        }
    }
    return true;
};

