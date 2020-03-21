#include "skarrmann.h"

#define LAYOUT_ortho_4x12_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#define LAYOUT_ortho_4x12_base( \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
) \
LAYOUT_ortho_4x12_wrapper( \
  B_L1, K11      , K12      , K13      , K14      , K15      , K16      , K17      , K18      , K19      , K1A      , B_R1, \
  B_L2, B_LA(K21), B_LB(K22), B_LC(K23), B_LD(K24), K25      , K26      , B_RD(K27), B_RC(K28), B_RB(K29), B_RA(K2A), B_R2, \
  B_L3, K31      , K32      , K33      , K34      , K35      , K36      , K37      , K38      , K39      , K3A      , B_R3, \
  B_B0, B_B1     , B_B2     , B_B3     , B_B4     , B_B5     , B_B6     , B_B7     , B_B8     , B_B9     , B_BA     , B_BB  \
)

#define LAYOUT_ortho_4x12_base_wrapper(...) LAYOUT_ortho_4x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, \
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, \
  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________  \
),

[_COLEMAK] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, \
  _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, \
  _________________COLEMAK_L3________________, _________________COLEMAK_R3________________  \
),

[_SYMBOL] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________SYMBOL_L1_________________, _________________SYMBOL_R1_________________, \
  _________________SYMBOL_L2_________________, _________________SYMBOL_R2_________________, \
  _________________SYMBOL_L3_________________, _________________SYMBOL_R3_________________  \
),

[_NUMBER] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________NUMBER_L1_________________, _________________NUMBER_R1_________________, \
  _________________NUMBER_L2_________________, _________________NUMBER_R2_________________, \
  _________________NUMBER_L3_________________, _________________NUMBER_R3_________________  \
),

[_UTILITY] = LAYOUT_ortho_4x12_base_wrapper( \
  _________________UTILITY_L1________________, _________________UTILITY_R1________________, \
  _________________UTILITY_L2________________, _________________UTILITY_R2________________, \
  _________________UTILITY_L3________________, _________________UTILITY_R3________________  \
),

[_STANDARD] = LAYOUT_ortho_4x12_wrapper( \
  STND_L1, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, STND_R1, \
  STND_L2, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, STND_R2, \
  STND_L3, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, STND_R3, \
  STND_B0, STND_B1, STND_B2, STND_B3, STND_B4, STND_B5, STND_B6, STND_B7, STND_B8, STND_B9, STND_BA, STND_BB  \
),

};
