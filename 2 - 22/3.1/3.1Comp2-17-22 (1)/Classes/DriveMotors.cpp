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
  void TempCheck(){
    Paincreas.Screen.setFont(mono20);
    Paincreas.Screen.clearLine(1, black);
    Paincreas.Screen.setCursor(Paincreas.Screen.row(), 1);
    Paincreas.Screen.setCursor(1, 1);
    Paincreas.Screen.print("pringle(C)[12] = ");

    Paincreas.Screen.setCursor(2, 1);
    Paincreas.Screen.print("leftFront(C)[1] = ");

    Paincreas.Screen.setCursor(3, 1);
    Paincreas.Screen.print("leftBack(C)[2] = ");

    Paincreas.Screen.setCursor(4, 1);
    Paincreas.Screen.print("rightFront(C)[14] = ");

    Paincreas.Screen.setCursor(5, 1);
    Paincreas.Screen.print("rightBack(C)[15] = ");

    Paincreas.Screen.setCursor(6, 1);
    Paincreas.Screen.print("clamp state = ");

    Paincreas.Screen.setCursor(7, 1);
    Paincreas.Screen.print("lift(C)[11] = ");

    Paincreas.Screen.setCursor(8, 1);
    Paincreas.Screen.print("bL state = ");

    Paincreas.Screen.setCursor(9, 1);
    Paincreas.Screen.print("aG2(C) = ");

    Paincreas.Screen.setCursor(1, 15);
    Paincreas.Screen.print(pringle.temperature(celsius));

    Paincreas.Screen.setCursor(2, 15);
    Paincreas.Screen.print(lF.temperature(celsius));

    Paincreas.Screen.setCursor(3, 15);
    Paincreas.Screen.print( lB.temperature(celsius));

    Paincreas.Screen.setCursor(4, 15);
    Paincreas.Screen.print( rF.temperature(celsius));

    Paincreas.Screen.setCursor(5, 15);
    Paincreas.Screen.print( rB.temperature(celsius));

    Paincreas.Screen.setCursor(6, 15);
    Paincreas.Screen.print(Clamp.value());

    Paincreas.Screen.setCursor(7, 15);
    Paincreas.Screen.print(Lift.temperature(celsius));

    Paincreas.Screen.setCursor(8, 15);
    Paincreas.Screen.print(bL.value());
  }
};

MotorControl DriveMotors; 


