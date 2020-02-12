
#include "skarrmann.h"

#define _________________BLANK__X0_________________ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define _________________NUMROW_L0_________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define _________________NUMROW_R0_________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0

#define _________________QWERTY_L1_________________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R1_________________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _________________QWERTY_R2_________________ KC_H   , KC_J   , KC_L   , KC_L   , KC_SCLN
#define _________________QWERTY_R3_________________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define _________________QWERTY_L2_HOME____________ KC_A   , KC_S            , LT(_HOME1, KC_D), LT(_HOME2, KC_F), KC_G
#define _________________QWERTY_R2_HOME____________ KC_H   , LT(_HOME3, KC_J), LT(_HOME4, KC_K), KC_L            , KC_SCLN

/* Lower
 ,-----------------------------------------------------------------------------------------------------------.
 |        |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   \    |   |    |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
#define _________________LOWER__L1_________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define _________________LOWER__L2_________________ KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
#define _________________LOWER__L3_________________ _______, _______, _______, _______, _______

#define _________________LOWER__R1_________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0
#define _________________LOWER__R2_________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE // Substitutes () with \|
#define _________________LOWER__R3_________________ _______, _______, _______, _______, _______

/* Raise
 ,-----------------------------------------------------------------------------------------------------------.
 |        |   F1   |   F2   |   F3   |   F4   |        |  Vol+  |  Home  |  PgDn  |  PgUp  |  End   |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   F5   |   F6   |   F7   |   F8   |        |  Vol-  |  Left  |  Down  |   Up   | Right  |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |   F9   |  F10   |  F11   |  F12   |        |  Mute  | Media- | Media- | Media- | Media- |        |
 |        |        |        |        |        |        |        |  Prev  |  Play  |  Stop  |  Next  |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
#define _________________RAISE__L1_________________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______
#define _________________RAISE__L2_________________ KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______
#define _________________RAISE__L3_________________ KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______

#define _________________RAISE__R1_________________ KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END 
#define _________________RAISE__R2_________________ KC_VOLD, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
#define _________________RAISE__R3_________________ KC_MUTE, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT

/* Adjust (Lower + Raise)
 ,-----------------------------------------------------------------------------------------------------------.
 |        | Reset  | Debug  |        |        |        |        |  Caps  | Insert |        |  PScr  |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |        |        |        |        |        |        |
 |        |        |        |        |        |        |        |        |        |        |        |        |
 `-----------------------------------------------------------------------------------------------------------'
 */
#define _________________ADJUST_L1_________________ RESET  , DEBUG  , _______, _______, _______
#define _________________ADJUST_L2_________________ _______, _______, _______, _______, _______
#define _________________ADJUST_L3_________________ _______, _______, _______, _______, _______

#define _________________ADJUST_R1_________________ _______, KC_CAPS, KC_INS , _______, KC_PSCR
#define _________________ADJUST_R2_________________ _______, _______, _______, _______, _______
#define _________________ADJUST_R3_________________ _______, _______, _______, _______, _______
