#pragma once

// Keycodes for MacOS

// Characters
#define CB_SLSH SE_SLSH
#define CB_BSLS S(A(KC_7))
#define CB_LBRC A(KC_8)
#define CB_RBRC A(KC_9)
#define CB_LCBR S(A(KC_8))
#define CB_RCBR S(A(KC_9))
#define CB_PIPE A(KC_7)
#define CB_DGRE SE_RABK

// Editing
#define BSP_WRD A(KC_BSPC)
#define BSP_LNE G(KC_BSPC)
#define DEL_WRD A(KC_DEL)
#define DEL_LNE C(KC_K)
#define LFT_WRD A(KC_LEFT)
#define LFT_LNE G(KC_LEFT)
#define RGT_WRD A(KC_RGHT)
#define RGT_LNE G(KC_RGHT)

// OS
#define CB_SCRC S(C(G(KC_4))) // Print screen region to clipboard
#define CB_SCRF S(G(KC_4))    // Print screen region to file
#define CB_VOLU LSA(KC_VOLU)  // Small volume increment
#define CB_VOLD LSA(KC_VOLD)

