[1mdiff --git a/users/skarrmann/wrappers.h b/users/skarrmann/wrappers.h[m
[1mindex ecfa3d6..1185150 100644[m
[1m--- a/users/skarrmann/wrappers.h[m
[1m+++ b/users/skarrmann/wrappers.h[m
[36m@@ -5,36 +5,36 @@[m
  |   `    |                                            | |                                            |   \    |[m
  |        |                                            | |                                            |        |[m
  |--------|                          ,--------.        | |        ,--------.                          |--------|[m
[31m- |  ESC   |                          |  (KC)  |        | |        |  (KC)  |                          |   -    |[m
[32m+[m[32m |   -    |                          |  (KC)  |        | |        |  (KC)  |                          |   '    |[m
  |        |                          | BASE1  |        | |        | BASE3  |                          |        |[m
  |--------+--------------------------+--------|        | |        |-----------------------------------+--------|[m
[31m- |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        | |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |   '    |[m
[31m- |  LSFT  |  LCTL  |  LGUI  |  LALT  | BASE2  |        | |        | BASE4  |  RALT  |  RGUI  |  RCTL  |  RSFT  |[m
[32m+[m[32m |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        | |        |  (KC)  |  (KC)  |  (KC)  |  (KC)  |        |[m
[32m+[m[32m |  LSFT  |        |  LGUI  |  LALT  | BASE2  |        | |        | BASE4  |  RALT  |  RGUI  |        |  RSFT  |[m
  |--------+-----------------------------------'        | |        `-----------------------------------+--------|[m
[31m- |        |                                            | |                                            |  ENT   |[m
[31m- |  LALT  |                                            | |                                            |  RALT  |[m
[32m+[m[32m |  ESC   |                                            | |                                            |  ENT   |[m
[32m+[m[32m |        |                                            | |                                            |        |[m
  |--------+--------------------------------------------| |--------------------------------------------+--------|[m
[31m- |        |        |        |  APP   |  DEL   |  TAB   | |  SPC   |  BSPC  |  LEFT  |  DOWN  |   UP   | RIGHT  |[m
[32m+[m[32m |        |        |        |  APP   |   DEL  |  TAB   | |  SPC   |  BSPC  |  LEFT  |  DOWN  |   UP   | RIGHT  |[m
  |  LCTL  |  LGUI  |  LALT  |        |  LCTL  | LOWER  | | RAISE  |  RCTL  |        |        |        |        |[m
  `-----------------------------------------------------' `-----------------------------------------------------'[m
  */[m
 #define BASE_L0 KC_GRV[m
[31m-#define BASE_L1 KC_ESC[m
[32m+[m[32m#define BASE_L1 KC_MINS[m
 #define BASE_L2 KC_LSFT[m
[31m-#define BASE_L3 KC_LALT[m
[32m+[m[32m#define BASE_L3 KC_ESC[m
 [m
 #define BASE_R0 KC_BSLS[m
[31m-#define BASE_R1 KC_MINS[m
[31m-#define BASE_R2 MT(MOD_RSFT, KC_QUOT)[m
[31m-#define BASE_R3 MT(MOD_RALT, KC_ENT)[m
[32m+[m[32m#define BASE_R1 KC_QUOT[m
[32m+[m[32m#define BASE_R2 KC_RSFT[m
[32m+[m[32m#define BASE_R3 KC_ENT[m
 [m
[31m-#define BASE_LA(k) MT(MOD_LCTL, k)[m
[32m+[m[32m#define BASE_LA(k) k[m
 #define BASE_LB(k) MT(MOD_LGUI, k)[m
 #define BASE_LC(k) MT(MOD_LALT, k)[m
 #define BASE_LD(k) LT(_BASE2, k)[m
 #define BASE_LE(k) LT(_BASE1, k)[m
 [m
[31m-#define BASE_RA(k) MT(MOD_RCTL, k)[m
[32m+[m[32m#define BASE_RA(k) k[m
 #define BASE_RB(k) MT(MOD_RGUI, k)[m
 #define BASE_RC(k) MT(MOD_RALT, k)[m
 #define BASE_RD(k) LT(_BASE4, k)[m
