#include "skarrmann.h"

// Layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode) {

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
    uint16_t layer = ((keycode & 0x0F00) >> 8);
    switch (layer) {
      case _BASE1:
      case _BASE2:
      case _BASE3:
      case _BASE4:
        return TAPPING_TERM_L_BASE;
    }
  }

  return TAPPING_TERM;
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  // Enable tapping force hold for specific basic keys
  uint16_t basic_keycode = (keycode & 0x00FF);
  switch (basic_keycode) {
    case KC_DEL:
    case KC_BSPC:
      return false;
  }

  return true;
}
