#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _SYMBOL,
  _NAVIGATE,
  _FUNCTION,
};

// Custom keycodes
enum userspace_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
};
