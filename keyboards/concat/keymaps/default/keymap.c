/* Copyright 2020 Steven Karrmann
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = {
        LAYOUT_concat(                                                          \
                 KC_DEL , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,          \
                 KC_TAB , KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,          \
                 KC_ESC , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,          \
        KC_ESC , KC_PGUP, KC_GRV , KC_LBRC, KC_RBRC, KC_LALT, KC_LSFT, KC_LCTL, \
        KC_HOME, KC_PGDN, KC_END ,                   KC_DEL , KC_SPC , KC_ESC),
        LAYOUT_concat(                                                          \
                 KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_MINS,          \
                 KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,          \
                 KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,          \
        KC_RCTL, KC_RSFT, KC_RALT, KC_EQL , KC_RBRC, KC_INS , KC_UP  , KC_LCTL, \
        KC_ENT , KC_SPC , KC_BSPC,                   KC_LEFT, KC_DOWN, KC_RGHT)
    }
};


#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
