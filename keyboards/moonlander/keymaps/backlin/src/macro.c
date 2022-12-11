#include "macro.h"
#include "sendstring_swedish.h"
#include "print.h" // For console debugging

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

void print_state(void) {
    for (int i = 0; i < 8; i++) {
        if (jetbrains_state & 1 << i)
            print("1");
        else
            print(".");
    }
    print("\n");
}

void jetbrains_reset(void) {
    print("reset\n");
    jetbrains_state = 0;
}

#define _JB_RUN  1UL
#define _JB_DBUG (1 << 1)
#define _JB_NEW  (1 << 2)
#define _JB_REC  (1 << 3)
#define _JB_UPDT (1 << 4)
#define _JB_NONE (1 << 5)

void jetbrains_pressed(uint16_t keycode) {
    switch (keycode) {
    case JB_RUN:
        if (jetbrains_state & _JB_DBUG){
            jetbrains_reset();
            return;
        }
        jetbrains_state |= _JB_RUN;
        return;
    case JB_DBUG:
        if (jetbrains_state & _JB_RUN){
            jetbrains_reset();
            return;
        }
        jetbrains_state |= _JB_DBUG;
        return;
    }

    if (!(jetbrains_state & (_JB_RUN | _JB_DBUG)))
        return;

    switch (keycode) {
    case JB_NEW:
        jetbrains_state |= _JB_NEW;
        return;
    case JB_REC:
        jetbrains_state &= ~_JB_NONE;
        jetbrains_state |= _JB_REC;
        return;
    case JB_UPDT:
        jetbrains_state &= ~_JB_NONE;
        jetbrains_state |= _JB_UPDT;
        return;
    case JB_NONE:
        jetbrains_state &= ~(_JB_REC | _JB_UPDT);
        jetbrains_state |= _JB_NONE;
        return;
    }
}

enum flag_state jetbrains_parse_flags(void) {
    if (jetbrains_state & _JB_NONE) {
        return None;
    } else if (jetbrains_state & _JB_REC) {
        if (jetbrains_state & _JB_UPDT) {
            return RecordUpdate;
        } else {
            return Record;
        }
    } else if (jetbrains_state & _JB_UPDT) {
        return Update;
    }
    return Unchanged;
}

void jetbrains_released(uint16_t keycode) {
    if (keycode == JB_RUN && jetbrains_state & _JB_RUN) {
        jetbrains_run(jetbrains_state & _JB_NEW, false);
    } else if (keycode == JB_DBUG && jetbrains_state & _JB_DBUG) {
        jetbrains_run(jetbrains_state & _JB_NEW, true);
    }
    return;
}

void jetbrains_run(bool new_test, bool debug) {
    enum flag_state flags = jetbrains_parse_flags();

    if (debug) print("debug");
    else print("run");
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

    uint8_t mods = get_mods();

    if (flags != Unchanged) {
        if (new_test) {
            // Open context actions (Cursor must be on first line of test function)
            set_mods(MOD_MASK_ALT);
            tap_code(KC_ENT);
            tap_code(KC_ENT);

            // Modify run configuration
            tap_code(KC_DOWN);
            set_mods(0);
            tap_code(KC_ENT);

            new_test = false;
        } else {
            // Open run context menu
            set_mods(MOD_MASK_CA);
            tap_code(KC_R);
            set_mods(0);
            wait_ms(500);

            // Edit config
            tap_code(KC_0);
        }
        wait_ms(500);

        set_mods(MOD_MASK_CA);
        tap_code(KC_P); // Program arguments
        wait_ms(500);

        SEND_STRING(SS_LGUI(SS_TAP(X_BSPC)));

        switch (flags) {
        case Record:
            set_mods(0);
            SEND_STRING("-test.record");
            break;
        case Update:
            set_mods(0);
            SEND_STRING("-test.update");
            break;
        case RecordUpdate:
            set_mods(0);
            SEND_STRING("-test.record -test.update");
            break;
        default: {}
        }

        wait_ms(500);
        set_mods(MOD_MASK_CA);
        tap_code(KC_A); // Apply
        wait_ms(500);
        tap_code(KC_C); // Close
        wait_ms(500);
    }

    // Open context menu
    if (debug) {
        // Can't use Ctrl+Alt+D since that is used by Magnet
        set_mods(MOD_MASK_AG);
    } else {
        set_mods(MOD_MASK_CA);
    }
    tap_code(KC_R);

    // Pick entry
    set_mods(0);
    if (new_test) {
        tap_code(KC_2);
    } else {
        tap_code(KC_1);
    }

    set_mods(mods);
    jetbrains_reset();
}


void process_macro(uint16_t keycode, bool pressed) {
    if (keycode >= JB_RUN_RANGE_START && keycode <= JB_RUN_RANGE_END) {
        if (pressed)
            jetbrains_pressed(keycode);
        else
            jetbrains_released(keycode);
        print_state();
        return;
    }
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
                SEND_STRING( "@christofer.backlin.se" );
            } else if (mods & MOD_MASK_GUI) {
                SEND_STRING( "christofer.backlin@relexsolutions.com" );
            } else if (mods & MOD_MASK_ALT) {
                SEND_STRING( "christofer.backlin@formulate.app" );
            }
            set_mods(mods);
            return;
        }

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
        case BOX_BL:  // ┐
            send_unicode(KC_2, KC_5, KC_1, KC_0);
            return;
        case BOX_BLR: // ┬
            send_unicode(KC_2, KC_5, KC_2, KC_C);
            return;
        case BOX_BR:  // ┌
            send_unicode(KC_2, KC_5, KC_0, KC_C);
            return;
        case BOX_L:  // ╴
            send_unicode(KC_2, KC_5, KC_7, KC_4);
            return;
        case BOX_LR:  // ─
            send_unicode(KC_2, KC_5, KC_0, KC_0);
            return;
        case BOX_TB:  // │
            send_unicode(KC_2, KC_5, KC_0, KC_2);
            return;
        case BOX_TBL: // ┤
            send_unicode(KC_2, KC_5, KC_2, KC_4);
            return;
        case BOX_TBR: // ├
            send_unicode(KC_2, KC_5, KC_1, KC_C);
            return;
        case BOX_TL:  // ┘
            send_unicode(KC_2, KC_5, KC_1, KC_8);
            return;
        case BOX_TLR: // ┴
            send_unicode(KC_2, KC_5, KC_3, KC_4);
            return;
        case BOX_TR:  // └
            send_unicode(KC_2, KC_5, KC_1, KC_4);
            return;
#endif

#ifdef CB_SECRET_1
        case CB_MCRO:
            SEND_STRING(xor_cipher(CB_SECRET_1);
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

#ifdef CB_SECRET_1
char* xor_cipher(char* data, char* key, int dataLen, int keyLen) {
	char* output = (char*)malloc(sizeof(char) * dataLen);

	for (int i = 0; i < dataLen; ++i) {
		output[i] = data[i] ^ key[i % keyLen];
	}

	return output;
}
#endif
