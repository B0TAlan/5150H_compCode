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


using namespace vex;

// A global instance of competition
competition Competition;

float target;

void calculate(int tinch) {
  //target = ((target * 300.0) / (4.0 * M_PI)) * (30.0 / 84.0); 
  //goldern:target = (tinch / (4.0 * M_PI)) * (360 * (84.0 / 60.0));
  target = ((tinch * (300)) / (4.0 * M_PI)) * (84.0 / 60.0);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  setState(false, false);
  gyroConfig();
  
}

void autonomous(void) {
  thread gydebug (gyroReadings);
 clearPrint(1, 1, 1);
}

void usercontrol(void) {
  clearPrint(1, 1, 1);

  thread DriveControl (logTank);
  r1.resetPosition();
  Controller1.ButtonA.pressed(setBrake);
  Controller1.ButtonL1.pressed(clampCloes);
  Controller1.ButtonL2.pressed(clampOpen);
  Controller1.ButtonUp.pressed(bLOpen);
  Controller1.ButtonDown.pressed(bLClose);

  while (1) {
    liftControl();
    pringleIntake();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.setCursor(1, 1);
    calculate(24);
    Paincreas.Screen.print(r1.position(degrees));
    std::cout<<target<<std::endl;;
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
