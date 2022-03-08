/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "MasterAuton.h"
#include "MasterClass.h"
#include "MasterHeader.h"
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  preATon = true;
  Pistions.setState(true);
  gyroConfig();
  menuInput();
}

void autonomous(void) {
  preATon = true;
  clearPrint(1, 1, 1);
  menuOutput();
  // Skills();
}

void usercontrol(void) {
  preATon = false;
  clearPrint(1, 1, 1);
  Controller1.ButtonA.pressed(setBrake);
  Controller1.ButtonL1.pressed(clampCloes);
  Controller1.ButtonL2.pressed(clampOpen);
  Controller1.ButtonUp.pressed(bLOpen);
  Controller1.ButtonDown.pressed(bLClose);

  thread DriveControl(logTank);
  while (1) {
    liftControl();
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
