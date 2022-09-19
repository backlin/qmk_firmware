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
#include "keymap_swedish.h"
#include "muse.h"

enum preonic_keycodes {
    // CLEVER DIACRITIC MARKS:
    // Default: Behaves like macro mark+space.
    // Shift: Behaves like mark alone.
    //
    // This simplifies entering them in terminal and code, at the expense of writing
    // French etc. (which I rarely do).
    CB_CIRC = SAFE_RANGE, // ^
    CB_TILD,              // ~
    CB_GRV,               // `

    GIT_CMP, // GoLand compare with branch (default: master, shifted: user chooses)

    SYM1, // Symbols and arrows
    SYM2, // Symbols and word step arrows
    LFN,
    RFN,

    QWERTY,
    CB_BOOT,

    MAG_LFT,
    MAG_RGT,
    MAG_TOP,
    MAG_BTM,
    MAG_1_3,
    MAG_2_3,
    MAG_3_3
};

// clang-format off
enum preonic_layers {
    _SVORAK,
    _QWERTY,
    _NUM,
    _SYM1,
    _SYM2,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Svorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Å  |   Ä  |   Ö  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -_  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  .:  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  ,;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Num |  1!  |  2"  |  3#  |  4€  |  5%  |  6&  |  7/  |  8(  |  9)  |  0=  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Fn  | Alt  | GUI  |    Space    |    Enter    | Sym1 | Sym2 |  Fn  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SVORAK] = LAYOUT_preonic_2x2u(
  KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CB_MINS,
  KC_LSFT, CB_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    CB_COMM,
  CB_NUM,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PPLS,
  KC_LCTL, LFN,     KC_LALT, KC_LGUI, KC_SPC,           KC_ENT,           SYM1,    SYM2,    RFN,     XXXXXXX
),
[_QWERTY] = LAYOUT_preonic_2x2u(
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CB_ARNG,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    CB_ODIA, CB_ADIA,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    CB_COMM, CB_DOT,  CB_MINS, KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |   /  |   \  |   [  |   ]  |   |  |      |   ?  |   !  | BKSP |  DEL |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   @  |      |   "  |   '  | LEFT |  Up  | RIGHT|
 * |------+------+------+------+------+------|------+------+------+------+      +------|
 * |      |   :  |   =  |   <  |   >  |   %  |      |   *  |   &  | Left   Down   Right| Allows quick ":=" (golang)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ^  |   $  |      |      |      |      |   #  |   +  |   `  |   ´  |   ~  | Allows quick "`+" and "+`" (golang)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM1] = LAYOUT_preonic_2x2u(
  _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_PIPE, _______, CB_QUES, KC_EXLM, BSP_WRD, DEL_WRD, KC_DEL,
  _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,   _______, CB_DQUO, CB_QUOT, LFT_WRD, KC_UP,   RGT_WRD,
  _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC, _______, CB_ASTR, CB_AMPR, KC_LEFT, KC_DOWN, KC_RGHT,
  _______, CB_CIRC,   A(KC_4), _______, _______, _______, _______, CB_HASH, KC_PPLS, CB_GRV,  CB_ACUT, CB_TILD,
  _______, _______,   _______, _______, _______,          _______,          _______, _______, _______, _______
),
[_SYM2] = LAYOUT_preonic_2x2u(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, BSP_LNE, DEL_LNE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, LFT_LNE, KC_PGUP, RGT_LNE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Show    To    Cont |Screen|      |   7  |   8  |   9  |   +  |      |
 * |------+------|                    | shot |------+------+------+------+------+------|
 * |      |      |  Out    In    Step |      |      |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   .  |   ,  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_preonic_2x2u(
  _______, _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, CB_COMM, KC_PSLS, _______,
  _______, _______, _______, _______, _______,          _______,          GIT_CMP, _______, _______, _______
),

/* Fn = Symbol with different arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Show    To    Cont |Screen| 1/3     1/3    1/3 | Prev   Play   Next |
 * |------+------|                    | shot |                    |                    |
 * | Boot |      |  Out    In    Step |      | 1/2   Center   1/2 | Vol-   Mute   Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Bri- |      | Bri+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Left screen | Right screen| Diff | Home | PgDn |  F12 |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_2x2u(
  _______, _______, GL_SHOW, GL_TO,   GL_CONT, CB_SCRF, MAG_1_3, MAG_2_3, MAG_3_3, KC_MPRV, KC_MPLY, KC_MNXT,
  CB_BOOT, _______, GL_OUT,  GL_IN,   GL_STEP, CB_SCRC, MAG_LFT, MAG_CTR, MAG_RGT, KC_VOLD, KC_MUTE, CB_VOLU,
  _______, _______, QWERTY,  _______, _______, _______, _______, _______, _______, KC_BRID, XXXXXXX, KC_BRIU,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, LCAG(KC_LEFT),    LCAG(KC_RGHT),    GIT_CMP, _______, _______, KC_F12
)

};
// clang-format on

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

bool    sym1down;
uint8_t fn_down;
#define LFN_DOWN 1
#define RFN_DOWN 2

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

            case SYM1:
                sym1down = true;
                layer_on(_SYM1);
                break;
            case SYM2:
                layer_on(_SYM1);
                layer_on(_SYM2);
                break;
            case LFN:
                fn_down |= LFN_DOWN;
                layer_on(_FN);
                break;
            case RFN:
                fn_down |= RFN_DOWN;
                layer_on(_FN);
                break;
            case QWERTY:
                if (fn_down == (LFN_DOWN | RFN_DOWN)) {
                    layer_on(_QWERTY);
                    fn_down = 0;
                }
                break;
            case CB_BOOT:
                if (fn_down == (LFN_DOWN | RFN_DOWN)) {
                    reset_keyboard();
                }
                return false;

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
            case SYM1:
                sym1down = false;
                if (!layer_state_is(_SYM2)) {
                    layer_off(_SYM1);
                }
                break;
            case SYM2:
                if (!sym1down) {
                    layer_off(_SYM1);
                }
                layer_off(_SYM2);
                break;
            case LFN:
                fn_down &= ~LFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                break;
            case RFN:
                fn_down &= ~RFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                break;

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
