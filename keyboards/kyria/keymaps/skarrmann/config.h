#pragma once

#define EE_HANDS

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 32
#endif

#ifdef ENCODER_ENABLE
  #define ENCODER_RESOLUTION 2
#endif

#define LAYOUT_skarrmann(                                                                                                                        \
  K00    , K01    , K02    , K03    , K04    , K05    ,                                     K06    , K07    , K08    , K09    , K0A    , K0B    ,\
  K10    , K11    , K12    , K13    , K14    , K15    ,                                     K16    , K17    , K18    , K19    , K1A    , K1B    ,\
  K20    , K21    , K22    , K23    , K24    , K25    ,                                     K26    , K27    , K28    , K29    , K2A    , K2B    ,\
                                               K30    , K31    , K32    , K33    , K34    , K35                                                  \
)                                                                                                                                                \
LAYOUT(                                                                                                                                          \
  K00    , K01    , K02    , K03    , K04    , K05    ,                                     K06    , K07    , K08    , K09    , K0A    , K0B    ,\
  K10    , K11    , K12    , K13    , K14    , K15    ,                                     K16    , K17    , K18    , K19    , K1A    , K1B    ,\
  K20    , K21    , K22    , K23    , K24    , K25    , RGB_VAD, RGB_HUD, RGB_SAD, RGB_TOG, K26    , K27    , K28    , K29    , K2A    , K2B    ,\
                             KC_NO  , KC_NO  , K30    , K31    , K32    , K33    , K34    , K35    , KC_NO  , KC_NO                              \
)
