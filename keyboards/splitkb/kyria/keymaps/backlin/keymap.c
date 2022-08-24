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

#define NUMBERS MO(_NUMB)  // Aliased to simplify handling in macros

enum layers { _SVORAK = 0, _GOLAND, _ARW1, _ARW2, _ARW3, _NUMB, _FUNC, _MAGN };

enum custom_keycodes {
    // CLEVER DIACRITIC MARKS:
    // Default: Behaves like macro mark+space.
    // Shift: Behaves like mark alone.
    //
    // This simplifies entering them in terminal and code, at the expense of writing
    // French etc. (which I rarely do).
    CB_CIRC = SAFE_RANGE,  // ^
    CB_TILD,               // ~
    CB_GRV,                // `

    // CLEVER SPACE:
    // Default: Behaves like normal space.
    // If first stoke after activating symbol layer: Behaves like underescore.
    //
    // This simplifies entering snake case without adding underscores after symbols.
    // If the spacebar was always mapped to underscore in the symbol layer you'd often
    // end up with things like
    //    myVariable =_42   instead of   myVariable = 42
    //    blah blah:_blah   instead of   blah blah: blah
    SPACE,
    SYMBOL1,
    SYMBOL2,

    GOLAND1,  // GoLand debugger shortcuts
    GOLAND2,
    GIT_CMP,  // GoLand compare with branch (default: master, shifted: user chooses)
    REPLAY,   // Replay eager macro

