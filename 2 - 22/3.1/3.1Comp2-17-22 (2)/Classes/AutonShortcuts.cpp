#include "vex.h"

class LiftShortcuts{

  public:

  void Max(int vel, bool wait){
    Lift.rotateTo(2, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void Min(int vel, bool wait){
    Lift.rotateTo(0, rotationUnits::deg, vel, velocityUnits::pct, wait);
  }

  void score(int vel, bool wait){
    Lift.rotateTo(.5, rev, vel, velocityUnits::pct, wait);
  }

  void idle(int vel, bool wait){
    Lift.rotateTo(.1, rev, vel, velocityUnits::pct, wait);
  }
};

LiftShortcuts aL;
