/**
 * @Author: Chris James Champeau <semaj4712>
 * @Date:   2018-06-05T12:26:55-07:00
 * @Email:  semaj4712@gmail.com
 * @Filename: config.h
 * @Last modified by:   semaj4712
 * @Last modified time: 2018-07-08T00:52:10-07:00
 */



#ifndef MOUSE_CONFIG_H
#define MOUSE_CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Champs Speedshop
#define PRODUCT         Planck Keyboard + Joystick
#define DESCRIPTION     A Planck Keyboard with a Joystick Mouse

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { F4, C6, E6, B4 }
#define MATRIX_COL_PINS { D3, D2, D4, D7, B2, B3 }
// #define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6 } //uncomment this line and comment line above if you need to reverse left-to-right key order

// /* key matrix size */
// #define MATRIX_ROWS 4
// #define MATRIX_COLS 12
// 
// /* key matrix pins */
// #define MATRIX_ROW_PINS { B1, F0, F1, F4 }
// #define MATRIX_COL_PINS { E7, E6, F5, B0, D4, D5, D6, D7, E0, E1, C0, C1 }
// #define UNUSED_PINS { C2, C3 }
// 
// #define QMK_ESC_OUTPUT E7
// #define QMK_ESC_INPUT B1
// #define B5_AUDIO


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 0
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif
