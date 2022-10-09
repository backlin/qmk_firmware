/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

//#define ORYX_CONFIGURATOR

#define TAPPING_TOGGLE 2
#define CB_NUM TT(_NUM)

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

#define GL_IN   S(KC_F7)
#define GL_OUT  S(KC_F8)
#define GL_STEP KC_F8
#define GL_TO   A(KC_F9)
#define GL_SHOW A(KC_F10)
#define GL_CONT A(G(KC_R))

//  Magnet keys
//         Left Center Right
//      ┌──────┬──────┬──────┐
//  1/3 │      |      |      |
//      ├──────┼──────┼──────┤
//  1/2 │      |      |      |
//      └──────┴──────┴──────┘

#define MAG_LEFT_12    1
#define MAG_CENTER     2 // Not resizing on its own but just moving
#define MAG_RIGHT_12   4
#define MAG_LEFT_13    8
#define MAG_CENTER_13 16
#define MAG_RIGHT_13  32
#define MAG_S_L LCAG(KC_LEFT) // Move to left screen
#define MAG_S_R LCAG(KC_RGHT) // Move to left screen

#define MAG_FULL (MAG_LEFT_12 | MAG_RIGHT_12)

#define MAG_TOP_LEFT     (MAG_LEFT_12  | MAG_CENTER_13)
#define MAG_TOP_RIGHT    (MAG_RIGHT_12 | MAG_CENTER_13)
#define MAG_BOTTOM_LEFT  (MAG_LEFT_13  | MAG_CENTER)
#define MAG_BOTTOM_RIGHT (MAG_RIGHT_13 | MAG_CENTER)

#define MAG_CENTER_12_1 (MAG_LEFT_12  | MAG_CENTER)
#define MAG_CENTER_12_2 (MAG_RIGHT_12 | MAG_CENTER)
#define MAG_LEFT_23     (MAG_LEFT_13  | MAG_CENTER_13)
#define MAG_RIGHT_23    (MAG_RIGHT_13 | MAG_CENTER_13)
#define MAG_CENTER_23   (MAG_LEFT_13  | MAG_RIGHT_13)

#define MAG_TOP    (MAG_LEFT_13 | MAG_CENTER_13 | MAG_RIGHT_13)
#define MAG_BOTTOM (MAG_LEFT_12 | MAG_CENTER    | MAG_RIGHT_12)
// clang-format on

