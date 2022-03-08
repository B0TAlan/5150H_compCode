#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void skills(){
  Brain.Screen.drawImageFromFile("(s)kills", 0, 0);
  auton = true;
    cOn = false;
    clampOn();
    waitUntil(cOn == true);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    //driveBase.driveFor(fwd, 3, inches, 30, velocityUnits::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    driveBase.turnToHeading(90, rotationUnits::deg);
    bLUp();
    Lift.rotateTo(.5, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(fwd, -50, inches, 60, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
    driveBase.driveFor(fwd, -10, inches, 30, velocityUnits::pct);// slows down to not bump the Ngoal
    bLD = true;
    waitUntil(bLD == true);
    bLUp();
    Lift.rotateTo(.5, rev,90, velocityUnits::pct, false);
    driveBase.turnToHeading(300, rotationUnits::rev);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(60, inches, 45, velocityUnits::pct);


}