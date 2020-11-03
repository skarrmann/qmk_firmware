#include "skarrmann.h"

#define LAYOUT_ortho_5x12_wrapper(...) LAYOUT_ortho_5x12(__VA_ARGS__)

#define LAYOUT_ortho_5x12_base( \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
) \
LAYOUT_ortho_5x12_wrapper( \
  B_L0,    NUMROW_L0__________________________________, NUMROW_R0__________________________________, B_R0   , \
  B_L1   , K11    , K12    , K13    , K14    , K15    , K16    , K17    , K18    , K19    , K1A    , B_R1   , \
  B_L2   , B_LH_MODS(K21, K22, K23, K24)     , K25    , K26    , B_RH_MODS(K27, K28, K29, K2A)     , B_R2   , \
  B_L3   , K31    , K32    , K33    , K34    , K35    , K36    , K37    , K38    , K39    , K3A    , B_R3   , \
  B_B0   , B_B1   , B_B2   , B_B3   , B_B4   , B_B5   , B_B6   , B_B7   , B_B8   , B_B9   , B_BA   , B_BB     \
)

#define LAYOUT_ortho_5x12_base_wrapper(...) LAYOUT_ortho_5x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x12_base_wrapper( \
  QWERTY_L1__________________________________, QWERTY_R1__________________________________, \
  QWERTY_L2__________________________________, QWERTY_R2__________________________________, \
  QWERTY_L3__________________________________, QWERTY_R3__________________________________  \
),

[_COLEMAK] = LAYOUT_ortho_5x12_base_wrapper( \
  COLEMAK_L1_________________________________, COLEMAK_R1_________________________________, \
  COLEMAK_L2_________________________________, COLEMAK_R2_________________________________, \
  COLEMAK_L3_________________________________, COLEMAK_R3_________________________________  \
),

[_SYMBOL] = LAYOUT_ortho_5x12_wrapper( \
  SYMBOL_L0___________________________________________, SYMBOL_R0___________________________________________, \
  SYMBOL_L1___________________________________________, SYMBOL_R1___________________________________________, \
  SYMBOL_L2___________________________________________, SYMBOL_R2___________________________________________, \
  SYMBOL_L3___________________________________________, SYMBOL_R3___________________________________________, \
  SYMBOL_L4___________________________________________, SYMBOL_R4___________________________________________  \
),
  
[_NAVIGATE] = LAYOUT_ortho_5x12_wrapper( \
  NAVIGATE_L0_________________________________________, NAVIGATE_R0_________________________________________, \
  NAVIGATE_L1_________________________________________, NAVIGATE_R1_________________________________________, \
  NAVIGATE_L2_________________________________________, NAVIGATE_R2_________________________________________, \
  NAVIGATE_L3_________________________________________, NAVIGATE_R3_________________________________________, \
  NAVIGATE_L4_________________________________________, NAVIGATE_R4_________________________________________  \
),

[_FUNCTION] = LAYOUT_ortho_5x12_wrapper( \
  FUNCTION_L0_________________________________________, FUNCTION_R0_________________________________________, \
  FUNCTION_L1_________________________________________, FUNCTION_R1_________________________________________, \
  FUNCTION_L2_________________________________________, FUNCTION_R2_________________________________________, \
  FUNCTION_L3_________________________________________, FUNCTION_R3_________________________________________, \
  FUNCTION_L4_________________________________________, FUNCTION_R4_________________________________________  \
),

[_GAME] = LAYOUT_ortho_5x12_wrapper( \
  GAME_L0_____________________________________________, GAME_R0_____________________________________________, \
  GAME_L1_____________________________________________, GAME_R1_____________________________________________, \
  GAME_L2_____________________________________________, GAME_R2_____________________________________________, \
  GAME_L3_____________________________________________, GAME_R3_____________________________________________, \
  GAME_L4_____________________________________________, GAME_R4_____________________________________________  \
),
};
