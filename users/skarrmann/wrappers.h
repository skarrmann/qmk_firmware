#include "skarrmann.h"

/* Base modifiers - for productivity and efficiency
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |   `    |        |        |        |        |        | |        |        |        |        |        |   \    |
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  DEL   |        |        |        |        |        | |        |        |        |        |        |  BSPC  |
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        | |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        |
 |  LSFT  |  LGUI  |  LALT  |  LSFT  |  LCTL  |        | |        |  RCTL  |  RSFT  |  RALT  |  RGUI  |  RSFT  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  ESC   |        |        |        |        |        | |        |        |        |        |        |  ENT   |
 |  LCTL  |        |        |        |        |        | |        |        |        |        |        |  RCTL  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |  APP   | LSFT + |        | |  SPC   |  TAB   |  LEFT  |  DOWN  |   UP   | RIGHT  |
 |  LCTL  |  LGUI  |  LALT  |        | LOWER  | LOWER  | | RAISE  |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define B_L0 KC_GRV
#define B_L1 KC_DEL
#define B_L2 KC_LSFT
#define B_L3 MT(MOD_LCTL, KC_ESC)

#define B_R0 KC_BSLS
#define B_R1 KC_BSPC
#define B_R2 KC_RSFT
#define B_R3 MT(MOD_RCTL, KC_ENT)

#define B_LA(k) MT(MOD_LGUI, k)
#define B_LB(k) MT(MOD_LALT, k)
#define B_LC(k) MT(MOD_LSFT, k)
#define B_LD(k) MT(MOD_LCTL, k)

#define B_RA(k) MT(MOD_RGUI, k)
#define B_RB(k) MT(MOD_RALT, k)
#define B_RC(k) MT(MOD_RSFT, k)
#define B_RD(k) MT(MOD_RCTL, k)

#define B_B0 KC_LCTL
#define B_B1 KC_LGUI
#define B_B2 KC_LALT
#define B_B3 KC_APP
#define B_B4 LM(_LOWER, MOD_LSFT)
#define B_B5 MO(_LOWER)
#define B_B6 LT(_RAISE, KC_SPC)
#define B_B7 KC_TAB
#define B_B8 KC_LEFT
#define B_B9 KC_DOWN
#define B_BA KC_UP
#define B_BB KC_RIGHT

/* Standard modifiers - for games and applications which need standard key behavior
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |  ESC   |                                            | |                                            |  BSPC  |
 |        |                                            | |                                            |        |
 |--------|                                            | |                                            |--------|
 |  TAB   |                                            | |                                            |   -    |
 |        |                                            | |                                            |        |
 |--------|                                            | |                                            |--------|
 |        |                                            | |                                            |   '    |
 |  CAPS  |                                            | |                                            |        |
 |--------|                                            | |                                            |--------|
 |        |                                            | |                                            |  ENT   |
 |  LSFT  |                                            | |                                            |        |
 |--------+--------------------------------------------| |--------------------------------------------+--------|
 |        |        |        |  APP   |  DEL   |  SPC   | |  SPC   |  BSPC  |  LEFT  |   UP   |  DOWN  | RIGHT  |
 |  LCTL  |  LGUI  |  LALT  |        | LOWER  |        | |        | RAISE  |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define STND_L0 KC_ESC
#define STND_L1 KC_TAB
#define STND_L2 KC_CAPS
#define STND_L3 KC_LSFT

#define STND_R0 KC_BSPC
#define STND_R1 KC_MINS
#define STND_R2 KC_QUOT
#define STND_R3 KC_ENT

#define STND_B0 KC_LCTL
#define STND_B1 KC_LGUI
#define STND_B2 KC_LALT
#define STND_B3 KC_APP
#define STND_B4 LT(_LOWER, KC_DEL)
#define STND_B5 KC_SPC
#define STND_B6 KC_SPC
#define STND_B7 LT(_RAISE, KC_BSPC)
#define STND_B8 KC_LEFT
#define STND_B9 KC_DOWN
#define STND_BA KC_UP
#define STND_BB KC_RGHT

/* Base layers - placed inside of a modifier wrapper */
#define _________________NUMROW_L0_________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define _________________NUMROW_R0_________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0

