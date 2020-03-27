#include "skarrmann.h"

/* Base modifiers - for productivity and efficiency
 ,-----------------------------------------------------. ,-----------------------------------------------------.
 |   `    |        |        |        |        |        | |        |        |        |        |        |   \    |
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  CAPS  |        |        |        |        |        | |        |        |        |        |        |   -    |
 |        |        |        |        |        |        | |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        | |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |   '    |
 |  LSFT  |  LGUI  |  LALT  |  LSFT  |  LCTL  |        | |        |  RCTL  |  RSFT  |  RALT  |  RGUI  |  RSFT  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  ESC   |        |        |        |        |        | |        |        |        |        |        |  ENT   |
 |  LCTL  |        |        |        |        |        | |        |        |        |        |        |  RCTL  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  ESC   |   UP   |   APP  |        |  DEL   |  TAB   | |  SPC   |  BSPC  |        |        |  LEFT  |  ENT   |
 |        |        |        |  LGUI  |FUNCTION| SYMBOL | |NAVIGATE|        |  RGUI  |        |        |        |
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

#define B_LH_MODS(k1, k2, k3, k4) MT(MOD_LGUI, k1), MT(MOD_LALT, k2), MT(MOD_LSFT, k3), MT(MOD_LCTL, k4)
#define B_RH_MODS(k1, k2, k3, k4) MT(MOD_RCTL, k1), MT(MOD_RSFT, k2), MT(MOD_RALT, k3), MT(MOD_RGUI, k4)

#define B_B0 KC_ESC
#define B_B1 KC_UP
#define B_B2 KC_APP
#define B_B3 KC_LGUI
#define B_B4 LT(_FUNCTION, KC_DEL)
#define B_B5 LT(_SYMBOL, KC_TAB)
#define B_B6 LT(_NAVIGATE, KC_SPC)
#define B_B7 KC_BSPC
#define B_B8 KC_RGUI
#define B_B9 KC_DOWN
#define B_BA KC_LEFT
#define B_BB KC_ENT

/* Base layers */
#define NUMROW_L0__________________________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5   
#define NUMROW_R0__________________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   
                                    
#define QWERTY_L1__________________________________ KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   
#define QWERTY_L2__________________________________ KC_A   , KC_S   , KC_D   , KC_F   , KC_G   
#define QWERTY_L3__________________________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   
                                    
#define QWERTY_R1__________________________________ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   
#define QWERTY_R2__________________________________ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define QWERTY_R3__________________________________ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH
                                    
#define COLEMAK_L1_________________________________ KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   
#define COLEMAK_L2_________________________________ KC_A   , KC_R   , KC_S   , KC_T   , KC_D   
#define COLEMAK_L3_________________________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   
                                    
#define COLEMAK_R1_________________________________ KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define COLEMAK_R2_________________________________ KC_H   , KC_N   , KC_E   , KC_I   , KC_O   
#define COLEMAK_R3_________________________________ KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

/* Custom layers */ 

#define SYMBOL_L0___________________________________________ _______, _______, _______, _______, _______, _______
#define SYMBOL_L1___________________________________________ KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   
#define SYMBOL_L2___________________________________________ KC_PLUS, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_AMPR
#define SYMBOL_L3___________________________________________ KC_TILD, KC_HASH, KC_DLR , KC_LBRC, KC_RBRC, KC_PERC
#define SYMBOL_L4___________________________________________ _______, _______, _______, _______, _______, _______

#define SYMBOL_R0___________________________________________ _______, _______, _______, _______, _______, _______
#define SYMBOL_R1___________________________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS
#define SYMBOL_R2___________________________________________ KC_PIPE, KC_EQL , KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO
#define SYMBOL_R3___________________________________________ KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS
#define SYMBOL_R4___________________________________________ _______, _______, _______, _______, _______, _______

#define NAVIGATE_L0_________________________________________ _______, _______, _______, _______, _______, _______
#define NAVIGATE_L1_________________________________________ _______, _______, _______, _______, _______, _______
#define NAVIGATE_L2_________________________________________ _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define NAVIGATE_L3_________________________________________ _______, _______, _______, _______, _______, _______
#define NAVIGATE_L4_________________________________________ _______, _______, _______, _______, _______, _______

#define NAVIGATE_R0_________________________________________ _______, _______, _______, _______, _______, _______
#define NAVIGATE_R1_________________________________________ _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______
#define NAVIGATE_R2_________________________________________ _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
#define NAVIGATE_R3_________________________________________ _______, _______, _______, _______, _______, _______
#define NAVIGATE_R4_________________________________________ _______, _______, _______, _______, _______, _______

#define FUNCTION_L0_________________________________________ _______, _______, _______, _______, _______, _______
#define FUNCTION_L1_________________________________________ KC_CLCK, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR
#define FUNCTION_L2_________________________________________ KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS 
#define FUNCTION_L3_________________________________________ KC_NLCK, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS
#define FUNCTION_L4_________________________________________ _______, _______, _______, _______, _______, _______

#define FUNCTION_R0_________________________________________ _______, _______, _______, _______, _______, _______
#define FUNCTION_R1_________________________________________ QWERTY , _______, _______, _______, _______, _______
#define FUNCTION_R2_________________________________________ COLEMAK, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______ 
#define FUNCTION_R3_________________________________________ _______, _______, _______, _______, _______, _______
#define FUNCTION_R4_________________________________________ _______, _______, _______, _______, _______, _______