    MAG_LFT,
    MAG_RGT,
    MAG_TOP,
    MAG_BTM,
    MAG_1_3,
    MAG_2_3,
    MAG_3_3
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//
// Base layer: SVORAK (Swedish Dvorak)
//
// ,-----------------------------------------.                              ,-----------------------------------------.
// |  Tab |  ,Å  |  ^Ä  |  $Ö  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  | Bksp |
// |------+------+------+------+------+------|                              |------+------+------+------+------+------|
// |  Esc |  AÅ  |  OÄ  |  EÖ  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  Del |
// |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
// |LShift|  . : |   Q  |   J  |   K  |   X  |      |Replay|  |  Git |      |   B  |   M  |   W  |   V  |   Z  |  - _ |
// `--------------------+------+------+------+ Space+------|  |------+ Enter+------+------+------+--------------------'
//                      | Ctrl |  Alt |  Cmd |   _- |Numpad|  | Func |      |Arrow1|Arrow2|Arrow3|
//                      `----------------------------------'  `----------------------------------'
//
    [_SVORAK] = LAYOUT(
        KC_TAB,  CB_ARNG, CB_ADIA, CB_ODIA, KC_P, KC_Y,                                           KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, // Opposite dir is KC_DEL
        KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U, KC_I,                                            KC_D, KC_H, KC_T, KC_N, KC_S, KC_DEL,
        KC_LSFT, CB_DOT,  KC_Q,    KC_J,   KC_K, KC_X,   XXXXXXX,  REPLAY,  GIT_CMP,   XXXXXXX,   KC_B, KC_M, KC_W, KC_V, KC_Z, CB_COMM,
                              KC_LCTL, KC_LALT, KC_LCMD, KC_SPACE, NUMBERS, MO(_FUNC), KC_ENT, SYMBOL1, SYMBOL2, MO(_ARW3)
    ),
    [_GOLAND] = LAYOUT(
        _______, GOLAND1, GOLAND2, S(KC_F8), _______, _______,                                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______,                                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______,   _______, _______,  _______, _______,   _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
    ),

//
// Symbol and arrow layers
//
// ,-----------------------------------------.                              ,-----------------------------------------.
// |      |   /  |   \  |   [  |   ]  |   |  |                              |   !  |   ?  |   '  |   ´  |   ~  |      |
// |------+------+------+------+------+------|                              |------+------+------+------+------+------|
// |      |   {  |   }  |   (  |   )  |   @  |                              |   *  |   "  |   `  |  up  | right|      |
// |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
// |      |      |   =  |   <  |   >  |   %  |      |      |  |      |      |   #  |   &  | left | down |   +  |   -  |
// `--------------------+------+------+------+   _  +------|  |------+      +------+------+------+--------------------'
//                      |      |      |      |      | Func |  |Magnet|      |      |      |      |
//                      `----------------------------------'  `----------------------------------'
//
    [_ARW1] = LAYOUT( // Normal arrows
        _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_PIPE,                                       KC_EXLM, CB_QUES, CB_QUOT, CB_ACUT, CB_TILD, _______,
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,                                         CB_ASTR, CB_DQUO, CB_GRV,  KC_UP,   KC_RGHT, _______,
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC, XXXXXXX, _______, _______,   XXXXXXX, CB_HASH, CB_AMPR, KC_LEFT, KC_DOWN, KC_PPLS, CB_MINS,
                                     _______, _______, _______, SPACE,   _______, MO(_MAGN), _______, _______, _______, _______
    ),
    [_ARW2] = LAYOUT( // Step whole words
        _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_PIPE,                                     KC_EXLM, CB_QUES, CB_QUOT,    CB_ACUT, CB_TILD,    A(KC_BSPC),
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,                                       CB_ASTR, CB_DQUO, CB_GRV,     KC_UP,   A(KC_RGHT), A(KC_DEL),
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, CB_HASH, CB_AMPR, A(KC_LEFT), KC_DOWN, KC_PPLS,    CB_MINS,
                                     _______, _______, _______, SPACE,   _______, _______, _______, _______, _______, _______
    ),
    [_ARW3] = LAYOUT( // Step whole line
        _______, CB_SLSH,   CB_BSLS, CB_LBRC, CB_RBRC, CB_PIPE,                                     KC_EXLM, CB_QUES, CB_QUOT,    CB_ACUT, CB_TILD,    G(KC_BSPC),
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,                                       CB_ASTR, CB_DQUO, CB_GRV,     KC_PGUP, G(KC_RGHT), C(KC_K),
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, CB_HASH, CB_AMPR, G(KC_LEFT), KC_PGDN, KC_PPLS,    CB_MINS,
                                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MAGN] = LAYOUT(
        _______, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, RGB_MOD,                                         _______, _______,    _______, MAG_2_3, MAG_3_3, _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_TOG, RGB_RMOD,                                        _______, G(KC_PPLS), MAG_1_3, MAG_TOP, MAG_RGT, _______,
        _______, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX,   _______, G(CB_MINS), MAG_LFT, MAG_BTM, _______, _______,
                                     _______, _______, _______, MAG_CTR, _______, _______, MAG_FUL, _______, _______, _______
    ),

//
// Numpad
//
// ,-----------------------------------------.                              ,-----------------------------------------.
// |      |      |      |      |      |      |                              |   °  |   7  |   8  |   9  |   ^  |      |
// |------+------+------+------+------+------|                              |------+------+------+------+------+------|
// |      |      |   Symbols   |      |      |                              |   *  |   4  |   5  |   6  |   $  |      |
// |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
// |      |      |      |      |      |      |      |      |  |      |      |   #  |   1  |   2  |   3  |   +  |   -  |
// `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
//                      |      |      |      |      |Goland|  |Goland|      |   0  |   .  |   :  |
//                      `----------------------------------'  `----------------------------------'
//
    [_NUMB] = LAYOUT(
        _______, CB_SLSH,   KC_BSLS, CB_LBRC, CB_RBRC, CB_PIPE,                                     CB_DGRE, KC_7, KC_8, KC_9, CB_CIRC, _______,
        _______, CB_LCBR,   CB_RCBR, CB_LPRN, CB_RPRN, CB_AT,                                       CB_ASTR, KC_4, KC_5, KC_6, CB_DLR,  _______,
        _______, S(CB_DOT), CB_EQL,  CB_LABK, CB_RABK, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, CB_HASH, KC_1, KC_2, KC_3, KC_PPLS, CB_MINS,
                                     _______, _______, _______, _______, _______, _______, _______, KC_0, CB_DOT, S(CB_DOT)
    ),
    [_FUNC] = LAYOUT(
        _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MPLY,                                         CB_SCRF, KC_F7, KC_F8, KC_F9, _______, _______,
        _______, _______, KC_MUTE, CB_VOLD, CB_VOLU, KC_MUTE,                                         CB_SCRC, KC_F4, KC_F5, KC_F6, _______, _______,
        _______, _______, _______, KC_BRID, KC_BRIU, _______,   XXXXXXX, _______,   _______, XXXXXXX, _______, KC_F1, KC_F2, KC_F3, _______, _______,
                             _______, TO(_GOLAND), TO(_SVORAK), _______, TO(_NUMB), _______, _______, KC_F10, KC_F11, KC_F12
    ),

//
// Template
//
// ,-----------------------------------------.                              ,-----------------------------------------.
// |      |      |      |      |      |      |                              |      |      |      |      |      |      |
// |------+------+------+------+------+------|                              |------+------+------+------+------+------|
// |      |      |      |      |      |      |                              |      |      |      |      |      |      |
// |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
// |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |      |
// `--------------------+------+------+------+      +------|  |------+      +------+------+------+--------------------'
//                      |      |      |      |      |      |  |      |      |      |      |      |
//                      `----------------------------------'  `----------------------------------'
//
//  [_TEMPL] = LAYOUT(
//      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
//                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//  ),
//
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

// Eager Macros ----------------------------------------------------------------
// In contrast to a regular macro are these dynamic and picked up automatically
// as you type.

typedef enum { input_prefix, input_suffix } InputState;
InputState input_state;

#define N_PREFIXES 2
#define MAX_SUFFIX_LENGTH 20
#define SEPARATOR CB_DOT
#define MAX_STORED_TOKENS 2

const uint16_t  project_prefix[]     = {KC_F, KC_O, KC_R, KC_M, KC_U, KC_L, KC_A, KC_T, KC_E, CB_MINS};
const uint16_t  retailer_prefix[]    = {KC_R, KC_E, KC_T, KC_A, KC_I, KC_L, KC_E, KC_R, S(CB_MINS)};
const uint16_t* prefixes[N_PREFIXES] = {project_prefix, retailer_prefix};
const uint8_t   prefix_n[N_PREFIXES] = {10, 9};

typedef struct MacroToken {
    uint8_t  prefix_i;
    uint8_t  suffix_n;
    uint16_t suffix[MAX_SUFFIX_LENGTH];
} MacroToken;

bool       first_token;
uint8_t    n_stored_tokens;
MacroToken stored_tokens[MAX_STORED_TOKENS];

uint8_t     current_prefix_i;
uint8_t     current_prefix_n;
MacroToken* current_token;

void init_macro_prefix(uint16_t keycode) {
    for (int i = 0; i < N_PREFIXES; i++) {
        if (keycode == prefixes[i][0]) {
            current_prefix_i = i;
            current_prefix_n = 1;
            return;
        }
    }
}

void append_token(uint8_t prefix_i) {
    if (n_stored_tokens >= MAX_STORED_TOKENS) {
        return;
    }
}

void wait_for_new_prefix(void) {
    input_state      = input_prefix;
    current_prefix_n = 0;
}

void end_token_store(void) {
    first_token = true;
    wait_for_new_prefix();
}

void update_macro_prefix(uint16_t keycode) {
    if (current_prefix_n == 0) {
        init_macro_prefix(keycode);
        return;
    }

    if (keycode != prefixes[current_prefix_i][current_prefix_n]) {
        // Unexpected char
        end_token_store();
        init_macro_prefix(keycode);
        return;
    }

    current_prefix_n++;

    if (first_token || n_stored_tokens >= MAX_STORED_TOKENS) {
        n_stored_tokens = 0;  // clear stored tokens
    }

    current_token           = &stored_tokens[n_stored_tokens];
    current_token->prefix_i = current_prefix_i;
    current_token->suffix_n = 0;
    n_stored_tokens++;
    first_token = false;
    input_state = input_suffix;
}

void update_macro_suffix(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:  // 1 -- 9, 0
        case CB_MINS:
            if (current_token->suffix_n < MAX_SUFFIX_LENGTH) {
                current_token->suffix[current_token->suffix_n] = keycode;
                current_token->suffix_n++;
            }
            break;
        case SEPARATOR:
            wait_for_new_prefix();
            break;
        default:
            end_token_store();
    }
}

void update_macro(uint16_t keycode) {
    uint16_t cased_keycode = keycode;
    switch (keycode) {
        case KC_LSHIFT:
        case KC_RSHIFT:
        case NUMBERS:
            return;
    }

    if (get_mods() & MOD_MASK_SHIFT) {
        cased_keycode = S(cased_keycode);
    }

    if (input_state == input_prefix) {
        update_macro_prefix(cased_keycode);
    } else {
        update_macro_suffix(cased_keycode);
    }
}

void replay_macro(void) {
    uint8_t original_mods = get_mods();
    set_mods(0);

    const uint16_t* codes;
    uint8_t         n;

    for (int i = 0; i < n_stored_tokens; i++) {
        if (i > 0) {
            tap_code(SEPARATOR);
        }

        codes = prefixes[stored_tokens[i].prefix_i];
        n     = prefix_n[stored_tokens[i].prefix_i];
        for (int j = 0; j < n; j++) {
            if (codes[j] == S(codes[j])) {
                register_code(KC_LSFT);
                tap_code(codes[j]);
                unregister_code(KC_LSFT);
            } else {
                tap_code(codes[j]);
            }
        }

        codes = stored_tokens[i].suffix;
        n     = stored_tokens[i].suffix_n;
        for (int j = 0; j < n; j++) {
            tap_code(codes[j]);
        }
    }
    set_mods(original_mods);

    first_token = true;
}

