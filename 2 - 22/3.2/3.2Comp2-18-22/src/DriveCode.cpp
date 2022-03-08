#include "vex.h"


int brakeMode = 1;

brakeType driveBrake;

void setBrake(){
  if (driveBrake == hold){
    
    driveBrake = coast;
  }
  else if(driveBrake == coast){
    
    driveBrake = hold;
  }
  else {
    driveBrake = coast;
  }

}

bool rT = false;

void runTemp(){
  if (Paincreas.Screen.pressing()){

    rT = true;
  }
  else {
    rT = false;
  }
}

void logTank() {

  while (true) {
    // Max voltage onf the motors in volts
    float maxVolt = 12.0;

    // Value of left and right stick devided by max volts
    float leftStick = Controller1.Axis3.value() / maxVolt;
    float rightStick = Controller1.Axis2.value() / maxVolt;

    // Stick value cubed
    float cubedLeft = pow(leftStick, 3);
    float cubedRight = pow(rightStick, 3);

    // Devide the cubed value by 100
    float leftOutput = cubedLeft / 100.0;
    float rightOutput = cubedRight / 100.0;

    // used to change brake type for parking
    if (leftOutput != 0){
      lF.spin(fwd, leftOutput, volt);
      lM.spin(fwd, leftOutput, volt);
      lB.spin(fwd, leftOutput, volt);
    }
    else if (leftOutput == 0){
      lF.stop(driveBrake);
      lM.stop(driveBrake);
      lB.stop(driveBrake);
    }

    if (rightOutput != 0){
      rF.spin(fwd, rightOutput, volt);
      rM.spin(fwd, rightOutput, volt);
      rB.spin(fwd, rightOutput, volt);
    }
    else if (rightOutput == 0){
      rF.stop(driveBrake);
      rM.stop(driveBrake);
      rB.stop(driveBrake);
    }
    


  }

  wait(20, msec);
}