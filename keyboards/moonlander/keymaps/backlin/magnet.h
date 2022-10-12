/* Magnet keys
 *
 *         Left Center Right
 *      ┌──────┬──────┬──────┐
 *  1/3 │      |      |      |
 *      ├──────┼──────┼──────┤
 *  1/2 │      |      |      |
 *      └──────┴──────┴──────┘
 */

#pragma once

uint8_t magnet_down(uint8_t state, uint16_t keycode);
void magnet_up(uint8_t state);
void process_magnet(uint16_t keycode, bool down);

// clang-format off
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
