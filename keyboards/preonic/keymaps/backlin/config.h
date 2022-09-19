/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(DVORAK_SOUND), SONG(QWERTY_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2


#define TAPPING_TOGGLE 2

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
#define MAG_CTR LCA(KC_SPC)   // Magnet center
#define MAG_FUL LCA(KC_ENT)   // Magnet full

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
// clang-format on
