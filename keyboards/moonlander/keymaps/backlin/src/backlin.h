#pragma once

#include "keycodes.h"
#include "macro.h"
#include "magnet.h"
#ifdef RGB_MATRIX_ENABLE
#   include "rgbmatrix.h"
#endif
#include QMK_KEYBOARD_H

#define KEYMAP const uint16_t PROGMEM
extern KEYMAP keymaps [][MATRIX_ROWS][MATRIX_COLS];

bool process_record_user(uint16_t keycode, keyrecord_t* record);

// Keys related to flashing, rebooting, EEProm etc. are only enabled if 2 layer keys are
// simultaneous held down. The choice of layer keys is configurable below.
#ifndef BOOT_LOCK1
#   define BOOT_LOCK1 FN_LEFT
#endif
#ifndef BOOT_LOCK2
#   define BOOT_LOCK2 FN_RGHT
#endif
extern uint8_t layer_key_state; // Extern to be accessible from RGB matrix files.

#define STATE_BIT1 1
#define STATE_BIT2 2
#define STATE_BIT3 4
#define STATE_BIT4 8
#define STATE_BIT5 16
#define STATE_BIT6 32
#define STATE_BIT7 64

#define SYMBOLS_PRESSED    STATE_BIT1
#define NUMPAD_PRESSED     STATE_BIT2
#define MAGNET_PRESSED     STATE_BIT3
#define FN_LEFT_PRESSED    STATE_BIT4
#define FN_RGHT_PRESSED    STATE_BIT5
#define BOOT_LOCK1_PRESSED STATE_BIT6
#define BOOT_LOCK2_PRESSED STATE_BIT7

#define JETBRAINS_PRESSED (NUMPAD_PRESSED | MAGNET_PRESSED)
#define FN_PRESSED (FN_LEFT_PRESSED | FN_RGHT_PRESSED)
#define BOOT_LOCK_OPEN (BOOT_LOCK1_PRESSED | BOOT_LOCK2_PRESSED)
