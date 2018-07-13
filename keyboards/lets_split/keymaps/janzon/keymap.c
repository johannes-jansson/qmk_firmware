#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN 3
#define _GAME 5
#define _GFN 6


#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYCAPS MT(MOD_LCTL, KC_ESC)
#define KC_MYALT MT(MOD_RALT, KC_ENT)
#define KC_MYSFT MT(MOD_RSFT, KC_ENT)
#define KC_GMESC LT(_GFN, KC_ESC)

/* TODOS:
 * Decide on shift
 * Decide on backspace
 * Fix fn layer
 * Fix movement keys
 * Flash eeprom
 * Look at swap hands https://github.com/qmk/qmk_firmware/blob/master/docs/feature_swap_hands.md
 * Try out mousekeys
 */
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
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Bspace|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Shift| Shift| Shift|  CMD |  Fn  | Shift|   | Space| Alt  | Ctrl | Shift| Shift| Shift|
 * `-----------------------------------------'   `-----------------------------------------'
 *  alt acts as enter when tapped
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,      KC_U,    KC_I,    KC_O,      KC_P, KC_SWLBRC, \
    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,      KC_J,    KC_K,    KC_L, KC_SWSCLN, KC_SWQUOT, \
   KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,      KC_M, KC_COMM,  KC_DOT,   KC_SLSH,   KC_BSPC, \
   KC_LSFT, KC_LSFT, KC_LSFT, KC_LGUI,      FN, KC_LSFT,      KC_SPC,  KC_MYALT, KC_RCTL, KC_RSFT,   KC_RSFT,   KC_RSFT  \
),

/* Fn
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   |   *  |   7  |   8  |   9  |   +  |   =  |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   ~  |   ^  |   $  |   (  |   )  |   '  |   |   ;  |   4  |   5  |   6  |   -  |   _  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |   |  |   #  |   %  |   [  |   ]  |   "  |   |   :  |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | RESET| Game |      |      |      |      |   |      |      |      |   0  |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
     KC_GRV,   KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_AMPR, KC_ASTR,    KC_7,    KC_8,    KC_9, KC_PLUS,  KC_EQL, \
    KC_TILD,   KC_CIRC,  KC_DLR, KC_LPRN, KC_RPRN, KC_QUOT, KC_SCLN,    KC_4,    KC_5,    KC_6, KC_MINS, KC_UNDS, \
    KC_PIPE,   KC_HASH, KC_PERC, KC_LBRC, KC_RBRC, KC_DQUO, KC_COLN,    KC_1,    KC_2,    KC_3, KC_BSLS, _______, \
      RESET, TO(_GAME), _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______  \
),

/* Game
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   |QWERTY|   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  | Space|   | Space| Alt  | CMD  |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */

[_GAME] = LAYOUT_ortho_4x12(
    KC_GMESC,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    TO(_QWERTY), _______, _______, _______, _______, _______, \
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,        _______, _______, _______, _______, _______, _______, \
     KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,        _______, _______, _______, _______, _______, _______, \
     KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_SPC,        _______, _______, _______, _______, _______, _______ \
),

/* Game FN
 * ,-----------------------------------------. 
 * |      |  F1  |  F2  | VOTE | TEAM | Cons | 
 * |------+------+------+------+------+------- 
 * |  Buy | Vol- | Mute | Vol+ | rebuy|autbuy| 
 * |------+------+------+------+------+------| 
 * |      | Bri- |      | Bri+ |      |      | 
 * |------+------+------+------+------+------+ 
 * |      |      |      |      |      |QWERTY| 
 * `-----------------------------------------' 
 */

[_GFN] = LAYOUT_ortho_4x12(
    _______,   KC_F1,   KC_F1, KC_SWLBRC,      KC_M,     KC_SLSH,    _______,  _______, _______, _______, _______, _______, \
       KC_B, KC_VOLD, KC_MUTE,   KC_VOLU, KC_SWSCLN,   KC_SWQUOT,    _______,  _______, _______, _______, _______, _______, \
    _______,  BL_INC, _______,    BL_DEC,   _______,     _______,    _______,  _______, _______, _______, _______, _______, \
    _______, _______, _______,   _______,   _______, TO(_QWERTY),    _______,  _______, _______, _______, _______, _______ \
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
