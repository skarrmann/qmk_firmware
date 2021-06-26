#include "skarrmann.h"

/* Base modifiers - for productivity and efficiency
 .-----------------------------------------------------. .-----------------------------------------------------.
 |        |        |        |        |        |        | |        |        |        |        |        |   -    |
 |  LALT  |        |        |        |        |        | |        |        |        |        |        |  ALT   |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        | |        |        |        |        |        |   '    |
 |  LSFT  |        |        |        |        |        | |        |        |        |        |        |  RSFT  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |  ESC   |        |        |        |        |        | |        |        |        |        |        |  ENT   |
 |  LCTL  |        |        |        |        |        | |        |        |        |        |        |  RCTL  |
 |--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
 |        |  INS   |  PSCR  |  CAPS  |  DEL   |  TAB   | |  SPC   |  BSPC  |   1    |   2    |   4    |        |
 |  LGUI  |        |        |        |        | SYMBOL | |FUNCTION|        |        |        |        |  RGUI  |
 '-----------------------------------------------------' '-----------------------------------------------------'
 */
#define B_L1 MT(MOD_LALT, KC_GRV)
#define B_L2 KC_LSFT
#define B_L3 MT(MOD_LCTL, KC_ESC)

#define B_R1 MT(MOD_RALT, KC_MINS)
#define B_R2 MT(MOD_RSFT, KC_QUOT)
#define B_R3 MT(MOD_RCTL, KC_ENT)

#define B_LH_MODS(k1, k2, k3, k4) k1, k2, k3, k4 
#define B_RH_MODS(k1, k2, k3, k4) k1, k2, k3, k4 

#define B_B0 MT(MOD_LGUI, KC_ESC)
#define B_B1 KC_INS
#define B_B2 KC_PSCR
#define B_B3 KC_CAPS
#define B_B4 KC_DEL
#define B_B5 LT(_SYMBOL, KC_TAB)
#define B_B6 LT(_FUNCTION, KC_SPC)
#define B_B7 KC_BSPC
#define B_B8 KC_1
#define B_B9 KC_2
#define B_BA KC_4
#define B_BB MT(MOD_RGUI, KC_ENT)

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
#define SYMBOL_L2___________________________________________ KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR , KC_AMPR
#define SYMBOL_L3___________________________________________ KC_TILD, KC_AT  , KC_LBRC, KC_RBRC, KC_PLUS, KC_PERC
#define SYMBOL_L4___________________________________________ _______, _______, _______, _______, _______, _______

#define SYMBOL_R0___________________________________________ _______, _______, _______, _______, _______, _______
#define SYMBOL_R1___________________________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS
#define SYMBOL_R2___________________________________________ KC_PIPE, KC_EQL , KC_LCBR, KC_RCBR, KC_COLN, KC_DQUO
#define SYMBOL_R3___________________________________________ KC_CIRC, KC_ASTR, KC_LABK, KC_RABK, KC_QUES, KC_BSLS
#define SYMBOL_R4___________________________________________ _______, _______, _______, _______, _______, _______

#define FUNCTION_L0_________________________________________ _______, _______, _______, _______, _______, _______
#define FUNCTION_L1_________________________________________ _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PSCR
#define FUNCTION_L2_________________________________________ _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_INS 
#define FUNCTION_L3_________________________________________ _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PAUS
#define FUNCTION_L4_________________________________________ _______, _______, _______, _______, _______, KC_TAB 

#define FUNCTION_R0_________________________________________ _______, _______, _______, _______, _______, _______
#define FUNCTION_R1_________________________________________ QWERTY , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______
#define FUNCTION_R2_________________________________________ COLEMAK, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
#define FUNCTION_R3_________________________________________ TG_GAME, KC_MUTE, KC_VOLD, KC_VOLU, KC_APP , _______
#define FUNCTION_R4_________________________________________ _______, _______, _______, _______, _______, _______

#define GAME_L0_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_L1_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_L2_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_L3_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_L4_____________________________________________ _______, _______, _______, _______, KC_TAB , KC_SPC 

#define GAME_R0_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_R1_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_R2_____________________________________________ _______, _______, _______, _______, _______, _______
#define GAME_R3_____________________________________________ _______, _______, _______, _______, _______, _______

