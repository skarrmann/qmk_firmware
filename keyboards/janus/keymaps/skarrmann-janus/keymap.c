// Copyright 2023 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../../../../users/skarrmann/oneshot.h"

enum layer_names {
    _BASE,
    _SYMBOL,
    _NAVIGATION,
    _FUNCTION
};

enum keycodes {
    OSMLCTL = SAFE_RANGE,
    OSMLSFT,
    OSMLALT,
    OSMLGUI,
    OSMRCTL,
    OSMRSFT,
    OSMRALT,
    OSMRGUI
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
        OSMLGUI, OSMLALT, OSMLSFT, OSMLCTL, XXXXXXX, KC_SPC , OSMRCTL, OSMRSFT, OSMRALT, OSMRGUI,
                                   MO_FUN , _______, _______, _______
    ),
    [_NAVIGATION] = LAYOUT_split_3x5_2(
        KC_PSCR, KC_INS , KC_APP , KC_DEL , XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
        KC_ESC , KC_TAB , KC_ENT , KC_BSPC, XXXXXXX, KC_PAUS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
        OSMLGUI, OSMLALT, OSMLSFT, OSMLCTL, XXXXXXX, XXXXXXX, OSMRCTL, OSMRSFT, OSMRALT, OSMRGUI,
                                   _______, _______, _______, MO_FUN
    ),
    [_FUNCTION] = LAYOUT_split_3x5_2(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , QK_BOOT, KC_SCRL, KC_MPLY, KC_MPRV, KC_MNXT, KC_BRIU,
        KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID,
        KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_NUM , OSMRCTL, OSMRSFT, OSMRALT, OSMRGUI,
                                   _______, _______, _______, _______
    ),
};

uint16_t get_oneshot_keycode(uint16_t keycode) {
    switch (keycode) {
        case OSMLCTL: return KC_LCTL;
        case OSMLSFT: return KC_LSFT;
        case OSMLALT: return KC_LALT;
        case OSMLGUI: return KC_LGUI;
        case OSMRCTL: return KC_RCTL;
        case OSMRSFT: return KC_RSFT;
        case OSMRALT: return KC_RALT;
        case OSMRGUI: return KC_RGUI;
        default: return 0;
    }
}

bool is_oneshot_ignore(uint16_t keycode) {
    switch (keycode) {
        case MO_FUN:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return update_oneshot(keycode, record);
}