#pragma once

// Keycodes for MacOS

// Characters
#define CB_PLUS KC_PPLS
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

#define CB_TABN C(KC_PGUP) // Next tab
#define CB_TABP C(KC_PGDN) // Previous tab
#define CB_M_NW MAG_1_3
#define CB_M_N  MAG_2_3
#define CB_M_NE MAG_3_3
#define CB_M_W  MAG_LFT
#define CB_M_C  MAG_CTR
#define CB_M_E  MAG_RGT
#define CB_M_SW MAG_S_L
// South not mapped
#define CB_M_SE MAG_S_R

    /*
      Magnet section on Mac:
      MAG_1_3, MAG_2_3, MAG_3_3,
      MAG_LFT, MAG_CTR, MAG_RGT,
      MAG_S_L, _______, MAG_S_R,
    */
// Modifier layout
#define CB_LPRM KC_LCMD // Left primary
#define CB_RPRM KC_RCMD // Right primary
#define CB_SCND KC_LCTL // Secondary
