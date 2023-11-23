// Copyright 2023 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "oneshot.h"

bool oneshot_active = false;
uint16_t queued_oneshot_keycodes[ONESHOT_QUEUE_SIZE] = { 0 };

bool update_oneshot(uint16_t keycode, keyrecord_t *record) {
    if (is_oneshot_ignore(keycode)) {
        return true;
    }

    int16_t oneshot_keycode = get_oneshot_keycode(keycode);

    if (oneshot_keycode > 0) {
        if (record->event.pressed) {
            oneshot_active = true;
            register_code(oneshot_keycode);
        } else {
            if (oneshot_active) {
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
        
    if (oneshot_active && record->event.pressed) {
        register_code(keycode);
        oneshot_active = false;
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