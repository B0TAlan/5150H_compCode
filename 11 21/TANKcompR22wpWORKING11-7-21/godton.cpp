#include "vex.h"
#include"main.cpp"

/*/////////////////////
  //Sart of BLock 1 // grab the first nutral mGoal linup for 
   // set bL and reset the sensors 
   vexcodeInit();
   bL.setVelocity(100, percent);
   bL.spinFor(-1.75,rev);
   resetbL();
   driveBase.setDriveVelocity(200, percent);//set the speed of robot (speed up robot)
   driveBase.driveFor(forward, 38, inches);// drive 43 inches forward to closed distance between robot and mGoal
   driveBase.setDriveVelocity(15, percent);// slow down 
   driveBase.driveFor(forward, 6, inches);// drive 10 inches forward (i inch form mGaol)
   //driveBase.setDriveVelocity(15, percent);// slow down
   //driveBase.driveFor(forward, 1, inches);//move slowly to have mGoal line up with Clamp1
   Clamp1.setVelocity(200, percent); // set Clamp velocity 
   Clamp1.spinFor(-1.1 ,rev); //manual close Clamp
   Clamp1.stop(brake);//stop the Clamp
   driveBase.setDriveVelocity(200, percent);// set drive speed 
   driveBase.driveFor(reverse, 35.5, inches);// drive backwards 
   //leftDrive.spinFor(reverse, 1, rev);
   driveBase.turnFor(-90, degrees);// 43 = 90 degrees ish due demisinons of drive base are wrong
   Clamp1.setVelocity(200, percent);// set Clamp speed 
   Clamp1.spinFor(1.1 ,rev); //manula open lift 
   //driveBase.setDriveVelocity(15, percent);// slow down the robot 
   //driveBase.driveFor(reverse, 1, inches);// nudge mGoal in Clamp1
   //driveBase.setDriveVelocity(5, percent);
   // driveBase.driveFor(forward, 1, inches);// ^
  ///////////////////////////////////////////////////
  //Start of Block 2// score aMGoal  line up on next nutral mGoal and ATEMP to grab next mGaol
   driveBase.setDriveVelocity(100, percent);//set dive speed 
   driveBase.driveFor(4, inches);// move 4 inches to lower bL 
   Clamp1.setVelocity(200, percent);// make clamp zoom
   bL.spinFor(-1.75, rev);// lower bL
   driveBase.driveFor(-12, inches);// 
   bL.setVelocity(200, percent);
   //bLoUp();
   // bLrabDown();
   driveBase.setDriveVelocity(200, percent);
   driveBase.turnFor(43, degrees);
   driveBase.driveFor(7, inches);
   bLoUp();
   Clamp1.setVelocity(200, percent);
   driveBase.turnFor(-28, degrees);
   //Clamp1.spinFor(1.1 ,rev);
   //driveBase.turnFor(-70, degrees);
  ////////////////////////////////*/
  /*Start of Block 3 // atamept the the nutral Mgoal and scroe then park for telop
  /////////////////////////////////////
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(40, inches);
   driveBase.setDriveVelocity(20, percent);
   driveBase.driveFor(16, inches);
   clamp1On();
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(-45, inches);
   driveBase.turnFor(60, degrees);
   driveBase.driveFor(-25, inches);
   /////////////////////////////////////////*/
   //dead auton
   //clamp1Off();
   /*driveBase.setDriveVelocity(200, percent);
     driveBase.driveFor(44, inches);
     driveBase.setDriveVelocity(15, percent);
     driveBase.driveFor(3, inches);
     driveBase.setDriveVelocity(15, percent);
     driveBase.driveFor(1, inches);
     Clamp1.setVelocity(200, percent);
     Clamp1.spinFor(-1.1 ,rev);
     bLoUp();
     driveBase.setDriveVelocity(200, percent);
     driveBase.driveFor(-44, inches);*/