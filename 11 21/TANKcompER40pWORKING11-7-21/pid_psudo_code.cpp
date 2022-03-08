#include "vex.h"
#include "main.cpp"
bool pidDrive;
float error;
float prevError;
float pidPower;
float setPofloat;
float floatergral;
float derivatve;
float kP = 1;
float kI = .1;
float kD = 1;
void drivePid (float setPofloat) {
while(pidDrive) {
  float leftMotorPostion = leftDrive.position(degrees);
  float rightMotorPostion = rightDrive.position(degrees);
  float avergePosition = (leftMotorPostion + rightMotorPostion)/2;
  error = setPofloat - avergePosition;
  pidPower = error * kP; 
  floatergral = floatergral + error;
  prevError = error;
  derivatve = error - prevError;
  if (error == 0){

    floatergral = 0;

}

  if(error > setPofloat){
    floatergral = 0;
}
  

}



}
///////////////////////////////////////////////////////////////////////////////////////////////

void driveForward(double inches){
  //PID variables
  timer Timer;
  float threshold = 10; //exit loop while robot is within 10 ticks of target
  float error, prevError; //proportional terms
  float integral = 0; //ditto
  float derivative = 1; //ditto 
  float kP = 1, kI = .01, kD = 1; //change in time
  float dT,  prevTime = 0; //set delta time to current time
  float output;
  float targetTicks = 2.75*2*M_PI/(360*inches);//conversion from inches to ticks 

 //PID Loop
  while(fabs(error) > threshold){
    float currentPosition = (leftDrive.position(rotationUnits::raw) + rightDrive.position(rotationUnits::raw))/2.0;
    
    error = targetTicks - currentPosition; //distance between robot and target position
      if(dT > 0){ //prevent divide by 0 error
      integral += error * dT;
      derivative = (error - prevError) * dT;
      }
      prevError = error;
      dT = Timer - prevTime;

      output = error*kP + integral*kI + derivative*kD;
     
      leftDrive.spin(reverse, output, volt);
      rightDrive.spin(reverse, output, volt);
     
      wait(20, msec);
    }
      rightDrive.stop(brake); //stop robot at target
      leftDrive.stop(brake);
}

/////////////////////////////////////////////////////////////////////////////////////
void dirveToPid(double inches){
  //PID settings and peramiters 
  float error = 100;
  float prevError = 0;
  float integral = 0;
  float derivative = 0;
  float kP = 1;
  float kI = .1;
  float kD = 1;
  float speed = 100; 
  float ticks = (2.75*2*M_PI/(360)*inches);//conversion from ticks to inches 
 // while loop that tell robit to drive to Xinches and check how close
  while(1){
    Controller1.Screen.print("inwhileloop");
    error = ticks - leftDrive.position(rotationUnits:: raw);
  
    if (error < 10){
      break;
    }
    integral += error;
    derivative = error - prevError;
    //Controller1.Screen.print("%lf", error);
    //printf("%lf /n", error);
    speed = (error*kP) + (integral*kI) + (derivative*kD);
    prevError = error;
    Brain.Screen.print("%f %f", speed, integral);
   // Controller1.Screen.print("%lf /n", error);
   // printf("%lf /n", error);
    //printf("pogchamp");
    leftDrive.spin(fwd, speed, pct );
    rightDrive.spin(fwd, speed, pct );
    //rightDrive.spin(fwd, speed, pct );
    task::sleep(10);
    Controller1.Screen.clearLine();

  }
  rightDrive.stop(brake);
  leftDrive.stop(brake);
}