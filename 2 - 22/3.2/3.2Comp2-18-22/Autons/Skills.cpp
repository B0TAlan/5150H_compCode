#include "vex.h"
#include "MasterHeader.h"
#include "MasterClass.h"


void Skills(){
  aL.setPos(0);
  aC.Open(); 
  driveBase.driveFor(fwd, 8, distanceUnits::in, 20, velocityUnits::pct);
  aC.Cloes();
    //driveBase.driveFor(fwd, 6, distanceUnits::in, 30, velocityUnits::pct);
    aL.ClearWall(100, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    //driveBase.driveFor(fwd, 3, inches, 30, velocityUnit::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    
    driveBase.turnToHeading(92, rotationUnits::deg);
    bL.set(false);
    driveBase.driveFor(fwd, -20, inches, 15, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
    aL.Min(100, true);
    driveBase.driveFor(fwd, -30, inches, 30, velocityUnits::pct);
    driveBase.driveFor(fwd, -14, inches, 10, velocityUnits::pct);// slows down to not bump the Ngoal
    bL.set(true);
    //Lift1.rotateTo(.5, rev,90, velocityUnits::pct, false);
    aL.Idle(100, true);
    driveBase.turnToHeading(311, rotationUnits::deg);
    Lift.rotateTo(1.3, rev,90, velocityUnits::pct, false);
    driveBase.driveFor(52, inches, 25, velocityUnits::pct);
    //driveBase.turnToHeading(270, rotationUnits::deg);
    driveBase.driveFor(5, inches, 5, velocityUnits::pct);
    aL.Score(100, true);
    wait(1500, msec);
    Clamp.set(false);
    Lift.rotateTo(1.35, rev,40, velocityUnits::pct, false);
    driveBase.driveFor(fwd, -20, distanceUnits::in, 30, velocityUnits::pct);
    aL.Min(100, true);
    driveBase.driveFor(fwd, 10, distanceUnits::in, 30, velocityUnits::pct);
    driveBase.turnToHeading(186, rotationUnits::deg);
    aB.Open();
    Clamp.set(false);
    driveBase.driveFor(fwd, 40, distanceUnits::in, 30, velocityUnits::pct);
    driveBase.driveFor(fwd, 5, distanceUnits::in, 10, velocityUnits::pct, false);
    Clamp.set(true);
   // Lift1.rotateTo(1.35, rev,90, velocityUnits::pct, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    driveBase.driveFor(fwd, -15, distanceUnits::in, 60, velocityUnits::pct);
    aL.Idle(100, true);
    driveBase.turnToHeading(215, rotationUnits::deg);
    driveBase.driveFor(fwd, -34, distanceUnits::in, 30, velocityUnits::pct);
    aL.Min(100, true);
    driveBase.driveFor(fwd, -15, distanceUnits::in, 15, velocityUnits::pct);
    aB.Close();
    driveBase.driveFor(fwd, -84, distanceUnits::in, 15, velocityUnits::pct);
    driveBase.turnToHeading(180, rotationUnits::deg);



}