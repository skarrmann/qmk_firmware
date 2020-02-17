#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _DVORAK,
  _STANDARD,
  _BASE1,
  _BASE2,
  _BASE3,
  _BASE4,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Custom keycodes
#define DF_QWRT DF(_QWERTY)
#define DF_CLMK DF(_COLEMAK)
#define DF_DVRK DF(_DVORAK)
#define DF_STND DF(_STANDARD)
