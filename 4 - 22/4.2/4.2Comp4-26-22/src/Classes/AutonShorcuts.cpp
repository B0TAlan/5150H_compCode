#include "vex.h"
#include "Classes.h"
#include "Functions.h"

// Lift Shortcuts
void LiftShortcut::Max(int vel, bool wait) { // raises the lift to the max height
  unLock();
  Lift.rotateTo(1.8, rotationUnits::rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) >= 1.6){
    lock();
  }
}

void LiftShortcut::Min(int vel, bool wait) { // returns to 0 the lowest point
  unLock();
  Lift.rotateTo(.08, rotationUnits::rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) <= .15){
    lock();
  }
}

void LiftShortcut::Score(int vel, bool wait) { // half way from max height used to help balance platform
  unLock();
  Lift.rotateTo(1.25, rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) >= .8){
    lock();
  }
}

void LiftShortcut::Idle(int vel, bool wait) { //  raises lift to allow pringle intake to to sping and for pringles to slide under lift
  unLock();
  Lift.rotateTo(.3, rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) >= .2){
    lock();
  }
}
void LiftShortcut::P(int vel, bool wait) { //  raises lift to allow pringle intake to to sping and for pringles to slide under lift
  unLock();
  Lift.rotateTo(.6, rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) >= .5){
    lock();
  }
}
void LiftShortcut::ClearWall(int vel, bool wait) { // raises lift to clear the wall with a mgoal
  unLock();
  Lift.rotateTo(1.3, rev, vel, velocityUnits::pct, wait);
  if(Lift.position(rev) >= 1.2){
    lock();
  }
}

void LiftShortcut::setPos(int pos) { // sets the position of the lift
  unLock();
  Lift.setPosition(0, rotationUnits::rev);
  if(Lift.position(rev) <= .15){
    lock();
  }
}

void LiftShortcut::lock(){
  Lock = true;
  //locker();
}

void LiftShortcut::unLock(){
  Lock = false;
  //locker();
}

//Clamp Shortcuts
void ClampShortcuts::Open() { // opens clamps and waits to make sure clamp opens
  Clamp.set(true); // opens clamp

  wait(100, msec); // waits

  closed = false; // sets clamp

  cOn = closed;
}

void ClampShortcuts::Cloes() { // closes clamp and waits so that its full closed
  Clamp.set(false); // closes clamp

  wait(200, msec); // waits

  closed = true; // sets state of the clamp to close (true)
  
  cOn = closed;
}

void ClampShortcuts::CF() { Clamp.set(state); } // closes clamp without delay

void ClampShortcuts::OF() { Clamp.set(true); } // opens clamp without delay

// BackLift Shortcuts
void BackLiftShortcuts::Open() { // opens the bL with a delay
  bW.set(!state), wait(250, msec), bC.set(state);

  wait(100, msec);

  bLOff = true;
}

void BackLiftShortcuts::Close() { // closes bL with delay
  bC.set(!state), wait(250, msec), bW.set(state);

  wait(100, msec);

  bLOff = false;
}
void BackLiftShortcuts::CF() { // opens bL without delay
  bC.set(!state), wait(250, msec), bW.set(state);

  bLOff = true;
}
void BackLiftShortcuts::OF() { // closes bL without delay
  bW.set(!state), wait(250, msec), bC.set(state);

  bLOff = false;
}

// Pringle Shortcuts
void PringleShortcuts::Intake(int X, vex::timeUnits time) { // spins the pringle intake for X amount of msec
  pringle.spin(reverse, 550, rpm);
  wait(X, time);
  pringle.stop();
}

void PringleShortcuts::Outtake(int X, vex::timeUnits time) { // spins the pringle Outtake for X amount of msec
  pringle.spin(fwd, 550, rpm);
  wait(X, time);
  pringle.stop();
}

void PringleShortcuts::On(directionType dir){
  pringle.spin(dir, 600, rpm);
}

void PringleShortcuts::Off(){
  pringle.stop();
}

// Drivebase control
void DriveBaseControler::Brake(vex::brakeType mode){
  lF.stop(mode);
  lB.stop(mode);
  lM.stop(mode);
  rF.stop(mode);
  rB.stop(mode);
  rM.stop(mode);
}

void DriveBaseControler::Move(int L, int R){
  lF.spin(fwd, L, voltageUnits::volt);
  lB.spin(fwd, L, voltageUnits::volt);
  lM.spin(fwd, L, voltageUnits::volt);
  rF.spin(fwd, R, voltageUnits::volt);
  rB.spin(fwd, R, voltageUnits::volt);
  rM.spin(fwd, R, voltageUnits::volt);
}

void DriveBaseControler::Reset(){
  lF.resetRotation();
  rF.resetRotation();
  lB.resetRotation();
  rB.resetRotation();
  lM.resetRotation();
  rM.resetRotation();

  endL.resetPosition();
  endR.resetPosition();
}

void DriveBaseControler::MoveL(int L){
  lF.spin(fwd, L, voltageUnits::volt);
  lB.spin(fwd, L, voltageUnits::volt);
  lM.spin(fwd, L, voltageUnits::volt);
}
void DriveBaseControler::MoveR(int R){
  rF.spin(fwd, R, voltageUnits::volt);
  rB.spin(fwd, R, voltageUnits::volt);
  rM.spin(fwd, R, voltageUnits::volt);
}