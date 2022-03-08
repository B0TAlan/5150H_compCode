/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// MotorLf              motor         1
// MotorLb              motor         2
// MotorRf              motor         14
// MotorRb              motor         15
// Clamp1               motor         7
// Lift1                motor         11
// bL1                  motor         18
// Gyro                 inertial      9
// line1                line          A
// pringle              motor         12
// bLR                  rotation      10
// bL2                  motor         20
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

using namespace vex;

competition Competition;

//---------------------------------------------------------------------------//
//                          Pre-Autonomous Functions                         //
//---------------------------------------------------------------------------//

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Gyro.calibrate(); // start the gyro calabration
  while (Gyro.isCalibrating()) {
    wait(200, msec); // waits until teh calabration is done
  }
  // this is to make the robot trun properly
  // due to the limits of the vex motor groups,
  // and because the built in motor encoders
  // ARE NOT RELIABLE

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
//---------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//                              Autonomous Task                               //
//                                  2 Points                                  //
//                                 Win Point                                  //
//----------------------------------------------------------------------------//

void autonomous(void) {
  auton = true; // is to actavate line sen only in  auton
  clampOn = false;
  Gyro.resetHeading(); // to set gyro 0 if not already
  Gyro.resetRotation();
  driveBase.setDriveVelocity(200, percent); // set the speed of robot (speed up robot)
  driveBase.driveFor(forward, 40, inches); // drive twards the mgoal
  driveBase.setDriveVelocity(50, percent); // manule pid
  driveBase.driveFor(forward, 7, inches,false); // this is so make the robot not nock the mgoal away
  line1.changed(Aclamp1On);
  waitUntil(clampOn == true); // wait till clamp is closed by line sen
  Clamp1.stop(hold);          // stop the Clamp
  driveBase.setDriveVelocity(200, percent); // set drive speed
  Lift1.setVelocity(100, percentUnits::pct);
  Lift1.rotateTo(.1, rotationUnits::rev);
  driveBase.driveFor(reverse, 34, inches); // drive backwards
  // leftDrive.spinFor(reverse, 1, rev);
  // driveBase.turnToRotation(-90, rotationUnits::deg);// 43 = 90 degrees ish
  // due demisinons of drive base are wrong
  driveBase.turnToHeading(270, rotationUnits::deg);
  bL.rotateTo(-4.8, rev, 100, velocityUnits::pct, false);
  driveBase.driveFor(forward, 8, inches);
  Clamp1.setVelocity(200, percent); // set Clamp speed
  auton = false;
  clamp1Off();
  wait(300, msec);
  //---------------------------------------------------------//
  // Start of Block 2// score aMGoal  line up on next nutral mGoal and ATEMP to
  // grab next mGaol
  driveBase.setDriveVelocity(60, percentUnits::pct);
  driveBase.driveFor(forward, 6, inches);
  driveBase.setDriveVelocity(20, percentUnits::pct);
  driveBase.driveFor(reverse, 23, inches);
  bL.setVelocity(100, percentUnits::pct);
  bL.rotateTo(-3.2, rev, false);
  waitUntil(bL.position(rotationUnits::rev) >= -3.3);
  pringle.spin(directionType::rev, 100, velocityUnits::pct);
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);
  driveBase.turnToHeading(0, rotationUnits::deg);
  clampOn = false;
  /*line1.changed(Aclamp1On);
  auton = true;
  driveBase.turnFor(36, rotationUnits::deg);
  bLDown();
  driveBase.setDriveVelocity(100, percentUnits::pct);
  driveBase.driveFor(fwd, 60, inches);
  driveBase.setDriveVelocity(30, percentUnits::pct);
  driveBase.driveFor(fwd, 60, inches);
  waitUntil(clampOn == true);
  driveBase.setDriveVelocity(100, percentUnits::pct);
  driveBase.driveFor(reverse, 54, inches);
  driveBase.turnFor(-56, rotationUnits::deg);
  pringle.spinFor(-5, rev, 100, velocityUnits::pct);*/
}
//---------------------------------------------------------------------------//
//}

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//

void usercontrol(void) {
  thread driveCont(tankCont);
  // User control code here, inside the loop
  auton = false;   // stops lin sen
  clampOn = false; // stops lin sen so it does not interfear with driving
  Pring = 1;       // sets the stat of pringle intake to stopped
  while (1) {
    lUp();
    lDown();
    displayTemp(); // display all motors temps on cortext
    //tempcheck();   // if a motor is over heating print port # on the controller

    if (RobotIsWorking == false) { // checks if the robot is working
      RobotIsWorking = true;
    }

    switch (Pring) { //used to control the state of the pringle intake
    case 1: // if Pring = 1 stop the intake
      pringle.stop();
      break;

    case 2: 
    //^ if Pring = 2 start the intake and set the lift to intake height
      pringle.spin(reverse, 200, velocityUnits::pct);
      if (Lift1.position(rotationUnits::rev) < .5) {
        Lift1.setVelocity(100, percentUnits::pct);
        Lift1.rotateTo(.5, rev, false);
      }
      break;
    }
    
    // runs func when button is pressed 
    Controller1.ButtonL2.pressed(clamp1On);// closes clamp when L2 is pressed
    Controller1.ButtonL1.pressed(clamp1Off);// open clamp when L1 is pressed
    Controller1.ButtonUp.pressed(bLUp);// raises bL up from from lowest point 
    Controller1.ButtonDown.pressed(bLDown);// lower bL to lowest height 
    Controller1.ButtonA.pressed(bLReset);// raises bL up to heiest point (0)
    Controller1.ButtonLeft.pressed(pringON);

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
