#include "skarrmann.h"

// Custom key names
#define FUN_DEL LT(FUN, KC_DEL)
#define SYM_TAB LT(SYM, KC_TAB)
#define NAV_SPC LT(NAV, KC_SPC)
#define ALT_MIN RALT_T(KC_MINS)
#define SFT_QUO RSFT_T(KC_QUOT)
#define TG_SYM  TG(SYM)
#define TG_FUN  TG(FUN)
#define TG_NAV  TG(NAV)
#define TG_GAM  TG(GAM)

// Layer key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_skarrmann(
    KC_LALT, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, ALT_MIN,
    KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,                   KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , SFT_QUO,
    KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                        FUN_DEL, SYM_TAB, KC_ESC , KC_ENT , NAV_SPC, KC_BSPC
  ),

  [SYM] = LAYOUT_skarrmann(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
    KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR,                   KC_PIPE, KC_EQL , KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO,
    KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC,                   KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS,
                                        _______, _______, _______, _______, KC_SPC , _______
  ),

  [NAV] = LAYOUT_skarrmann(
    _______, _______, _______, _______, _______, _______,                   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_APP , _______,
                                        _______, KC_TAB , _______, _______, _______, _______
  ),

  [FUN] = LAYOUT_skarrmann(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR,                   _______, _______, _______, _______, _______, _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS ,                   EEP_RST, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_CAPS,                   TG_GAM , _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [GAM] = LAYOUT_skarrmann(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                        _______, KC_TAB , _______, _______, KC_SPC , _______
  ),
};


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
      case NAV:
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
