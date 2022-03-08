#include "vex.h"


  void lMax(int vel, bool wait){
    Lift.rotateTo(2, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void lMin(int vel, bool wait){
    Lift.rotateTo(0, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void lScore(int vel, bool wait){
    Lift.rotateTo(.5, rev, vel, velocityUnits::pct, wait);
  }

  void lIdle(int vel, bool wait){
    Lift.rotateTo(.1, rev, vel, velocityUnits::pct, wait);
  }

