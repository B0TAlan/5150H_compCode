#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>


void left20(){
  driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
  driveBase.driveFor(40,inches);
  driveBase.setDriveVelocity(20, velocityUnits::pct);//set the speed of robot (slow down robot)
  driveBase.driveFor(10,inches);
  //line1.changed(AclampOn);
  Clamp.set(true);
  //waitUntil(cOn == true);
  Lift.rotateTo(.15, rotationUnits::rev, 100, velocityUnits::pct,false);
  driveBase.setDriveVelocity(40, percent);//set the speed of robot (speed up robot)
  driveBase.driveFor(-35,inches);
  //clampOff();
 //waitUntil(cOn == false);
  //driveBase.driveFor(3,inches,false);
  //driveBase.turnToHeading(375, rotationUnits::deg);
  //driveBase.driveFor(-3,inches,false);
  driveBase.turnToHeading(312, rotationUnits::deg);
  driveBase.setDriveVelocity(20, velocityUnits::pct);//set the speed of robot (slow down robot)
  driveBase.driveFor(-8,inches);
  pringle.spin(reverse, 100, velocityUnits::pct);


}