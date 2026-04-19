#pragma once

// Keycodes for Windows and Linux

// Characters
#define CB_PLUS KC_MINS // +
#define CB_SLSH SE_SLSH // /
#define CB_BSLS SE_BSLS // Backslash
#define CB_LBRC SE_LBRC // <
#define CB_RBRC SE_RBRC // ]
#define CB_LCBR SE_LCBR // {
#define CB_RCBR SE_RCBR // }
#define CB_PIPE SE_PIPE // |
#define CB_DGRE XXXXXXX // (none)

// Editing
#define BSP_WRD C(KC_BSPC) // Delete word backward
#define BSP_LNE G(KC_BSPC) // Delete to line start
#define DEL_WRD C(KC_DEL)  // Delete word forward
#define DEL_LNE C(KC_K)    // Delete to line end
#define LFT_WRD C(KC_LEFT) // Move word left
#define LFT_LNE KC_HOME    // Move to line start
#define RGT_WRD C(KC_RGHT) // Move word right
#define RGT_LNE KC_END     // Move to line end

// OS
#define CB_LNCH KC_LGUI // Launcher
#define CB_SCRC KC_PSCR // Print screen to clipboard
#define CB_SCRF KC_PSCR // Map to the same on Windows, different on Mac
#define CB_VOLU KC_VOLU // Volume up
#define CB_VOLD KC_VOLD // Volume down

#define CB_TABN C(KC_PGUP) // Next tab
#define CB_TABP C(KC_PGDN) // Previous tab
#define CB_M_NW G(KC_DOWN)   // Snap down / minimize
#define CB_M_N  G(KC_UP)     // Maximize
#define CB_M_NE A(KC_F4)     // Close window
#define CB_M_W  G(KC_LEFT)   // Snap left
#define CB_M_C  G(KC_HOME)   // Minimize all others
#define CB_M_E  G(KC_RGHT)   // Snap right
#define CB_M_SW LSG(KC_LEFT) // Move to left monitor
// South not mapped
#define CB_M_SE LSG(KC_RGHT) // Move to right monitor
