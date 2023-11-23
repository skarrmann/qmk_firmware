// Copyright 2022 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define ONESHOT_QUEUE_SIZE 16

bool update_oneshot(
    uint16_t oneshot_keycode,
    bool *oneshot_active,
    uint16_t queued_oneshot_keycodes[ONESHOT_QUEUE_SIZE],
    uint16_t keycode,
    keyrecord_t *record
);