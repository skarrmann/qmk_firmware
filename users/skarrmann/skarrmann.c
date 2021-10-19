#include "skarrmann.h"

#define MO_SYM  MO(SYM)
#define MO_FUN  MO(FUN)
#define TO_DEF  TO(DEF)
#define TG_GAM  TG(GAM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_skarrmann(
        KC_GRV , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_MINS,
        KC_EQL , KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_DEL , KC_BSPC, KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
        KC_LALT, KC_LGUI, _______, _______, KC_TAB , KC_LSFT, MO_SYM , MO_FUN , KC_SPC , KC_ENT , _______, _______, KC_RGUI, KC_RALT
    ),

    [SYM] = LAYOUT_skarrmann(
        KC_TILD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
        KC_PLUS, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_HASH, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
        _______, KC_AT  , KC_LBRC, KC_RBRC, KC_BSLS, KC_PERC, _______, _______, KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [FUN] = LAYOUT_skarrmann(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   KC_SLCK, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_APP , _______, _______, KC_NLCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [GAM] = LAYOUT_skarrmann(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

};
