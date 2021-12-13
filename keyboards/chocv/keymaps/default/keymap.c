/* Copyright 2021 Steven Karrmann
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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SYMBOL,
    _FUNCTION
};

#define MO_SYMB MO(_SYMBOL)
#define MO_FUNC MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,  KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT,
        KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,  KC_H   , KC_N   , KC_E   , KC_I   , KC_O,
        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                          KC_LALT, KC_LCTL, KC_LSFT,  KC_SPC, MO_SYMB, MO_FUNC
    ),
    [_SYMBOL] = LAYOUT(
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
        KC_GRV , KC_SCLN, KC_EQL , KC_MINS, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
        _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
                          _______, _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_CAPS, KC_SLCK, KC_NLCK, _______,
        KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_INS , KC_PSCR, KC_PAUS, _______,
        KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
                          _______, _______, _______, _______, _______, _______
    )
};
