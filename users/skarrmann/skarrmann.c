#include "skarrmann.h"

#define SYM_TAB LT(SYM, KC_TAB)
#define FUN_SPC LT(FUN, KC_SPC)
#define TO_DEF  TO(DEF)
#define TG_GAM  TG(GAM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_skarrmann(
        KC_SCLN, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_MINS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_RSFT,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , TO_DEF , TG_GAM , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
        KC_LALT, KC_LGUI, TO_DEF , KC_ESC , KC_DEL , SYM_TAB, KC_ESC , KC_ENT , FUN_SPC, KC_BSPC, KC_ENT , TG_GAM , KC_RGUI, KC_RALT
    ),

    [SYM] = LAYOUT_skarrmann(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
        KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_EQL , KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
        KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC, _______, _______, KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______
    ),

    [FUN] = LAYOUT_skarrmann(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   KC_SLCK, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, _______,
        _______, _______, _______, _______, _______, KC_TAB , _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [GAM] = LAYOUT_skarrmann(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_TAB , _______, _______, KC_SPC , _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FUN_SPC:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
