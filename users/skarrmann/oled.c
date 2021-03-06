#include "skarrmann.h"

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
	case HOM:
	    oled_write_P(PSTR("Home mods\n"), false);
	    break;
        case SYM:
            oled_write_P(PSTR("Symbol\n"), false);
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
    if (is_keyboard_master()) {
        render_status(); 
    }
}
#endif
