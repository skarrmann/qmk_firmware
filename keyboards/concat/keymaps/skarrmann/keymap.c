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

#include "skarrmann.h"

#define LAYOUT_concat_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_concat_base_left( \
  K11, K12, K13, K14, K15, \
  K21, K22, K23, K24, K25, \
  K31, K32, K33, K34, K35  \
) \
LAYOUT_concat_wrapper( \
           _______, NUMROW_L0__________________________________,          \
           B_LO1  , K11    , K12    , K13    , K14    , K15    ,          \
           B_LO2  , B_LH_MODS(K21, K22, K23, K24)     , K25    ,          \
  _______, B_LO3  , K31    , K32    , K33    , K34    , K35    , B_LI3  , \
  _______, _______, _______,                   B_LB2  , B_LB1  , B_LI4    \
)

#define LAYOUT_concat_base_left_wrapper(...) LAYOUT_concat_base_left(__VA_ARGS__)

#define LAYOUT_concat_base_right( \
  K11, K12, K13, K14, K15, \
  K21, K22, K23, K24, K25, \
  K31, K32, K33, K34, K35  \
) \
LAYOUT_concat_wrapper( \
           _______, NUMROW_R0__________________________________,          \
           K11    , K12    , K13    , K14    , K15    , B_RO1  ,          \
           K21    , B_RH_MODS(K22, K23, K24, K25)     , B_RO2  ,          \
  B_RI3  , K31    , K32    , K33    , K34    , K35    , B_RO3  , _______, \
  B_RI4  , B_RB1  , B_RB2  ,                   _______, _______, _______  \
)

#define LAYOUT_concat_base_right_wrapper(...) LAYOUT_concat_base_right(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_QWERTY] = {
        LAYOUT_concat_base_left_wrapper( \
            QWERTY_L1__________________________________, \
            QWERTY_L2__________________________________, \
            QWERTY_L3__________________________________),
        LAYOUT_concat_base_right_wrapper( \
            QWERTY_R1__________________________________, \
            QWERTY_R2__________________________________, \
            QWERTY_R3__________________________________)
    },
    [_COLEMAK] = {
        LAYOUT_concat_base_left_wrapper( \
            COLEMAK_L1_________________________________, \
            COLEMAK_L2_________________________________, \
            COLEMAK_L3_________________________________),
        LAYOUT_concat_base_right_wrapper( \
            COLEMAK_R1_________________________________, \
            COLEMAK_R2_________________________________, \
            COLEMAK_R3_________________________________)
    },
    [_SYMBOL] = {
	LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
		 SYMBOL_L1___________________________________________,          \
		 SYMBOL_L2___________________________________________,          \
        _______, SYMBOL_L3___________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______),
	LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
		 SYMBOL_R1___________________________________________,          \
		 SYMBOL_R2___________________________________________,          \
        _______, SYMBOL_R3___________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______)
    },
    [_NAVIGATE] = {
        LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
                 NAVIGATE_L1_________________________________________,          \
                 NAVIGATE_L2_________________________________________,          \
        _______, NAVIGATE_L3_________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______),
        LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
                 NAVIGATE_R1_________________________________________,          \
                 NAVIGATE_R2_________________________________________,          \
        _______, NAVIGATE_R3_________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______)
    },
    [_FUNCTION] = {
        LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
                 FUNCTION_L1_________________________________________,          \
                 FUNCTION_L2_________________________________________,          \
        _______, FUNCTION_L3_________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______),
        LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
                 FUNCTION_R1_________________________________________,          \
                 FUNCTION_R2_________________________________________,          \
        _______, FUNCTION_R3_________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______)
    },
    [_GAME] = {
	LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
		 GAME_L1_____________________________________________,          \
		 GAME_L2_____________________________________________,          \
        _______, GAME_L3_____________________________________________, _______, \
        _______, _______, _______,                   _______, KC_SPC , _______),
	LAYOUT_concat_wrapper( \
                 _______, _______, _______, _______, _______, _______,          \
		 GAME_R1_____________________________________________,          \
		 GAME_R2_____________________________________________,          \
	_______, GAME_R3_____________________________________________, _______, \
        _______, _______, _______,                   _______, _______, _______)
    }
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void render_base_layer_status(void) {
    oled_write_P(PSTR("Base: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
	    break;
	default:
            oled_write_P(PSTR("\n"), false);
	    break;
    }
}

void render_custom_layer_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _SYMBOL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
	case _NAVIGATE:
            oled_write_P(PSTR("Navigate\n"), false);
	    break;
	case _FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
	    break;
	case _GAME:
	    oled_write_P(PSTR("Game\n"), false);
	    break;
	default:
            oled_write_P(PSTR("\n"), false);
	    break;
    }
}

void render_mod_status(void) {
    uint8_t mod_state = get_mods();
    oled_write_P(PSTR("Mod: "), false);
    oled_write_P((mod_state & MOD_MASK_SHIFT) ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_P((mod_state & MOD_MASK_CTRL)  ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_P((mod_state & MOD_MASK_ALT)   ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mod_state & MOD_MASK_GUI)   ? PSTR("OS")   : PSTR("  ")  , false);
    oled_write_P(PSTR("\n"), false);
}

void render_lock_status(void) {
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void render_status(void) {
    oled_write_P(PSTR("Keymap: skarrmann\n\n"), false);
    render_base_layer_status();
    render_custom_layer_status();
    render_mod_status();
    render_lock_status();
}

void oled_task_user(void) {
    render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
}
#endif
