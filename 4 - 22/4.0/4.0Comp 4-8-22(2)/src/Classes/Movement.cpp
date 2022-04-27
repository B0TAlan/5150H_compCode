#include "vex.h"
#include "Classes.h"


// Drive control
void Movement_Controller::customDrive(float target, float kp, float kd, float ki){
  DriveBaseControler DriveMotors;
   DriveMotors.Reset();// reset all motors encoders to 0
    lF.setPosition(0, rotationUnits::deg);
    rF.setPosition(0, rotationUnits::deg);
    float startT = Paincreas.timer(msec); // time when pid starts
    float prevT = startT, dT, currentT;
    //^ the time x amount ago is equal to start time delta time(dt) and current time

    target = (target / (3.5 * M_PI)) * (360 * (1.4));
    /*D-Bot target = ((target * (625)) / (4.0 * M_PI)) * (36.0/84.0)*/;
    // convets from inches to motor encoder value 

    /////////////////////////////////////
    // color    ratio   encoder value  //
    // Red      36:1    1800 ticks/rev //
    // green    18:1    900 ticks/rev  //
    // blue     6:1     300 ticks/rev  //
    /////////////////////////////////////

    float leftCurrent = /*lF.position(degrees)*/ 0; 
    float rightCurrent = /*rF.position(degrees)*/ 0;
    // get current val of motor encoders

    float leftError = 0, rightError = 0;

    //jose is a bad programer 0 prog skills smh
    float prevLeftError = 0, prevRightError = 0;
    // Error = the differnce between target and current position

    float leftDeriv = 0, rightDeriv= 0;

    //float errorLim = 30;
    
    float intim = 12;
    
    float leftIntergral = 0;
    float rightIntergral = 0;

    bool stopPid = false;

    while(stopPid == false){
     
      currentT = Paincreas.timer(msec);
      dT = currentT - prevT;
      prevT = currentT;

      leftCurrent =  endL.position(degrees);;
      rightCurrent = endR.position(degrees);
      
      prevLeftError = leftError + dT;
      prevRightError = rightError + dT;

      leftError = target - leftCurrent;
      rightError = target - rightCurrent;

      leftDeriv = (leftError - prevLeftError) / dT;
      rightDeriv = (rightError - prevRightError) / dT;
      
      
      leftIntergral += leftError * dT;
      rightIntergral += rightError * dT;

      if (fabs(leftIntergral) > intim){
        leftIntergral = 0;
      }
      if (fabs(rightIntergral) > intim){
        rightIntergral = 0;
      }

      float leftPut = (kp * rightError) + (kd * leftDeriv) + (ki * leftIntergral);
      float rightPut = (kp*rightError) + (kd * rightDeriv) + (ki * rightIntergral);
      
      
      std::cout<<"Target = "<<target<<std::endl;
      std::cout<<"Current = "<<"R = "<<rightCurrent<<" L = "<<leftCurrent<<std::endl;
      std::cout<<"Error = "<<"R = "<<rightError<<" L = "<<prevLeftError<<std::endl;
      std::cout<<"prevError = "<<"R = "<<prevRightError<<" L = "<<prevLeftError<<std::endl;
      std::cout<<"Dx = "<<"R = "<<rightDeriv<<" L = "<<leftDeriv<<std::endl;
      std::cout<<"D/Dx = "<<"R = "<<rightIntergral<<" L = "<<leftIntergral<<std::endl;
      std::cout<<"pow = "<<"R = "<<rightPut<<" L = "<<leftPut<<std::endl;

      DriveMotors.Move(leftPut, rightPut );

      if ((fabs(rightPut)< 1) && (fabs(leftPut)< 1)){//
        DriveMotors.Brake(hold);
        std::cout<<"BRAKE"<<std::endl;
        stopPid = true;
        break;
        
      }

      vex::task::sleep(20);
    }
    std::cout<<"ploop"<<std::endl;
  


}

void Movement_Controller::Drive(float target, float kp){

    customDrive(target, kp, .05, .01);
  
}

//Turn control

void Movement_Controller::customPivot(float heading, float kp, float kd, float ki, bool left, bool right){
  DriveBaseControler DriveMotors;
  float startTime = Paincreas.timer(msec);
   float prevTime = startTime, dT, currentTime;
   float integral = 0, error = 0, derivative = 0, prevError = 0;
   bool done = false;
   float  currentHeading = Gyro.heading(degrees);
 
  
 
   while(!done) {
 
     

     currentTime = Paincreas.timer(msec);
     dT = currentTime - prevTime;
     prevTime = currentTime;
 
      currentHeading = Gyro.heading(degrees);
 
     error = heading -  currentHeading;
 
     if (error > 180) {
       error = error - 360;
     } else if (error < -180) {
       error = 360 + error;
     }
 
     derivative = (error - prevError) / dT;
 
     prevError = error;
 
     integral += error * dT;
    
     float driveSpeed = kp*error + ki*integral + kd*derivative;
     
     DriveMotors.Move(driveSpeed, -driveSpeed);
 
     if ((fabs(error) < 1.5)){
       done = true;
       DriveMotors.Brake(hold);
       std::cout << "turn: " << Paincreas.timer(msec)-startTime << std::endl;
       
       break;
     }
     wait(20, msec);
  }

   std::cout << "pid ended "  << heading<< ", " << Gyro.heading() <<std::endl;
   
 }

