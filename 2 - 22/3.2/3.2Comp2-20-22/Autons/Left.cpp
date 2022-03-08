#include "vex.h"

void leftMid() {
    //DRIVES UNTIL TALL NEUTRAL
    Clamp.set(false);
    driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
    //driveBase.driveFor(forward, 75.4, inches); entire distance to middle goal
    driveBase.driveFor(forward, 52.2115, inches); //this one goes to nearby the ring region

    //ADD THINGS FOR THE PRINGLE RUNNING HERE IDK WHERE THE THING TO SET THE LIFT IS
    Lift.rotateTo(.1, rotationUnits::rev, false);
    pringle.spin(directionType::rev, 100, velocityUnits::pct);

    driveBase.turnToHeading(31.095, rotationUnits::deg);

    driveBase.setDriveVelocity(40, percent);
    driveBase.driveFor(forward, 34.45, inches);

    //CLAMPS TALL NEUTRAL + LIFTS IT
    Clamp.set(true);
    //waitUntil(cOn);// wait till clamp is closed by line sen
    Lift.setVelocity(100, percentUnits::pct);
    //waitUntil(cOn);
    Lift.rotateTo(.1, rotationUnits::rev, false);


    //DRIVING TO RIGHT-SIDE ALLIANCE 
    driveBase.setDriveVelocity(100, percent);
    driveBase.turnToHeading(-31.095, rotationUnits::deg);
    driveBase.driveFor(reverse, 55, inches);

}

void left20(){
  Clamp.set(false);
  driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
  driveBase.driveFor(40,inches, 100, velocityUnits::pct);
  //set the speed of robot (slow down robot)
  driveBase.driveFor(10,inches, 30, velocityUnits::pct);
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