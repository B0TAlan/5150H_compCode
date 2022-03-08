#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>


// helper
void setlift(int p) { 
  Lift.spin(fwd, p, voltageUnits::volt); 
  // sets the velocity of the lift motor 
}

// controls
void liftControl() {
  int liftPower = 127 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  // uses R1 and R2 as a constant (1 || 0) so that the lift will run @ 12 volts(up) or -12 volts(down)
  setlift(liftPower);
  if (liftPower == 0) {
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) >= 2 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes max hight stop the lift
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) <= .1 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes min hight stop the lift
    liftPower = 0;
  }
  else {
   liftPower = 127 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  }
}