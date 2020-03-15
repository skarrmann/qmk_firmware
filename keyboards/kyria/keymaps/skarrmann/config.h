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

// Handle Elite C rev3 on the slave side
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
