#include "backlin.h"

// State of layer keys
bool    symbol_state;
uint8_t fn_state;
uint8_t layer_key_state;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef RGB_MATRIX_ENABLE
    if (biton32(layer_state) == _RGB) {
        if (keycode == 1) { // To test conversion from code in layout to uint8_t
            rgb_matrix_mode(1);
        } else if (keycode > 0) {
            rgb_matrix_mode((uint8_t)keycode);
        } else {
            rgb_matrix_mode(1);
        }
        layer_off(_RGB);
        return false;
    }
#endif

    switch (keycode) {
        case CB_CIRC ... JB_DIFF:
            if (record->event.pressed)
                macro_pressed(keycode);
            return false;
        case MAG_CTR ... MAG_3_3:
            process_magnet(keycode, record->event.pressed);
            return false;
    }

    if (record->event.pressed) {
        // Done separately since they overlap with keys in next switch
        switch (keycode) {
        case BOOT_LOCK1:
            layer_key_state |= BOOT_LOCK1_PRESSED;
            break;
        case BOOT_LOCK2:
            layer_key_state |= BOOT_LOCK2_PRESSED;
            break;
        }

        switch (keycode) {
            case SYMBOLS:
                layer_key_state |= SYMBOLS_PRESSED;
                layer_on(_SYMBOLS);
                return false;
            case SYM_ALT:
                layer_on(_SYMBOLS);
                layer_on(_SYM_ALT);
                return false;
            case FN_LEFT:
                layer_key_state |= FN_LEFT_PRESSED;
                layer_on(_FN);
                return false;
            case FN_RGHT:
                layer_key_state |= FN_RGHT_PRESSED;
                layer_on(_FN);
                return false;

            case KC_PGUP: // Tmux scroll up
            case KC_PGDN: // Tmux scroll down
            case CB_QUES: // Tmux search up
                if (get_mods() & MOD_MASK_SHIFT)
                    // If already in copy mode this is a no-op
                    enter_tmux_copy_mode();
                return true;

            case QK_RBT:
            case EE_CLR:
            case QK_BOOT:
                if ((layer_key_state & BOOT_LOCK_OPEN) != BOOT_LOCK_OPEN) {
                    return false;
                }
                return true;

            case CB_AT: {
                uint8_t mods = get_mods();
                if (mods & MOD_MASK_SHIFT) {
                    set_mods(0);
                    SEND_STRING( SS_LALT("2") "christofer.backlin.se" );
                    set_mods(mods);
                    return false;
                }
                return true;
            }

#ifdef RGB_MATRIX_ENABLE
            case RGB_SEL:
                rgb_matrix_mode(1);
                if (rgb_matrix_is_enabled())
                    layer_on(_RGB);
                else
                    rgb_matrix_enable();
                return false;
            case RGB_MOD:
                rgb_matrix_enable();
                return true;
#endif
        }
    } else {
        switch (keycode) {
        case BOOT_LOCK1:
            layer_key_state &= ~BOOT_LOCK1_PRESSED;
            break;
        case BOOT_LOCK2:
            layer_key_state &= ~BOOT_LOCK2_PRESSED;
            break;
        }

        switch (keycode) {
            case SYMBOLS:
                layer_key_state &= ~SYMBOLS_PRESSED;
                if (!layer_state_is(_SYM_ALT))
                    layer_off(_SYMBOLS);
                return false;
            case SYM_ALT:
                if (!(layer_key_state & SYMBOLS_PRESSED))
                    layer_off(_SYMBOLS);
                layer_off(_SYM_ALT);
                return false;
            case FN_LEFT:
                layer_key_state &= ~FN_LEFT_PRESSED;
                if (!(layer_key_state & FN_PRESSED))
                    layer_off(_FN);
                return false;
            case FN_RGHT:
                layer_key_state &= ~FN_RGHT_PRESSED;
                if (!(layer_key_state & FN_PRESSED))
                    layer_off(_FN);
                return false;
        }
    }
    return true;
};
