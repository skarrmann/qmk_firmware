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

// See config.h for layout mapping to LAYOUT_skarrmann
// See /users/skarrmann/skarrmann.c for LAYOUT_skarrmann layout mappings

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void render_base_layer_status(void) {
    oled_write_P(PSTR("Base: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case DEF:
            oled_write_P(PSTR("Default\n"), false);
            break;
	default:
            oled_write_P(PSTR("\n"), false);
	    break;
    }
}

void render_custom_layer_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case SYM:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
	case NAV:
            oled_write_P(PSTR("Navigate\n"), false);
	    break;
	case FUN:
            oled_write_P(PSTR("Function\n"), false);
	    break;
	case GAM:
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
