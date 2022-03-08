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