void keyboard_post_init_user(void) {
    input_state      = input_prefix;
    first_token      = true;
    current_prefix_n = 0;
}

// Process input ---------------------------------------------------------------

uint8_t space_state;
#define SPACE_NEXT 0
#define UNDERSCORE_NEXT 1
#define DASH_NEXT 2
#define SPACE_DOWN 3
#define UNDERSCORE_DOWN 4
#define DASH_DOWN 5

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        // when key is pressed
        update_macro(keycode);

        if (space_state != SPACE_NEXT && keycode != SPACE) {
            space_state = SPACE_NEXT;
        }

        switch (keycode) {
            case REPLAY:
                replay_macro();
                return true;

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

            case SPACE:
                switch (space_state) {
                case UNDERSCORE_NEXT: {
                    uint8_t original_mods = get_mods();
                    set_mods(MOD_MASK_SHIFT);
                    register_code(SE_MINS);
                    set_mods(original_mods);
                    space_state = UNDERSCORE_DOWN;
                    break;
                }
                case DASH_NEXT: {
                    register_code(SE_MINS);
                    space_state = DASH_DOWN;
                    break;
                }
                default: {
                    register_code(KC_SPACE);
                    space_state = SPACE_DOWN;
                   }
                }
                break;
            case SYMBOL1:
                layer_on(_ARW1);
                // Only update state if space bar is up
                if (space_state == SPACE_NEXT) {
                    space_state = UNDERSCORE_NEXT;
                }
                break;
            case SYMBOL2:
                layer_on(_ARW2);
                // Only update state if space bar is up
                if (space_state == SPACE_NEXT) {
                    space_state = DASH_NEXT;
                }
                break;

            case GOLAND1: {
                uint8_t original_mods = get_mods();
                if (original_mods & MOD_MASK_SHIFT) {
                    // Run to cursor
                    set_mods(MOD_MASK_ALT);
                    tap_code(KC_F9);
                    set_mods(original_mods);
                } else {
                    // Step into
                    tap_code(KC_F7);
                }
                break;
            }
            case GOLAND2: {
                uint8_t original_mods = get_mods();
                if (original_mods & MOD_MASK_SHIFT) {
                    // Continue
                    set_mods(MOD_MASK_AG);
                    tap_code(KC_R);
                    set_mods(original_mods);
                } else {
                    // Step
                    tap_code(KC_F8);
                }
                break;
            }

            // clang-format off
            case MAG_LFT: magnet_state |=  1; process_magnet(magnet_state); break;
            case MAG_RGT: magnet_state |=  2; process_magnet(magnet_state); break;
            case MAG_TOP: magnet_state |=  4; process_magnet(magnet_state); break;
            case MAG_BTM: magnet_state |=  8; process_magnet(magnet_state); break;
            case MAG_1_3: magnet_state |= 16; process_magnet(magnet_state); break;
            case MAG_2_3: magnet_state |= 32; process_magnet(magnet_state); break;
            case MAG_3_3: magnet_state |= 64; process_magnet(magnet_state); break;
                // clang-format on

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
        }
    } else {  // when Key is released
        switch (keycode) {
            case SPACE:
                switch (space_state) {
                    case UNDERSCORE_DOWN:
                    case DASH_DOWN:
                        unregister_code(SE_MINS);
                        break;
                    case SPACE_DOWN:
                        unregister_code(KC_SPACE);
                        break;
                }
                if (space_state == UNDERSCORE_DOWN && layer_state_is(_ARW1)) {
                    space_state = UNDERSCORE_NEXT;
                } else if (space_state == DASH_DOWN && layer_state_is(_ARW2)) {
                    space_state = DASH_NEXT;
                } else {
                    space_state = SPACE_NEXT;
                }
                break;
            case SYMBOL1:
                layer_off(_ARW1);
                break;
            case SYMBOL2:
                layer_off(_ARW2);
                break;

            // clang-format off
            case MAG_LFT: magnet_state &=  ~1; break;
            case MAG_RGT: magnet_state &=  ~2; break;
            case MAG_TOP: magnet_state &=  ~4; break;
            case MAG_BTM: magnet_state &=  ~8; break;
            case MAG_1_3: magnet_state &= ~16; break;
            case MAG_2_3: magnet_state &= ~32; break;
            case MAG_3_3: magnet_state &= ~64; break;
                // clang-format on
        }
    }
    return true;
};

    // Display ---------------------------------------------------------------

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("\n"), false);

        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _SVORAK:
                oled_write_P(PSTR("Svorak\n"), false);
                switch (space_state) {
                    case SPACE_NEXT:
                        oled_write_P(PSTR("Space next\n\n"), false);
                        break;
                    case SPACE_DOWN:
                        oled_write_P(PSTR("Space down\n\n"), false);
                        break;
                    case UNDERSCORE_NEXT:
                        oled_write_P(PSTR("Underscore next\n\n"), false);
                        break;
                    case UNDERSCORE_DOWN:
                        oled_write_P(PSTR("Underscore down\n\n"), false);
                        break;
                    case DASH_NEXT:
                        oled_write_P(PSTR("Dash next\n\n"), false);
                        break;
                    case DASH_DOWN:
                        oled_write_P(PSTR("Dash down\n\n"), false);
                        break;
                    default:
                        oled_write_P(PSTR("Space unknown\n\n"), false);
                        break;
                }
                break;
            case _GOLAND:
                oled_write_P(PSTR("GoLand Dvorak\n(In, Next, Out)\n To, Continue\n"), false);
                break;
            case _ARW1:
            case _ARW2:
            case _ARW3:
                oled_write_P(PSTR("Symbols\n"), false);
                switch (space_state) { // copied from above
                    case SPACE_NEXT:
                        oled_write_P(PSTR("Space next\n\n"), false);
                        break;
                    case SPACE_DOWN:
                        oled_write_P(PSTR("Space down\n\n"), false);
                        break;
                    case UNDERSCORE_NEXT:
                        oled_write_P(PSTR("Underscore next\n\n"), false);
                        break;
                    case UNDERSCORE_DOWN:
                        oled_write_P(PSTR("Underscore down\n\n"), false);
                        break;
                    case DASH_NEXT:
                        oled_write_P(PSTR("Dash next\n\n"), false);
                        break;
                    case DASH_DOWN:
                        oled_write_P(PSTR("Dash down\n\n"), false);
                        break;
                    default:
                        oled_write_P(PSTR("Space unknown\n\n"), false);
                        break;
                }
                break;
            case _NUMB:
                oled_write_P(PSTR("Numbers\n\n\n"), false);
                break;
            case _FUNC:
                oled_write_P(PSTR("Track, Play | F1-12\nVolume, Mute\nBrightness\nSticky layers\n"), false);
                break;
            case _MAGN:
                oled_write_P(PSTR("RGB | Magnet\n\n\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
    } else {
        // clang-format off
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
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
}
#endif
