/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "Functions.h"
#include "Autons.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  setState(false, false);
  gyroConfig();
  
}

void autonomous(void) {
 thread gydebug (lockLift);
 clearPrint(1, 1, 1);
 testing();

}

void usercontrol(void) {
  clearPrint(1, 1, 1);
  buildIssue();

  thread DriveControl (logTank);

  Controller1.ButtonA.pressed(setBrake);
  Controller1.ButtonL1.pressed(clampOpen);
  Controller1.ButtonL2.pressed(clampCloes);
  Controller1.ButtonUp.pressed(bLOpen);
  Controller1.ButtonDown.pressed(bLClose);

  while (1) {
    liftControl();
    pringleIntake();
    singlePringle();
    
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
    wait(100, msec); //heehee 69
  }
}
