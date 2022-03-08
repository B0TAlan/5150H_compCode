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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

using namespace vex;
//MotorControl Motors;
competition Competition;

int velCap; //velCap limits the change in velocity and must be global
int targetLeft;
int targetRight;
bool isAuton = true;

void drivePIDFn(void*){
  Lf.setPosition(0, rotationUnits::raw);
  Rf.setPosition(0, rotationUnits::raw);
  Motors.printVal();
  int errorLeft;
  int errorRight;
  float kp = 0.075;
  float kpTurn = 0.2;
  int acc = 5;
  int voltageLeft = 0;
  int voltageRight = 0;
  int signLeft;
  int signRight;
  wait(20, msec);
  while(isAuton){
    errorLeft = targetLeft - Lf.value(); //error is target minus actual value
    errorRight = targetRight - Rf.value();

    signLeft = errorLeft / abs(errorLeft); // + or - 1
    signRight = errorRight / abs(errorRight);

    if(signLeft == signRight){
      voltageLeft = errorLeft * kp; //intended voltage is error times constant
      voltageRight = errorRight * kp;
    }
    else{
      voltageLeft = errorLeft * kpTurn; //same logic with different turn value
      voltageRight = errorRight * kpTurn;
    }

    velCap = velCap + acc;  //slew rate
    if(velCap > 115){
      velCap = 115; //velCap cannot exceed 115
    }

    if(abs(voltageLeft) > velCap){ //limit the voltage
      voltageLeft = velCap * signLeft;
    }

    if(abs(voltageRight) > velCap){ //ditto
      voltageRight = velCap * signRight;
    }
    std::cout<<"Lerror = "<<errorLeft<<std::endl;
    std::cout<<"Rerror = "<<errorRight<<std::endl;
    Motors.setVel(voltageLeft, voltageRight);
   /* Lf.spin(fwd ,voltageLeft, voltageUnits::volt); //set the motors to the intended speed
    Lb.spin(fwd ,voltageLeft, voltageUnits::volt);
    Lm.spin(fwd ,voltageLeft, voltageUnits::volt);
    Rf.spin(fwd ,voltageLeft, voltageUnits::volt);
    Rb.spin(fwd ,voltageLeft, voltageUnits::volt);
    Rm.spin(fwd ,voltageLeft, voltageUnits::volt);*/

    wait(20, msec);
  }

  //Motors.Brake(hold);
}

void drive(int left, int right){
  targetLeft = targetLeft + left;
  targetRight = targetRight + right;
  velCap = 0; //reset velocity cap for slew rate
}



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
  drive(100, 100);
  wait(20, msec);
  
}
//---------------------------------------------------------------------------//
//}

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//

void usercontrol(void) {
  
  while (1) {
    
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
