#pragma once

// One shot keys configuration
#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 5000

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
