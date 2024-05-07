#pragma once

// Keycodes for Windows and Linux

// Characters
#define CB_SLSH SE_SLSH
#define CB_BSLS SE_BSLS
#define CB_LBRC SE_LBRC
#define CB_RBRC SE_RBRC
#define CB_LCBR SE_LCBR
#define CB_RCBR SE_RCBR
#define CB_PIPE SE_PIPE
#define CB_DGRE XXXXXXX

// Editing
#define BSP_WRD C(KC_BSPC)
#define BSP_LNE G(KC_BSPC)
#define DEL_WRD C(KC_DEL)
#define DEL_LNE C(KC_K)
#define LFT_WRD C(KC_LEFT)
#define LFT_LNE KC_HOME
#define RGT_WRD C(KC_RGHT)
#define RGT_LNE KC_END

// OS
#define CB_SCRC S(C(G(KC_4))) // Print screen region to clipboard
#define CB_SCRF S(G(KC_4))    // Print screen region to file
#define CB_VOLU KC_VOLU
#define CB_VOLD KC_VOLD

