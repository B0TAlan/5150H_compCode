#include "vex.h"

#ifndef AUTONSHORTCUT_H
#define AUTONSHORTCUT_H

class LiftShortcut {

public:
  void Max(int vel, bool wait) {
    Lift.rotateTo(1.6, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void Min(int vel, bool wait) {
    Lift.rotateTo(0, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void Score(int vel, bool wait) {
    Lift.rotateTo(.5, rev, vel, velocityUnits::pct, wait);
  }

  void Idle(int vel, bool wait) {
    Lift.rotateTo(.1, rev, vel, velocityUnits::pct, wait);
  }
};

LiftShortcut aL;

#endif