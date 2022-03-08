#include "vex.h"


int defualtDrive(){
  return 0, 0, 0;
}

int defualtTurn(){
  return 0, 0, 0;
}

class PidController{

  public:

  int Drive(float target, float kp, float ki, float kd){
    
    lF.setPosition(0, rotationUnits::deg);// reset all motors encoders to 0
    rF.setPosition(0, rotationUnits::deg);
    lB.setPosition(0, rotationUnits::deg);
    rB.setPosition(0, rotationUnits::deg);
    lM.setPosition(0, rotationUnits::deg);
    rM.setPosition(0, rotationUnits::deg); 

    float startT = Paincreas.timer(msec); // time when pid starts
    float prevT = startT, dT, currentT;
    //^ the time x amount ago is equal to start time delta time(dt) and current time

    target = target = ((target * 300.0) / (4.0 * M_PI)) * (30.0 / 84.0); 
    // convets from inches to motor encoder value 

    float leftCurrent = lF.position(rotationUnits::raw); 
    float rightCurrent = rF.position(rotationUnits::raw);
    // get current val of motor encoders

    float leftError = 0, rightError = 0;
    float prevLeftError = 0, prevRightError = 0;
    // Error = the differnce between target and current position

    float intergralLim = 8;
    float errorLim = 2;
    // ^ limits set to brake loop when either when robo reaches target
    // or if it over shoots

    float leftIntergral = 0, rightIntergral = 0;
    float leftDerivative = 0, rightDerivative = 0;
    //^ intergral for over shooting derivative for under shooting

    bool stopPid = false;

    while(!stopPid){
      
      // defind time vars
      currentT = Paincreas.timer(msec);
      dT = currentT - prevT;
      prevT = currentT;

      leftCurrent = lF.position(rotationUnits::raw);
      rightCurrent = rF.position(rotationUnits::raw);

      leftError = target - leftCurrent;
      rightError = target - rightCurrent;

      prevLeftError = leftError;
      prevRightError = rightError;

      rightDerivative = (rightError - prevRightError)/dT;
      leftDerivative = (leftError - prevLeftError)/dT;

      if (fabs(rightError) < intergralLim){
        leftIntergral += (leftError *dT);
        rightIntergral += (rightError *dT);
      } else{
        leftIntergral = 0;
        rightIntergral = 0;
      } 

      float leftOutput = kp*leftError + ki*leftIntergral + kd*leftDerivative;
      float rightOutput = kp*rightError + ki*rightIntergral + kd*rightDerivative;
      std::cout<<"output"<<leftOutput<<std::endl;
      std::cout<<"Error"<<leftError<<std::endl;
      lF.spin(fwd, leftOutput, voltageUnits::volt);
      lB.spin(fwd, leftOutput, voltageUnits::volt);
      lM.spin(fwd, leftOutput, voltageUnits::volt);
      rF.spin(fwd, rightOutput, voltageUnits::volt);
      rB.spin(fwd, rightOutput, voltageUnits::volt);
      rM.spin(fwd, rightOutput, voltageUnits::volt);

      // end condition
      if ((fabs(rightError)< errorLim) && (fabs(leftError)< errorLim)){
        stopPid = true;
        lF.stop(hold);
        lB.stop(hold);
        lM.stop(hold);
        rF.stop(hold);
        rB.stop(hold);
        rM.stop(hold);
        break;
      }
      wait(20, msec);
    }
    std::cout<<"Pid ended"<<std::endl;
    return 1;
  }

  int Turn(float angle, float kp, float ki, float kd){



    return 1;
  }

};

PidController PID;

