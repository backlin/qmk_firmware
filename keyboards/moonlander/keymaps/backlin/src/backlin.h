#pragma once

#include "keymap_swedish.h"
#include "macro.h"
#include "magnet.h"
#ifdef RGB_MATRIX_ENABLE
#   include "rgbmatrix.h"
#endif
#include QMK_KEYBOARD_H

#define KEYMAP const uint16_t PROGMEM
extern KEYMAP keymaps [][MATRIX_ROWS][MATRIX_COLS];

bool process_record_user(uint16_t keycode, keyrecord_t* record);

extern uint8_t fn_down;

enum layers {
    _SVORAK,
    _NUM,
    _SYM1,
    _SYM2,
    _FN
#ifdef RGB_MATRIX_ENABLE
    , _RGB
#endif
};

enum custom_keycodes {
    // Layers
    SYM1 = SAFE_RANGE,
    SYM2,
    LFN,
    RFN,

    CB_CIRC, // ^
    CB_TILD, // ~
    CB_GRV,  // `

    // Tmux
    TX_SESS, // {List, create} sessions
    TX_NEXT, // {Next, create} window
    TX_PREV, // {Previous, create} window
    TX_UP,   // {Up, create} pane
    TX_DOWN, // {Down, create} pane
    TX_JOIN, // Join window into pane
    TX_BREK, // Break pane into window
    JB_RUN,  // Run or debgu (shifted)
    JB_EDRN, // Edit run configuration
    JB_DIFF, // JetBrains compare with branch (default: master, shifted: user chooses)

#ifdef RGB_MATRIX_ENABLE
    RGB_SEL,
#endif

    // Magnet
    MAG_CTR,
    MAG_LFT,
    MAG_RGT,
    MAG_1_3,
    MAG_2_3,
    MAG_3_3
};

#define LFN_DOWN 1
#define RFN_DOWN 2
#define BOTH_FN_DOWN (LFN_DOWN | RFN_DOWN)

#define CB_SCRC S(C(G(KC_4))) // Print screen region to clipboard
#define CB_SCRF S(G(KC_4))    // Print screen region to file
#define CB_VOLU LSA(KC_VOLU)  // Small volume increment
#define CB_VOLD LSA(KC_VOLD)
#define BSP_WRD A(KC_BSPC)
#define BSP_LNE G(KC_BSPC)
#define DEL_WRD A(KC_DEL)
#define DEL_LNE C(KC_K)
#define LFT_WRD A(KC_LEFT)
#define LFT_LNE G(KC_LEFT)
#define RGT_WRD A(KC_RGHT)
#define RGT_LNE G(KC_RGHT)

// clang-format off
#define CB_APRX A(KC_X)
#define CB_DGRE SE_RABK
#define CB_DOT  SE_DOT
#define CB_COLN S(SE_DOT)
#define CB_ACUT SE_ACUT
#define CB_ADIA SE_ADIA
#define CB_AMPR SE_AMPR
#define CB_ARNG SE_ARNG
#define CB_ASTR SE_ASTR
#define CB_AT   SE_AT
#define CB_COMM SE_COMM
#define CB_DLR  SE_DLR
#define CB_DOT  SE_DOT
#define CB_DQUO SE_DQUO
#define CB_EQL  SE_EQL
#define CB_HASH SE_HASH
#define CB_LABK KC_NUBS
#define CB_RABK S(KC_NUBS)
#define CB_LBRC A(KC_8)    //SE_LBRC
#define CB_RBRC A(KC_9)    //SE_RBRC
#define CB_LCBR S(A(KC_8)) //SE_LCBR
#define CB_RCBR S(A(KC_9)) //SE_RCBR
#define CB_LPRN S(KC_8)    //SE_LPRN
#define CB_RPRN S(KC_9)    //SE_RPRN
#define CB_MINS SE_MINS
#define CB_ODIA SE_ODIA
#define CB_PIPE A(KC_7) //SE_PIPE
#define CB_PRGF SE_LABK
#define CB_QUES SE_QUES
#define CB_QUOT SE_QUOT
#define CB_SLSH SE_SLSH
#define CB_BSLS S(A(KC_7))

// JetBrains
#define JB_IN   S(KC_F7)
#define JB_OUT  S(KC_F8)
#define JB_STEP KC_F8
#define JB_TO   A(KC_F9)
#define JB_SHOW A(KC_F10)
#define JB_CONT A(G(KC_R))
#define JB_NXTC LCAG(KC_DOWN)
#define JB_PRVC LCAG(KC_UP)
#define JB_NXTF S(C(KC_RGHT))
#define JB_PRVF S(C(KC_LEFT))
#define JB_BREK G(KC_F8)
