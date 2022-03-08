#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

void rightTest(){
  Brain.Screen.clearScreen();
  Brain.Screen.drawImageFromFile("ham.png", 240, 0);
  driveBase.driveFor(fwd, 24, distanceUnits::in);
  driveBase.turnToHeading(180, rotationUnits::deg);
  driveBase.driveFor(fwd, 24, distanceUnits::in);
  Brain.Screen.drawImageFromFile("ham.png", 240, 0);
  //Brain.Screen.drawImageFromFile("test1.png", 100, 100);
}

void right20(){
  Brain.Screen.drawImageFromFile("Alan.png", 0, 0);
  auton = true; // is to actavate line sen only in  auton
  cOn = false;
  driveBase.setDriveVelocity(200, percent); // set the speed of robot (speed up robot)
  driveBase.driveFor(forward, 40, inches); // drive twards the mgoal
  driveBase.setDriveVelocity(50, percent); // manule pid
  driveBase.driveFor(forward, 7, inches,false); // this is so make the robot not nock the mgoal away
  line1.changed(AclampOn);
  waitUntil(cOn == true); // wait till clamp is closed by line sen
  driveBase.setDriveVelocity(200, percent); // set drive speed
  Lift.setVelocity(100, percentUnits::pct);
  Lift.rotateTo(.1, rotationUnits::rev);
  driveBase.driveFor(reverse, 34, inches); // drive backwards
  driveBase.turnToHeading(270, rotationUnits::deg);
  bLDown();
  driveBase.driveFor(forward, 8, inches);
  auton = false;
  clampOff();
  wait(300, msec);
  //---------------------------------------------------------//
  // Start of Block 2// score aMGoal  line up on next nutral mGoal and ATEMP to
  // grab next mGaol
  driveBase.setDriveVelocity(60, percentUnits::pct);
  driveBase.driveFor(forward, 6, inches);
  driveBase.setDriveVelocity(20, percentUnits::pct);
  driveBase.driveFor(reverse, 23, inches);
  bLDown();
  waitUntil(bL.value() == true);
  pringle.spin(directionType::rev, 100, velocityUnits::pct);
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);
  driveBase.turnToHeading(0, rotationUnits::deg);
  cOn = false;

}