#pragma once

#include QMK_KEYBOARD_H

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _STANDARD,
  _D,
  _F,
  _J,
  _K,
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
#define LD_D    LT(_D, KC_D)
#define LF_F    LT(_F, KC_F)
#define LJ_J    LT(_J, KC_J)
#define LK_K    LT(_K, KC_K)
#define TG_STND TG(_STANDARD)

