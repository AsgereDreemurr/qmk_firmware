/* Copyright 2015-2021 Jack Humbert
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

 // Guide: https://docs.qmk.fm/#/newbs_building_firmware

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN,
};

// Layers
#define QWERTY 	MO(0)
#define COLEMAK MO(1)
#define LOWER 	MO(2)
#define RAISE 	MO(3)
#define FUNC  	MO(4)

#define DK_AA KC_LBRC
#define DK_AE KC_SCLN
#define DK_OE KC_QUOT

// Shifted characters
#define DK_SECT LSFT(KC_GRV)  // §
#define DK_EXLM LSFT(KC_1)    // !
#define DK_DQUO LSFT(KC_2)    // "
#define DK_HASH LSFT(KC_3)    // #
#define DK_CURR LSFT(KC_4)    // ¤
#define DK_PERC LSFT(KC_5)    // %
#define DK_AMPR LSFT(KC_6)    // &
#define DK_SLSH LSFT(KC_7)    // /
#define DK_LPRN LSFT(KC_8)    // (
#define DK_RPRN LSFT(KC_9)    // )
#define DK_EQL  LSFT(KC_0)    // =
#define DK_QUES LSFT(KC_MINS) // ?
#define DK_SCLN LSFT(KC_COMM)	// ;
#define DK_TICK LSFT(KC_EQL)	// `

// Alt-Gr keys
#define DK_AT   RALT(KC_2)    // @
#define DK_PND  RALT(KC_3)		// £
#define DK_DOL  RALT(KC_4)		// $
#define DK_EUR  RALT(KC_5)		// €
#define DK_PIPE RALT(KC_EQL)	// |
#define DK_LCBR RALT(KC_7)    // {
#define DK_LPRN LSFT(KC_8)		// (
#define DK_RPRN LSFT(KC_9)		// )
#define DK_RCBR RALT(KC_0)		// }
#define DK_ASTX LSFT(KC_NUHS)	// asterisk
#define DK_LBRC RALT(KC_8)		// [
#define DK_RBRC RALT(KC_9)		// ]
#define DK_BSLH RALT(KC_NUBS)	// backslash
#define DK_TILD RALT(KC_RBRC) // ~

// Combos
const uint16_t PROGMEM combo_AE[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_OE[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM combo_AA[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM combo_PGUP[] = {KC_ESC, KC_U, COMBO_END};
const uint16_t PROGMEM combo_PGDN[] = {KC_ESC, KC_O, COMBO_END};
const uint16_t PROGMEM combo_HOME[] = {KC_ESC, KC_N, COMBO_END};
const uint16_t PROGMEM combo_END[] = {KC_ESC, KC_M, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_AE, DK_AE),
    COMBO(combo_OE, DK_OE),
    COMBO(combo_AA, DK_AA),
		COMBO(combo_PGDN, KC_PGDN),
		COMBO(combo_PGUP, KC_PGUP),
		COMBO(combo_HOME, KC_HOME),
		COMBO(combo_END, KC_END)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Qwerty
	* ,-----------------------------------------------------------------------------------.
	* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Æ  |  '   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Ctrl |  OS  | AlGr | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_QWERTY] = LAYOUT_planck_grid(
		KC_TAB, 	KC_Q, 	KC_W, 	KC_E, 	 KC_R, 	KC_T, 	KC_Y, 	KC_U, 	 KC_I, 		KC_O, 	KC_P, 	 KC_BSPC, 
		KC_ESC, 	KC_A, 	KC_S, 	KC_D, 	 KC_F, 	KC_G, 	KC_H, 	KC_J, 	 KC_K, 		KC_L, 	DK_AE, 	 KC_NUHS, 
		KC_LSFT, 	KC_Z, 	KC_X, 	KC_C, 	 KC_V, 	KC_B, 	KC_N, 	KC_M, 	 KC_COMM, KC_DOT, KC_SLSH, KC_ENT, 
		KC_LCTL, 	KC_LGUI,FUNC, KC_LALT, 	 LOWER, KC_SPC, KC_SPC, RAISE, 	KC_LEFT, KC_DOWN, KC_UP, 	KC_RGHT
	),
	/* Colemak DH
	* ,-----------------------------------------------------------------------------------.
	* | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ^  | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   -  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Ctrl |  OS  |  FN  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_COLEMAK] = LAYOUT_planck_grid(
		KC_TAB, 	KC_Q, 		KC_W, 	KC_F, 		KC_P, 	KC_B, 	KC_J, 	KC_L, 	 KC_U, 		KC_Y, 	KC_RBRC, KC_BSPC, 
		KC_ESC, 	KC_A, 		KC_R, 	KC_S, 		KC_T, 	KC_G, 	KC_M, 	KC_N, 	 KC_E,    KC_I, 	KC_O, 	 KC_NUHS, 
		KC_LSFT, 	KC_Z, 		KC_X, 	KC_C, 		KC_D, 	KC_V, 	KC_K, 	KC_H, 	 KC_COMM, KC_DOT, KC_SLSH, KC_ENT, 
		KC_LCTL, 	KC_LGUI, 	FUNC, 	KC_LALT, 	LOWER, 	KC_SPC, KC_SPC, RAISE, 	KC_LEFT, KC_DOWN, KC_UP, 	KC_RGHT
	),


	/* Lower
	* ,-----------------------------------------------------------------------------------.
	*	|   ½  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  DEL |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |   +  |  ´   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   ,  |   .  |  -   |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      | [ON] |             |      | Home | PgDn | PgUp | End  |
	* `-----------------------------------------------------------------------------------'
	*/
	[_LOWER] = LAYOUT_planck_grid(
		KC_GRV, 	KC_1, 	 KC_2, 		KC_3, 	 	KC_4, 		KC_5, 	 KC_6, 		KC_7, 		KC_8, 	 KC_9, 		KC_0, 		KC_BSPC, 
		KC_DEL, 	KC_F1, 	 KC_F2, 	KC_F3, 	 	KC_F4, 		KC_F5, 	 KC_F6, 	KC_NO, 		KC_NO, 	 KC_NO, 	KC_MINS, 	KC_EQL, 	
		KC_TRNS, 	KC_F7, 	 KC_F8, 	KC_F9, 		KC_F10,  	KC_F11,  KC_F12, 	KC_NO, 	  KC_TRNS, 	 KC_TRNS, 	KC_TRNS, 		KC_TRNS, 
		KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, 	KC_PGDN, KC_PGUP, KC_END
	),

	/* Raise
	* ,-----------------------------------------------------------------------------------.
	* |   §  |   !  |   "  |   #  |   %  |   &  |   /  |   (  |   )  |   =  |   ?  |  `   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Del  |      |   /  |      |      |      |      |   {  |   (  |   )  |   }  |  *   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |  <   |      |      |      |      |      |      |   [  |   ]  |   ;  |  ´   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             | [ON] | Mute | Vol- | Vol+ | Play |
	* `-----------------------------------------------------------------------------------'
	*/
	[_RAISE] = LAYOUT_planck_grid(
		DK_SECT, 	DK_EXLM, DK_DQUO,	DK_HASH, 	DK_PERC, 	DK_AMPR, 	DK_SLSH, 	DK_LPRN, 	DK_RPRN, 	DK_EQL,	 DK_QUES,  DK_TICK,
		KC_DEL,  	KC_NO, 	 DK_SLSH, KC_NO, 		KC_NO, 	 	KC_NO, 		KC_NO, 		DK_LCBR, 	DK_LPRN, 	DK_RPRN, 	DK_RCBR, DK_ASTX, 
		KC_TRNS, 	KC_NUBS, KC_NO, 	KC_NO, 		KC_NO, 	 	KC_NO, 		KC_NO, 		KC_NO, 		DK_LBRC, 	DK_RBRC, 	DK_SCLN, KC_EQL, 
		KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS,  KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	KC_MPLY
	),

	/* FN layer (http://opensteno.org)
	* ,-----------------------------------------------------------------------------------.
	* |      |      |   @  |   £  |   $  |   €  |      |   {  |   [  |   ]  |   }  |  |   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |   Å  |      |      |      |      |      |      |   Æ  |      |   Ø  |  ~   |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |   \  |      |      |      |      |      |   µ  |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |   <  |   v   |  ^  |   >  |
	* `-----------------------------------------------------------------------------------'
	*/

	[_FN] = LAYOUT_planck_grid(
		KC_TRNS, 	KC_NO,		DK_AT, 		DK_PND, 	DK_DOL, 	DK_EUR, 	KC_NO, 	 DK_LCBR, 		DK_LBRC, 	DK_RBRC, 	DK_RCBR, 	DK_PIPE, 
		KC_TRNS, 	DK_AA, 	  KC_NO, 		KC_NO, 		KC_NO, 	  KC_NO, 		KC_NO, 	 KC_NO, 			DK_AE,		KC_NO, 	 	DK_OE,		DK_TILD, 
		KC_TRNS, 	DK_BSLH, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 	 RALT(KC_M), 	KC_NO,		KC_NO,		KC_NO,		KC_TRNS, 
		KC_TRNS, 	KC_TRNS,	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, KC_TRNS,     KC_LEFT,  KC_DOWN,	KC_UP,		KC_RGHT
	),

	/* Adjust (Lower + Raise)
	*                      v------------------------RGB CONTROL--------------------v
	* ,-----------------------------------------------------------------------------------.
	* | EEPRM| Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      | CMBo | CMBx |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |Click |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_ADJUST] = LAYOUT_planck_grid(
		EEP_RST, RESET, 	DEBUG, 	 RGB_TOG,  RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL, 
		KC_TRNS, KC_TRNS, MU_MOD,  AU_ON, 	 AU_OFF, 	KC_TRNS, KC_TRNS, QWERTY,  COLEMAK,  KC_TRNS, CMB_OFF, CMB_ON, 
		KC_TRNS, MUV_DE, 	MUV_IN,  MU_ON, 	 MU_OFF, 	MI_ON, 	 MI_OFF, 	TERM_ON, TERM_OFF, KC_TRNS, CK_TOGG, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}