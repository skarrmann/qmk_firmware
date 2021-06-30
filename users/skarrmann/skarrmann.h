#pragma once

#include QMK_KEYBOARD_H

// Layer declarations
enum userspace_layers {
  CLMK = 0,
  NAVI,
  SYMB,
  FUNC,
};

/* Thumb keys */
#define THUMB_LEFT_______________ MO(NAVI), KC_LSFT, _______
#define THUMB_RGHT_______________ _______, KC_SPC, MO(SYMB)

/* Home row mods */
#define MODS_LEFT_________________________ OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL)
#define MODS_RGHT_________________________ OSM(MOD_RCTL), OSM(MOD_RSFT), OSM(MOD_RALT), OSM(MOD_RGUI)

/* Base layers */
#define BASE_NBRW_L0_______________________________ EEP_RST, KC_2   , KC_3   , KC_4   , KC_5   
#define BASE_NBRW_R0_______________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   
                                    
#define BASE_CLMK_L1_______________________________ KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   
#define BASE_CLMK_L2_______________________________ KC_A   , KC_R   , KC_S   , KC_T   , KC_D   
#define BASE_CLMK_L3_______________________________ KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   

#define BASE_CLMK_R1_______________________________ KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT
#define BASE_CLMK_R2_______________________________ KC_H   , KC_N   , KC_E   , KC_I   , KC_O   
#define BASE_CLMK_R3_______________________________ KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH

/* Custom layers */ 
#define LAYER_NAVI_L1______________________________ _______, _______, _______, _______, _______
#define LAYER_NAVI_L2______________________________ MODS_LEFT_________________________, _______
#define LAYER_NAVI_L3______________________________ KC_ESC , _______, _______, KC_TAB , _______

#define LAYER_NAVI_R1______________________________ _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END 
#define LAYER_NAVI_R2______________________________ _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
#define LAYER_NAVI_R3______________________________ _______, KC_BSPC, KC_ENT , KC_INS , KC_CAPS

#define LAYER_SYMB_L1______________________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5   
#define LAYER_SYMB_L2______________________________ KC_GRV , KC_SCLN, KC_MINS, KC_EQL , KC_BSLS
#define LAYER_SYMB_L3______________________________ KC_ESC , KC_LBRC, KC_RBRC, KC_TAB , _______

#define LAYER_SYMB_R1______________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0   
#define LAYER_SYMB_R2______________________________ _______, MODS_RGHT_________________________
#define LAYER_SYMB_R3______________________________ _______, KC_BSPC, KC_ENT , KC_INS , KC_CAPS

#define LAYER_FUNC_L1______________________________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  
#define LAYER_FUNC_L2______________________________ MODS_LEFT_________________________, KC_F6  
#define LAYER_FUNC_L3______________________________ KC_ESC , _______, _______, KC_TAB , _______

#define LAYER_FUNC_R1______________________________ KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 
#define LAYER_FUNC_R2______________________________ KC_F7  , MODS_RGHT_________________________
#define LAYER_FUNC_R3______________________________ _______, KC_BSPC, KC_ENT , KC_INS , KC_CAPS

