#include "vex.h"
#include "Classes.h"


// Drive control
void Movement_Controller::customDrive(float target, float kp, float kd, float ki, float Volts){
  DriveBaseControler DriveMotors;
   DriveMotors.Reset();// reset all motors encoders to 0
    lF.setPosition(0, rotationUnits::deg);
    rF.setPosition(0, rotationUnits::deg);
    float startT = Paincreas.timer(msec); // time when pid starts
    float prevT = startT, dT, currentT;
    float powCap = 0, signL = 0, signR;
    //^ the time x amount ago is equal to start time delta time(dt) and current time

    target = (target / (2.95 * M_PI)) * (360 * (1.4));
    //*D-Bot */target =((target * (625)) / (4.0 * M_PI)) * (36.0/84.0);
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

      leftCurrent =  endL.position(degrees);  //lF.position(degrees);
      rightCurrent = endR.position(degrees);  //rF.position(degrees);
      
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
      

      signL = fabs(leftPut)/leftPut;
      signR = fabs(leftPut)/leftPut;

     if (fabs(leftPut) > Volts){
        leftPut = Volts * signL;
     }

     powCap += acceleration * signL;

     if (fabs(powCap) > fabs(Volts)){
       powCap = Volts * signL;
     }

     if(fabs(leftPut) > fabs(powCap)){
       leftPut = powCap;
     }

     if(fabs(leftPut) > maxPow){
       leftPut = maxPow * signL;
       
     }

     if (fabs(rightPut) > Volts){
        rightPut = Volts * signR;
        
     }

     if (fabs(powCap) > fabs(Volts)){
       powCap = Volts * signR;
     }

     if(fabs(rightPut) > fabs(powCap)){
       rightPut = powCap;
       
     }

     if(fabs(rightPut) > maxPow){
       rightPut = maxPow * signR;
       
     }
      
      std::cout<<"Target = "<<target<<std::endl;
      std::cout<<"Current = "<<"R = "<<rightCurrent<<" L = "<<leftCurrent<<std::endl;
      std::cout<<"Error = "<<"R = "<<rightError<<" L = "<<prevLeftError<<std::endl;
      std::cout<<"prevError = "<<"R = "<<prevRightError<<" L = "<<prevLeftError<<std::endl;
      std::cout<<"Dx = "<<"R = "<<rightDeriv<<" L = "<<leftDeriv<<std::endl;
      std::cout<<"D/Dx = "<<"R = "<<rightIntergral<<" L = "<<leftIntergral<<std::endl;
      std::cout<<"pow = "<<"R = "<<rightPut<<" L = "<<leftPut<<std::endl;

      DriveMotors.Move(leftPut, rightPut);

      if ((fabs(rightPut)< 1) && (fabs(leftPut)< 1)){//
        DriveMotors.Brake(brake);
        std::cout<<"BRAKE"<<std::endl;
        stopPid = true;
        break;
        
      }

      vex::task::sleep(20);
    }
    std::cout<<"ploop"<<std::endl;
  


}

void Movement_Controller::Drive(float target, float Volts){

    customDrive(target, .013, .05, .6 /*.05, .01 == moon walk*/, Volts);
  
}

//Turn control

void Movement_Controller::customPivot(float heading, float kp, float kd, float ki, float Volts, vex::turnType Dir, bool Auto){
  DriveBaseControler DriveMotors;
  float startTime = Paincreas.timer(msec);
   float prevTime = startTime, dT, currentTime;
   float integral = 0, error = 0, derivative = 0, prevError = 0;
   bool done = false;
   float  currentHeading = Gyro.heading(degrees);
   float powCap = 0, sign = 0;
  
 
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
    
     float output = kp*error + ki*integral + kd*derivative;

     sign = fabs(output)/output;

     if (fabs(output) > Volts){
        output = Volts * sign;
     }

     powCap += acceleration * sign;

     if (fabs(powCap) > fabs(Volts)){
       powCap = Volts * sign;
     }

     if(fabs(output) > fabs(powCap)){
       output = powCap;
     }

     if(fabs(output) > maxPow){
       output = maxPow * sign;
     }

     std::cout<<"Target = "<<heading<<std::endl;
     std::cout<<"Current = "<<Gyro.heading()<<std::endl;
     std::cout<<"Error = "<<error<<std::endl;
     std::cout<<"prevError = "<<prevError<<std::endl;
     std::cout<<"Dx = "<<derivative<<std::endl;
     std::cout<<"D/Dx = "<<integral<<std::endl;
     std::cout<<"pow = "<<output<<std::endl;

     if (Dir == left && Auto == false /*fabs(heading) > 180*/){
     DriveMotors.Move(-output, 0);
     }else if (Dir == right && Auto == false /*fabs(heading) <= 180 && fabs(heading) >= 0*/){
       DriveMotors.Move(0, output);
     }else if (fabs(heading) > 180 && Auto == true) {
       DriveMotors.Move(-output, 0);
     }else if (fabs(heading) <= 180 && fabs(heading) >= 0 && Auto == true) {
       DriveMotors.Move(0, output);
     }else {
       DriveMotors.Move(0, 0);
       std::cout << "FUCK" << std::endl;
     }
 
     if ((fabs(error) < 2)){
       DriveMotors.Brake(hold);
       done = true;
       DriveMotors.Brake(hold);
       std::cout << "turn: " << Paincreas.timer(msec)-startTime << std::endl;
       
       break;
     }
     wait(10, msec);
  }

   std::cout << "pid ended "  << heading<< ", " << Gyro.heading() <<std::endl;
   
 }

 void Movement_Controller::customPivot(float heading, float kp, float kd, float ki, float Volts){
   customPivot(heading, kp, kd, ki, Volts, right, true);
 }

