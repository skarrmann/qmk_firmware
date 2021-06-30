#include "skarrmann.h"

#define LAYOUT_ortho_5x12_wrapper(...) LAYOUT_ortho_5x12(__VA_ARGS__)

#define LAYOUT_ortho_5x12_base( \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
) \
LAYOUT_ortho_5x12_wrapper( \
  BASE_NBRW_L0_______________________________, _______, _______, BASE_NBRW_R0_______________________________, \
  K11    , K12    , K13    , K14    , K15    , _______, _______, K16    , K17    , K18    , K19    , K1A    , \
  K21    , K22    , K23    , K24    , K25    , _______, _______, K26    , K27    , K28    , K29    , K2A    , \
  K31    , K32    , K33    , K34    , K35    , _______, _______, K36    , K37    , K38    , K39    , K3A    , \
  _______, _______, _______, THUMB_LEFT_______________, THUMB_RGHT_______________, _______, _______, _______  \
)

#define LAYOUT_ortho_5x12_base_wrapper(...) LAYOUT_ortho_5x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[CLMK] = LAYOUT_ortho_5x12_base_wrapper( \
  BASE_CLMK_L1_______________________________, BASE_CLMK_R1_______________________________, \
  BASE_CLMK_L2_______________________________, BASE_CLMK_R2_______________________________, \
  BASE_CLMK_L3_______________________________, BASE_CLMK_R3_______________________________  \
),

[NAVI] = LAYOUT_ortho_5x12_base_wrapper( \
  LAYER_NAVI_L1______________________________, LAYER_NAVI_R1______________________________, \
  LAYER_NAVI_L2______________________________, LAYER_NAVI_R2______________________________, \
  LAYER_NAVI_L3______________________________, LAYER_NAVI_R3______________________________  \
),

[SYMB] = LAYOUT_ortho_5x12_base_wrapper( \
  LAYER_SYMB_L1______________________________, LAYER_SYMB_R1______________________________, \
  LAYER_SYMB_L2______________________________, LAYER_SYMB_R2______________________________, \
  LAYER_SYMB_L3______________________________, LAYER_SYMB_R3______________________________  \
),
  
[FUNC] = LAYOUT_ortho_5x12_base_wrapper( \
  LAYER_FUNC_L1______________________________, LAYER_FUNC_R1______________________________, \
  LAYER_FUNC_L2______________________________, LAYER_FUNC_R2______________________________, \
  LAYER_FUNC_L3______________________________, LAYER_FUNC_R3______________________________  \
),

};
