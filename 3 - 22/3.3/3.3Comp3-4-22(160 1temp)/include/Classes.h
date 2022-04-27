#ifndef CLASSES_H
#define CLASSES_H

#include "robot-config.h"
#include <math.h>
#include <iostream>

class MotorControl {
public:
  void BrakeAll(brakeType mode) {
    lF.stop(mode);
    lB.stop(mode);
    lM.stop(mode);
    rF.stop(mode);
    rB.stop(mode);
    rM.stop(mode);
  }
  void BrakeL(brakeType mode) {
    lF.stop(mode);
    lB.stop(mode);
    lM.stop(mode);
  }
  void BrakeR(brakeType mode) {
    rF.stop(mode);
    rB.stop(mode);
    rM.stop(mode);
  }
  void setVel(int Lv, int Rv, velocityUnits V) {
    lF.setVelocity(Lv, V); // set the motors to the intended speed
    lB.setVelocity(Lv, V);
    lM.setVelocity(Lv, V);
    rF.setVelocity(Lv, V);
    rB.setVelocity(Lv, V);
    rM.setVelocity(Lv, V);
  }
  void printVal() {
    std::cout << "lF = " << lF.value() << std::endl;
    std::cout << "lB = " << lB.value() << std::endl;
    std::cout << "lM = " << lM.value() << std::endl;
    std::cout << "rF = " << rF.value() << std::endl;
    std::cout << "rB = " << rB.value() << std::endl;
    std::cout << "rM = " << rM.value() << std::endl;
  }
  void Move(int Lp, int Rp) {
    lF.spin(fwd, Lp, voltageUnits::volt);
    lB.spin(fwd, Lp, voltageUnits::volt);
    lM.spin(fwd, Lp, voltageUnits::volt);
    rF.spin(fwd, Rp, voltageUnits::volt);
    rB.spin(fwd, Rp, voltageUnits::volt);
    rM.spin(fwd, Rp, voltageUnits::volt);
  }
  void reset() {
    lF.setPosition(0, rotationUnits::raw);
    rF.setPosition(0, rotationUnits::raw);
    lB.setPosition(0, rotationUnits::raw);
    rB.setPosition(0, rotationUnits::raw);
    lM.setPosition(0, rotationUnits::raw);
    rM.setPosition(0, rotationUnits::raw);
  }
  void setPos(int L, int R) {
    lF.setPosition(L, rotationUnits::raw);
    rF.setPosition(R, rotationUnits::raw);
    lB.setPosition(L, rotationUnits::raw);
    rB.setPosition(R, rotationUnits::raw);
    lM.setPosition(L, rotationUnits::raw);
    rM.setPosition(R, rotationUnits::raw);
  }
};

MotorControl DriveMotors;

class LiftShortcut {

public:
  void Max(int vel, bool wait) {// raises the lift to the max height
    Lift.rotateTo(1.6, rotationUnits::rev, vel, velocityUnits::pct, wait);
  }

  void Min(int vel, bool wait) {// returns to 0 the lowest point
    Lift.rotateTo(0, rotationUnits::rev, vel, velocityUnits::pct, wait);
  }

  void Score(int vel, bool wait) {// half way from max height used to help balance platform
    Lift.rotateTo(1, rev, vel, velocityUnits::pct, wait);
  }

  void Idle(int vel, bool wait) {//  raises lift to allow pringle intake to to sping and for pringles to slide under lift
    Lift.rotateTo(.4, rev, vel, velocityUnits::pct, wait);
  }
  void ClearWall(int vel, bool wait) {// raises lift to clear the wall with a mgoal 
    Lift.rotateTo(1.3, rev, vel, velocityUnits::pct, wait);
  }

  void setPos(int pos) { Lift.setPosition(0, rotationUnits::rev); }// sets the position of the lift 
};

LiftShortcut aL;

class ClampShortcuts {
public:
  bool closed = false;// reps state of the clamp

  void Open() {// opens clamps and waits to make sure clamp fully opens 
    Clamp.set(true);

    wait(100, msec);

    closed = false;
  }

  void Cloes() {// closes clamp and waits so that its full closed
    Clamp.set(false);

    wait(100, msec);

    closed = true;
  }

  void CF() { Clamp.set(false); }// closes clamp without delay 

  void OF() { Clamp.set(true); }// opens clamp without delay 
};

ClampShortcuts aC;

class BackLiftControls {

public:
  bool bLOff = true;// reps the state of the bL
  void Open() {// opens the bL with a delay
    bL.set(true);

    wait(100, msec);

    bLOff = true;
  }

  void Close() {// closes bL with delay
    bL.set(false);

    wait(100, msec);

    bLOff = false;
  }
  void CF() {// opens bL without delay
    bL.set(false);

    bLOff = true;
  }
  void OF() {// closes bL without delay
    bL.set(true);

    bLOff = false;
  }
};

BackLiftControls aB;

class PneumaticControls {
public:
  void setState(bool state) {

    Clamp.set(state);
    bL.set(state);
  }

  void getState() {

    std::cout << "Clamp = " << Clamp.value() << std::endl;
    std::cout << "bL = " << bL.value() << std::endl;
  }
};

PneumaticControls Pistions;

class PIDController{
  
  public:
  int defualtDrive(){
  return 0.1, 0, 0;
}

int defualtTurn(){
  return 0, 0, 0;
}

// THIS CODE SUCKS 


