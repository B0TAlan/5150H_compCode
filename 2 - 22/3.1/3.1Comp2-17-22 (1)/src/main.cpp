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
#include "MasterHeader.h"



using namespace vex;

// A global instance of competition
competition Competition;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  setState(true);
  gyroConfig();

}

void autonomous(void) {
 clampOn();
 wait(500, msec);
 driveBase.driveFor(fwd, 10, distanceUnits::in, 20, velocityUnits::pct);
 clampOff();
  wait(500, msec);
   Lift.rotateTo( 1, rev, 100, velocityUnits::pct);// waits until lift raises to .5 revs to raise the lift over the Amgola
    //driveBase.driveFor(fwd, 3, inches, 30, velocityUnit::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    driveBase.turnToHeading(94, rotationUnits::deg);
    bL.set(false);
    driveBase.driveFor(fwd, -50, inches, 40, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
    driveBase.driveFor(fwd, -14, inches, 10, velocityUnits::pct);// slows down to not bump the Ngoal
    bL.set(false);
    //Lift1.rotateTo(.5, rev,90, velocityUnits::pct, false);
    driveBase.turnToHeading(311, rotationUnits::deg);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(50, inches, 45, velocityUnits::pct);
    driveBase.turnToHeading(270, rotationUnits::deg);
    lScore(100, true);
    wait(1500, msec);
    Clamp.set(false);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(fwd, -10, distanceUnits::in, 30, velocityUnits::pct);
    Lift.rotateTo(1.6, rotationUnits::deg, 100, velocityUnits::pct, false);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 30, velocityUnits::pct);
    driveBase.turnToHeading(191, rotationUnits::deg);
    Clamp.set(false);
    driveBase.driveFor(fwd, 44, distanceUnits::in, 50, velocityUnits::pct);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 20, velocityUnits::pct, false);
    Clamp.set(true);
   // Lift1.rotateTo(1.35, rev,90, velocityUnits::pct, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    driveBase.driveFor(fwd, 10, distanceUnits::in, 60, velocityUnits::pct);
 
}

void usercontrol(void) {
  getState();

  // Call back functions
  Controller1.ButtonA.pressed(setDriveMode);
  Controller1.ButtonL1.pressed(clampOn);
  Controller1.ButtonL2.pressed(clampOff);
  Controller1.ButtonUp.pressed(bLOpen);
  Controller1.ButtonDown.pressed(bLClose);

  thread driveCont (logTank);
  thread liftCont (liftControl);
  while (1) {
    pringleIntake();
    
    
    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
