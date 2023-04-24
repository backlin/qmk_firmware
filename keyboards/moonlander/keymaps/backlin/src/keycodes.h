#pragma once
#include "keymap_swedish.h"

enum layers {
    _SVORAK,
    _SYMBOLS,
    _SYM_ALT,
    _JETBRAINS,
    _NUMPAD,
    _MAGNET,
    _FN
#ifdef RGB_MATRIX_ENABLE
    , _RGB
#endif
#ifdef CB_BOXDRAW_ENABLE
    , _BOX
#endif
};

enum custom_keycodes {
    // Layers
    LOCK = SAFE_RANGE, // Lock currently active layers. Press again to deactivate all but default layer.
    SYMBOLS, // Symbols (optionally including arrows)
    SYM_ALT, // Symbols with alternative arrows (not used in all layouts).
    NUMPAD,
    MAGNET,
    FN_LEFT, // F keys, media brightness etc.
    FN_RGHT, // (not used in all layouts)
#ifdef CB_BOXDRAW_ENABLE
    BOXDRAW,
#endif

    // Macro keys start

    CB_CIRC, // ^
    CB_TILD, // ~
    CB_GRV,  // `
#ifdef CB_BOXDRAW_ENABLE
    // Box drawing
    BOX_ALL, // ┼
    BOX_BL,  // ┐
    BOX_BLR, // ┬
    BOX_BR,  // ┌
    BOX_L,   // ╴
    BOX_LR,  // ─
    BOX_TB,  // │
    BOX_TBL, // ┤
    BOX_TBR, // ├
    BOX_TL,  // ┘
    BOX_TLR, // ┴
    BOX_TR,  // └
#endif
    // Tmux
    TX_SESS, // {List, create} sessions
    TX_NEXT, // {Next, create} window
    TX_PREV, // {Previous, create} window
    TX_UP,   // {Up, create} pane
    TX_DOWN, // {Down, create} pane
    TX_JOIN, // Join window into pane
    TX_BREK, // Break pane into window

    // JetBrains
    JB_DIFF, // compare with branch (default: master, shifted: user chooses)
    // Run macros
    JB_RUN,
    JB_DBUG,
    JB_NONE,
    JB_REC,
    JB_UPDT,
    JB_RCUP,

    // Macro keys end

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

#define NUM_ON  TG(_NUMPAD)
#define NUM_OFF TG(_NUMPAD)

#define MACRO_RANGE_START  CB_CIRC
#define MACRO_RANGE_END    JB_RCUP
#define MAGNET_RANGE_START MAG_CTR
#define MAGNET_RANGE_END   MAG_3_3

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
#define TAB_PRV C(KC_PGUP)
#define TAB_NXT C(KC_PGDN)

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
