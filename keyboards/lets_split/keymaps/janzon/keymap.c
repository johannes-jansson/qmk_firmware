#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN 3

#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYCAPS MT(MOD_LCTL, KC_ESC)
#define KC_MYALT MT(MOD_RALT, KC_ENT)
#define KC_MYSFT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * |      |      |      | Shift|  Fn  | Bksp |   | Space| Alt  | CMD  |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 *  escape acts as ctrl when pressed
 *  alt acts as enter when tapped
 */

[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,       KC_U,       KC_I,    KC_O,      KC_P, KC_SWLBRC, \
   KC_MYCAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,       KC_J,       KC_K,    KC_L, KC_SWSCLN, KC_SWQUOT, \
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,       KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT , \
     _______, KC_LCTL, KC_LALT, KC_LSFT,      FN,   KC_BSPC, KC_SPC,  KC_MYALT,    KC_LGUI, _______,   _______, _______    \
),

/* Fn
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   |   :  |   7  |   8  |   9  |   +  | RESET|
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   ~  |   #  |   %  |   (  |   )  |   =  |   |   ;  |   4  |   5  |   6  |   -  |   *  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |   ^  |   $  |   [  |   ]  |   _  |   |   '  |   1  |   2  |   3  |   \  |   |  |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |   "  |      |   0  |   ,  |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
   KC_GRV, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_COLN,    KC_7, KC_8,    KC_9, KC_PLUS,   RESET, \
  KC_TILD, KC_HASH, KC_PERC, KC_LPRN, KC_RPRN,  KC_EQL, KC_SCLN,    KC_4, KC_5,    KC_6, KC_MINS, KC_ASTR, \
  _______, KC_CIRC, KC_DLR,  KC_LBRC, KC_RBRC, KC_UNDS, KC_QUOT,    KC_1, KC_2,    KC_3, KC_BSLS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, KC_DQUO, _______, KC_0, KC_COMM, _______, _______  \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
}
