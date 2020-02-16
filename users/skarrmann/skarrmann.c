#include "skarrmann.h"

// Layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode) {
  // Handle layer-specific tapping term
  if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
    uint16_t layer = ((keycode & 0x0F00) >> 8);
    switch (layer) {
      case _HOME1:
      case _HOME2:
      case _HOME3:
      case _HOME4:
        return TAPPING_TERM_LONG;
    }
  }

  // Handle basic key-spefic tapping term
  uint16_t basic_keycode = (keycode & 0x00FF);
  switch (basic_keycode) {
    case KC_ENT:
      return TAPPING_TERM_SHORT;
    case KC_SPC:
      return TAPPING_TERM_LONG;
  }

  return TAPPING_TERM;
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  // Enable tapping force hold for specific basic keys
  uint16_t basic_keycode = (keycode & 0x00FF);
  switch (basic_keycode) {
    case KC_SPC:
    case KC_ENT:
      return true;
  }

  return false;
}
