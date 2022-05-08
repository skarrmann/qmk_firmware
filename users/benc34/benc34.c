#include QMK_KEYBOARD_H

#define BASE TO(0)

#define NUMBER OSL(_NUMBER)
#define NAV OSL(_NAV)
#define FUNCT OSL(_FUNCT)

#define MOUSE TO(_MOUSE)
#define WM TO(_WM)

#define SHIFT OSM(MOD_LSFT)
#define CONTROL OSM(MOD_LCTL)
#define GUI OSM(MOD_LGUI)
#define ALT OSM(MOD_LALT)

#define SELECT S(KC_INS)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define CTRL_A C(KC_A)
#define SLOCK G(KC_Z)

enum layers {
	_QWERTY,
	_NUMBER,
	_WM,
	_NAV,
	_FUNCT,
	_MOUSE,
};

enum custom_keycodes {
	CLRMOD = SAFE_RANGE
};

const key_override_t delete_key_override = ko_make_basic(
	MOD_MASK_SHIFT, KC_BSPC, KC_DEL
);
const key_override_t terminal_copy_key_override = ko_make_basic(
	MOD_MASK_SHIFT, COPY,    A(KC_C)
);
const key_override_t terminal_paste_key_override = ko_make_basic(
	MOD_MASK_SHIFT, PASTE,   A(KC_V)
);
const key_override_t mouse_select_all_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, CUT,     C(KC_A), (1 << _MOUSE)
);
const key_override_t mouse_keepass_toggle_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, KC_ENT,  G(KC_O), (1 << _MOUSE)
);
const key_override_t mouse_keepass_user_copy_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, KC_TAB,  C(KC_B), (1 << _MOUSE)
);
const key_override_t mouse_insert_mode_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, KC_ESC,  KC_I,    (1 << _MOUSE)
);
const key_override_t mouse_space_key_override = ko_make_with_layers(
	MOD_MASK_SHIFT, SELECT,  KC_SPC,  (1 << _MOUSE)
);

const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	&terminal_copy_key_override,
	&terminal_paste_key_override,
	&mouse_select_all_key_override,
	&mouse_keepass_toggle_key_override,
	&mouse_keepass_user_copy_key_override,
	&mouse_insert_mode_key_override,
	&mouse_space_key_override,
	NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_34(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
		                           NUMBER,  SHIFT,        KC_SPC,  NAV
	),

	[_NUMBER] = LAYOUT_34(
		KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
		KC_GRV,  KC_TILD, KC_LBRC, KC_LPRN, KC_LCBR,      KC_RCBR, KC_RPRN, KC_RBRC, KC_EQL,  KC_BSLS,
		                           _______, MOUSE,        _______, _______
	),

	[_WM] = LAYOUT_34(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      G(KC_H), G(KC_J), G(KC_K), G(KC_L), XXXXXXX,
		G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),      G(KC_6), G(KC_7), G(KC_8), G(KC_9), XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      G(KC_N), G(KC_M), XXXXXXX, XXXXXXX, XXXXXXX,
		                           BASE,    _______,      G(KC_0), _______
	),

	[_NAV] = LAYOUT_34(
		KC_TAB,  CTRL_A,  CLRMOD,  WM,      CAPSWRD,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
		KC_ESC,  ALT,     CONTROL, GUI,     KC_UNDS,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
		SLOCK,   CUT,     COPY,    PASTE,   SELECT,       KC_INS,  KC_DEL,  KC_SCLN, KC_COLN, KC_PIPE,
		                           BASE,    _______,      FUNCT,   _______
	),

	[_FUNCT] = LAYOUT_34(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
		KC_CAPS, ALT,     CONTROL, GUI,     KC_APP,       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
		KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS,      KC_BRID, KC_MUTE, KC_BRIU, QK_RBT,  QK_BOOT,
		                           BASE,    _______,      _______, BASE
	),

	[_MOUSE] = LAYOUT_34(
		KC_TAB,  ALT,     CONTROL, GUI,     KC_BSPC,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
		KC_ESC,  CUT,     COPY,    PASTE,   SELECT,       KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
		                           BASE,    _______,      KC_BTN1, BASE
	),

	/* Mouse layer left hand shift overrides
	 *      C(KC_B), _______, _______, _______, KC_DEL,
	 *      _______, _______, _______, _______, G(KC_O),
	 *      KC_I,    C(KC_A), A(KC_C), A(KC_V), KC_SPC,
	 */
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	switch (keycode) {
		case CLRMOD:
			if (record->event.pressed) {
				/* see users/dshields/dshields.c */
				uint8_t mods = 0;
				if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
					clear_oneshot_mods();
					unregister_mods(mods);
				}
				if ((mods = get_oneshot_locked_mods())) {
					clear_oneshot_locked_mods();
					unregister_mods(mods);
				}
				if (is_oneshot_layer_active()) {
					layer_clear();
				}
				return false;
			}
	}
	return true;
}
