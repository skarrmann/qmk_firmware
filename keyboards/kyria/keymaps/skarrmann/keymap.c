#include "skarrmann.h"

#define B_THUMB_L0______ KC_LCTL, KC_LALT
#define B_THUMB_R0______ KC_RALT, KC_RCTL

#define B_THUMB_L1_________________________________ _______, B_B2, B_B4, B_B5, B_B3
#define B_THUMB_R1_________________________________ B_B8, B_B6, B_B7, B_B9, _______

#define LAYOUT_kyria_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_kyria_base( \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
) \
LAYOUT_kyria_wrapper( \
  B_L1   , K11    , K12    , K13    , K14    , K15                                        , K16    , K17    , K18    , K19    , K1A    , B_R1   , \
  B_L2   , B_LH_MODS(K21, K22, K23, K24)     , K25                                        , K26    , B_RH_MODS(K27, K28, K29, K2A)     , B_R2   , \
  B_L3   , K31    , K32    , K33    , K34    , K35    , B_THUMB_L0______, B_THUMB_R0______, K36    , K37    , K38    , K39    , K3A    , B_R3   , \
                             B_THUMB_L1_________________________________, B_THUMB_R1_________________________________                             \
)

#define LAYOUT_kyria_base_wrapper(...) LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_kyria_base_wrapper( \
  QWERTY_L1__________________________________, QWERTY_R1__________________________________, \
  QWERTY_L2__________________________________, QWERTY_R2__________________________________, \
  QWERTY_L3__________________________________, QWERTY_R3__________________________________  \
),

[_COLEMAK] = LAYOUT_kyria_base_wrapper( \
  COLEMAK_L1_________________________________, COLEMAK_R1_________________________________, \
  COLEMAK_L2_________________________________, COLEMAK_R2_________________________________, \
  COLEMAK_L3_________________________________, COLEMAK_R3_________________________________  \
),

[_SYMBOL] = LAYOUT_kyria_wrapper( \
  SYMBOL_L1___________________________________________,                                     SYMBOL_R1___________________________________________, \
  SYMBOL_L2___________________________________________,                                     SYMBOL_R2___________________________________________, \
  SYMBOL_L3___________________________________________, _______, _______, _______, _______, SYMBOL_R3___________________________________________, \
                             _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______ \
),

[_FUNCTION] = LAYOUT_kyria_wrapper( \
  FUNCTION_L1_________________________________________,                                     FUNCTION_R1_________________________________________, \
  FUNCTION_L2_________________________________________,                                     FUNCTION_R2_________________________________________, \
  FUNCTION_L3_________________________________________, _______, _______, _______, _______, FUNCTION_R3_________________________________________, \
                             _______, _______, _______, KC_TAB , _______, _______, _______, _______, _______, _______ \
),

[_GAME] = LAYOUT_kyria_wrapper( \
  GAME_L1_____________________________________________,                                     GAME_R1_____________________________________________, \
  GAME_L2_____________________________________________,                                     GAME_R2_____________________________________________, \
  GAME_L3_____________________________________________, KC_LCTL, KC_LALT, KC_RALT, KC_RCTL, GAME_R3_____________________________________________, \
                             _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______, _______ \
),

};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
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
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
