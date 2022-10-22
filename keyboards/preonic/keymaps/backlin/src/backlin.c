#include "backlin.h"

bool    sym1down;
uint8_t fn_down;

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
            if (record->event.pressed) {
                macro_pressed(keycode);
            }
            return false;
        case MAG_CTR ... MAG_3_3:
            process_magnet(keycode, record->event.pressed);
            return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case SYM1:
                sym1down = true;
                layer_on(_SYM1);
                return false;
            case SYM2:
                layer_on(_SYM1);
                layer_on(_SYM2);
                return false;
            case LFN:
                fn_down |= LFN_DOWN;
                layer_on(_FN);
                return false;
            case RFN:
                fn_down |= RFN_DOWN;
                layer_on(_FN);
                return false;

            case KC_PGUP:
            case KC_PGDN:
            case CB_QUES:
                if (get_mods() && biton32(_SYM2))
                    macro_pressed(keycode);
                return true;
            case QK_RBT:
            case EE_CLR:
            case QK_BOOT:
                if (fn_down != BOTH_FN_DOWN) {
                    return false;
                }
                return true;

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
            case SYM1:
                sym1down = false;
                if (!layer_state_is(_SYM2)) {
                    layer_off(_SYM1);
                }
                return false;
            case SYM2:
                if (!sym1down) {
                    layer_off(_SYM1);
                }
                layer_off(_SYM2);
                return false;
            case LFN:
                fn_down &= ~LFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                return false;
            case RFN:
                fn_down &= ~RFN_DOWN;
                if (!fn_down) {
                    layer_off(_FN);
                }
                return false;
        }
    }
    return true;
};
