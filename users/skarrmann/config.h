#pragma once

// Tap-hold configuration
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 120
#define TAPPING_TERM_K_SPC 200
#define TAPPING_TERM_M_SFT 100
#define TAPPING_TERM_M_CTL 120
#define TAPPING_TERM_M_ALT 120
#define TAPPING_TERM_M_GUI 120
#define TAPPING_TERM_M_MLT 120
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define ONESHOT_TAP_TOGGLE 4

// Combo configuration
#define COMBO_COUNT 6
#define COMBO_TERM 10

// Mouse keys configuration
#ifdef MOUSEKEY_ENABLE
  #define MOUSEKEY_INTERVAL 16
  #define MOUSEKEY_WHEEL_INTERVAL 32
  
  #define MOUSEKEY_DELAY 0
  #define MOUSEKEY_WHEEL_DELAY 0
  
  // IMPORTANT: COMMAND must be disabled for constant speed - see https://github.com/qmk/qmk_firmware/issues/6974
  #define MK_3_SPEED
  
  #define MK_C_INTERVAL_0 MOUSEKEY_INTERVAL
  #define MK_C_OFFSET_0 2
  #define MK_W_INTERVAL_0 MOUSEKEY_WHEEL_INTERVAL
  #define MK_W_OFFSET_0 1
  
  #define MK_C_INTERVAL_1 MOUSEKEY_INTERVAL
  #define MK_C_OFFSET_1 8
  #define MK_W_INTERVAL_1 MOUSEKEY_WHEEL_INTERVAL
  #define MK_W_OFFSET_1 2
  
  #define MK_C_INTERVAL_2 MOUSEKEY_INTERVAL
  #define MK_C_OFFSET_2 16
  #define MK_W_INTERVAL_2 MOUSEKEY_WHEEL_INTERVAL
  #define MK_W_OFFSET_2 4
#endif
