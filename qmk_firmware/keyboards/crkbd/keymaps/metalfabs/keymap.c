/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"

enum corne_layers {
	DEF = _A_CUSTOM + 1,
	SYM,
	FUNCNAV,
	RRGB,
	MNUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        // default layer
		[DEF] = LAYOUT_split_3x6_3(
				KC_ESC,		KC_Q,	KC_W,	KC_E, 	KC_R, 			KC_T,					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
				KC_LSFT, 	KC_A, 	KC_S, 	KC_D, 	SFT_T(KC_F), 	KC_G, 					KC_H, SFT_T(KC_J), KC_K, KC_L, KC_SCLN, KC_QUOT,
				KC_LCTL, 	KC_Z, 	KC_X, 	KC_C, 	KC_V, 			KC_B, 					KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TT(MNUM),
											KC_LALT, LT(SYM,KC_DEL), KC_SPC, 					KC_ENT, LT(FUNCNAV,KC_TAB), KC_LGUI),

		//	symbol layer
        [SYM] = LAYOUT_split_3x6_3(
				KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, 								KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
				KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, 					KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_TRNS,
				KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_LPRN, 				KC_RPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
						KC_TRNS, KC_TRNS, KC_TRNS,									KC_TRNS, MO(RRGB), KC_P0),

		//	function and arrow layer
        [FUNCNAV] = LAYOUT_split_3x6_3(
				KC_TRNS, KC_F1, KC_F2, 	KC_F3,	KC_F4, 	KC_TRNS, 					KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_BSPC,
				KC_TRNS, KC_F5, KC_F6, 	KC_F7, 	KC_F8, 	KC_TRNS, 					KC_LEFT, KC_DOWN, KC_UP, 	KC_RGHT, 	KC_TRNS, 	KC_TRNS,
				KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 					KC_HOME, KC_PGDN, KC_PGUP, 	KC_END, 	KC_TRNS, 	KC_TRNS,
										KC_TRNS, MO(RRGB), KC_TRNS, 					KC_TRNS, KC_TRNS, KC_LGUI),

