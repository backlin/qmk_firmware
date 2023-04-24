#include "macro.h"
#include "sendstring_swedish.h"
#include "print.h" // For console debugging

/*
    GoLand keymap setup

    The following keybindings are used:

    Run context configuration:   Ctrl + Shift + R (default)
    Debug context configuration: Ctrl + Shift + D (default)
    Edit configurations...:      Ctrl + Shift + C (not default)
*/

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

void tmux_command(uint16_t mods, uint16_t keycode) {
    uint8_t original_mods = get_mods();
    set_mods(0);

    register_code(KC_LCTL);
    tap_code(KC_B);
    unregister_code(KC_LCTL);

    if (mods) register_code(mods);
    tap_code(keycode);
    if (mods) unregister_code(mods);

    set_mods(original_mods);
}

void tmux_new_session() {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_CTRL);
    tap_code(KC_B);
    set_mods(MOD_MASK_SHIFT);
    tap_code(KC_DOT);
    set_mods(0);
    SEND_STRING("new" SS_TAP(X_ENT));
    set_mods(original_mods);
}

void enter_tmux_copy_mode() {
    tmux_command(KC_LALT, KC_8);
}

uint8_t jetbrains_state;

#ifdef DEBUG_ENABLE
void jb_debug(bool debug, enum flag_state flags) {
    if (debug)
        print("debug");
    else
        print("run");
    if (new_test) print(" new");

    switch (flags) {
        case None:
            print(" clear");
            break;
        case Record:
            print(" record");
            break;
        case Update:
            print(" update");
            break;
        case RecordUpdate:
            print(" record");
            break;
        case Unchanged:
            print(" unchanged");
            break;
    }
    print("\n");
}
#endif

void run_existing(bool debug) {
    set_mods(MOD_MASK_CS);
    if (debug) {
        tap_code(KC_D);
    } else {
        tap_code(KC_R);
    }
}

const uint64_t MACRO_DELAY = 1000;

void edit_run_configurations(enum flag_state flags) {
    // Open window "Edit run configurations"
    set_mods(MOD_MASK_CS);
    tap_code(KC_C);
    wait_ms(MACRO_DELAY);

    // Focus textbox "Program arguments"
    set_mods(MOD_MASK_CA);
    tap_code(KC_P);
    wait_ms(200);

    // Clear existing content
    set_mods(0);
    register_code(KC_LGUI); // Send key to OS, don't just alter keyboard's mods
    tap_code(KC_BSPC);
    unregister_code(KC_LGUI);

    switch (flags) {
        case Record:
            SEND_STRING("-test.record");
            break;
        case Update:
            SEND_STRING("-test.update");
            break;
        case RecordUpdate:
            SEND_STRING("-test.record -test.update");
            break;
        default: {
            // Otherwise leave empty.
            // This no-op case is required to not error on "unhandled enumeration value 'None'".
        }
    }
    wait_ms(200);

    // save
    register_code(KC_LGUI); // See above
    tap_code(KC_ENT);
    unregister_code(KC_LGUI);
    wait_ms(MACRO_DELAY);
}

void jetbrains_run(enum flag_state flags, bool debug) {
#ifdef DEBUG_ENABLE
    jb_debug(debug, flags);
#endif
    uint8_t mods = get_mods();
    if (flags != Unchanged) {
        edit_run_configurations(flags);
    }
    run_existing(debug);
    set_mods(mods);
}

void process_macro(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return;
    }
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
        case CB_AT: {
            uint8_t mods = get_mods();
            set_mods(0);
            if (mods & MOD_MASK_CTRL) {
                SEND_STRING("@christofer.backlin.se");
            } else if (mods & MOD_MASK_GUI) {
                SEND_STRING("christofer.backlin@relexsolutions.com");
            } else if (mods & MOD_MASK_ALT) {
                SEND_STRING("christofer.backlin@formulate.app");
            }
            set_mods(mods);
            return;
        }

        case JB_RUN:
            jetbrains_run(Unchanged, false);
            return;
        case JB_DBUG:
            jetbrains_run(Unchanged, true);
            return;
        case JB_NONE:
            jetbrains_run(None, false);
            return;
        case JB_REC:
            jetbrains_run(Record, false);
            return;
        case JB_UPDT:
            jetbrains_run(Update, false);
            return;
        case JB_RCUP:
            jetbrains_run(RecordUpdate, false);
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

        case TX_PREV:
            if (get_mods() & MOD_MASK_GUI) {
                tmux_command(KC_LSFT, KC_S); // List sessions
                return;
            }
            if (get_mods() & MOD_MASK_ALT) {
                tmux_new_session();
                return;
            }
            tmux_command(0, KC_P); // Previous window
            return;
        case TX_NEXT:
            if (get_mods())
                tmux_command(0, KC_C); // Create window
            else
                tmux_command(0, KC_N); // Next window
            return;
        case TX_SESS:
            if (get_mods())
                tmux_new_session();
            else
                tmux_command(KC_LSFT, KC_S); // List sessions
            return;
        case TX_UP:
            if (get_mods()) tmux_command(KC_LSFT, KC_2);
            tmux_command(0, KC_UP);
            return;
        case TX_DOWN:
            if (get_mods())
                tmux_command(KC_LSFT, KC_2);
            else
                tmux_command(0, KC_DOWN);
            return;
        case TX_JOIN:
            tmux_command(0, KC_J);
            return;
        case TX_BREK:
            tmux_command(0, KC_B);
            return;

#ifdef CB_BOXDRAW_ENABLE
        case BOX_ALL: // ┼
            send_unicode(KC_2, KC_5, KC_3, KC_C);
            return;
        case BOX_BL: // ┐
            send_unicode(KC_2, KC_5, KC_1, KC_0);
            return;
        case BOX_BLR: // ┬
            send_unicode(KC_2, KC_5, KC_2, KC_C);
            return;
        case BOX_BR: // ┌
            send_unicode(KC_2, KC_5, KC_0, KC_C);
            return;
        case BOX_L: // ╴
            send_unicode(KC_2, KC_5, KC_7, KC_4);
            return;
        case BOX_LR: // ─
            send_unicode(KC_2, KC_5, KC_0, KC_0);
            return;
        case BOX_TB: // │
            send_unicode(KC_2, KC_5, KC_0, KC_2);
            return;
        case BOX_TBL: // ┤
            send_unicode(KC_2, KC_5, KC_2, KC_4);
            return;
        case BOX_TBR: // ├
            send_unicode(KC_2, KC_5, KC_1, KC_C);
            return;
        case BOX_TL: // ┘
            send_unicode(KC_2, KC_5, KC_1, KC_8);
            return;
        case BOX_TLR: // ┴
            send_unicode(KC_2, KC_5, KC_3, KC_4);
            return;
        case BOX_TR: // └
            send_unicode(KC_2, KC_5, KC_1, KC_4);
            return;
#endif
    }
}

#ifdef CB_BOXDRAW_ENABLE
void send_unicode(uint16_t k1, uint16_t k2, uint16_t k3, uint16_t k4) {
    uint8_t original_mods = get_mods();
    set_mods(MOD_MASK_ALT);
    tap_code(k1);
    tap_code(k2);
    tap_code(k3);
    tap_code(k4);
    set_mods(original_mods);
}
#endif
