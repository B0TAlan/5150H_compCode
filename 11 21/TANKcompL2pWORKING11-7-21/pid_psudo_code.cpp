#include "vex.h"
#include "main.cpp"
bool pidDrive;
float error;
float prevError;
float pidPower;
float setPoint;
float intergral;
float derivatve;
double kP = 0;
double kI = 0;
double kD = 0;
void drivePid (int setPoint) {
  while(pidDrive) {
    int leftMotorPostion = leftDrive.position(degrees);
    int rightMotorPostion = rightDrive.position(degrees);
    int avergePosition = (leftMotorPostion + rightMotorPostion)/2.0;
    error = setPoint - avergePosition;
    pidPower = error * kP; 
    intergral = intergral + error;
    prevError = error;
    derivatve = error - prevError;
    if (error == 0){

      intergral = 0;

      }

    if(error > setPoint){
    intergral = 0;
      }
  

}



}
/*/////////////////////////////////////////////////////////////////////////////////////////////////

void driveForwardm(double inches){
  //PID variables
  float threshold = 10; //exit loop while robot is within 10 ticks of target
  float error, prevError; //proportional terms
  float integral = 0; //ditto
  float derivative = 1; //ditto 
  float kP = 1, kI = .01, kD = 1; //change in time
  float dT = T.time, prevTime = 0; //set delta time to current time
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
      dT = T.time() - prevTime;

      output = error*kP + integral*kI + derivative*kD;
     
      leftDrive.spin(reverse, output, volt);
      rightDrive.spin(reverse, output, volt);
     
      wait(20, msec);
    }
      rightDrive.stop(brake); //stop robot at target
      leftDrive.stop(brake);
}

/////////////////////////////////////////working Jank//////////////////////////////////////
void dirveToPidi(double inches){
  //PID settings and peramiters
  float error;
  float prevError;
  float integral = 0;
  float derivative = 1;
  double kP = 1;
  double kI = .01;
  double kD = 1;
  float speed = 100; 
  float ticks = (2.75*2*M_PI/(360)*inches);//conversion from ticks to inches 
 // while loop that tell robit to drive to Xinches and check how close
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.print("%f %f", speed, integral);
    Controller1.Screen.clearLine();
    Controller1.Screen.print("%f %f", speed, integral);
    float averbLepos = leftDrive.position(rotationUnits:: raw) + rightDrive.position(rotationUnits:: raw)/2.0;
    error = ticks - averbLepos;

    if (error > ticks){
      rightDrive.stop(brake);
      leftDrive.stop(brake);
    }
    else if (error == 0) {
      rightDrive.stop(brake);
      leftDrive.stop(brake);
    }
    else if (error < ticks) {
 
      integral += error;
      derivative = error - prevError;
      //Controller1.Screen.print("%lf", error);
      //printf("%lf /n", error);
      speed = (error*kP) + (integral*kI) + (derivative*kD);
     prevError = error;
     Brain.Screen.print("%f %f", speed, integral);
     Controller1.Screen.clearScreen();
     Controller1.Screen.print("%f %f", speed, integral);
     // Controller1.Screen.print("%lf /n", error);
     // printf("%lf /n", error);
      //printf("pogchamp");
      leftDrive.spin(reverse, speed, pct );
      rightDrive.spin(reverse, speed, pct );
      //rightDrive.spin(fwd, speed, pct );
      task::sleep(10);
      Controller1.Screen.clearLine();
    }
    else if(error == 0){
      rightDrive.stop(brake);
      leftDrive.stop(brake);
    }
    else {
      rightDrive.stop(brake);
      leftDrive.stop(brake);
    }
   }
  
  //rightDrive.stop(brake);
  //leftDrive.stop(brake);
}
//similar process of turning but requires own pid
/////////////////////////////////////////////////////////*/
//dirveToPid(goTo == 48);
  //gTurnTo(90);
 // bL.setVelocity(100, percent);
 // bL.spinFor(-1.75,rev);
  //resetbL();
 // driveBase.setDriveVelocity(200, percent);//set the speed of robot (speed up robot)
 // driveBase.driveFor(forward, 38, inches);// drive 43 inches forward to closed distance between robot and mGoal
 // driveBase.setDriveVelocity(15, percent);// slow down 
 // driveBase.driveFor(forward, 6, inches);
 // clamp1On();
 // wait(5, sec);
  //driveBase.turnFor(90,degrees);
  //wait(5, sec);
  //gTurnTo();
  //driveForward(49);
  //wait(5, sec);