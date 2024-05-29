#pragma once

// Keycodes for Windows and Linux

// Characters
#define CB_PLUS KC_MINS
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

#define CB_TABN C(KC_TAB)    // Next tab
#define CB_TABP C(S(KC_TAB)) // Previous tab
#define CB_M_NW G(KC_DOWN)
#define CB_M_N  G(KC_UP)
#define CB_M_NE A(KC_F4)
#define CB_M_W  G(KC_LEFT)
#define CB_M_C  G(KC_HOME)
#define CB_M_E  G(KC_RGHT)
#define CB_M_SW LSG(KC_LEFT)
// South not mapped
#define CB_M_SE LSG(KC_RGHT)

// Modifier layout
#define CB_LPRM KC_LCTL // Left primary
#define CB_RPRM KC_RCTL // Right primary
#define CB_SCND KC_LWIN // Secondary

