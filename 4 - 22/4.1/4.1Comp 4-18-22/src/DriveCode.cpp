#include "vex.h"
#include "Classes.h"
#include "Functions.h"

int brakeMode = 1;

brakeType driveBrake;

void setBrake() {
  if (driveBrake == hold) {

    driveBrake = coast;
  } else if (driveBrake == coast) {

    driveBrake = hold;
  } else {
    driveBrake = coast;
  }
}

void logTank() {
  Lift.setMaxTorque(100, pct);

  Controller1.ButtonA.pressed(setBrake);
  Controller1.ButtonL1.pressed(clampOpen);
  Controller1.ButtonL2.pressed(clampCloes);
  Controller1.ButtonUp.pressed(bLOpen);
  Controller1.ButtonDown.pressed(bLClose);

  while (true) {
    DriveBaseControler Base;

    // Max voltage onf the motors in volts
    float maxVolt = 12.0;

    // Value of left and right stick devided by max volts
    float leftStick = Controller1.Axis2.value() / maxVolt;
    float rightStick = Controller1.Axis3.value() / maxVolt;

    // Stick value cubed
    float cubedLeft = pow(leftStick, 3);
    float cubedRight = pow(rightStick, 3);

    // Devide the cubed value by 100
    float leftOutput = cubedLeft / 100.0;
    float rightOutput = cubedRight / 100.0;

    // used to change brake type for parking
    if (leftOutput != 0) {
      Base.MoveL(leftOutput);
    } else if (leftOutput == 0) {
      lF.stop(driveBrake);
      lM.stop(driveBrake);
      lB.stop(driveBrake);
    }

    if (rightOutput != 0) {
      Base.MoveR(rightOutput);
    } else if (rightOutput == 0) {
      rF.stop(driveBrake);
      rM.stop(driveBrake);
      rB.stop(driveBrake);
    }
  }

  wait(20, msec);
}

void marioKart(){
  DriveBaseControler Base;

  Controller1.ButtonX.pressed(setBrake);
  Controller2.ButtonL1.pressed(clampOpen);
  Controller2.ButtonL2.pressed(clampCloes);
  Controller2.ButtonUp.pressed(bLOpen);
  Controller2.ButtonDown.pressed(bLClose);

  float maxVolt = 12.0;

  float accel = Controller1.ButtonA.pressing();

  float brake = Controller1.ButtonB.pressing();;

  while (1){
    accel += Controller1.ButtonA.pressing();

    float vel = accel/maxVolt;

    float cubevel = pow(vel, 3);

    float finalVal = cubevel/100.0;

    float turnAxis = Controller1.Axis4.value() / maxVolt;

    float turnCubed = pow(turnAxis, 3);

    brake -= Controller1.ButtonB.pressing();

    float bcubed = pow(brake, 3);

    float brakePut = bcubed/100.0;

    float outputL = (finalVal + turnCubed) - brakePut;
    float outputR = (finalVal - turnCubed) - brakePut;

    if(Controller1.ButtonL2.pressing()){
      Base.Move(outputL, outputR/10);
    }else if (Controller1.ButtonR2.pressing()) {
      Base.Move(outputL/10, outputR);
    }else {
      Base.Move(outputL, outputR);
    }
    
    wait(20, msec);
  }

}