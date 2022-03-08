#include "MasterClass.h"
//#include "MasterHeader.h"
#include "vex.h"



void rightMid() {
  // DRIVES UNTIL TALL NEUTRAL
  Clamp.set(false);
  driveBase.setDriveVelocity(
      100, percent); // set the speed of robot (speed up robot)
  // driveBase.driveFor(forward, 75.4, inches); entire distance to middle goal
  driveBase.driveFor(forward, 67.420,
                     inches); // fr the math works out to be around 69.4 inches
  driveBase.setDriveVelocity(25, percent);
  driveBase.driveFor(forward, 6.98, inches);

  // CLAMPS TALL NEUTRAL + LIFTS IT
  Clamp.set(true);
  // waitUntil(cOn);// wait till clamp is closed by line sen
  Lift.setVelocity(100, percentUnits::pct);
  // waitUntil(cOn);
  Lift.rotateTo(.1, rotationUnits::rev, false);

  // DRIVING TO RIGHT-SIDE ALLIANCE
  driveBase.setDriveVelocity(100, percent);
  driveBase.driveFor(reverse, 55, inches);
  /*no manual pid included here, may need to change later if overshooting occurs
  //driveBase.turnToHeading(45, rotationUnits::deg);
  bLUp();
  driveBase.driveFor(reverse, 35.2, inches); //switch to 35.4 if needed

  //doing wp - practically copied straight from right side 20p
  bLDown();
  //waitUntil(bL.position(rotationUnits::rev) >= -3.3);
  pringle.spin(directionType::rev, 100, velocityUnits::pct);
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);
  driveBase.turnToHeading(0, rotationUnits::deg);
  cOn = false;

  //dont know why this is needed but kept it here just in case tbh

  auton = false;
  clampOff();
  wait(300, msec);*/
}

void right20() {
  Clamp.set(false);
  aB.Open();
  driveBase.setDriveVelocity(
      200, percent); // set the speed of robot (speed up robot)
  driveBase.driveFor(forward, 40, inches); // drive twards the mgoal
  driveBase.setDriveVelocity(50, percent); // manule pid
  driveBase.driveFor(
      forward, 10, inches,
      false); // this is so make the robot not nock the mgoal away
  Clamp.set(true);
  // waitUntil(cOn == true); // wait till clamp is closed by line sen
  driveBase.setDriveVelocity(70, percent); // set drive speed
  Lift.setVelocity(100, percentUnits::pct);
  Lift.rotateTo(.2, rotationUnits::rev, false);
  driveBase.driveFor(reverse, 32, inches); // drive backwards
  driveBase.turnToHeading(255, rotationUnits::deg);
  // bLDown();
  // driveBase.driveFor(forward, 8, inches);
  aC.Open();
  wait(300, msec);
  //---------------------------------------------------------//
  // Start of Block 2// score aMGoal  line up on next nutral mGoal and ATEMP to
  // grab next mGaol
  driveBase.setDriveVelocity(60, percentUnits::pct);
  driveBase.driveFor(forward, 6, inches);
  Lift.rotateTo(.2, rotationUnits::rev, false);
  driveBase.setDriveVelocity(20, percentUnits::pct);
  driveBase.driveFor(reverse, 26, inches);
  aB.Close();
  // waitUntil(bL.value() == true);
  pringle.spin(directionType::rev, 100, velocityUnits::pct);
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);

  driveBase.turnToHeading(0, rotationUnits::deg);
  // driveBase.driveFor(fwd, 10, inches, 40, velocityUnits::pct);
}