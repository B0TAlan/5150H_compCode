#include <vex.h>

// Helper
void setLiftVel(int p) { Lift.spin(fwd, p, volt); }

// Lift Control
void liftControl() {

  int liftPower = 12.0 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  // uses R1 and R2 as a constant (1 || 0) so that the lift will run @ 12 volts(up) or -12 volts(down)

  setLiftVel(liftPower);
  if (liftPower == 0) {
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) >= 2 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes max hight stop the lift
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) <= .1 && Controller1.ButtonR2.pressing()) {
    // if the lift reashes min hight stop the lift
    liftPower = 0;
  } else {
    liftPower = 127 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  }
}

// Helper
bool Pring = false;

void setPingle() {
  if (Pring)
    Pring = false;
  else if (!Pring)
    Pring = true;
}

// Pringle intake Control p1
void spinPringle() {
  if (Controller1.ButtonLeft.pressing() && pringle.isDone())
    pringle.spin(reverse, 600, rpm);
  else if (Controller1.ButtonLeft.pressing() && pringle.isSpinning()) {
    pringle.stop(coast);
  } else {
    pringle.stop(coast);
  }
}

// Pringle intake Control p1
void pringleIntake() {
  if (Controller2.ButtonR2.pressing()) {
    pringle.spin(fwd, 300 , rpm);

  } else if (Controller2.ButtonR1.pressing()) {
    pringle.spin(reverse, 300 , rpm);

  } else
    pringle.stop(coast);
}

bool cOn = false;

void clampOpen() { Clamp.set(false); }

void clampCloes() { Clamp.set(true); }

bool bLD = false;

void bLOpen() { bL.set(true); }

void bLClose() { bL.set(false); }

void clearPrint(int B, int C, int C2) {
  if (C == 1) {
    Controller1.Screen.clearScreen();
  }
  if (B == 1) {
    Paincreas.Screen.clearScreen();
  }
  if (C2 == 1) {
    Controller2.Screen.clearScreen();
  }
  if (C == 1 && B == 1 && C2 == 1) {
    Controller1.Screen.clearScreen();
    Paincreas.Screen.clearScreen();
    Controller2.Screen.clearScreen();
  }
}

void gyroConfig() {
  Gyro.calibrate();              // start the gyro calabration
  while (Gyro.isCalibrating()) { // calabrates gyro
    std::cout << "Gyro is calibrating" << std::endl;
    wait(500, msec); // waits until teh calabration is done
  }
  std::cout << "Gyro is calibrated" << std::endl;
  Controller1.Screen.print("calibrated");
}

void setState(bool clamp, bool baL) {

    Clamp.set(clamp);
    bL.set(baL);
  }

void gyroReadings(){
  clearPrint(1, 0, 0);
  while(true){
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.setCursor(2, 2);
    Paincreas.Screen.print(Gyro.heading());



  }

}