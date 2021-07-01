#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _GAME,
  _SYMBOL,
  _NAVIGATE,
  _FUNCTION,
};

// Custom keycodes
enum userspace_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
};

// Convenience keycode macros
#define TG_SYMB TG(_SYMBOL)
#define TG_FUNC TG(_FUNCTION)
#define TG_GAME TG(_GAME)
