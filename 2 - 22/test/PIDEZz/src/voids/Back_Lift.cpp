#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void bLReset() {
  bL1.rotateTo(0, rotationUnits::rev, 100, velocityUnits::pct, false);
}

// voids to set macros for lift

void bLDown() { // down
  bL.setVelocity(200, percent);
  if (bLR.position(rev) < 2.3) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-3.2, rev, false);
  } else if (Controller1.ButtonDown.pressing() && bLR.position(rev) >= 1 &&
             bL1.isDone()) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-4.8, rev, false);
  } else {
  }
}
void bLUp() { // up
  bL.setVelocity(200, percent);
  if (bLR.position(rev) > 2) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-3.2, rev, false);
  } else if (Controller1.ButtonUp.pressing() && bLR.position(rev) < 1 &&
             bL1.isDone()) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(0, rev, false);
  } else {
    bL1.stop(hold);
  }
}
void resetAll() {
  all.rotateTo(0, rev, 100, velocityUnits::pct, true);
  all.stop();
  Controller1.Screen.print(green);
  Brain.Screen.clearScreen();
}