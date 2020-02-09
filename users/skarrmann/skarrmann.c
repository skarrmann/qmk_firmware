#include "skarrmann.h"

// Layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LR_SPC:
    case LH1_QWE:
    case LH2_QWE:
    case LH3_QWE:
    case LH4_QWE:
    case LH5_QWE:
    case LH6_QWE:
    case LH7_QWE:
    case LH8_QWE:
      return TAPPING_TERM_LONG;
    default:
      return TAPPING_TERM;
  }
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LR_SPC:
    case SR_ENT:
      return true;
    default:
      return false;
  }
}
