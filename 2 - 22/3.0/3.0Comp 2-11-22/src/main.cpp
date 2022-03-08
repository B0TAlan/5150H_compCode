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

#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

using namespace vex;
 
competition Competition;
//thread mI(menuInput);
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  preATon = true;
  
  gyroConfig();
  //thread mI(menuInput);
  
}

void autonomous(void) {
  
  preATon = false;
  auton = true;
  clearPrint(1, 1);
  menuOutput();
  clearPrint(1, 1);

}

void usercontrol(void) {
  preATon = false;
  auton = false;
  Dcont = true;
  wait(10, msec);
  thread driverControl(tankCont);
  
  clearPrint(1, 1);
  Pring = 1;
  while (1) {
    
    
    //pringle.spin(reverse, 100, velocityUnits::pct);
  
    liftControl();
    checkTemp();
    pringControl();
    
    Controller1.ButtonL1.pressed(clampOn);
    Controller1.ButtonL2.pressed(clampOff);
    Controller1.ButtonUp.pressed(bLUp);
    Controller1.ButtonDown.pressed(bLDown);
    //Controller1.ButtonLeft.pressed(pringOn);
    
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
  //menuInput();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
