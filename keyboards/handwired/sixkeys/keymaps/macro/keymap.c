#include "sixkeys.h"
#include <time.h>
#include "stdlib.h"

#define randadd 163 
#define randmul 5
#define randmod 106
#define num_options 3

enum custom_keycodes {
    NOUN = SAFE_RANGE,
    VERB,
    ADJECTIVE,
    BAJS
};

const char *nouns[] = {"apskaft","dumhuvud","jubelidiot"};

static uint16_t r = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        r = TCNT0 % 256;
        r = ((r + randadd) * randmul) % randmod % num_options;
        switch(keycode) {
            case NOUN:
                // SEND_STRING(nouns[r]);
                // return false;
                switch(r) {
                  case 0:
                    SEND_STRING("apskaft ");
                    return false;
                  case 1:
                    SEND_STRING("dumhuvud ");
                    return false;
                  case 2:
                    SEND_STRING("jubelidiot ");
                    return false;
                }
            case VERB:
                SEND_STRING("'t bajs ");
                return false;
            case ADJECTIVE:
                SEND_STRING("fula ");
                return false;
            case BAJS:
                SEND_STRING("Vid fr[gor r;rande ditt v[rdtillf'lle, var v'nlig kontakta medicinmottagningen p[ tel> 0451/296330. Vid ;vriga medicinska fr[gor b;r du i f;rsta hand v'nda dig till din v[rdcentral.");
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  {
    { KC_MPRV, BAJS, KC_MNXT},
    { NOUN, ADJECTIVE, VERB}
  }
};
