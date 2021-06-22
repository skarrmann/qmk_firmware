#include "skarrmann.h"

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
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
  // Enable tapping force hold for specific basic keys
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

  return true;
}

// Combos
enum combos {
  COMBO_BIN_3,
  COMBO_BIN_5,
  COMBO_BIN_6,
  COMBO_BIN_7,
  COMBO_BIN_9,
  COMBO_BIN_0
};

const uint16_t PROGMEM combo_bin_3[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_bin_5[] = {KC_1, KC_4, COMBO_END};
const uint16_t PROGMEM combo_bin_6[] = {KC_2, KC_4, COMBO_END};
const uint16_t PROGMEM combo_bin_7[] = {KC_1, KC_2, KC_4, COMBO_END};
const uint16_t PROGMEM combo_bin_9[] = {KC_1, KC_8, COMBO_END};
const uint16_t PROGMEM combo_bin_0[] = {KC_2, KC_8, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BIN_3] = COMBO(combo_bin_3, KC_3),
  [COMBO_BIN_5] = COMBO(combo_bin_5, KC_5),
  [COMBO_BIN_6] = COMBO(combo_bin_6, KC_6),
  [COMBO_BIN_7] = COMBO(combo_bin_7, KC_7),
  [COMBO_BIN_9] = COMBO(combo_bin_9, KC_9),
  [COMBO_BIN_0] = COMBO(combo_bin_0, KC_0)
};

