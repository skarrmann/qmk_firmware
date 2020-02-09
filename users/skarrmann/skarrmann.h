#pragma once

#include QMK_KEYBOARD_H

// Layer declarations
enum userspace_layers {
  _QWERTY = 0,
  _STANDARD,
  _HOME1,
  _HOME2,
  _HOME3,
  _HOME4,
  _HOME5,
  _HOME6,
  _HOME7,
  _HOME8,
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
#define LH1_QWE LT(_HOME1, KC_A)
#define LH2_QWE LT(_HOME2, KC_S)
#define LH3_QWE LT(_HOME3, KC_D)
#define LH4_QWE LT(_HOME4, KC_F)
#define LH5_QWE LT(_HOME5, KC_J)
#define LH6_QWE LT(_HOME6, KC_K)
#define LH7_QWE LT(_HOME7, KC_L)
#define LH8_QWE LT(_HOME8, KC_QUOT)
#define TG_STND TG(_STANDARD)

