#include "skarrmann.h"

// Custom key names
#define SYM_TAB LT(SYM, KC_TAB)
#define FUN_SPC LT(FUN, KC_SPC)

#define GUI_ESC LGUI_T(KC_ESC)
#define GUI_ENT RGUI_T(KC_ENT)

#define TG_SYM  TG(SYM)
#define TG_FUN  TG(FUN)
#define TG_NAV  TG(NAV)
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

// Layer key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_skarrmann(
    KC_LALT, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_RALT,
    KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_RSFT,
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
    KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_SCLN, KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
    KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC,                   KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS,
                                        _______, _______, _______, _______, KC_MINS, KC_EQL 
  ),

  [FUN] = LAYOUT_skarrmann(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   TG_HOM , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   EEP_RST, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_CAPS,                   TG_GAM , KC_MUTE, KC_VOLD, KC_VOLU, KC_APP , _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [GAM] = LAYOUT_skarrmann(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                        KC_TAB , KC_SPC , _______, _______, _______, _______
  ),

};


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

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

  // Key-specific tapping terms
  uint16_t basic_keycode = (keycode & 0x00FF);
  switch (basic_keycode) {
    case KC_SPC:
      return TAPPING_TERM_K_SPC;
  }

  // Mod tapping terms
  if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
    uint16_t mod = mod_config((keycode >> 0x8) & 0x1F);
    switch (mod) {
      case MOD_LSFT:
      case MOD_RSFT:
        return TAPPING_TERM_M_SFT;
      case MOD_LCTL:
      case MOD_RCTL:
        return TAPPING_TERM_M_CTL;
      case MOD_LALT:
      case MOD_RALT:
        return TAPPING_TERM_M_ALT;
      case MOD_LGUI:
      case MOD_RGUI:
        return TAPPING_TERM_M_GUI;
      default:
        return TAPPING_TERM_M_MLT;
    }
  }

  // Layer tapping terms
  if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
    uint16_t layer = ((keycode & 0x0F00) >> 0x8);
    switch (layer) {
      // Add entries for any layers with their own tapping terms
      // case _NUMBER:
      // case _FUNCTION:
      //   return TAPPING_TERM_L_BASE;
    }
  }

  return TAPPING_TERM;
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  uint16_t basic_keycode = (keycode & 0x00FF);
  switch (basic_keycode) {
    case KC_DEL:
    case KC_BSPC:
    case KC_UP:
    case KC_DOWN:
    case KC_LEFT:
    case KC_RIGHT:
      return false;
  }

  if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
    uint16_t layer = ((keycode & 0x0F00) >> 0x8);
    switch (layer) {
      case SYM:
      case FUN:
        return true;
    }
  }

  return false;
}

// Combos
#ifdef COMBO_ENABLED
enum combos {
};


combo_t key_combos[COMBO_COUNT] = {
};
#endif
