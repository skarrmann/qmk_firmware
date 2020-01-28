#include QMK_KEYBOARD_H

// Custom keycode names
#define LL_DEL  LT(_LOWER, KC_DEL)
#define LR_BSPC LT(_RAISE, KC_BSPC)
#define LD_D    LT(_D, KC_D)
#define LF_F    LT(_F, KC_F)
#define LJ_J    LT(_J, KC_J)
#define LK_K    LT(_K, KC_K)
#define CL_EQL  MT(MOD_LCTL, KC_EQL)
#define CR_ESC  MT(MOD_RCTL, KC_ESC)
#define SR_ENT  MT(MOD_RSFT, KC_ENT)
#define TG_MODD TG(_MODDED)
#define TG_MOUS TG(_MOUSE)
#define TG_MASK TG(_MASK)

enum preonic_layers {
  _QWERTY,
  _MODDED,
  _D,
  _F,
  _J,
  _K,
  _MOUSE,
  _MASK,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 ,-----------------------------------------------------------------------------------------------------------.
 |   `    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  Bksp  |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |  Tab   |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |   -    |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |   =    |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   ;    |   '    |
 |  LCtl  |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |   /    | Enter  |
 | LShift |        |        |        |        |        |        |        |        |        |        | RShift |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |  Del   |  Bksp  |        |  Esc   |        |        |        |        |
 |  LCtl  |  GUI   |  App   |  LAlt  | Lower  | Raise  | Space  |  RCtl  |  RAlt  | Insert | Mouse  |   \    |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
  CL_EQL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SR_ENT , \
  KC_LCTL, KC_LGUI, KC_APP , KC_LALT, LL_DEL , LR_BSPC, KC_SPC , CR_ESC , KC_RALT, KC_INS , TG_MOUS, KC_BSLS  \
),

/* Lower
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |  F1    |  F2    |  F3    |  F4    |        |        |  Home  |  PgDn  |  PgUp  |  End   |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |  F5    |  F6    |  F7    |  F8    |        |        |  Left  |  Down  |   Up   | Right  |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |  F9    |  F10   |  F11   |  F12   |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, \
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, \
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |   ~    |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   (    |   )    |   `    |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |   [    |   ]    |   |    |   {    |   }    |   \    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_TILD, \
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV , \
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_LCBR, KC_RCBR, KC_BSLS, _______, \
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
 |        |        |        |        |        |        |        | Mouse  | Modded |  Mask  |        |        |
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
  _______, _______, _______, _______, _______, _______, _______, TG_MOUS, TG_MODD, TG_MASK, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


/* Modded - Experimental layer taps
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |   D    |   F    |        |        |   J    |   K    |        |        |        |
 |        |        |        | LayerD | LayerF |        |        | LayerJ | LayerK |        |        |        |
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
  _______, _______, _______, LD_D   , LF_F   , _______, _______, LJ_J   , LK_K   , _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer D
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |   "    |   ?    |   !    |   ~    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        | [][][] |        |        |        |   '    |   ,    |   .    |   -    |        |
 |        |        |        | [][][] |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |   `    |   ;    |   :    |   /    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_D] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_DQUO, KC_QUES, KC_EXLM, KC_TILD, _______, \
  _______, _______, _______, KC_TRNS, _______, _______, _______, KC_QUOT, KC_COMM, KC_DOT , KC_MINS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_GRV , KC_SCLN, KC_COLN, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer F
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |   [    |   ]    |   {    |   }    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        | [][][] |        |        |   (    |   )    |   <    |   >    |        |
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
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, KC_TRNS, _______, _______, KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer J
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   1    |   3    |   5    |   7    |   9    |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   0    |   2    |   4    |   6    |   8    |        | [][][] |        |        |        |        |
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
  _______, KC_1   , KC_3   , KC_5   , KC_7   , KC_9   , _______, _______, _______, _______, _______, _______, \
  _______, KC_0   , KC_2   , KC_4   , KC_6   , KC_8   , _______, KC_TRNS, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Layer K
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   ^    |   *    |   &    |   |    |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   @    |   #    |   =    |   _    |        |        |        | [][][] |        |        |        |
 |        |        |        |        |        |        |        |        | [][][] |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   \    |   %    |   $    |   +    |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_K] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_CIRC, KC_ASTR, KC_AMPR, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_AT  , KC_HASH, KC_EQL , KC_UNDS, _______, _______, _______, KC_TRNS, _______, _______, _______, \
  _______, KC_BSLS, KC_PERC, KC_DLR , KC_PLUS, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Mouse
 ,-----------------------------------------------------------------------------------------------------------.
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |  MsB3  |  MsB4  |  MsB5  |        |        | MwLeft | MwDown |  MwUp  | MwRght |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |  MsB1  |  MsB2  |        |        | MsLeft | MsDown |  MsUp  | MsRght |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        | MsAcl0 | MsAcl1 | MsAcl2 |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, \
  _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
  _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, KC_BTN5, _______, _______, _______, _______, \
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
