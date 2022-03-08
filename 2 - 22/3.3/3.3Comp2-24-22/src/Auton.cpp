#include "vex.h"
#include "Classes.h"

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

void rightMid() {
  // DRIVES UNTIL TALL NEUTRAL
  Clamp.set(false);
  driveBase.setDriveVelocity(
      100, percent); // set the speed of robot (speed up robot)
  // driveBase.driveFor(forward, 75.4, inches); entire distance to middle goal
  driveBase.driveFor(forward, 67.420, inches); // fr the math works out to be around 69.4 inches
  driveBase.setDriveVelocity(25, percent);
  driveBase.driveFor(forward, 10.98, inches);

  // CLAMPS TALL NEUTRAL + LIFTS IT
  Clamp.set(true);
  // waitUntil(cOn);// wait till clamp is closed by line sen
  Lift.setVelocity(100, percentUnits::pct);
  // waitUntil(cOn);
  

  // DRIVING TO RIGHT-SIDE ALLIANCE
  driveBase.setDriveVelocity(100, percent);
  driveBase.driveFor(reverse, 54, inches);
  
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
  aB.OF();
  driveBase.setDriveVelocity(200, percent); // set the speed of robot (speed up robot)
  driveBase.driveFor(forward, 40, inches); // drive twards the mgoal
  driveBase.setDriveVelocity(50, percent); // manule pid
  driveBase.driveFor(forward, 10, inches,false); // this is so make the robot not nock the mgoal away
  Clamp.set(true);
  // waitUntil(cOn == true); // wait till clamp is closed by line sen
  driveBase.setDriveVelocity(70, percent); // set drive speed
  Lift.setVelocity(100, percentUnits::pct);
  Lift.rotateTo(.2, rotationUnits::rev, false);
  driveBase.driveFor(reverse, 32, inches); // drive backwards
  driveBase.turnToHeading(255, rotationUnits::deg);
  // bLDown();
  // driveBase.driveFor(forward, 8, inches);
  aC.OF();
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

void Skills(){
  aL.setPos(0);// reset lift
  aC.Open(); // open clamp
  driveBase.driveFor(fwd, 8, distanceUnits::in, 20, velocityUnits::pct);// drives twords first mgoal
  aC.Cloes();// clamps the mgoal
  aL.ClearWall(100, true);// raises the lift and mgoal over the wall allowing it to turn 
  driveBase.turnToHeading(93, rotationUnits::deg);// turn to aline with next mgoal
  bL.set(true);// makes sure the back lift is open
  driveBase.driveFor(fwd, -20, inches, 15, velocityUnits::pct);// drives tworads Nmgoal to grab it with bL
  aL.Min(100, true);// lowers the lift 
  driveBase.turnToHeading(90, rotationUnits::deg);
  driveBase.driveFor(fwd, -30, inches, 30, velocityUnits::pct);// drives twords the mgoal
  driveBase.driveFor(fwd, -14, inches, 10, velocityUnits::pct);// slows down to have magoal slide into back lift 
  aB.Close();// cloese back lift 
  aL.Idle(100, true);// raises the lift so the mgoal doent drag agenst the ground
  driveBase.turnToHeading(311, rotationUnits::deg);// turns twoards platform 
  Lift.rotateTo(1.3, rev,90, velocityUnits::pct, false);// raises the lift to be able to score
  driveBase.driveFor(52, inches, 25, velocityUnits::pct);// drives tworads platform
  driveBase.driveFor(5, inches, 5, velocityUnits::pct);// makes sure clamp is over 
  aL.Score(100, true);// lowers the lift to make sure the platform is balenced 
  wait(500, msec);// waits to the robo doesn't get caught on platform
  aC.Open();// open clamp to balnace mgoal 
  Lift.rotateTo(1.35, rev,40, velocityUnits::pct, false);
  driveBase.driveFor(fwd, -20, distanceUnits::in, 30, velocityUnits::pct);
  aL.Min(100, true);
  driveBase.driveFor(fwd, 10, distanceUnits::in, 30, velocityUnits::pct);
  driveBase.turnToHeading(191, rotationUnits::deg);
  aB.Open();
  aC.Open();
  //----------------------------------------------------------------------//
  driveBase.driveFor(fwd, 36, distanceUnits::in, 30, velocityUnits::pct);
  driveBase.driveFor(fwd, 5, distanceUnits::in, 10, velocityUnits::pct, false);
  aC.Cloes();
  driveBase.driveFor(fwd, -15, distanceUnits::in, 60, velocityUnits::pct);
  aL.Idle(100, true);
  driveBase.turnToHeading(217, rotationUnits::deg);
  driveBase.driveFor(fwd, -34, distanceUnits::in, 30, velocityUnits::pct);
  //aL.Min(100, false);
  driveBase.driveFor(fwd, -15, distanceUnits::in, 15, velocityUnits::pct);
  aB.Close();
  driveBase.driveFor(fwd, -80, distanceUnits::in, 15, velocityUnits::pct);
  aB.Open();
  driveBase.driveFor(fwd, 6, distanceUnits::in, 15, velocityUnits::pct);
  driveBase.turnToHeading(122, rotationUnits::deg);
  //aL.ClearWall(100, true);
  driveBase.driveFor(fwd, -10, distanceUnits::in, 15, velocityUnits::pct);
  aB.Close();
  driveBase.turnToHeading(180, rotationUnits::deg);
  driveBase.driveFor(fwd, 44, distanceUnits::in, 30, velocityUnits::pct);
  driveBase.turnToHeading(135, rotationUnits::deg);
  aC.Open();

}

void Awp(){
  Pid.Drive(24, .1, .0001, .02);
}

void NoTon(){
  
}