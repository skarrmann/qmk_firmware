#include QMK_KEYBOARD_H

// Custom keycode names
#define LL_DEL  LT(_LOWER, KC_DEL)
#define LR_ESC  LT(_RAISE, KC_ESC)
#define LM_EQL  LT(_MOUSE, KC_EQL)
#define AL_LBRC MT(MOD_LALT, KC_LBRC)
#define AR_RBRC MT(MOD_RALT, KC_RBRC)
#define CL_DEL  MT(MOD_LCTL, KC_DEL)
#define CR_BSPC MT(MOD_RCTL, KC_BSPC)
#define SL_TAB  MT(MOD_LSFT, KC_TAB)
#define SR_ENT  MT(MOD_RSFT, KC_ENT)
#define TG_MOUS TG(_MOUSE)
#define TG_CLMK TG(_COLEMAK)

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _MOUSE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  =   |      |      |      |      |      |      |      |      |      |      |      |
 * |Mouse |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |      |      |      |      |Enter |
 * |LShift|  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  [   | Del  | Esc  |      | Bksp |  ]   |      |      |      |
 * | LCtl | GUI  | App  | LAlt |Lower |Raise |Space | RCtl | RAlt |Insert|  \   |Mouse |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
  LM_EQL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
  SL_TAB , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SR_ENT , \
  KC_LCTL, KC_LGUI, KC_APP , AL_LBRC, LL_DEL , LR_ESC , KC_SPC , CR_BSPC, AR_RBRC, KC_INS , KC_BSLS, TG_MOUS  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Q   |  W   |  F   |  P   |  G   |  J   |  L   |  U   |  Y   |  ;   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  A   |  R   |  S   |  T   |  D   |  H   |  N   |  E   |  I   |  O   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  K   |  M   |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______, \
  _______, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , _______, \
  _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F1   | F2   | F3   | F4   |      |      | Home | PgDn | PgUp | End  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | F5   | F6   | F7   | F8   |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | F9   | F10  | F11  | F12  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, \
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, \
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |Debug |      |      |      |      | Caps |Insert|      | PScr |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Mouse |Colmak|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RESET  , DEBUG  , _______, _______, _______, _______, KC_CAPS, KC_INS , _______, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______, _______, TG_MOUS, TG_CLMK, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MsB3 | MsB4 | MsB5 |      |      |MwLeft|MwDown| MwUp |MwRght|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | MsB1 | MsB2 |      |      |MsLeft|MsDown| MsUp |MsRght|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |MsAcl0|MsAcl1|MsAcl2|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, \
  _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
  _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, KC_BTN5, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
