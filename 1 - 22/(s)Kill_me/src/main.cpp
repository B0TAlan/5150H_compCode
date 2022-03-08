/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>
using namespace vex;
#include "voids.h"
// A global instance of competition
competition Competition;

void pre_auton(void) {
  while(Gyro.isCalibrating()){
    wait(200, msec);
  }
  wait(100, msec);
  Gyro.resetHeading();// MAKE SURE THE GYRO RESETS PROPERLY 
    Gyro.resetRotation();//^ because vex sensors don't like resetting all the time
  vexcodeInit();
}


void autonomous(void) {
  
    auton = true;
    clampOn = false;
    waitTING = true;
    clamp1On();
    //driveBase.driveFor(fwd, 6, distanceUnits::in, 30, velocityUnits::pct);
    waitUntil(clampOn == true);
    std::cout<<Clamp1.value()<<std::endl;// print state of the clamp to make sure its opend and @ 0
    Lift1.rotateTo(1.35, rev,90, velocityUnits::pct, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    //driveBase.driveFor(fwd, 3, inches, 30, velocityUnit::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    driveBase.turnToHeading(94, rotationUnits::deg);
    bL.rotateTo(-4.7, rev, 100, velocityUnits::pct);
    driveBase.driveFor(fwd, -50, inches, 40, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
    driveBase.driveFor(fwd, -14, inches, 10, velocityUnits::pct);// slows down to not bump the Ngoal
    bLD = true;
    waitUntil(bLD == true);
    bLUp();
    bLD = false;
    //Lift1.rotateTo(.5, rev,90, velocityUnits::pct, false);
    driveBase.turnToHeading(311, rotationUnits::deg);
    Lift1.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(50, inches, 45, velocityUnits::pct);
    driveBase.turnToHeading(270, rotationUnits::deg);
    deScore();
    wait(1500, msec);
    clamp1Off();
    waitUntil(clampOn==false);
    liftUp();
    driveBase.driveFor(fwd, -10, distanceUnits::in, 30, velocityUnits::pct);
    Lift1.rotateTo(0, rotationUnits::rev, 50, velocityUnits::pct);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 30, velocityUnits::pct);
    driveBase.turnToHeading(190, rotationUnits::deg);
    driveBase.driveFor(fwd, 50, distanceUnits::in, 50, velocityUnits::pct);
    
}


void usercontrol(void) {
  while (1) {
    wait(20, msec); 
  }
}


int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
