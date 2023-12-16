/* Copyright 2020 Steven Karrmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "skarrmann.h"

// See config.h for layout mapping to LAYOUT_skarrmann
// See /users/skarrmann/skarrmann.c for LAYOUT_skarrmann layout mappings


const rgblight_segment_t PROGMEM rgb_scroll_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 3, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_num_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {16, 3, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_scroll_lock,
    rgb_caps_lock,
    rgb_num_lock
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.scroll_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.num_lock);
    return true;
}