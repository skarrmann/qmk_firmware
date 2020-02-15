#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _COLEMAK,
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
#define OSM_CL  OSM(MOD_LCTL)
#define CL_DEL  MT(MOD_LCTL, KC_DEL)
#define CR_BSPC MT(MOD_RCTL, KC_BSPC)
#define OSM_SL  OSM(MOD_LSFT)
#define SL_ESC  MT(MOD_LSFT, KC_ESC)
#define SR_ENT  MT(MOD_RSFT, KC_ENT)
#define OSL_L   OSL(_LOWER)
#define LL_TAB  LT(_LOWER, KC_TAB)
#define LR_SPC  LT(_RAISE, KC_SPC)
#define HT1(k)  LT(_HOME1, k)
#define HT2(k)  LT(_HOME2, k)
#define HT3(k)  LT(_HOME3, k)
#define HT4(k)  LT(_HOME4, k)
#define DF_QWRT DF(_QWERTY)
#define DF_CLMK DF(_COLEMAK)
#define TG_STND TG(_STANDARD)
