// Copyright 2022 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "oneshot.h"

enum layer_names {
    _BASE,
    _SYMBOL,
    _NAVIGATION,
    _FUNCTION
};

enum keycodes {
    OS_LCTL = SAFE_RANGE,
    OS_LSFT,
    OS_LALT,
    OS_LGUI,
    OS_RCTL,
    OS_RSFT,
    OS_RALT,
    OS_RGUI
};

#define MO_SYM MO(_SYMBOL)
#define MO_NAV MO(_NAVIGATION)
#define MO_FUN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
        KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT,
        KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   ,
        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                                   MO_NAV , KC_LSFT, KC_SPC, MO_SYM
    ),
    [_SYMBOL] = LAYOUT_split_3x5_2(
        KC_SCLN, KC_LBRC, KC_RBRC, KC_5   , XXXXXXX, XXXXXXX, KC_6   , KC_MINS, KC_EQL , KC_GRV ,
        KC_1   , KC_2   , KC_3   , KC_4   , KC_BSLS, XXXXXXX, KC_7   , KC_8   , KC_9   , KC_0   ,
        OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, XXXXXXX, KC_SPC , OS_RCTL, OS_RSFT, OS_RALT, OS_RGUI,
                                   MO_FUN , _______, _______, _______
    ),
    [_NAVIGATION] = LAYOUT_split_3x5_2(
        KC_PSCR, KC_INS , KC_APP , KC_DEL , XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
        KC_ESC , KC_TAB , KC_ENT , KC_BSPC, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
        OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, XXXXXXX, XXXXXXX, OS_RCTL, OS_RSFT, OS_RALT, OS_RGUI,
                                   _______, _______, _______, MO_FUN
    ),
    [_FUNCTION] = LAYOUT_split_3x5_2(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , QK_BOOT, KC_SCRL, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS,
        OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, XXXXXXX, KC_NUM , OS_RCTL, OS_RSFT, OS_RALT, OS_RGUI,
                                   _______, _______, _______, _______
    ),
};

uint16_t get_oneshot_keycode(uint16_t keycode) {
    switch (keycode) {
        case OS_LCTL: return KC_LCTL;
        case OS_LSFT: return KC_LSFT;
        case OS_LALT: return KC_LALT;
        case OS_LGUI: return KC_LGUI;
        case OS_RCTL: return KC_RCTL;
        case OS_RSFT: return KC_RSFT;
        case OS_RALT: return KC_RALT;
        case OS_RGUI: return KC_RGUI;
        default: return 0;
    }
}

bool is_oneshot_ignore(uint16_t keycode) {
    switch (keycode) {
        case KC_LSFT:
        case MO_FUN:
            return true;
        default:
            return false;
    }
}

bool oneshot_active = false;
uint16_t queued_oneshot_keycodes[ONESHOT_QUEUE_SIZE] = { 0 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!is_oneshot_ignore(keycode)) {
        return update_oneshot(
            get_oneshot_keycode(keycode),
            &oneshot_active,
            queued_oneshot_keycodes,
            keycode,
            record
        );
    }

    return true;
}