#define _________________QWERTY_L1_________________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R1_________________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _________________QWERTY_R2_________________ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define _________________QWERTY_R3_________________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define _________________COLEMAK_L1________________ KC_Q   , KC_W   , KC_F   , KC_P   , KC_G
#define _________________COLEMAK_L2________________ KC_A   , KC_R   , KC_S   , KC_T   , KC_D
#define _________________COLEMAK_L3________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________COLEMAK_R1________________ KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define _________________COLEMAK_R2________________ KC_H   , KC_N   , KC_E   , KC_I   , KC_O
#define _________________COLEMAK_R3________________ KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

#define _________________DVORAK_L1_________________ KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y
#define _________________DVORAK_L2_________________ KC_A   , KC_O   , KC_E   , KC_U   , KC_I
#define _________________DVORAK_L3_________________ KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X

#define _________________DVORAK_R1_________________ KC_F   , KC_G   , KC_C   , KC_R   , KC_L
#define _________________DVORAK_R2_________________ KC_D   , KC_H   , KC_T   , KC_N   , KC_S
#define _________________DVORAK_R3_________________ KC_B   , KC_M   , KC_W   , KC_V   , KC_Z

/* Custom layers - also placed inside of a modified wrapper */
/* LOWER
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   `    |   [    |   ]    |   =    |        | |        |   -    |   '    |   \    |   ;    |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   1    |   2    |   3    |   4    |   5    | |   6    |   7    |   8    |   9    |   0    |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |   ,    |   .    |   /    |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _________________LOWER_L1__________________ KC_GRV , KC_LBRC, KC_RBRC, KC_EQL , _______
#define _________________LOWER_L2__________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5   
#define _________________LOWER_L3__________________ _______, _______, _______, _______, _______

#define _________________LOWER_R1__________________ _______, KC_MINS, KC_QUOT, KC_BSLS, KC_SCLN
#define _________________LOWER_R2__________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   
#define _________________LOWER_R3__________________ _______, _______, KC_COMM, KC_DOT , KC_SLSH

/* RAISE
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F1   |   F2   |   F3   |   F4   |  PSCR  | |        |  HOME  |  PGUP  |  PGDN  |  END   |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F5   |   F6   |   F7   |   F8   |  SLCK  | |        |  LEFT  |  DOWN  |   UP   | RIGHT  |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F9   |  F10   |  F11   |  F12   |  PAUS  | |        |  INS   |  CAPS  |  SLCK  | NLCK   |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _________________RAISE_L1__________________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR
#define _________________RAISE_L2__________________ KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_SLCK
#define _________________RAISE_L3__________________ KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS

#define _________________RAISE_R1__________________ _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END 
#define _________________RAISE_R2__________________ _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
#define _________________RAISE_R3__________________ _______, KC_INS , KC_CAPS, KC_SLCK, KC_NLCK

/* ADJUST (LOWER + RAISE)
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        | RESET  | DEBUG  |        |        |        | |        |DF_QWRT |DF_CLMK |DF_DVRK |DF_STND |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _________________ADJUST_L1_________________ RESET  , DEBUG  , _______, _______, _______
#define _________________ADJUST_L2_________________ _______, _______, _______, _______, _______
#define _________________ADJUST_L3_________________ _______, _______, _______, _______, _______

#define _________________ADJUST_R1_________________ _______, DF_QWRT, DF_CLMK, DF_DVRK, DF_STND
#define _________________ADJUST_R2_________________ _______, _______, _______, _______, _______
#define _________________ADJUST_R3_________________ _______, _______, _______, _______, _______
