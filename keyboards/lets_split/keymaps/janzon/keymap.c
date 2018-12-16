#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN 3
#define _SYS 4
#define _GAME 5
#define _GFN 6


#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYCAPS MT(MOD_LCTL, KC_ESC)
#define KC_MYALT MT(MOD_RALT, KC_ENT)
#define KC_MYSFT MT(MOD_LSFT, KC_BSPC)
#define KC_MYFN LT(_FN, KC_TAB)
#define KC_MYZERO MT(MOD_RCTL, KC_0)
#define KC_MYTAB LT(_SYS, KC_TAB)
#define KC_GMESC LT(_GFN, KC_ESC)

#define KC_ARING KC_LBRC
#define KC_OUML KC_SCLN
#define KC_AUML KC_QUOT

#define KC_SE_SLSH S(KC_7)
#define KC_SE_AT LALT(KC_2) 
#define KC_SE_AMPR S(KC_6)
#define KC_SE_LPRN S(KC_8)
#define KC_SE_RPRN S(KC_9)
#define KC_SE_QUOT KC_BSLS
#define KC_SE_DQUO S(KC_2)
#define KC_SE_DLR LALT(KC_4)
#define KC_SE_LCBR S(LALT(KC_8))
#define KC_SE_RCBR S(LALT(KC_9))
#define KC_SE_LBRC LALT(KC_8)
#define KC_SE_RBRC LALT(KC_9)
#define KC_SE_EQL S(KC_0)
#define KC_SE_GBP LALT(KC_3)
#define KC_SE_TILD LALT(KC_RBRC)
#define KC_SE_EURO LALT(KC_E)
#define KC_SE_AA KC_LBRC
#define KC_SE_OE KC_SCLN
#define KC_SE_AE KC_QUOT
#define KC_SE_PLAYP KC_MEDIA_PLAY_PAUSE
#define KC_SE_MUTE KC_AUDIO_MUTE
#define KC_SE_CIRC KC_RCBR
#define KC_SE_PARA KC_GRAVE
#define KC_SE_HALF KC_TILD
#define KC_SE_ACUT KC_EQL
#define KC_SE_GRAV KC_PLUS
#define KC_SE_GT S(KC_GRV)
#define KC_SE_LT KC_GRV
#define KC_SE_PLUS KC_MINS
#define KC_SE_ASTR KC_PIPE
#define KC_SE_QUES S(KC_MINS)
#define KC_SE_BSLS S(LALT(KC_7))
#define KC_SE_PIPE LALT(KC_7)
#define KC_SE_SCLN S(KC_COMM)
#define KC_SE_COLN S(KC_DOT)
#define KC_SE_MINS KC_SLSH
#define KC_SE_UNDS S(KC_SLSH)


/* TODOS:
 * [x] Decide on shift
 * [x] Decide on backspace
 * [x] Fix fn layer
 * [x] Fix movement keys
 * [x] Flash eeprom
 * [x] Gaming layer
 * [x] Gaming fn layer
 * [x] Volume and media keys
 * [x] Look at swap hands https://github.com/qmk/qmk_firmware/blob/master/docs/feature_swap_hands.md
 * [x] Try out mousekeys
 * [x] Use ISO not unicode
 * [ ] Navigating words and lines
 * [ ] Move SYS to tapdance thumb
 */

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
  SYS,
  ANSIKEY,
  M_SORT,
  M_ID,
  ANDREE,
  MY_SCREENSHOT,
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
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |  Alt |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Shift| Shift| Shift|  CMD |  Fn  | Shift|   | Space| Alt  | Ctrl | Shift| Shift| Shift|
 * `-----------------------------------------'   `-----------------------------------------'
 *  alt acts as enter when tapped
 *  fn acts as tab when tapped
 *  middle shift acts as backspace when tapped
 *  , . / becomes ; > ? when shift is pressed
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_MYTAB,    KC_Q,    KC_W,     KC_E,    KC_R,      KC_T,        KC_Y,      KC_U,    KC_I,    KC_O,       KC_P, KC_ARING, \
      KC_ESC,    KC_A,    KC_S,     KC_D,    KC_F,      KC_G,        KC_H,      KC_J,    KC_K,    KC_L,    KC_OUML,  KC_AUML, \
     KC_RSFT,    KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,        KC_N,      KC_M, KC_COMM,  KC_DOT,    ANSIKEY,  KC_RALT, \
     KC_RSFT,   RESET,  KC_RSFT, KC_LGUI, KC_MYFN,  KC_MYSFT,      KC_SPC,  KC_MYALT, KC_RCTL, KC_RSFT,    KC_RSFT,  KC_RSFT  \
),
// SH_MON is swap hands

