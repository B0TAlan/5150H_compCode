#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void tankCont() {
  while (1) {

    // this stops the robot for tokoy driting
    float x = 0; // reps axis 3 on the controller
    float y = 0; // reps axis 2 on controller
    if (Controller1.Axis3.position(pct) <= 10 &&
        Controller1.Axis3.position(pct) >= -10) {
      //^if axis 3 is drifing (between 10% and -10%)
      x = 0; // set x to 0
    } else {
      x = Controller1.Axis3.position(pct);
      //^ else set x to the vaule of axis 3 on the controller
    }
    if (Controller1.Axis2.position(pct) < 10 &&
        Controller1.Axis2.position(pct) > -10) {
      //^if axis 2 is drifing (between 10% and -10%)
      y = 0; // set y to 0

    } else {
      y = Controller1.Axis2.position(pct);
      //^ else set x to the vaule of axis 3 on the controller
    }

    leftDrive.spin(directionType::fwd, x, velocityUnits::pct);
    //^ map x to the velocity of the left motors where x = axis 3
    rightDrive.spin(directionType::fwd, y, velocityUnits::pct);
    //^ map y to the velocity of the left motors where y = axis 2
  }
}