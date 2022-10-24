#include "macro.h"

// Makes the default behaviour of ~, ^, etc. to print the charater on its own.
// If shifted it is added to the following character, i.e. what is normally the default.
void reverse_diacritic(uint16_t modcode, uint16_t keycode) {
    if (get_mods() & MOD_MASK_SHIFT) {
        tap_code(keycode);
    } else {
        // This is implemented as exact stroke sequences and not using using
        // set_mod_mask because the latter does not produce the desired result
        register_code(modcode);
        tap_code(keycode);
        unregister_code(modcode);
        tap_code(KC_SPC);
    }
}

void tmux_command(uint8_t mods, uint16_t keycode) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL);
    tap_code(KC_B);
    set_mods(mods);
    tap_code(keycode);
    set_mods(original_mods);
}

bool jb_debug;

void macro_pressed(uint16_t keycode) {
    switch (keycode) {
        case CB_CIRC:
            reverse_diacritic(KC_LSFT, KC_RBRC);
            return;
        case CB_TILD:
            reverse_diacritic(KC_RALT, KC_RBRC);
            return;
        case CB_GRV:
            reverse_diacritic(KC_LSFT, KC_EQL);
            return;

        case JB_DIFF: {
            uint8_t original_mods = get_mods();
            set_mods(MOD_MASK_CSAG);
            tap_code(KC_G);
            if (!(original_mods & MOD_MASK_SHIFT)) {
                set_mods(0);
                SEND_STRING(SS_DELAY(300) "master" SS_TAP(X_ENT));
            }
            set_mods(original_mods);
            return;
        }
        case JB_RUN: {
            uint8_t original_mods = get_mods();
            set_mods(MOD_MASK_CA);
            tap_code(KC_R);
            set_mods(0);
            wait_ms(50);
            tap_code(KC_RGHT);
            if (original_mods & MOD_MASK_SHIFT)
                jb_debug = !jb_debug;
            if (jb_debug)
                tap_code(KC_DOWN);
            tap_code(KC_ENT);
            set_mods(original_mods);
            return;
        }
        case JB_EDRN: {
            uint8_t original_mods = get_mods();
            set_mods(MOD_MASK_CA);
            tap_code(KC_R);
            set_mods(0);
            wait_ms(50);
            tap_code(KC_RGHT);
            tap_code(KC_UP);
            tap_code(KC_UP);
            tap_code(KC_UP);
            tap_code(KC_ENT);
            wait_ms(300);
            set_mods(MOD_MASK_CA);
            tap_code(KC_P);
            set_mods(original_mods);
            return;
        }

        case TX_PREV:
            if (get_mods())
                tmux_command(0, KC_C); // Create window
            else
                tmux_command(0, KC_P); // Previous window
            return;
        case TX_NEXT:
            if (get_mods())
                tmux_command(0, KC_C); // Create window
            else
                tmux_command(0, KC_N); // Next window
            return;
        case TX_SESS: {
            uint8_t original_mods = get_mods();
            if (original_mods) {
                set_mods(MOD_MASK_CTRL);
                tap_code(KC_B);
                set_mods(MOD_MASK_SHIFT);
                tap_code(KC_DOT);
                set_mods(0);
                SEND_STRING("new" SS_TAP(X_ENT)); // New session
                set_mods(original_mods);
            } else
                tmux_command(MOD_MASK_SHIFT, KC_S); // List sessions
            return;
        }
        case TX_UP:
            if (get_mods()) tmux_command(MOD_MASK_SHIFT, KC_2);
            tmux_command(0, KC_UP);
            return;
        case TX_DOWN:
            if (get_mods())
                tmux_command(MOD_MASK_SHIFT, KC_2);
            else
                tmux_command(0, KC_DOWN);
            return;
        case TX_JOIN:
            tmux_command(0, KC_J);
            return;
        case TX_BREK:
            tmux_command(0, KC_B);
            return;

        case KC_PGUP:
        case KC_PGDN:
        case CB_QUES:
            tmux_command(MOD_MASK_ALT, KC_8);
            return;
    }
}
