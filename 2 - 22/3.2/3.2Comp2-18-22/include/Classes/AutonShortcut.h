#include "vex.h"

#ifndef AUTONSHORTCUT_H
#define AUTONSHORTCUT_H

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
    Lift.rotateTo(1.2, rev, vel, velocityUnits::pct, wait);
  }
  
  void setPos( int pos ){
    Lift.setPosition(0, rotationUnits::rev);
  }
};

LiftShortcut aL;

class ClampShortcuts{
  public:
  bool closed = false;

void Open(){
  Clamp.set(false);

  wait(300, msec);

  closed = false;
}

void Cloes(){
  Clamp.set(true);

  wait(300, msec);

  closed = true;
}
};

ClampShortcuts aC;

class BackLiftControls{
  
  public:
  bool bLOff = true;
  void Open(){
  bL.set(false);

  wait(300, msec);

  bLOff = true;
}

void Close(){
  bL.set(true);

  wait(300, msec);
  
  bLOff = false;
}
};

BackLiftControls aB;


#endif