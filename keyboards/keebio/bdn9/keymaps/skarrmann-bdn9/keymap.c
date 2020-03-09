#include QMK_KEYBOARD_H

enum _layers {
  _NAV = 0,
  _EDIT,
  _MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: STab/Tab  |            | Knob 2: Page Dn/Up      |
        | Press: Enter      | Layer 1    | Press: Ctrl + Shift + P |
        | Alt + Left        | Up         | Alt + Right             |
        | Left              | Down       | Right                   |
     */
    [_NAV] = LAYOUT(
        KC_ENT       , TO(1)  , LCTL(LSFT(KC_P)),
        LALT(KC_LEFT), KC_UP  , LALT(KC_RGHT)   ,
        KC_LEFT      , KC_DOWN, KC_RGHT
    ),
    /*
        | Knob 1: Undo/Redo |          | Knob 2: Undo/Redo |
        | Ctrl + Q          | Layer 2  | Ctrl + O          |
        | Ctrl + A          | Ctrl + S | Ctrl + F          |
        | Cut               | Copy     | Paste             |
     */
    [_EDIT] = LAYOUT(
        LCTL(KC_Q), TO(2)     , LCTL(KC_Q),
        LCTL(KC_A), LCTL(KC_S), LCTL(KC_F),
        KC_CUT    , KC_COPY   , KC_PSTE
    ),
    /*
        | Knob 1: Vol+/Vol- |                | Knob 2: Media P/N  |
        | Press: Mute       | Layer 0        | Press: Media Play  |
        | RGB Toggle        | Backlight      | Media Stop         |
        |                   |                |                    |
     */
    [_MEDIA] = LAYOUT(
        KC_MUTE, TO(0)  , KC_MPLY,
        RGB_TOG, BL_STEP, KC_MSTP,
        RGB_M_P, KC_NO  , KC_NO
    	),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
            case _NAV:
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
		    register_code(KC_LSFT);
                    tap_code(KC_TAB);
		    unregister_code(KC_LSFT);
                }
                break;
            case _EDIT:
                if (clockwise) {
		    register_code(KC_LCTL);
                    tap_code(KC_Y);
		    unregister_code(KC_LCTL);
                } else {
		    register_code(KC_LCTL);
                    tap_code(KC_Z);
		    unregister_code(KC_LCTL);
                }
                break;
            case _MEDIA:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    else if (index == 1) {
        switch(biton32(layer_state)) {
            case _NAV:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _EDIT:
                if (clockwise) {
		    register_code(KC_LCTL);
                    tap_code(KC_Y);
		    unregister_code(KC_LCTL);
                } else {
		    register_code(KC_LCTL);
                    tap_code(KC_Z);
		    unregister_code(KC_LCTL);
                }
                break;
            case _MEDIA:
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _NAV:
            rgblight_setrgb(0x00, 0x33, 0xAA);
            break;
        case _EDIT:
            rgblight_setrgb(0xAA, 0x00, 0x33);
            break;
        case _MEDIA:
            rgblight_setrgb(0x33, 0xAA, 0x00);
            break;
        default:
            break;
    }
     return state;
}
