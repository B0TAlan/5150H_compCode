#include "vex.h"

void gyroConfig() {
  Gyro.calibrate();              // start the gyro calabration
  while (Gyro.isCalibrating()) { // calabrates gyro
    std::cout << "Gyro is calibrating" << std::endl;
    Paincreas.Screen.drawImageFromFile("chadhil.png", 0, 0);
    wait(200, msec); // waits until teh calabration is done
  }
  std::cout << "Gyro is calibrated" << std::endl;
  Controller1.Screen.print("calibrated");
}