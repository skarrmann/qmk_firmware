#include "skarrmann.h"

/* Base modifiers - for productivity and efficiency
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |   `    |        |        |        |        |        | |        |        |        |        |        |   \    |
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  CAPS  |        |        |        |  (KC)  |        | |        |  (KC)  |        |        |        |   -    |
 |        |        |        |        | BASE1  |        | |        | BASE3  |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        | |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |   '    |
 |  LSFT  |  LGUI  |  LALT  |  LSFT  |  LCTL  |        | |        |  RCTL  |  RSFT  |  RALT  |  RGUI  |  RSFT  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  ESC   |        |        |        |        |        | |        |        |        |        |        |  ENT   |
 |  LCTL  |        |        |        |        |        | |        |        |        |        |        |  RCTL  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |  APP   |  DEL   |  TAB   | |  SPC   |  BSPC  |  LEFT  |  DOWN  |   UP   | RIGHT  |
 |  LCTL  |  LGUI  |  LALT  |        | BASE2  | LOWER  | | RAISE  | BASE4  |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define B_L0 KC_GRV
#define B_L1 KC_CAPS
#define B_L2 KC_LSFT
#define B_L3 MT(MOD_LCTL, KC_ESC)

#define B_R0 KC_BSLS
#define B_R1 KC_MINS
#define B_R2 MT(MOD_RSFT, KC_QUOT)
#define B_R3 MT(MOD_RCTL, KC_ENT)

#define B_LA(k) MT(MOD_LGUI, k)
#define B_LB(k) MT(MOD_LALT, k)
#define B_LC(k) MT(MOD_LSFT, k)
#define B_LD(k) MT(MOD_LCTL, k)
#define B_LE(k) LT(_BASE1, k)

#define B_RA(k) MT(MOD_RGUI, k)
#define B_RB(k) MT(MOD_RALT, k)
#define B_RC(k) MT(MOD_RSFT, k)
#define B_RD(k) MT(MOD_RCTL, k)
#define B_RE(k) LT(_BASE3, k)

#define B_B0 KC_LCTL
#define B_B1 KC_LGUI
#define B_B2 KC_LALT
#define B_B3 KC_APP
#define B_B4 LT(_BASE2, KC_DEL)
#define B_B5 LT(_LOWER, KC_TAB)
#define B_B6 LT(_RAISE, KC_SPC)
#define B_B7 LT(_BASE4, KC_BSPC)
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

/* Custom layers - can cover the full keyboard layout */
/* LOWER
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   `    |   [    |   ]    |   =    |   /    | |   \    |   *    |   {    |   }    |   +    |   -    |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   !    |   @    |   #    |   $    |   %    | |   ^    |   &    |   (    |   )    |   |    |   '    |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   ~    |   .    |   ,    |   "    |   ;    | |   :    |   _    |   <    |   >    |   ?    |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________LOWER_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________LOWER_L1_______________________ _______, KC_GRV , KC_LBRC, KC_RBRC, KC_EQL , KC_SLSH
#define _____________________LOWER_L2_______________________ _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
#define _____________________LOWER_L3_______________________ _______, KC_TILD, KC_DOT , KC_COMM, KC_DQUO, KC_SCLN
#define _____________________LOWER_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________LOWER_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________LOWER_R1_______________________ KC_BSLS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PLUS, KC_MINS
#define _____________________LOWER_R2_______________________ KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_PIPE, KC_QUOT
#define _____________________LOWER_R3_______________________ KC_COLN, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, _______
#define _____________________LOWER_R4_______________________ _______, _______, _______, _______, _______, _______

/* RAISE
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |   -    |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   1    |   2    |   3    |   4    |   5    | |   6    |   7    |   8    |   9    |   0    |   '    |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |   ,    |   .    |   /    |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________RAISE_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________RAISE_L1_______________________ _______, _______, _______, _______, _______, _______
#define _____________________RAISE_L2_______________________ _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define _____________________RAISE_L3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________RAISE_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________RAISE_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________RAISE_R1_______________________ _______, _______, _______, _______, _______, KC_MINS
#define _____________________RAISE_R2_______________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_QUOT
#define _____________________RAISE_R3_______________________ _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______
#define _____________________RAISE_R4_______________________ _______, _______, _______, _______, _______, _______

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
#define _____________________ADJUST_L0______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_L1______________________ _______, RESET  , DEBUG  , _______, _______, _______
#define _____________________ADJUST_L2______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_L3______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_L4______________________ _______, _______, _______, _______, _______, _______

#define _____________________ADJUST_R0______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_R1______________________ _______, DF_QWRT, DF_CLMK, DF_DVRK, DF_STND, _______
#define _____________________ADJUST_R2______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_R3______________________ _______, _______, _______, _______, _______, _______
#define _____________________ADJUST_R4______________________ _______, _______, _______, _______, _______, _______

/* Layer BASE1 (Mouse)
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  ACL0  |  ACL1  |  ACL2  |[][][][]|        | |        |  WH_L  |  WH_D  |  WH_U  |  WH_R  |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |  MS_L  |  MS_D  |  MS_U  |  MS_R  |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |  BTN2  |  BTN3  |  BTN4  |  BTN5  |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |  BTN1  |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________BASE1_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE1_L1_______________________ _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, _______
#define _____________________BASE1_L2_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE1_L3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE1_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________BASE1_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE1_R1_______________________ _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______
#define _____________________BASE1_R2_______________________ _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _____________________BASE1_R3_______________________ _______, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, _______
#define _____________________BASE1_R4_______________________ KC_BTN1, _______, _______, _______, _______, _______

/* Layer BASE2 (Navigation)
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |  HOME  |  PGUP  |  PGDN  |  END   |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |[][][][]|        | |        |  LEFT  |  DOWN  |   UP   | RIGHT  |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |  INS   |  CAPS  |  SLCK  | NLCK   |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________BASE2_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE2_L1_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE2_L2_______________________ _______, _______, _______, _______, KC_TRNS, _______
#define _____________________BASE2_L3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE2_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________BASE2_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE2_R1_______________________ _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______
#define _____________________BASE2_R2_______________________ _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
#define _____________________BASE2_R3_______________________ _______, KC_INS , KC_CAPS, KC_SLCK, KC_NLCK, _______
#define _____________________BASE2_R4_______________________ _______, _______, _______, _______, _______, _______

/* Layer BASE3 (Media)
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  MPRV  |  MSTP  |  MPLY  |  MNXT  |        | |        |[][][][]|        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  MUTE  |  VOLD  |  VOLU  |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________BASE3_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE3_L1_______________________ _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______
#define _____________________BASE3_L2_______________________ _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______
#define _____________________BASE3_L3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE3_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________BASE3_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE3_R1_______________________ _______, KC_TRNS, _______, _______, _______, _______
#define _____________________BASE3_R2_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE3_R3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE3_R4_______________________ _______, _______, _______, _______, _______, _______


/* Layer BASE4 (Function)
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F1   |   F2   |   F3   |   F4   |  PSCR  | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F5   |   F6   |   F7   |   F8   |  SLCK  | |        |[][][][]|        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |   F9   |  F10   |  F11   |  F12   |  PAUS  | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 `-----------------------------------------------------' `-----------------------------------------------------'
 */
#define _____________________BASE4_L0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE4_L1_______________________ _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR
#define _____________________BASE4_L2_______________________ _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_SLCK
#define _____________________BASE4_L3_______________________ _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS
#define _____________________BASE4_L4_______________________ _______, _______, _______, _______, _______, _______

#define _____________________BASE4_R0_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE4_R1_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE4_R2_______________________ _______, KC_TRNS, _______, _______, _______, _______
#define _____________________BASE4_R3_______________________ _______, _______, _______, _______, _______, _______
#define _____________________BASE4_R4_______________________ _______, _______, _______, _______, _______, _______
