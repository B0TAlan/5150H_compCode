#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>


bool auton = false;
bool cOn = false;

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

void AclampOn() {
  while (auton == true && cOn == false) {
    if (line1.value(percentUnits::pct) <= 68) {
      Clamp.set(true);
      // std::cout<<Clamp1.position(rev)<<std::endl;
      waitUntil(Clamp.value() == true);
      cOn = true;
      break;
    } else if (line1.value(percentUnits::pct) > 68) {
      for (int i = 0; i < 3; i++) {
        driveBase.setDriveVelocity(5, velocityUnits::pct);

        if (cOn == true) {
          break;
        }
      }
    }
  }
}
