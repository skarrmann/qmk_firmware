// Copyright 2022 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "oneshot.h"

bool update_oneshot(
    uint16_t oneshot_keycode,
    bool *oneshot_active,
    uint16_t queued_oneshot_keycodes[ONESHOT_QUEUE_SIZE],
    uint16_t keycode,
    keyrecord_t *record
) {
    if (oneshot_keycode > 0) {
        if (record->event.pressed) {
            *oneshot_active = true;
            register_code(oneshot_keycode);
        } else {
            if (*oneshot_active) {
                for (int i = 0; i < ONESHOT_QUEUE_SIZE; i++ ) {
                    if (queued_oneshot_keycodes[i] == 0 || queued_oneshot_keycodes[i] == oneshot_keycode) {
                        queued_oneshot_keycodes[i] = oneshot_keycode;
                        break;
                    }
                }
            } else {
                unregister_code(oneshot_keycode);
            }
        }
        return true;
    }
        
    if (*oneshot_active && record->event.pressed) {
        register_code(keycode);
        *oneshot_active = false;
        for (int i = 0; i < ONESHOT_QUEUE_SIZE; i++ ) {
            if (queued_oneshot_keycodes[i] != 0) {
                unregister_code(queued_oneshot_keycodes[i]);
                queued_oneshot_keycodes[i] = 0;
            } else {
                break;
            }
        }
        return false;
    }

    return true;
}