void Movement_Controller::customPoint(float heading, float kp, float kd, float ki){
  DriveBaseControler DriveMotors;
  float startTime = Paincreas.timer(msec);
   float prevTime = startTime, dT, currentTime;
   float integral = 0, error = 0, derivative = 0, prevError = 0;
   bool done = false;
   float  currentHeading = Gyro.heading(degrees);
 
   while(!done) {

     currentTime = Paincreas.timer(msec);
     dT = currentTime - prevTime;
     prevTime = currentTime;
 
      currentHeading = Gyro.heading(degrees);
 
     error = heading -  currentHeading;
 
     if (error > 180) {
       error = error - 360;
     } else if (error < -180) {
       error = 360 + error;
     }
 
     derivative = (error - prevError) / dT;
 
     prevError = error;
 
     integral += error * dT;

     if (fabs(integral) >= 1000){
       integral += (error * dT)/100;
     }
    
     float output = kp*error + ki*integral + kd*derivative;

     std::cout<<"Target = "<<heading<<std::endl;
     std::cout<<"Current = "<<Gyro.heading()<<std::endl;
     std::cout<<"Error = "<<error<<std::endl;
     std::cout<<"prevError = "<<prevError<<std::endl;
     std::cout<<"Dx = "<<derivative<<std::endl;
     std::cout<<"D/Dx = "<<integral<<std::endl;
     std::cout<<"pow = "<<output<<std::endl;

      DriveMotors.Move(-output, output);

     if ((fabs(error) < 1)){
       done = true;
       DriveMotors.Brake(hold);
       std::cout << "turn: " << Paincreas.timer(msec)-startTime << std::endl;
       
       break;
     }
     wait(30, msec);
  }
  /*timer Timer;
  double errorMargin = 0, integralBound = 0, acceleration= 0;
double error = errorMargin + 1, integral = 0, derivetive = 0; 
  double sensorVal = 0;

  double volCap = 0;

  int sign = 0; 

  // this allows us to get a refrence as to where the position 
  // of the robot is. This is subtracted from the position of the robot 
  // as it updates which allows to get a change in angle without resetting 
  // the IMU which would mess up other code 
  double enterAngle = Gyro.rotation(); 

  double prevError = 0, prevTime = 0, dt = 0; 

  double output = 0;

  // checks if the robot has moved, if it hasent 
  // continue, if it has wait and update this variable
  if (fabs(enterAngle -  Gyro.rotation()) > 0) {
    wait(100, msec);
    enterAngle = Gyro.rotation();
  }

  // checks if the robot position is within 
  // a given range of the target position
  while(fabs(error) > errorMargin) {

    // calculates the diffrence from the robots current 
    // and the position of the robot when it entered the function
    sensorVal = Gyro.rotation() - enterAngle;

    // finds the diffrence of the robots current position 
    // and the target position 
    error = heading - sensorVal; 

    // updates the prevError variable
    prevError = error; 

    // updates the intergral variable 
    integral += error; 

    // calculates dt, the amount of time 
    // that has passed 
    dt = (Timer.time() - prevTime) / 1000;

    // figures out how close the robot is to the
    // target position. as the robot get closer 
    // derivetive gets smaller
    derivetive = (error - prevError) / dt;

    // limits integral, if it is outside a 
    // given range integral will be set to 0
    if (fabs(integral) > integralBound){
      integral = 0; 
    }

    // calculates output given all terms, and constants 
    output = (error * kp) + (integral * ki) + (derivetive * kd); 

    // finds wether the output is positive or negative 
    // one side is set to the absoulte value because 
    // would be always positive otherwise 
    sign = fabs(output) / output;

    // if output is greater than a given value 
    // output will be set to that given value
     and to the correct sign
    if (fabs(output) > maxVoltage)
      output = maxVoltage * sign;

    // volcap is added to acceleration which 
    // has the same sign as output 
    volCap += acceleration * sign;

    // if the voltage cap greater than the 
    // given max voltage set the voltage cap 
    / to the max voltage of the same sign as output 
    if (fabs(volCap) > fabs(maxVoltage)) {
      volCap = maxVoltage * sign;
    }

    // if the output is greater than the voltage cap
    / set it to voltage cap 
    if (fabs(output) > fabs(volCap)) {
      output = volCap;
    }

    // limits that output to be 12 trough -12
    // as that is the max voltage of the motors
    if (fabs(output) > 12 ) {
      output = 12 * sign; 
    }
    
    // applies the voltage to the chassis using 
    // the chassisPID object at the top 
    DriveMotors.Move(-output, output);

    // updates prevTime 
    prevTime = Timer.time();

    // waits to allow for the values to update 
    wait(15, msec);
  } 

  // check to see if the function has completed 
  // used for debugging 
  std::cout << "done ;)" << std::endl;

  // stops the chassis when it is done using the 
  // chassisPID object*/

   std::cout << "pid ended "  << heading<< ", " << Gyro.heading() <<std::endl;
   std::cout << "margin "  << heading - Gyro.heading() <<std::endl;
   
 }
void Movement_Controller::Point(float heading, float kp){
  customPoint(heading, kp, .00001, 0.1);
}

void Movement_Controller::Pivot(float heading, float kp, bool Dir/*true == left, flase == right*/){

  if (Dir == true) {
    customPivot(heading, kp, .00001, 0.1, true, false);
  }else if (Dir == false) {
    customPivot(heading, kp, .00001, 0.1, false, true);
  }
}

void Movement_Controller::turnFor(float amount, float kp, bool Point, bool Dir){

  float target = amount + Gyro.heading();

  if (Point == true){
    customPoint(target, kp, .00001, 0.1);
  }else if (Point == false && Dir == true) {
    customPivot(target, kp, .00001, 0.1, true, false);
  }else if (Point == false && Dir == false) {
    customPivot(target, kp, .00001, 0.1, false, true);
  }
}