#include <vex.h>

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

void logTank(){

  while(true){

    // Set the max voltage of the motors in volts
    float maxVolt = 127;

    // Get the value of left and right stick / the max volts 
    float leftStick = Controller1.Axis3.value() / maxVolt;
    float rightStick = Controller1.Axis2.value() / maxVolt; 

    // Get the value of the both sticks to the 3rd power
    float cubbedLeft = pow(leftStick, 3);
    float cubbedRight = pow(rightStick, 3);

    // Devide cubbed value by 100
    float leftOutput = cubbedLeft / 100;
    float rightOutput = cubbedRight / 100;
    
    // Apply the output val to the velocity of all motors 
    // Also apply driveBake to motors to toggle brakes for balencing
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
}