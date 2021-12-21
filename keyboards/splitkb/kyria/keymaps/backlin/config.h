/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

#ifdef OLED_DRIVER_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H "font.c"
#    define OLED_FONT_START 0
#    define OLED_FONT_END 229
#    define OLED_FONT_WIDTH 7 // total width 126 = 6 keys x 3 chars x 7 columns
#endif

#define CB_SCRC S(C(G(KC_4))) // Print screen region to clipboard
#define CB_SCRF S(G(KC_4))    // Print screen region to file
#define CB_VOLU LSA(KC_VOLU)  // Small volume increment
#define CB_VOLD LSA(KC_VOLD)
#define MAG_CTR LCA(KC_SPC)   // Magnet center
#define MAG_FUL LCA(KC_ENT)   // Magnet full

// clang-format off
#define CB_APRX A(KC_X)
#define CB_DGRE LSA(KC_Q)
#define CB_DOT  SE_DOT
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
#define CB_LABK SE_LABK
#define CB_RABK SE_RABK
#define CB_LBRC A(KC_8)    //SE_LBRC
#define CB_RBRC A(KC_9)    //SE_RBRC
#define CB_LCBR S(A(KC_8)) //SE_LCBR
#define CB_RCBR S(A(KC_9)) //SE_RCBR
#define CB_LPRN S(KC_8)    //SE_LPRN
#define CB_RPRN S(KC_9)    //SE_RPRN
#define CB_MINS SE_MINS
#define CB_ODIA SE_ODIA
#define CB_PIPE A(KC_7) //SE_PIPE
#define CB_PRGF 192
#define CB_QUES SE_QUES
#define CB_QUOT SE_QUOT
#define CB_SLSH SE_SLSH
#define CB_BSLS S(A(KC_7))
// clang-format on

