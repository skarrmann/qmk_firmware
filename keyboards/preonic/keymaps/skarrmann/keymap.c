#include QMK_KEYBOARD_H

// Custom keycode names
#define CL_DEL  MT(MOD_LCTL, KC_DEL)
#define CR_BSPC MT(MOD_RCTL, KC_BSPC)
#define OSL_LL  OSL(_LOWER)
#define LR_SPC  LT(_RAISE, KC_SPC)
#define LD_D    LT(_D, KC_D)
#define LF_F    LT(_F, KC_F)
#define LJ_J    LT(_J, KC_J)
#define LK_K    LT(_K, KC_K)
#define TG_MODD TG(_MODDED)
#define TG_MASK TG(_MASK)

enum preonic_layers {
  _QWERTY,
  _MODDED,
  _D,
  _F,
  _J,
  _K,
  _MASK,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 ,-----------------------------------------------------------------------------------------------------------.
 |  Del   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  Bspc  |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |  Tab   |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |   -    |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   ;    |   '    |
 | LShift |        |        | LayerD | LayerF |        |        | LayerJ | LayerK |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |  Esc   |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |   /    | Enter  |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |   [    |        |        |        |  Del   |One Shot| Space  |  Bspc  |        | Insert | Caps   |   ]    |
 |        |  GUI   |  App   |  LAlt  |  LCtl  | Lower  | Raise  |  RCtl  |  RAlt  |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_DEL , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
  KC_LSFT, KC_A   , KC_S   , LD_D   , LF_F   , KC_G   , KC_H   , LJ_J   , LK_K   , KC_L   , KC_QUOT, KC_QUOT, \
  KC_ESC , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT , \
  KC_LBRC, KC_LGUI, KC_APP , KC_LALT, CL_DEL , OSL_LL , LR_SPC , CR_BSPC, KC_RALT, KC_INS , KC_CAPS, KC_RBRC  \
),

/* Lower
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   [    |   ]    |   {    |   }    |        |        |   =    |   +    |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   (    |   )    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |   `    |   ~    |        |        |   \    |   |    |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_GRV , KC_LBRC, KC_RBRC, _______, _______, KC_EQL , KC_PLUS, _______, _______, _______, \
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_PIPE, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        | Reset  | Debug  |        |        |        |        |  Caps  | Insert |        |  PScr  |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        | Modded |  Mask  |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RESET  , DEBUG  , _______, _______, _______, _______, KC_CAPS, KC_INS , _______, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, TG_MODD, TG_MASK, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


/* Modded - Currently unused
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_MODDED] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer D
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        | MwLeft | MwDown |  MwUp  | MwRght |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        | MsAcl0 | [][][] | MsAcl2 |        |        | MsLeft | MsDown |  MsUp  | MsRght |        |
 |        |        |        | [][][] |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |  MsB1  |  MsB2  |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_D] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, \
  _______, _______, KC_ACL0, KC_TRNS, KC_ACL2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_BTN5, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______  \
),

/* Layer F
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |  Home  |  PgDn  |  PgUp  |  End   |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        | [][][] |        |        |  Left  |  Down  |   Up   | Right  |        |
 |        |        |        |        | [][][] |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_F] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, \
  _______, _______, _______, _______, KC_TRNS, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer J
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        | [][][] |        |        |        |        |
 |        |        |        |        |        |        |        | [][][] |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_J] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer K
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        | [][][] |        |        |        |
 |        |        |        |        |        |        |        |        | [][][] |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_K] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Mask (block out the top row)
 ,-----------------------------------------------------------------------------------------------------------.
 | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX |
 | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX | XXXXXX |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_MASK] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LR_SPC:
    case LD_D:
    case LK_K:
      return TAPPING_TERM_LONG;
    default:
      return TAPPING_TERM;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LR_SPC:
      return true;
    default:
      return false;
  }
}
