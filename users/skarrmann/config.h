#pragma once

// Tap-hold configuration
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 170
#define TAPPING_TERM_LONG 200
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define ONESHOT_TAP_TOGGLE 4

// Mouse keys configuration
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 3
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
//#define MK_3_SPEED // TODO: This setting causes build errors - investigate
#undef MK_MOMENTARY_ACCEL
