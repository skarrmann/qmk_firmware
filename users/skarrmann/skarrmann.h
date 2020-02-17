#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
  _DVORAK,
  _STANDARD,
  _HOME1,
  _HOME2,
  _HOME3,
  _HOME4,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Custom keycodes
#define DF_QWRT DF(_QWERTY)
#define DF_CLMK DF(_COLEMAK)
#define DF_DVRK DF(_DVORAK)
#define DF_STND DF(_STANDARD)
