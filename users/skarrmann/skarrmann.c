#include "skarrmann.h"

// Layer state
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LR_SPC:
    case LD_D:
    case LK_K:
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
