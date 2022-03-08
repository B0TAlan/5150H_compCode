#include "robot-config.h"
#include <iostream>

class MotorControl{
  public:

    //const char Bt;

    void BrakeAll(brakeType mode){
      lF.stop(mode);
      lM.stop(mode);
      lB.stop(mode);
      rF.stop(mode);
      rM.stop(mode);
      rB.stop(mode);

    }

    void BrakeL(brakeType mode){
      lF.stop(mode);
      lM.stop(mode);
      lB.stop(mode);
    }

    void BrakeR(brakeType mode){
      rF.stop(mode);
      rM.stop(mode);
      rB.stop(mode);
    }

    void setVel(int Lv, int Rv, velocityUnits V){
      lF.setVelocity(Lv, V); //set the motors to the intended speed
      lM.setVelocity(Lv, V);
      lB.setVelocity(Lv, V);
      rF.setVelocity(Lv, V);
      rM.setVelocity(Lv, V);
      rB.setVelocity(Lv, V);


    }

    void printVal(){
      std::cout<<"lf = "<<lF.value()<<std::endl;
      std::cout<<"lb = "<<lM.value()<<std::endl;
      std::cout<<"lm = "<<lB.value()<<std::endl;
      std::cout<<"Rf = "<<rF.value()<<std::endl;
      std::cout<<"Rb = "<<rM.value()<<std::endl;
      std::cout<<"Rm = "<<rB.value()<<std::endl;


    }

    void MoveAll(int Lp, int Rp){

      lF.spin(fwd ,Lp, voltageUnits::volt);
      lM.spin(fwd ,Lp, voltageUnits::volt);
      lB.spin(fwd ,Lp, voltageUnits::volt);
      rF.spin(fwd ,Rp, voltageUnits::volt);
      rM.spin(fwd ,Rp, voltageUnits::volt);
      rB.spin(fwd ,Rp, voltageUnits::volt);
    }

    void MoveR(int Rp){
      rF.spin(fwd ,Rp, voltageUnits::volt);
      rM.spin(fwd ,Rp, voltageUnits::volt);
      rB.spin(fwd ,Rp, voltageUnits::volt);
    }

    void MoveL(int Lp){
      lF.spin(fwd ,Lp, voltageUnits::volt);
      lM.spin(fwd ,Lp, voltageUnits::volt);
      lB.spin(fwd ,Lp, voltageUnits::volt);
    }

    void reset(){
      lF.setPosition(0, rotationUnits::raw);
      lM.setPosition(0, rotationUnits::raw);
      lB.setPosition(0, rotationUnits::raw);
      rF.setPosition(0, rotationUnits::raw);
      rM.setPosition(0, rotationUnits::raw);
      rB.setPosition(0, rotationUnits::raw);
    }
    void resetTo(int L, int R){
      lF.setPosition(L, rotationUnits::raw);
      lM.setPosition(R, rotationUnits::raw);
      lB.setPosition(L, rotationUnits::raw);
      rF.setPosition(R, rotationUnits::raw);
      rM.setPosition(L, rotationUnits::raw);
      rB.setPosition(R, rotationUnits::raw);

    }

};


extern MotorControl driveMotors;
