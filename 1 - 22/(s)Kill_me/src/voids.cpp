#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

//------------------------------------------------ Gloabal
//Vars--------------------------------------------------------//

bool sM = true;    // used to make the scoring macro repeat DNU
bool auton = true; // was used to trigger line sensor in auton DNU for solo awp
bool clampOn =
    false; // used to have the robot to wait for the clamp close in auton
bool RobotIsWorking = false; // to always make sure the robot is working
int Pring = 0;               // used to turn off and on the pringle intake
int allTemp[2][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 2, 14, 15, 7, 11, 12,
                      18}}; // 2d area to log motor temps and their port #
bool bLD = false; // used to state the whether the backLift is down(true) or
                  // up(false)| backLift up at start
bool waitTING = true;
//--------------------------------------------------------------------------------------------------------------------//

void clamp1On() { // rotate the clamp to close it
  Clamp1.setVelocity(100, percent);

  Clamp1.rotateTo(-.6, rev, true);

  Clamp1.stop(hold);
  waitUntil(Clamp1.position(rev) <= -.51);
  
  clampOn = true;
}
void Aclamp1On() {
  while (auton == true && clampOn == false) {
    if (line1.value(percentUnits::pct) <= 68) {
      Clamp1.rotateTo(-.55, rotationUnits::rev, 100, velocityUnits::pct, false);
      // std::cout<<Clamp1.position(rev)<<std::endl;
      waitUntil(Clamp1.position(rev) <= -.52);
      clampOn = true;
      Clamp1.stop(brake);
      break;
    } else if (line1.value(percentUnits::pct) > 68) {
      for (int i = 0; i < 3; i++) {
        driveBase.setDriveVelocity(5, velocityUnits::pct);

        if (clampOn == true) {
          break;
        }
      }
    }
  }
}
void clamp1Off() { // rotate the clamp to open it
  Clamp1.setVelocity(100, percent);

  Clamp1.rotateTo(-.1, rev, false); // not set to 0 to avoid over turning
  waitUntil(Clamp1.position(rev)>=-.2);
  clampOn = false; // DNU
  Clamp1.stop();
}
void bLReset() { // bring backLift all the way up only used in teleop
  bL1.rotateTo(0, rotationUnits::rev, 100, velocityUnits::pct, false);
}

// voids to set macros for lift
void liftUp() {

  if (Lift1.position(rev) < 1.35) {
    Lift1.setVelocity(200, percent);
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(1.35, rev, false);

  } else if (Controller1.ButtonR1.pressing() && Lift1.position(rev) >= 1.35) {
    Lift1.setVelocity(200, percent);
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(2, rev, false);

  } else {
  }
}
void liftDown() {
  if (Lift1.position(rev) <= 2) {
    Lift1.setVelocity(200, percent);
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(0, rev, false);
  } else if (Controller1.ButtonR2.pressing() && Lift1.position(rev) > 1.35) {
    Lift1.setVelocity(200, percent);
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(1.35, rev, false);
  } else {
  }
}
void deScore() {
  // lift.spinFor(fwd, 13, inches, 100, velocityUnits::pct);
  Lift1.rotateTo(.8, rotationUnits::rev, 60, velocityUnits::pct, true);
}
void bLDown() { // down
  bL.setVelocity(200, percent);
  if (bLR.position(rev) < 2.3) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-3.2, rev, false);
  } else if (Controller1.ButtonDown.pressing() && bLR.position(rev) >= 1 &&
             bL1.isDone()) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-4.8, rev, false);
  } else {
  }
}
void bLUp() { // up
  bL.setVelocity(200, percent);
  if (bLR.position(rev) > 2) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(-3.2, rev, false);
  } else if (Controller1.ButtonUp.pressing() && bLR.position(rev) < 1 &&
             bL1.isDone()) {
    // Lift1.spinFor(forward, 2, rev);
    bL.rotateTo(0, rev, false);
  } else {
    bL1.stop(hold);
  }
}
void resetAll() {
  all.rotateTo(0, rev, 100, velocityUnits::pct, true);
  all.stop();
  Controller1.Screen.print(green);
  Brain.Screen.clearScreen();
  Brain.Screen.print(white);
}
void score_macro() {
  // lower lift 1 step
  sM = true;
  Lift1.rotateTo(.9, rotationUnits::rev, 100, velocityUnits::pct, false);

  // open claw
  clamp1Off();
  waitUntil(Clamp1.isDone());

  // reset lift to full height
  liftUp();
}
void sMSet() { sM = false; }

void turnTo(int A) {
  rightDrive.spin(forward);
  rightDrive.spin(reverse);
  // Waits until the motor reaches a 90 degree turn and stops the Left and
  // Right Motors.
  waitUntil((Gyro.rotation(degrees) >= A));
  leftDrive.stop();
  rightDrive.stop();
  wait(1, seconds);
}
class lifState {
public:
  void Up() {
    if (Lift1.position(rev) < 1.35) {
      Lift1.setVelocity(200, percent);
      // Lift1.spinFor(forward, 2, rev);
      Lift1.rotateTo(1.35, rev, false);

    } else if (Controller1.ButtonR1.pressing() && Lift1.position(rev) >= 1.35) {
      Lift1.setVelocity(200, percent);
      // Lift1.spinFor(forward, 2, rev);
      Lift1.rotateTo(2, rev, false);

    } else {
    }
  }

  void Down() {
    if (Lift1.position(rev) <= 2) {
      Lift1.setVelocity(200, percent);
      // Lift1.spinFor(forward, 2, rev);
      Lift1.rotateTo(0, rev, false);
    } else if (Controller1.ButtonR2.pressing() && Lift1.position(rev) > 1.35) {
      Lift1.setVelocity(200, percent);
      // Lift1.spinFor(forward, 2, rev);
      Lift1.rotateTo(1.35, rev, false);
    } else {
    }
  }
};
int main2() {
  // lifState Lift;

  // Lift.Down();
  // Lift.Up();

  return 0;
}
