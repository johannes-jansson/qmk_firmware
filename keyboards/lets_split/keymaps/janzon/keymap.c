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
#define KC_MYSFT MT(MOD_LSFT, KC_BSPC)
#define KC_GMESC LT(_GFN, KC_ESC)

/* TODOS:
 * [x] Decide on shift
 * [x] Decide on backspace
 * [x] Fix fn layer
 * [x] Fix movement keys
 * [x] Flash eeprom
 * [x] Gaming layer
 * [x] Gaming fn layer
 * [ ] Look at swap hands https://github.com/qmk/qmk_firmware/blob/master/docs/feature_swap_hands.md
 * [ ] Try out mousekeys
 */

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
  UC_AUML,
  UC_OUML,
  UC_ARING,
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
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Bspace|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Shift| Shift| Shift|  CMD |  Fn  | Shift|   | Space| Alt  | Ctrl | Shift| Shift| Shift|
 * `-----------------------------------------'   `-----------------------------------------'
 *  alt acts as enter when tapped
 *  middle shift acts as backspace when tapped
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,        KC_Y,      KC_U,    KC_I,    KC_O,     KC_P, UC_ARING, \
    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,      KC_G,        KC_H,      KC_J,    KC_K,    KC_L,  UC_OUML,  UC_AUML, \
   KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,        KC_N,      KC_M, KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSPC, \
   KC_LSFT, KC_LSFT, KC_GRAVE, KC_LGUI,      FN, KC_MYSFT,      KC_SPC,  KC_MYALT, KC_RCTL, KC_RSFT,  KC_RSFT,  KC_RSFT  \
),
// #define KC_SWLBRC UC(0x00E5)

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
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   |QWERTY|      |      |      |      |      |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  | Space|   |      |      |      |      |      |      |
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

// This variable manually keeps track of whether alt is pressed or not
bool lisinges_variable = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t shift_pressed = get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
  uint8_t alt_pressed = get_mods() & ((MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)));
  // The following five cases map alt hjkl to arrow keys 
  switch (keycode) {
    case KC_MYALT:
      if (record->event.pressed) {
        lisinges_variable = true;
      } else {
        lisinges_variable = false;
      }
      return true;
    case KC_H:
      if (lisinges_variable) {
        if (record->event.pressed) {
          unregister_code(KC_RALT);
          register_code(KC_LEFT);
        } else {
          unregister_code(KC_LEFT);
          register_code(KC_RALT);
        }
        return false;
      }
      unregister_code(KC_LEFT);
      return true;
    case KC_J:
      if (lisinges_variable) {
        if (record->event.pressed) {
          unregister_code(KC_RALT);
          register_code(KC_DOWN);
        } else {
          unregister_code(KC_DOWN);
          register_code(KC_RALT);
        }
        return false;
      }
      unregister_code(KC_DOWN);
      return true;
    case KC_K:
      if (lisinges_variable) {
        if (record->event.pressed) {
          unregister_code(KC_RALT);
          register_code(KC_UP);
        } else {
          unregister_code(KC_UP);
          register_code(KC_RALT);
        }
        return false;
      }
      unregister_code(KC_UP);
      return true;
    case KC_L:
      if (lisinges_variable) {
        if (record->event.pressed) {
          unregister_code(KC_RALT);
          register_code(KC_RIGHT);
        } else {
          unregister_code(KC_RIGHT);
          register_code(KC_RALT);
        }
        return false;
      }
      unregister_code(KC_RIGHT);
      return true;

    case KC_E:
      if (alt_pressed) {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00E9"));
          return false;
          break;
        }
      } 
      return true;
      break;
    
    // The following three cases handle Swedish letters
    case UC_AUML:
      if (shift_pressed) {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00C4"));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00E4"));
        }
      }
      return false;
      break;
    case UC_OUML:
      if (shift_pressed) {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00D6"));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00F6"));
        }
      }
      return false;
      break;
    case UC_ARING:
      if (shift_pressed) {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00C5"));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_LALT("00E5"));
        }
      }
      return false;
      break;

    // The following two cases handle layer switching
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
