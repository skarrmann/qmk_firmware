// Copyright 2023 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define ONESHOT_QUEUE_SIZE 16

extern bool oneshot_active;
extern uint16_t queued_oneshot_keycodes[];

// When keycode is pressed, process the oneshot
bool update_oneshot(uint16_t keycode, keyrecord_t *record);

// Maps the custom oneshot keycode to the real keycode (e.g., OS_LCTL -> KC_LCTL)
uint16_t get_oneshot_keycode(uint16_t keycode);

// Returns whether pressing the specified keycode ignores the oneshot activation
bool is_oneshot_ignore(uint16_t keycode);