void Movement_Controller::customPoint(float heading, float kp, float kd, float ki, float Volts){
  DriveBaseControler DriveMotors;
  /*float startTime = Paincreas.timer(msec);
   float prevTime = startTime, dT, currentTime;
   float integral = 0, error = 0, newError = 0, derivative = 0, prevError = 0;
   bool done = false;
   float  currentHeading = Gyro.heading(degrees);
   float powCap = 0, sign = 0;
 
   while(!done) {

     currentTime = Paincreas.timer(msec);
     dT = currentTime - prevTime;
     prevTime = currentTime;
 
      currentHeading = Gyro.heading(degrees);
     
     error = heading -  currentHeading;
     newError = (heading + 5) -  currentHeading;
 
     if (error > 180) {
       error = error - 360;
     } else if (error < -180) {
       error = 360 + error;
     }
 
     derivative = (error - prevError) / dT;
 
     prevError = newError;
 
     integral += newError * dT;

     if (fabs(integral) >= 1000){
       integral += (error * dT)/100;
     }
    
     float output = kp*newError + ki*integral + kd*derivative;

     sign = fabs(output)/output;

     if (fabs(output) > Volts){
        output = Volts * sign;
     }

     powCap += acceleration * sign;

     if (fabs(powCap) > fabs(Volts)){
       powCap = Volts * sign;
     }

     if(fabs(output) > fabs(powCap)){
       output = powCap;
     }

     if(fabs(output) > maxPow){
       output = maxPow * sign;
     }

     std::cout<<"Target = "<<heading<<std::endl;
     std::cout<<"Current = "<<Gyro.heading()<<std::endl;
     std::cout<<"Error = "<<error<<std::endl;
     std::cout<<"prevError = "<<prevError<<std::endl;
     std::cout<<"Dx = "<<derivative<<std::endl;
     std::cout<<"D/Dx = "<<integral<<std::endl;
     std::cout<<"pow = "<<output<<std::endl;

      DriveMotors.Move(-output, output);

     if ((fabs(error) < 1.5)){
       done = true;
       DriveMotors.Brake(hold);
       
       break;
     }
     wait(30, msec);*/
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
     
     DriveMotors.Move(-driveSpeed, driveSpeed);
 
     if ((fabs(error) < 1.5)){
       done = true;
       DriveMotors.Brake(hold);
       std::cout << "turn: " << Paincreas.timer(msec)-startTime << std::endl;

       break;
     }
     wait(20, msec);
  }

   std::cout << "pid ended "  << heading<< ", " << Gyro.heading() <<std::endl;
   
 

   std::cout << "pid ended "  << heading<< ", " << Gyro.heading() <<std::endl;
   std::cout << "margin "  << heading - Gyro.heading() <<std::endl;
   
 }
void Movement_Controller::Point(float heading, float Volts){
  customPoint(heading, .14, 0.25, .0000005, Volts);
}
//.13, 9, .000015
void Movement_Controller::Pivot(float heading, float Volts, vex::turnType Dir){
customPivot(heading, .1, 0.003, 0.000045, Volts, Dir, false);
}

void Movement_Controller::turnFor(float amount, float Volts, bool Point){

  float target = amount + Gyro.heading();

  if (Point == true){
    customPoint(target, .15, 9.8, .00005, Volts);
  }else if (Point == false) {
    customPivot(target, .1, 0.004, 0.00004, Volts, left, true);
  }else{}
}