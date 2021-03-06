#include "skarrmann.h"

// Custom key names
#define SYM_TAB LT(SYM, KC_TAB)
#define FUN_SPC LT(FUN, KC_SPC)

#define MO_SYM  MO(SYM)
#define MO_FUN  MO(FUN)

#define ALT_MIN RALT_T(KC_MINS)
#define SFT_QUO RSFT_T(KC_QUOT)
#define GUI_ESC LGUI_T(KC_ESC)
#define GUI_ENT RGUI_T(KC_ENT)

#define TG_SYM  TG(SYM)
#define TG_FUN  TG(FUN)
#define TG_GAM  TG(GAM)
#define TG_HOM  TG(HOM)

#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_skarrmann(
    KC_LALT, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, ALT_MIN,
    KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , SFT_QUO,
    KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                        KC_DEL , SYM_TAB, GUI_ESC, GUI_ENT, FUN_SPC, KC_BSPC
  ),

  [HOM] = LAYOUT_skarrmann(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, HOME_A , HOME_R , HOME_S , HOME_T , _______,                   _______, HOME_N , HOME_E , HOME_I , HOME_O , _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [SYM] = LAYOUT_skarrmann(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
    KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_EQL , KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
    KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC,                   KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS,
                                        _______, _______, _______, _______, KC_SPC , _______
  ),

  [FUN] = LAYOUT_skarrmann(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   TG_HOM , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_RALT,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   EEP_RST, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_RSFT,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_CAPS,                   TG_GAM , KC_MUTE, KC_VOLD, KC_VOLU, KC_APP , _______,
                                        KC_RCTL, KC_TAB , KC_LGUI, _______, _______, _______
  ),

  [GAM] = LAYOUT_skarrmann(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                        KC_TAB , KC_SPC , _______, _______, _______, _______
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


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return true;
}
#endif
