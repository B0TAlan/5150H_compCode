#include "vex.h"

// Clamp control
bool auton = false;
bool cOn = false;

// Opens pnumatic Clamp
void clampOff() {

  Clamp.set(true);

  waitUntil(Clamp.value() == true);
  cOn = false;
}

void clampOn() {

  Clamp.set(false);

  waitUntil(Clamp.value() == false);
  cOn = true;
}

// BackLift control
bool bLD = false; 
//^ bool that represents whether backLift is down(true) or up(false)

// Cloes pnumatic back lift 
void bLClose() {
  bL.set(true);
  waitUntil(bL.value() == true);
  bLD = true;
}

// Opens pnumatic back lift
void bLOpen() {
  bL.set(false);
  waitUntil(bL.value() == false);
  bLD = false;
}