/* Fn
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   |   *  |   7  |   8  |   9  |   +  |   =  |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   ~  |   ^  |   $  |   (  |   )  |   '  |   |   "  |   4  |   5  |   6  |   -  |   _  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |   |  |   #  |   <  |   [  |   ]  |   >  |   |   %  |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | RESET| Game |      |      |      |      |   |      |      |   0  |   0  |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
    KC_SE_GRAV,    KC_EXLM,  KC_SE_AT, KC_SE_LCBR, KC_SE_RCBR, KC_SE_AMPR, KC_SE_ASTR,    KC_7,      KC_8,    KC_9, KC_SE_PLUS,  KC_SE_EQL, \
    KC_SE_TILD, KC_SE_CIRC, KC_SE_DLR, KC_SE_LPRN, KC_SE_RPRN, KC_SE_QUOT, KC_SE_DQUO,    KC_4,      KC_5,    KC_6, KC_SE_MINS, KC_SE_UNDS, \
    KC_SE_PIPE,    KC_HASH,  KC_SE_LT, KC_SE_LBRC, KC_SE_RBRC,   KC_SE_GT,    KC_PERC,    KC_1,      KC_2,    KC_3, KC_SE_BSLS,    _______, \
         RESET,  TO(_GAME),   _______,    _______,    _______,    _______,    _______, _______, KC_MYZERO,    KC_0,    _______,    _______  \
),

/* Sys
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |  Tab |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */

[_SYS] = LAYOUT_ortho_4x12(
    KC_MYTAB, KC_VOLD, KC_MUTE, KC_VOLU,        M_SORT,    M_ID,        _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, \
   TO(_GAME), KC_MRWD, KC_MPLY, KC_MFFD, MY_SCREENSHOT,  ANDREE,        KC_BTN1, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, \
       RESET, _______, _______, _______,       _______, _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, \
     _______, _______, _______, _______,       _______, _______,        KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______ \
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

  switch (keycode) {
    case ANSIKEY: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_MINS);
        } else {
          register_code(KC_LSHIFT);
          register_code(KC_7);
          unregister_code(KC_LSHIFT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_MINS);
        } else {
          unregister_code(KC_7);
        }
      return false;
    }
    // The following five cases map alt hjkl to arrow keys 
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
          /* register_code(KC_SE_ACUT); */
          register_code(KC_E);
        } else {
          /* unregister_code(KC_SE_ACUT); */
          unregister_code(KC_E);
        }
      } 
      return true;
      break;
    case ANDREE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL)SS_TAP(X_E));
      }
      return false;
      break;
    case MY_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT(SS_TAP(X_4)))));
      }
      return false;
      break;
    case M_SORT:
      if (record->event.pressed) {
        SEND_STRING(".sort* " SS_LALT(SS_LSFT(SS_TAP(X_8))) " created?on> /1 " SS_LALT(SS_LSFT(SS_TAP(X_9))) " (");
      }
      return false;
      break;
    case M_ID:
      if (record->event.pressed) {
        /* sends the string "_id": ObjectId("") */
        SEND_STRING(SS_LSFT(SS_TAP(X_2)) "?id" SS_LSFT(SS_TAP(X_2)) "> ObjectId*" SS_LSFT(SS_TAP(X_2)) SS_LSFT(SS_TAP(X_2)) "(");
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
