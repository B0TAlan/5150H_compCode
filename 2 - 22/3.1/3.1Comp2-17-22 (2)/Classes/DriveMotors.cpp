#include "vex.h"
#include <iostream>

class MotorControl {
public:
  // const char Bt;

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
