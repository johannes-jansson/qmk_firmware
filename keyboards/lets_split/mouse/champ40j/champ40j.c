/**
 * @Author: Chris James Champeau <semaj4712>
 * @Date:   2017-01-09T13:14:08-08:00
 * @Email:  semaj4712@gmail.com
 * @Filename: champ40j.c
 * @Last modified by:   semaj4712
 * @Last modified time: 2018-07-05T15:03:13-07:00
 */



#include "champ40j.h"
#include "analog.c"
#include "math.h"
#include "pincontrol.h"
#include "pointing_device.h"
#include "print.h"
#include "report.h"
#include "timer.h"
#define INPUT_PULLUP 0x2

// Joystick
// Set Pins
int xPin = 3; // VRx
int yPin = 2; // VRy
int swPin = C4; // SW

// Set Parameters
int minAxisValue = 0;
int maxAxisValue = 1023;

int maxCursorSpeed = 4;
int precisionSpeed = 1;
int speedRegulator = 20; // Lower Values Create Faster Movement

int xPolarity = -1;
int yPolarity = 1;

int cursorTimeout = 10;

int xOrigin, yOrigin;

uint16_t lastCursor = 0;

int axisCoordinate(int pin, int origin) {
  int direction;
  int distanceFromOrigin;
  int range;

  int position = analogRead(pin);

  if (origin == position) {
    return 0;
  } else  if (origin > position) {
    distanceFromOrigin = origin - position;
    range = origin - minAxisValue;
    direction = -1;
  } else {
    distanceFromOrigin = position - origin;
    range = maxAxisValue - origin;
    direction = 1;
  }

  float percent = (float)distanceFromOrigin / range;
    int coordinate = (int)(percent * 100);
    if (coordinate < 0) {
      return 0;
    }
    else if (coordinate > 100) {
      return 100 * direction;
    }
    else {
      return coordinate * direction;
    }
}

int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity) {
  int coordinate = axisCoordinate(pin, origin);
  if (coordinate == 0) {
    return 0;
  }
  else {
    float percent = (float)coordinate / 100;
    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
      return percent * precisionSpeed * polarity * (abs(coordinate)/speedRegulator);
    }
    else {
      return percent * maxCursorSpeed * polarity * (abs(coordinate)/speedRegulator);
    }
  }
}

void pointing_device_task(void) {
  report_mouse_t report;
  report.x = 0;
  report.y = 0;
  report.h = 0;
  report.v = 0;
  report.buttons = 0;

  // todo read as one vector
  if (timer_elapsed(lastCursor) > cursorTimeout) {
    lastCursor = timer_read();
    report.x = axisToMouseComponent(xPin, xOrigin, maxCursorSpeed, xPolarity);
    report.y = axisToMouseComponent(yPin, yOrigin, maxCursorSpeed, yPolarity);
  }

  if (digitalRead(swPin) == 1) {
    report.buttons |= MOUSE_BTN1;
    print("click\r\n");
  }

  pointing_device_set_report(report);
  pointing_device_send();
}

void matrix_init_kb(void) {
  timer_init();
  xOrigin = analogRead(xPin);
  yOrigin = analogRead(yPin);
}
