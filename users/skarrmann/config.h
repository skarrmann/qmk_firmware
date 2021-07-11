#pragma once

// Tap-hold configuration
#define TAPPING_TERM 200
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// One shot configuration
#define ONESHOT_TIMEOUT 1000

// Combo configuration
#define COMBO_COUNT 0
#define COMBO_TERM 50

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
