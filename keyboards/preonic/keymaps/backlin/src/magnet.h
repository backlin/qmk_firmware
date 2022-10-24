#pragma once
#include "backlin.h"

/* Magnet keys
 *
 *         Left Center Right
 *      ┌──────┬──────┬──────┐
 *  1/3 │      |      |      |
 *      ├──────┼──────┼──────┤
 *  1/2 │      |      |      |
 *      └──────┴──────┴──────┘
 */

void process_magnet(uint16_t keycode, bool down);
uint8_t magnet_pressed(uint8_t state, uint16_t keycode);
void magnet_released(uint8_t state);

// clang-format off
#define MAG_LEFT_12   STATE_BIT1
#define MAG_CENTER    STATE_BIT2 // Not resizing on its own but just moving
#define MAG_RIGHT_12  STATE_BIT3
#define MAG_LEFT_13   STATE_BIT4
#define MAG_CENTER_13 STATE_BIT5
#define MAG_RIGHT_13  STATE_BIT6

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
