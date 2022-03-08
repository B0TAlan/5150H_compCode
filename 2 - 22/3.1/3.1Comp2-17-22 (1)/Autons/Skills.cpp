#include "vex.h"
#include "ClassHeader.h"


void Skills(){
  Clamp.set(false); 
  //driveBase.driveFor(fwd, 8, distanceUnits::in, 20, velocityUnits::pct);
  Clamp.set(true);
    driveBase.driveFor(fwd, 6, distanceUnits::in, 30, velocityUnits::pct);
    Lift.rotateTo( 2, rev, 100, velocityUnits::pct);// waits until lift raises to .5 revs to raise the lift over the Amgola
    //driveBase.driveFor(fwd, 3, inches, 30, velocityUnit::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    driveBase.turnToHeading(94, rotationUnits::deg);
    bL.set(false);
    driveBase.driveFor(fwd, -50, inches, 40, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
    driveBase.driveFor(fwd, -14, inches, 10, velocityUnits::pct);// slows down to not bump the Ngoal
    bL.set(false);
    //Lift1.rotateTo(.5, rev,90, velocityUnits::pct, false);
    driveBase.turnToHeading(311, rotationUnits::deg);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(50, inches, 45, velocityUnits::pct);
    driveBase.turnToHeading(270, rotationUnits::deg);
    lScore(100, true);
    wait(1500, msec);
    Clamp.set(false);
    Lift.rotateTo(1.35, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(fwd, -10, distanceUnits::in, 30, velocityUnits::pct);
    Lift.rotateTo(2, rotationUnits::deg, 100, velocityUnits::pct, false);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 30, velocityUnits::pct);
    driveBase.turnToHeading(191, rotationUnits::deg);
    Clamp.set(false);
    driveBase.driveFor(fwd, 44, distanceUnits::in, 50, velocityUnits::pct);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 20, velocityUnits::pct, false);
    Clamp.set(true);
   // Lift1.rotateTo(1.35, rev,90, velocityUnits::pct, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    driveBase.driveFor(fwd, 10, distanceUnits::in, 60, velocityUnits::pct);

}