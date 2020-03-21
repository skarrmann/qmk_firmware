#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _SYMBOL,
  _NUMBER,
  _UTILITY,
  _STANDARD,
};

// Custom keycodes
#define DF_QWRT DF(_QWERTY)
#define DF_CLMK DF(_COLEMAK)
#define DF_STND DF(_STANDARD)
