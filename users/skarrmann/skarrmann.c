#include "skarrmann.h"
#include "keymap_steno.h"

#define SYM_TAB LT(SYM, KC_TAB)
#define FUN_SPC LT(FUN, KC_SPC)
#define STN_ON  TO(STN)
#define STN_OFF TO(DEF)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_skarrmann(
        KC_SCLN, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_MINS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_RSFT,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , STN_ON , STN_OFF, KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
        KC_LALT, KC_LGUI, _______, _______, KC_DEL , SYM_TAB, KC_ESC , KC_ENT , FUN_SPC, KC_BSPC, _______, _______, KC_RGUI, KC_RALT
    ),

    [SYM] = LAYOUT_skarrmann(
        KC_COLN, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_DQUO, KC_UNDS,
        KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_EQL , KC_LCBR, KC_RCBR, KC_0   , KC_GRV ,
        KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC, _______, _______, KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______
    ),

    [FUN] = LAYOUT_skarrmann(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   KC_SLCK, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_APP , _______, _______, KC_NLCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_PAUS, _______,
        _______, _______, _______, _______, _______, KC_TAB , _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [STN] = LAYOUT_skarrmann(
        STN_FN  , STN_S1 , STN_TL , STN_PL , STN_HL , STN_N4 ,                   STN_N8 , STN_FR , STN_PR , STN_LR , STN_TR , STN_DR  ,
        STN_PWR , STN_S2 , STN_KL , STN_WL , STN_RL , STN_ST2,                   STN_ST3, STN_RR , STN_BR , STN_GR , STN_SR , STN_ZR  ,
        STN_RES1, STN_N1 , STN_N2 , STN_N3 , STN_ST1, STN_N5 , _______, _______, STN_N9 , STN_ST4, STN_NA , STN_NB , STN_NC , STN_RES2,
        _______ , _______, _______, _______, STN_A  , STN_O  , STN_N6 , STN_N7 , STN_E  , STN_U  , _______, _______, _______, _______
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

void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI);
}