  int Drive(float target, float kp, float ki, float kd){
    
    DriveMotors.reset();// reset all motors encoders to 0
    
    float startT = Paincreas.timer(msec); // time when pid starts
    float prevT = startT, dT, currentT;
    //^ the time x amount ago is equal to start time delta time(dt) and current time

    //target = ((target * 300.0) / (4.0 * M_PI)) * (30.0 / 84.0); 
    //target = (target / (4.0 * M_PI)) * (360 * (84.0 / 60.0));
    target = ((target * (900)) / (4.0 * M_PI)) * (84.0 / 60.0);
    // convets from inches to motor encoder value 

    /////////////////////////////////////
    // color    ratio   encoder value  //
    // Red      36:1    1800 ticks/rev //
    // green    18:1    900 ticks/rev  //
    // blue     6:1     300 ticks/rev  //
    /////////////////////////////////////

    float leftCurrent = lM.position(rotationUnits::deg); 
    float rightCurrent = rF.position(rotationUnits::deg);
    // get current val of motor encoders

    float leftError, rightError;

    //jose is a bad programer 0 prog skills smh
    float prevLeftError = 0, prevRightError = 0;
    // Error = the differnce between target and current position

    float intergralLim = 120;
    float errorLim = 2;
    // ^ limits set to brake loop when either when robo reaches target
    // or if it over shoots

    float leftIntergral = 0, rightIntergral = 0;
    float leftDerivative = 0, rightDerivative= 0;
    //^ intergral for over shooting derivative for under shooting

    bool stopPid = false;

    while(!stopPid){
      
      // defind time vars
      currentT = Paincreas.timer(msec);
      dT = currentT - prevT;
      prevT = currentT;

      prevLeftError = leftError;
      prevRightError = rightError;

      leftCurrent = lF.position(rotationUnits::deg);
      rightCurrent = rF.position(rotationUnits::deg);


      leftError = target - leftCurrent;
      rightError = target - rightCurrent;

      rightDerivative = (rightError - prevRightError)/dT;
      leftDerivative = (leftError - prevLeftError)/dT;

      if (fabs(leftError) < intergralLim){
        leftIntergral += (leftError *dT);
        rightIntergral += (rightError *dT);
      } else{
        leftIntergral = 0;
        rightIntergral = 0;
      } 

      float leftOutput = (kp*leftError) + (ki*leftIntergral) + (kd*leftDerivative);
      float rightOutput = (kp*rightError) + (ki*rightIntergral) + (kd*rightDerivative);
      //std::cout<<"dt = "<<dT<<std::endl;
      std::cout<<"pret = "<<prevT<<std::endl;
      std::cout<<"Error = "<<leftError<<std::endl;
      std::cout<<"ErrorR = "<<rightError<<std::endl;
      std::cout<<"prevError = "<<leftError<<std::endl;
      std::cout<<"lDx = "<<leftDerivative<<std::endl;
      std::cout<<"lnFI = "<<leftIntergral<<std::endl;
      std::cout<<"pow = "<<leftOutput<<", "<<rightOutput<<std::endl;
      DriveMotors.Move(leftOutput, rightOutput);

      // end condition
      if ((fabs(rightError)< errorLim) && (fabs(leftError)< errorLim)){
        stopPid = true;
        DriveMotors.BrakeAll(hold);
        break;
      }
      wait(20, msec);
    }
    std::cout<<"Pid ended"<<std::endl;
    return 1;
  }

  int customTurn(float goalAngle, float kp/* = 4.0 */, float ki/* = .001 */, float kd/* = 3.0 */) {
  
   float startTime = Paincreas.timer(msec);
   float prevTime = startTime, deltaTime, currentTime;
   float integral = 0, error = 0, derivative = 0, prevError = 0;
   bool done = false;
   float currentAngle = Gyro.heading(degrees);
 
  
 
   while(!done) {
 
     currentTime = Paincreas.timer(msec);
     deltaTime = currentTime - prevTime;
     prevTime = currentTime;
 
     currentAngle = Gyro.heading(degrees);
 
     error = goalAngle - currentAngle;
 
     if (error > 180) {
       error = error - 360;
     } else if (error < -180) {
       error = 360 + error;
     }
 
     derivative = (error - prevError) / deltaTime;
 
     prevError = error;
 
     integral += error * deltaTime;
 
     float driveSpeed = kp*error + ki*integral + kd*derivative;
     
     lF.spin(forward, driveSpeed, percent);
     lB.spin(forward, driveSpeed, percent);
     lM.spin(forward, driveSpeed, percent);
     rF.spin(forward, -driveSpeed, percent);
     rB.spin(forward, -driveSpeed, percent);
     rM.spin(forward, -driveSpeed, percent);
 
     if ((fabs(error) < 1.5)){
       done = true;
       DriveMotors.BrakeAll(hold);
       std::cout << "turn: " << Paincreas.timer(msec)-startTime << std::endl;
       break;
     }
     wait(20, msec);
  }
   std::cout << "pid ended "  << goalAngle<< ", " << Gyro.heading() <<std::endl;
   return 1;
 }

 void Turn(float target, float kp){
  customTurn(target, kp, .00001, 0.1);
   
 }
};

PIDController Pid;

#endif
