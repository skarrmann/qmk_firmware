#pragma once

#include QMK_KEYBOARD_H

#include "wrappers.h"

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
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
#define OSL_LL  OSL(_LOWER)
#define LR_SPC  LT(_RAISE, KC_SPC)
#define TG_STND TG(_STANDARD)
