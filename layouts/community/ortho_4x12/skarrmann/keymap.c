#include "skarrmann.h"

#define LAYOUT_ortho_4x12_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
    KC_TAB ,  K01    , K02    , K03    , K04    , K05   , K06    , K07    , K08    , K09    , K0A    , KC_MINS, \
    OSM_SL ,  K11    , K12    , HT1(K13), HT2(K14), K15 , K16    , HT3(K17), HT4(K18), K19  , K1A    , KC_QUOT, \
    KC_EQL ,  K21    , K22    , K23    , K24    , K25   , K26    , K27    , K28    , K29    , K2A    , SR_ENT , \
    KC_ESC ,  KC_LGUI, KC_APP , KC_LALT, CL_DEL , OSL_L , LR_SPC , CR_BSPC, KC_RALT, KC_INS , KC_CAPS, TG_STND  \
  )

#define LAYOUT_ortho_4x12_base_wrapper(...) LAYOUT_ortho_4x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, \
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, \
  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________  \
),

[_COLEMAK] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, \
  _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, \
  _________________COLEMAK_L3________________, _________________COLEMAK_R3________________  \
),

[_LOWER] = LAYOUT_ortho_4x12_wrapper( \
  _____________________LOWER__L1______________________, _____________________LOWER__R1______________________, \
  _____________________LOWER__L2______________________, _____________________LOWER__R2______________________, \
  _____________________LOWER__L3______________________, _____________________LOWER__R3______________________, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_ortho_4x12_wrapper( \
  _____________________RAISE__L1______________________, _____________________RAISE__R1______________________, \
  _____________________RAISE__L2______________________, _____________________RAISE__R2______________________, \
  _____________________RAISE__L3______________________, _____________________RAISE__R3______________________, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_ADJUST] = LAYOUT_ortho_4x12_wrapper( \
  _____________________ADJUST_L1______________________, _____________________ADJUST_R1______________________, \
  _____________________ADJUST_L2______________________, _____________________ADJUST_R2______________________, \
  _____________________ADJUST_L3______________________, _____________________ADJUST_R3______________________, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

// Standard: Remove custom layer and mod keys
[_STANDARD] = LAYOUT_ortho_4x12_wrapper( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_LSFT, _______, _______, KC_D   , KC_F   , _______, _______, KC_J   , KC_K   , _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_SPC , KC_SPC , _______, _______, _______, _______, _______  \
),

[_HOME1] = LAYOUT_ortho_4x12_wrapper( \
  _______, _______, _______, _______, _______, _______, _____________________HOME1__R1______________________, \
  _______, _______, _______, _______, _______, _______, _____________________HOME1__R2______________________, \
  _______, _______, _______, _______, _______, _______, _____________________HOME1__R3______________________, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_HOME2] = LAYOUT_ortho_4x12_wrapper( \
  _______, _______, _______, _______, _______, _______, _____________________HOME2__R1______________________, \
  _______, _______, _______, _______, _______, _______, _____________________HOME2__R2______________________, \
  _______, _______, _______, _______, _______, _______, _____________________HOME2__R3______________________, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_HOME3] = LAYOUT_ortho_4x12_wrapper( \
  _____________________HOME3__L1______________________, _______, _______, _______, _______, _______, _______, \
  _____________________HOME3__L2______________________, _______, _______, _______, _______, _______, _______, \
  _____________________HOME3__L3______________________, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_HOME4] = LAYOUT_ortho_4x12_wrapper( \
  _____________________HOME4__L1______________________, _______, _______, _______, _______, _______, _______, \
  _____________________HOME4__L2______________________, _______, _______, _______, _______, _______, _______, \
  _____________________HOME4__L3______________________, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

};
