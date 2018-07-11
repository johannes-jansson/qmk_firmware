#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYCAPS MT(MOD_LCTL, KC_ESC)
#define KC_MYALT MT(MOD_RALT, KC_ENT)
#define KC_MYSFT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      | Shift|Lower | Bksp | Space| Alt  | GUI  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *  escape acts as ctrl when pressed
 *  left alt acts as enter when tapped
 *  left shift acts as enter when tapped
 */

[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,       KC_U,       KC_I,    KC_O,      KC_P, KC_SWLBRC, \
   KC_MYCAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,       KC_J,       KC_K,    KC_L, KC_SWSCLN, KC_SWQUOT, \
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,       KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_MYSFT , \
     KC_LCTL, KC_LCTL, KC_LALT, KC_LSFT,   LOWER,   KC_BSPC, KC_SPC,  KC_MYALT,    KC_LGUI, _______,   _______, _______    \
),

// & *
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   :  |   7  |   8  |   9  |   +  | RESET|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   #  |   %  |   (  |   )  |   =  |   ;  |   4  |   5  |   6  |   -  |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ^  |   $  |   [  |   ]  |   _  |   '  |   1  |   2  |   3  |   \  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   "  |      |   0  |   ,  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
   KC_GRV, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_COLN,    KC_7, KC_8,    KC_9, KC_PLUS,   RESET, \
  KC_TILD, KC_HASH, KC_PERC, KC_LPRN, KC_RPRN,  KC_EQL, KC_SCLN,    KC_4, KC_5,    KC_6, KC_MINS, KC_ASTR, \
  _______, KC_CIRC, KC_DLR,  KC_LBRC, KC_RBRC, KC_UNDS, KC_QUOT,    KC_1, KC_2,    KC_3, KC_BSLS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, KC_DQUO, _______, KC_0, KC_COMM, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
