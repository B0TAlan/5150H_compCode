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
  void Max(int vel, bool wait) {
    Lift.rotateTo(1.6, rotationUnits::rev, vel, velocityUnits::pct, wait);
  }

  void Min(int vel, bool wait) {
    Lift.rotateTo(0, rotationUnits::rev, vel, velocityUnits::pct, wait);
  }

  void Score(int vel, bool wait) {
    Lift.rotateTo(1, rev, vel, velocityUnits::pct, wait);
  }

  void Idle(int vel, bool wait) {
    Lift.rotateTo(.3, rev, vel, velocityUnits::pct, wait);
  }
  void ClearWall(int vel, bool wait) {
    Lift.rotateTo(1.3, rev, vel, velocityUnits::pct, wait);
  }

  void setPos(int pos) { Lift.setPosition(0, rotationUnits::rev); }
};

LiftShortcut aL;

class ClampShortcuts {
public:
  bool closed = false;

  void Open() {
    Clamp.set(false);

    wait(100, msec);

    closed = false;
  }

  void Cloes() {
    Clamp.set(true);

    wait(100, msec);

    closed = true;
  }

  void CF() { Clamp.set(true); }

  void OF() { Clamp.set(false); }
};

ClampShortcuts aC;

class BackLiftControls {

public:
  bool bLOff = true;
  void Open() {
    bL.set(false);

    wait(100, msec);

    bLOff = true;
  }

  void Close() {
    bL.set(true);

    wait(100, msec);

    bLOff = false;
  }
  void OF() {
    bL.set(false);

    bLOff = true;
  }
  void CF() {
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

    //target = ((target * 300.0) / (4.0 * M_PI)) * (30.0 / 84.0); 
    //target = (target / (4.0 * M_PI)) * (360 * (84.0 / 60.0));
    //target = (target / (4.0 * M_PI)) * (360 * (84.0 * 60.0));
    target = ((target * (1800)) / (4.0 * M_PI)) * (84.0 / 60.0);
    // convets from inches to motor encoder value 

    float leftCurrent = lF.position(rotationUnits::deg); 
    float rightCurrent = rF.position(rotationUnits::deg);
    // get current val of motor encoders

    float leftError = 0, rightError = 0;
    float prevLeftError = 0, prevRightError = 0;
    // Error = the differnce between target and current position

    float intergralLim = 8;
    float errorLim = 2;
    // ^ limits set to brake loop when either when robo reaches target
    // or if it over shoots

    float leftIntergral, rightIntergral;
    float leftDerivative, rightDerivative;
    //^ intergral for over shooting derivative for under shooting

    bool stopPid = false;

    while(!stopPid){
      
      // defind time vars
      currentT = Paincreas.timer(msec);
      dT = currentT - prevT;
      prevT = currentT;

      leftCurrent = lF.position(rotationUnits::deg);
      rightCurrent = rF.position(rotationUnits::deg);

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

      float leftOutput = (kp*leftError) + (ki*leftIntergral) + (kd*leftDerivative);
      float rightOutput = (kp*rightError) + (ki*rightIntergral) + (kd*rightDerivative);
      std::cout<<"dt = "<<dT<<std::endl;
      std::cout<<"prect = "<<prevT<<std::endl;
      std::cout<<"Error = "<<leftError<<std::endl;
      std::cout<<"prevError = "<<leftError<<std::endl;
      std::cout<<"lDx = "<<leftDerivative<<std::endl;
      std::cout<<"lnFI = "<<leftIntergral<<std::endl;
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

PIDController Pid;

#endif