		// reset and backlight layer
        [RRGB] = LAYOUT_split_3x6_3(
				RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 							KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
				RGB_M_P, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO,						KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
				RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO,					KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_A_BASE),
					    KC_TRNS, KC_TRNS, KC_TRNS,									KC_TRNS, KC_TRNS, KC_TRNS),

		// mouse and numpad layer
		[MNUM] = LAYOUT_split_3x6_3(
				KC_ACL2, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, 					KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
				KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO,					KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
				KC_ACL0, KC_NO, KC_BTN3, KC_NO, KC_NO, KC_NO,						KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_TRNS,
						KC_TRNS, KC_TRNS, KC_TRNS,									KC_TRNS, KC_0, KC_PDOT),
						
		// artsey.io follows.
		[_A_BASE] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_BASE_A,A_BASE_R,A_BASE_T,A_BASE_S,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_BASE_E,A_BASE_Y,A_BASE_I,A_BASE_O, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_NUM] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_NUM_A,A_NUM_R,A_NUM_T,A_NUM_S, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_NUM_E,A_NUM_Y,A_NUM_I,A_NUM_O, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_NAV] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_NAV_A,A_NAV_R,A_NAV_T,A_NAV_S,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_NAV_E,A_NAV_Y,A_NAV_I,A_NAV_O,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_SYM] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_SYM_A,A_SYM_R,A_SYM_T,A_SYM_S,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_SYM_E,A_SYM_Y,A_SYM_I,A_SYM_O,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_BRAC] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_BRAC_A,A_BRAC_R,A_BRAC_T,A_BRAC_S,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_BRAC_E,A_BRAC_Y,A_BRAC_I,A_BRAC_O,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_MOU] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_MOU_A,A_MOU_R,A_MOU_T,A_MOU_S,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_MOU_E,A_MOU_Y,A_MOU_I,A_MOU_O,KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS),

		[_A_CUSTOM] = LAYOUT_split_3x6_3(
			DF(DEF), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_CUSTOM_A,A_CUSTOM_R,A_CUSTOM_T,A_CUSTOM_S, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, A_CUSTOM_E,A_CUSTOM_Y,A_CUSTOM_I,A_CUSTOM_O, KC_NO,
			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
					KC_TRNS, KC_TRNS, KC_TRNS,			KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

/*
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    // Show Ctrl-Gui Swap options
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}
*/

static void oled_render_logo_satan(void) {
  static const char PROGMEM my_logo[] = {
    // Paste the code from the previous step below this line!
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x78, 0x78, 0x70, 0xf0, 0xf0, 
0xe0, 0xe0, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
0xe0, 0xf0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xf0, 
0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x70, 0xf0, 0xf0, 0xf0, 
0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x30, 0x00, 0x00, 0x00, 0x80, 
0xc0, 0xe0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xf0, 
0xf0, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
0xc0, 0xc0, 0x60, 0x70, 0x70, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xc0, 0xe0, 0x38, 0x7f, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
0xff, 0xf3, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x8f, 
0x03, 0x00, 0x00, 0x0c, 0x04, 0x87, 0x67, 0x3f, 0x0f, 0x07, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x03, 0xe0, 0xf0, 0xf8, 0x1c, 0x03, 0x00, 0x00, 0xff, 
0xff, 0xff, 0xff, 0x03, 0x03, 0xff, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xff, 
0x03, 0x00, 0x00, 0x08, 0x0c, 0x87, 0xc7, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x60, 0xfc, 0xff, 0xff, 0xff, 
0x00, 0xff, 0x20, 0x40, 0x40, 0x00, 0x00, 0x43, 0x47, 0x3f, 0xff, 0xff, 0xff, 0x38, 0x00, 0x00, 
0x00, 0x00, 0x81, 0x87, 0xcf, 0xce, 0xde, 0xdc, 0xdc, 0xdc, 0xfc, 0x9c, 0x9e, 0x9f, 0x1c, 0x1e, 
0x1e, 0x1e, 0x9e, 0xfc, 0xfc, 0x79, 0x31, 0x03, 0xff, 0x7f, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x01, 
0xc6, 0xec, 0x98, 0x1c, 0x1f, 0x1d, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0x80, 0xc0, 0xff, 
0x7f, 0x3f, 0x0f, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x00, 0x00, 0x00, 0x01, 
0x83, 0xe4, 0xb8, 0x1c, 0x1e, 0x1d, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x22, 0x22, 0x66, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xff, 0x04, 0x04, 0x00, 0x02, 0x00, 0x84, 0xf4, 0x7e, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x04, 0x1f, 0x27, 0x23, 0x23, 0x23, 0x23, 0x27, 0x07, 0x07, 0x1f, 0x0f, 0x0f, 0x1e, 0x1e, 
0x3e, 0x3e, 0x3f, 0x19, 0x19, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3c, 0x06, 
0x07, 0x07, 0x0f, 0x0e, 0x1e, 0x1c, 0x3c, 0x18, 0x18, 0x08, 0x04, 0x02, 0x07, 0x1f, 0x3f, 0x3f, 
0x1e, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3d, 
0x3c, 0x38, 0x38, 0x38, 0x38, 0x3f, 0x1c, 0x1c, 0x0e, 0x06, 0x03, 0x01, 0x00, 0x00, 0x38, 0x36, 
0x07, 0x07, 0x0f, 0x0e, 0x1e, 0x1c, 0x3c, 0x38, 0x18, 0x08, 0x04, 0x04, 0x03, 0x0f, 0x3f, 0x3f, 
0x1f, 0x0c, 0x0c, 0x04, 0x40, 0x60, 0x60, 0x70, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xfb, 0x6f, 0x23, 
0x10, 0x0f, 0x00, 0x00, 0x80, 0x70, 0x3c, 0x3f, 0x3d, 0x1c, 0x1c, 0x3c, 0x3c, 0x1c, 0x04, 0x00
  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_logo_satan();
    } else {
        oled_render_logo();
    }
}

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
        }
  #endif
    //if (record->event.pressed) {
    //set_keylog(keycode, record);
  //}
  return true;
}
*/
#endif // OLED_DRIVER_ENABLE