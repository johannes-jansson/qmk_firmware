#include "lets_split.h"

#include "mouse.h"
#include "analog.c"
#include "math.h"
#include "pincontrol.h"
#include "pointing_device.h"
#include "print.h"
#include "report.h"
#include "timer.h"

// Joystick
// Set Pins
int xPin = 3; // VRx
int yPin = B5; // VRy
int swPin = F7; // SW

// Set Parameters
int minAxisValue = 0;
int maxAxisValue = 1023;

int maxCursorSpeed = 1;

int xPolarity = 1;
int yPolarity = -1;

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
  print_decs(coordinate); println();
  if (coordinate == 0) {
    return 0;
  }
  else {
    float percent = (float)coordinate / 100;
    return percent * maxCursorSpeed * polarity * (abs(coordinate)/6);
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
  }

  pointing_device_set_report(report);
  pointing_device_send();
}

void matrix_init_kb(void) {
  timer_init();
  xOrigin = analogRead(xPin);
  yOrigin = analogRead(yPin);
	matrix_init_user();
}

#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    led_set_user(usb_led);
}
#endif

/* void matrix_init_kb(void) { */

/*     // // green led on */
/*     // DDRD |= (1<<5); */
/*     // PORTD &= ~(1<<5); */

/*     // // orange led on */
/*     // DDRB |= (1<<0); */
/*     // PORTB &= ~(1<<0); */

/* 	matrix_init_user(); */
/* }; */

