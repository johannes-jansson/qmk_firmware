#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYM 3
#define _SYS 4
#define _GAME 5
#define _GFN 6


#define KC_SWLBRC LALT(KC_LBRC)
#define KC_SWQUOT LALT(KC_QUOT)
#define KC_SWSCLN LALT(KC_SCLN)
#define KC_MYSFT MT(MOD_LSFT, KC_ENT)
#define KC_MYSYM LT(_SYM, KC_TAB)
#define KC_MYALT MT(MOD_RALT, KC_TAB)
#define KC_MYTAB LT(_SYS, KC_ESC)
#define KC_MYBSPC MT(MOD_RCTL, KC_BSPC)
#define KC_GMESC LT(_GFN, KC_ESC)
#define KC_WIN_BSLS RALT(KC_MINS)

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

#define KC_MYF MT(MOD_LSFT, KC_F)
#define KC_MYJ MT(MOD_LSFT, KC_J)
#define KC_MYD MT(MOD_LCTL, KC_D)
#define KC_MYK MT(MOD_RCTL, KC_K)
#define KC_MYS MT(MOD_LALT, KC_S)
#define KC_MYL MT(MOD_RALT, KC_L)
#define KC_MYA MT(MOD_LGUI, KC_A)
#define KC_MYOUML MT(MOD_RGUI, KC_OUML)


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
 * [x] Navigating words and lines
 * [ ] Move SYS to tapdance thumb
 */

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  SYS,
  ANSIKEY,
  ANSICOM,
  ANSIDOT,
  M_SORT,
  M_ID,
  MY_SCREENSHOT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Shift|   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Shift| Shift| Shift| Cmd  | Tab  | Bspc |   | Space| Enter| Alt  | Shift| Shift| Shift|
 * `-----------------------------------------'   `-----------------------------------------'
 *
 * Enter becomes shift when held down
 * Tab goes to SYM layer when held down
 * , . / becomes < > ? when shift is pressed
 * Ö becomes right cmd when held down
 * HJKL becomes arrows when right cmd (Ö) is pressed
 *
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_MYTAB,    KC_Q,    KC_W,     KC_E,    KC_R,      KC_T,        KC_Y,      KC_U,    KC_I,    KC_O,       KC_P, KC_ARING, \
      KC_ESC,    KC_A,    KC_S,     KC_D,    KC_F,      KC_G,        KC_H,      KC_J,    KC_K,    KC_L,  KC_MYOUML,  KC_AUML, \
     KC_LSFT,    KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,        KC_N,      KC_M, ANSICOM,  ANSIDOT,   ANSIKEY, MO(_SYS), \
     KC_LSFT,   RESET, KC_LSFT, KC_LGUI, KC_MYSYM, KC_MYBSPC,      KC_SPC,  KC_MYSFT,KC_MYALT,  KC_LSFT,    KC_LSFT,  KC_LSFT  \
),
// SH_MON is swap hands

/* SYM
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   |   *  |   7  |   8  |   9  |   +  |   =  |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   ~  |   ^  |   $  |   (  |   )  |   '  |   |   ;  |   4  |   5  |   6  |   -  |   _  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |   |  |   #  |   %  |   [  |   ]  |   "  |   |   :  |   1  |   2  |   3  |   \  |  \   | but windows
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | RESET| Game |      |      |      |      |   |      |      |   0  |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_SYM] = LAYOUT_ortho_4x12( \
    KC_SE_GRAV,    KC_EXLM,  KC_SE_AT, KC_SE_LCBR, KC_SE_RCBR, KC_SE_AMPR, KC_SE_ASTR,    KC_7,      KC_8,    KC_9, KC_SE_PLUS,  KC_SE_EQL, \
    KC_SE_TILD, KC_SE_CIRC, KC_SE_DLR, KC_SE_LPRN, KC_SE_RPRN, KC_SE_QUOT, KC_SE_SCLN,    KC_4,      KC_5,    KC_6, KC_SE_MINS, KC_SE_UNDS, \
    KC_SE_PIPE,    KC_HASH,   KC_PERC, KC_SE_LBRC, KC_SE_RBRC, KC_SE_DQUO, KC_SE_COLN,    KC_1,      KC_2,    KC_3, KC_SE_BSLS,KC_WIN_BSLS, \
         RESET,  TO(_GAME),   _______,    _______,    _______,    _______,    _______, _______,      KC_0, _______,    _______,    _______  \
),

/* Sys
 */

[_SYS] = LAYOUT_ortho_4x12(
    KC_MYTAB, KC_VOLD, KC_MUTE, KC_VOLU,        M_SORT,    M_ID,        _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, \
   TO(_GAME), KC_MRWD, KC_MPLY, KC_MFFD, MY_SCREENSHOT, _______,        KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______, \
       RESET, _______, _______, _______,       _______, _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, \
     _______, _______, _______, _______,       _______, _______,        KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______ \
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
    case ANSICOM: {
      if (record->event.pressed)
        if(shift_pressed) {
          unregister_code(KC_LSHIFT);
          register_code(KC_GRV);
          register_code(KC_LSHIFT);
        } else {
          register_code(KC_COMM);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_COMM);
        }
      return false;
    }
    case ANSIDOT: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_GRV);
        } else {
          register_code(KC_DOT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_DOT);
        }
      return false;
    }
    case KC_E: // inserts the character é
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
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
  }
  return true;
}
