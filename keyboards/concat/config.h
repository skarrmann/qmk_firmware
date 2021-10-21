/*
Copyright 2020 Steven Karrmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER Steven Karrmann
#define PRODUCT      Concat

/* key matrix size */
#define MATRIX_ROWS 2 // Numer of shift registers
#define MATRIX_COLS 16 // Number of keys per shift register
#define MATRIX_PIN_COUNT 2 // Number of input pins on IC

#define SR_DATA_PIN E6
#define SR_LATCH_PIN B4
#define SR_CLOCK_PIN B5
#define MATRIX_PINS { B1, B2 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
