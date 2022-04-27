#include <vex.h>

bool cState;
bool bState;
bool Lock = false;

// Helper
void setLiftVel(int p) { Lift.spin(fwd, p, volt); }

// Lift Control
void liftControl() {

  int liftPower = 127.0 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  // uses R1 and R2 as a constant (1 || 0) so that the lift will run @ 12
  // volts(up) or -12 volts(down)

  setLiftVel(liftPower);
  if (liftPower == 0) {
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) >= 2.9 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes max hight stop the lift
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) <= .1 && Controller1.ButtonR2.pressing()) {
    // if the lift reashes min hight stop the lift
    liftPower = 0;
  } else {
    Lock = false;
    liftPower = 127 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  }
}

void liftLock() { Lock = true; }

void liftUnLock() { Lock = false; }

void lockLift() {
  competition comp;
  Lift.setMaxTorque(100, pct);
  while (1) {
    if (Lock == true) {
      Lift.setBrake(hold);
      Lift.rotateTo(Lift.rotation(deg), deg);
    } else if (Lock == false) {
      Lift.setBrake(coast);
    }

    if(comp.isDriverControl() == true){
      break;
    }

    wait(20, msec);
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
void singlePringle() {
  if (Controller1.ButtonLeft.pressing()) {
    Pring = true;

  } else if (pringle.isSpinning()) {
    waitUntil(Controller1.ButtonLeft.pressing());
    Pring = false;
  } else {
    Pring = false;
  }
}

void pushingP() {

  while (Controller2.ButtonR2.pressing()) {
    pringle.spin(reverse, 550, rpm);
  }
  while (Controller2.ButtonR1.pressing()) {
    pringle.spin(fwd, 550, rpm);
  }
  while (Pring) {
    pringle.spin(reverse, 550, rpm);

    if (!Pring) {
      pringle.stop();
    }
  }
}

// Pringle intake Control p1
void pringleIntake() {
  if (Controller2.ButtonR2.pressing()) {
    pringle.spin(fwd, 550, rpm);

  } else if (Controller2.ButtonR1.pressing()) {
    pringle.spin(reverse, 550, rpm);

  } else
    pringle.stop(coast);
}

bool cOn = false;

void clampOpen() { Clamp.set(!cState); }

void clampCloes() { Clamp.set(cState); }

bool bLD = false;

void bLOpen() { bW.set(!bState), wait(250, msec), bC.set(bState); }

void bLClose() { bC.set(!bState), wait(250, msec), bW.set(bState); }

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

    wait(500, msec);
  }
  std::cout << "Gyro is calibrated" << std::endl;
  Controller1.Screen.print("calibrated");
}

void setState(bool clamp, bool baL) {

  Clamp.set(clamp);
  bW.set(baL);
  bC.set(!baL);
}

void gyroReadings() {
  competition comp;
  //clearPrint(1, 0, 0);
  while (true) {
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.setCursor(2, 2);
    Paincreas.Screen.print(Gyro.heading());

    if(comp.isDriverControl() == true){
      break;
    }
  }
}

void buildIssue() {
  Paincreas.Screen.setCursor(2, 2);
  Paincreas.Screen.setPenColor(yellow);
  Paincreas.Screen.setFont(mono60);
  Paincreas.Screen.print("Build Issue");
}