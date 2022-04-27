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
  aL.setPos(0);
  aC.OF();
  aB.OF();
  //driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
  driveBase.driveFor(37,inches, 200, velocityUnits::pct);
  //set the speed of robot (slow down robot)
  driveBase.driveFor(6,inches, 30, velocityUnits::pct);
  //line1.changed(AclampOn);
  aC.CF();
  //waitUntil(cOn == true);
  driveBase.driveFor(-40,inches, 65, velocityUnits::pct);
  //clampOff();
 //waitUntil(cOn == false);
  //driveBase.driveFor(3,inches,false);
  //driveBase.turnToHeading(375, rotationUnits::deg);
  //driveBase.driveFor(-3,inches,false);
  //Pid.Turn(310, .45);
  driveBase.setDriveVelocity(20, velocityUnits::pct);//set the speed of robot (slow down robot)
  driveBase.driveFor(-6,inches);
  aL.Idle(100, true);
  pringle.spin(reverse, 100, velocityUnits::pct);


}

void rightMid() {
  aC.OF();
  aB.OF();
  //Pid.Turn(323, .45);
  driveBase.driveFor(48, inches, 100, velocityUnits::pct);
  aL.Min(100, true);
  driveBase.driveFor(7, inches, 50, velocityUnits::pct);
  aC.CF();
  driveBase.driveFor(-48, inches, 100, velocityUnits::pct);
  pringle.spinFor(reverse, .5, rotationUnits::rev, 100, velocityUnits::pct);
  //Pid.Turn(258, .45);
  driveBase.driveFor(-18, inches, 100);
  aB.CF();
  pringle.spin(reverse, 100, velocityUnits::pct);
  wait(1000, msec);
  pringle.stop();
  //Pid.Turn(0, .45);
  driveBase.driveFor(reverse, 3, inches, 25, velocityUnits::pct);
  aB.OF();
  driveBase.driveFor(reverse, 3, inches, 25, velocityUnits::pct);
  /* DRIVES UNTIL TALL NEUTRAL
  Clamp.set(false);
  driveBase.setDriveVelocity(100, percent); // set the speed of robot (speed up robot)
  // driveBase.driveFor(forward, 75.4, inches); entire distance to middle goal
  driveBase.driveFor(forward, 67.420, inches); // fr the math works out to be around 69.4 inches
  driveBase.setDriveVelocity(25, percent);
  driveBase.driveFor(forward, 10.98, inches);

  // CLAMPS TALL NEUTRAL + LIFTS IT
  Clamp.set(true);
  // waitUntil(cOn);// wait till clamp is closed by line sen
  
  // waitUntil(cOn);
  

  // DRIVING TO RIGHT-SIDE ALLIANCE
  driveBase.setDriveVelocity(100, percent);
  driveBase.driveFor(reverse, 54, inches);
  
  no manual pid included here, may need to change later if overshooting occurs
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

void rightA() {
  aL.setPos(0);
  aC.OF();
  aB.OF();
  driveBase.setDriveVelocity(80, percent); // set the speed of robot (speed up robot)
  driveBase.driveFor(forward, 38, inches); // drive twards the mgoal
  driveBase.setDriveVelocity(40, percent); // manule pid
  driveBase.driveFor(forward, 8, inches,false); // this is so make the robot not nock the mgoal away
  aC.CF();
  // waitUntil(cOn == true); // wait till clamp is closed by line sen
  driveBase.setDriveVelocity(70, percent); // set drive speed
  //Lift.setVelocity(100, percentUnits::pct);
  
  driveBase.driveFor(reverse, 32, inches); // drive backwards
  
  driveBase.turnToHeading(245, rotationUnits::deg);
  // bLDown();
  // driveBase.driveFor(forward, 8, inches);
  aC.OF();
  wait(300, msec);
  //---------------------------------------------------------//
  // Start of Block 2// score aMGoal  line up on next nutral mGoal and ATEMP to
  // grab next mGaol
  //aL.Idle(80, false);
  driveBase.setDriveVelocity(60, percentUnits::pct);
  //driveBase.driveFor(forward, 6, inches);
  
  driveBase.setDriveVelocity(20, percentUnits::pct);
  driveBase.driveFor(reverse, 26, inches);
  aB.Close();
  // waitUntil(bL.value() == true);
  pringle.spin(directionType::rev, 100, velocityUnits::pct);
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);

  driveBase.turnToHeading(0, rotationUnits::deg);
  // driveBase.driveFor(fwd, 10, inches, 40, velocityUnits::pct);
}

void right20(){
  aL.setPos(0);
  aB.OF();
  aC.OF();
  aL.Min(100, false);
  driveBase.driveFor(fwd, 35, inches, 150, velocityUnits::pct);
  aL.Min(100, false);
  driveBase.driveFor(fwd, 5, inches, 30, velocityUnits::pct);
  aC.CF();
  driveBase.driveFor(reverse, 35, inches, 95, velocityUnits::pct);
  aL.Idle(100, true);
  pringle.spinFor(reverse, .5, rotationUnits::rev, 100, velocityUnits::pct);
  //Pid.Turn(248, .45);
  driveBase.driveFor(reverse, 13, inches, 25, velocityUnits::pct);
  aB.CF();
  pringle.spin(reverse, 100, velocityUnits::pct);
  wait(1000, msec);
  pringle.stop();
  //Pid.Turn(0, .45);
  driveBase.driveFor(reverse, 1, inches, 25, velocityUnits::pct);
  aB.OF();
  driveBase.driveFor(reverse, 3, inches, 25, velocityUnits::pct);
}

void right40(){
  driveBase.driveFor(40,inches, 100, velocityUnits::pct);      // drive for the nGoal
  aC.CF();                                                     // clamp the nGoal
  driveBase.driveFor(-12,inches, 80, velocityUnits::pct);      // drive back to line up with aGoal
  driveBase.turnToHeading(45, rotationUnits::deg);             // turn to line up with aGoal
  driveBase.driveFor(-5,inches);                               // drive back to clamp aGOal
  aB.CF();                                                     // clamp to aGoal
  pringle.spin(directionType::rev, 150, rpm);                  // put pringles on goal
}

void Skills(){
  aL.setPos(0);// reset lift
  aC.Open(); // open clamp
  driveBase.driveFor(fwd, 4, distanceUnits::in, 20, velocityUnits::pct);// drives twords blue mgoal
  aC.Cloes();// clamps the blue mgoal
  aL.ClearWall(100, true);// raises the lift and blue mgoal over the wall allowing it to turn 
  //Pid.Turn(90, .45);// turn to aline with yello mgoal
  bL.set(true);// makes sure the back lift is open
  driveBase.driveFor(fwd, -20, inches, 30, velocityUnits::pct);// drives tworads yello mgoal to grab it with bL
  aL.Idle(100, true);// lowers the lift to avoid tipping  
  //Pid.Turn(91, .45);// corrects its self
  driveBase.driveFor(fwd, -30, inches, 80, velocityUnits::pct);// drives twords the yello mgoal
  driveBase.driveFor(fwd, -14, inches, 30, velocityUnits::pct);// slows down to have yello magoal slide into back lift 
  aB.Close();// cloese back lift 
  aL.Idle(100, true);// raises the lift so a mgoal in the clamp doesn't drag agenst the ground
  //Pid.Turn(315, .45);// turns twoards platform 
  Lift.rotateTo(1.3, rev, 90, velocityUnits::pct, false);// raises the lift to be able to score
  driveBase.driveFor(44, inches, 70, velocityUnits::pct);// drives tworads platform
  //Pid.Turn(303, .3);
  //driveBase.driveFor(5, inches, 10, velocityUnits::pct);// makes sure clamp is over 
  aL.Score(100, true);// lowers the lift to make sure the platform is balenced 
  wait(500, msec);// waits to the robo doesn't get caught on platform
  aC.Open();// open clamp to balnace blue mgoal 
  Lift.rotateTo(1.35, rev,40, velocityUnits::pct, false);// raises lift to clear platform
  driveBase.driveFor(fwd, -21, distanceUnits::in, 30, velocityUnits::pct);// backs away from the platform
  aL.Min(100, true);// lowers lift to 0
  driveBase.driveFor(fwd, 10, distanceUnits::in, 30, velocityUnits::pct);// alines with next red mgoal 
  //Pid.Turn(190, .45);// rotates to face red mgoal
  aB.Open();// opens bL to drop yello mgoal
  aC.Open();// makes sure clamp is open
  //-----------------------------2nd part--------------------------------------//
  driveBase.driveFor(fwd, 36, distanceUnits::in, 60, velocityUnits::pct);// drives twords  red mgoal
  driveBase.driveFor(fwd, 3, distanceUnits::in, 25, velocityUnits::pct, false);// slows down in order to not crash
  aC.Cloes();// grabes mgoal
  driveBase.driveFor(fwd, -20, distanceUnits::in, 60, velocityUnits::pct);//dive back to aline with middle mgoal and to avoids pringles
  aL.Idle(100, true);// raises lift to idle height for smoother turning
  //Pid.Turn(221, .45);// turn twords middle mgoal
  driveBase.driveFor(fwd, -34, distanceUnits::in, 60, velocityUnits::pct);// drives twords the middle mgoal  
  //aL.Min(100, false);
  driveBase.driveFor(fwd, -15, distanceUnits::in, 35, velocityUnits::pct);// nessles middle mgoal into bL
  aB.Close();// close back lift 
  //Pid.Turn(226, .45);// self correct 
  driveBase.driveFor(fwd, -69, distanceUnits::in, 45, velocityUnits::pct);// drive back to put middle mgoal into the conner next to the blue mgoal
  //Pid.Turn(225, .45);
  driveBase.driveFor(fwd, -5, distanceUnits::in, 45, velocityUnits::pct);
  aB.Open();// releases middle mgoal in the conner
  driveBase.driveFor(fwd, 6, distanceUnits::in, 25, velocityUnits::pct);// moves out of the conner in order to get next blue mgoal
  //Pid.Turn(128, .45);// turns twords blue mgoal so its alines with bL 
  //aL.ClearWall(100, true);
  driveBase.driveFor(fwd, -12, distanceUnits::in, 25, velocityUnits::pct);// nessles blue mgoal into bL
  aB.Close();// close bL 
  driveBase.driveFor(fwd, 6, distanceUnits::in, 35, velocityUnits::pct);
  //Pid.Turn(182, .45);// turns to be parralle to the platform 
  driveBase.driveFor(fwd, 44, distanceUnits::in, 30, velocityUnits::pct);// drive until its around the middle of the mgoal
  aL.ClearWall(100, true);// raises the lift 
  //Pid.Turn(125, .45);// turns to put red mgoal on the plat form
  driveBase.driveFor(fwd, 8, distanceUnits::in, 15, velocityUnits::pct);// moves forward to make sure rd mgoal is ove the platform 
  aC.Open();// drops red mgoal balancing it
  driveBase.driveFor(reverse, 8, distanceUnits::in, 15, velocityUnits::pct);// backs away form the platform 
  aL.Min(100, true);// lowers the lift to 0
  //Pid.Turn(180, .45);// turns back parralle to the platform 
  driveBase.driveFor(reverse, 30, distanceUnits::in, 30, velocityUnits::pct);// drive back to aline with yello mgoal
  //Pid.Turn(270, .45);// turns to face yello mgoal
  driveBase.driveFor(fwd, 30, distanceUnits::in, 90, velocityUnits::pct);// drive twords yello mgoal 
  driveBase.driveFor(fwd, 14, distanceUnits::in, 40, velocityUnits::pct);// nessles yello mgoal in clamp
  aC.Cloes();// closes clamp
  //Pid.Turn(245, .45);
  //aL.Max(80, false);
  driveBase.driveFor(fwd, 15, distanceUnits::in, 30, velocityUnits::pct);
  //Pid.Turn(180, .45);


}

void Awp(){
   //Lineup ig: left side, facing left, bot around 8 inches away from the goal
  aB.Open();
  driveBase.driveFor(reverse, 8, distanceUnits::in, 30, velocityUnits::pct); //drive to left neutral
  aB.Close(); //clamp left neutral
  driveBase.turnToHeading(270, deg); //prepare drive to middle of alliance zone, back facing out
  aL.Idle(200, false); // prepare lift for ring intake
  driveBase.driveFor(reverse, 36, inches, 80, velocityUnits::pct); // drive to middle of alliance zone
  driveBase.turnToHeading(180, deg); // face towards right
  driveBase.driveFor(forward, 94-58.9, distanceUnits:: in, 80, velocityUnits::pct, false); //stops at the center of the field
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct); //begin ring intake
  //CHANGE TF OUT OF THIS ONE ABOVE - ITS A COMPLETE ESTIMATE THAT IS LIKELY INACCURATE AS HELL
  //Rings should run until the bot gets to the center of the field
  waitUntil(!(pringle.isSpinning()));
  driveBase.turnToHeading(90, deg); //face middle neutral
  aL.Min(100, true); //get ready to clamp
  aB.Open(); //drops the alliance hopefully with rings on it
  driveBase.driveFor(forward, 17.4, distanceUnits:: in, 30, velocityUnits::pct); //drives to the exact center of the field
  aC.CF(); //yoink
  /*Math Moment: 58.9^2 (length) + 29.2^2 (width) = 65.741 length  Angle to turn to = 26.37deg*/
  driveBase.turnToHeading(360 - 26.37, deg); //with neutral goal, move the bot to be able to clamp the right alliance
  driveBase.driveFor(reverse, 65.741-15, distanceUnits:: in, 80, velocityUnits:: pct); //drive to the right alliance
  driveBase.driveFor(reverse, 15, distanceUnits:: in, 25, velocityUnits:: pct); //drive slower to not knock it
  aB.Close(); //yoinks the right alliance
  aL.Idle(100, false); //prepares lift for ring intake
  driveBase.turnToHeading(90, degrees); //faces the L of rings
  driveBase.driveFor(forward, 30, distanceUnits:: in, 100, velocityUnits:: pct, false); //zooooms to get rings
  pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct); //ring intake while moving
  waitUntil(!(pringle.isSpinning()));
  driveBase.driveFor(reverse, 50, distanceUnits:: in, 100, velocityUnits:: pct); //zoooms all the way back to the corner, will prolly hit the alliance bot
}

void NoTon(){
  Pid.newPid(45, .04, .005, .01);
  Pid.newPid(-45, .02, .005, .01);
 // Pid.newPid(24, .03, .03);
  //Pid.customBalance(0, .1, .001, .05);
  ////Pid.Turn(90, .45);
  //driveBase.driveFor(fwd, 24, distanceUnits::in, 100, velocityUnits::pct);
  //driveBase.turnToHeading(90, degrees);
  //Pid.Drive(24, .01,.0000001, 0.1);
}