/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorLf              motor         1               
// MotorLb              motor         2               
// MotorRf              motor         14              
// MotorRb              motor         15              
// Clamp1               motor         7               
// Lift1                motor         11              
// bL1                  motor         18              
// Gyro                 inertial      9               
// line1                line          A               
// pringle              motor         12              
// bLR                  rotation      10              
// bL2                  motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
//Key:
// Amgoal = Alliance moble goal 
// Nmgoal = Nutrual moble goal
// DNW/DNU = Does Not Work or Did Not Use
// bL = backLift
// teleop = driver/user control

#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

using namespace vex;

//--------------------------------------------------- Groups ---------------------------------------------------------//
 competition Competition;
 motor_group leftDrive(MotorLf,MotorLb);// group for the left side 
 motor_group rightDrive(MotorRf,MotorRb);// group for the right side 
 motor_group bL(bL1,bL2);// group for back Lift (bL)
 motor_group all(bL1,bL2,Lift1, Clamp1);// used for testing DNU
 smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);
 //^all drive motors including the Intergral sensor to simplfy auton and have acurate turring
//--------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ Global Vars ------------------------------------------------------//
 bool sM = true;// used to make the scoring macro repeat DNU
 bool auton = true;// was used to trigger line sensor in auton DNU for solo awp
 bool clampOn = false;// used to have the robot to wait for the clamp close in auton 
 bool RobotIsWorking = false;// to always make sure the robot is working 
 int Pring = 0;// used to turn off and on the pringle intake 
 int allTemp[2][8] ={{0,0,0,0,0,0,0,0},{1,2,14,15,7,11,12,18}};// 2d area to log motor temps and their port #
 bool bLD= false;// used to state the whether the backLift is down(true) or up(false)| backLift up at start
//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------- voids ---------------------------------------------------------//
  void pringON(){
    // use Pring like a bool 0 being false, 1 true
    if (Pring >= 1){ // if pring = 1 or more set it to 0(false)
      Pring  = 0;
    }
    else if (Pring < 1){// if pring less than 1 set it to 1(true)
       Pring = 1;
    }
    else{// set to 0(false) by defualt 
      Pring = 0;
    }
    
  }
  void clamp1On(){ // rotate the clamp to close it 
   Clamp1.setVelocity(100, percent);
   
    Clamp1.rotateTo(-.65, rev, true);
    
    Clamp1.stop(hold);
    
  }
  void Aclamp1On(){
   while (auton == true && clampOn == false) {// only runs during auton (when auton = true) and when the clamp is open (clamOn = false)
    if (line1.value(percentUnits::pct) <= 68) {// if mgoal is in range closes the clamp when the line sen is closed enough the mgoal in order to clamp
      //^ this value is fine tuned so it is reliable 
      Clamp1.rotateTo(-.6, rotationUnits::rev, 100, velocityUnits::pct, false);// closes the clamp so that it grips the mgoal
      // std::cout<<Clamp1.position(rev)<<std::endl;
      waitUntil(Clamp1.position(rev) <= -.52);// waits for the clamp to be mostly closed 
      clampOn = true;// sets the state of the clamp to closed (clampOn = true)
      Clamp1.stop(hold);// applies a breack that resistes movement to grip mgoal
      break;// exit loop
    } else if (line1.value(percentUnits::pct) > 68) {// if no mgoal in range
      for (int i = 0; i < 3; i++) {// runs 3 times
        driveBase.setDriveVelocity(5, velocityUnits::pct);// sets the velocity low 
        driveBase.drive(fwd);// makes the robo creep forward until either mgoal is in range or it runs for 3 itterations 
        if (clampOn == true) {// if the clamp is closed (clampOn = true)
          break;// exit loop
        }
      }
    }
  }
}
    

    

  
  void clamp1Off(){// rotate the clamp to open it 
    Clamp1.setVelocity(100,percent);
   
    Clamp1.rotateTo( -.1, rev, false);// not set to 0 to avoid over turning 
    waitUntil(Clamp1.isDone());
    clampOn = true;// DNU 
    Clamp1.stop();
   
  }
  void bLReset(){// bring backLift all the way up only used in teleop
    bL1.rotateTo(0, rotationUnits::rev, 100, velocityUnits::pct, false);


  }
  
  //voids to set macros for lift 
  void liftUp(){
    
    if(Lift1.position(rev) < 1.35){
       Lift1.setVelocity(200, percent);
       //Lift1.spinFor(forward, 2, rev);
       Lift1.rotateTo(1.35, rev,false);
       

    }
    else if (Controller1.ButtonR1.pressing() && Lift1.position(rev) >= 1.35){
       Lift1.setVelocity(200, percent);
        //Lift1.spinFor(forward, 2, rev);
        Lift1.rotateTo(2, rev,false);
        
    }
    else {
     
    }
  }
  void liftDown(){
    if(Lift1.position(rev) <= 2){
       Lift1.setVelocity(200, percent);
       //Lift1.spinFor(forward, 2, rev);
       Lift1.rotateTo(0, rev,false);
    }
    else if (Controller1.ButtonR2.pressing() && Lift1.position(rev) > 1.35){
       Lift1.setVelocity(200, percent);
        //Lift1.spinFor(forward, 2, rev);
        Lift1.rotateTo(1.35, rev,false);
    }
    else { }
  }
  void deScore() {
     //lift.spinFor(fwd, 13, inches, 100, velocityUnits::pct);
     Lift1.rotateTo(.9, rotationUnits::rev, 100, velocityUnits::pct, false);
   }
  void bLDown(){//down 
    bL.setVelocity(200, percent);
    if(bLR.position(rev) < 2.3){
       //Lift1.spinFor(forward, 2, rev);
       bL.rotateTo(-3.2, rev,false);
    }
    else if (Controller1.ButtonDown.pressing() && bLR.position(rev) >= 1 && bL1.isDone()){
        //Lift1.spinFor(forward, 2, rev);
        bL.rotateTo(-4.8,rev, false);
    }
    else {
       
     }
    
  }
  void bLUp(){//up
   bL.setVelocity(200, percent);
   if(bLR.position(rev) > 2){
       //Lift1.spinFor(forward, 2, rev);
       bL.rotateTo(-3.2, rev,false);
    }
    else if (Controller1.ButtonUp.pressing() && bLR.position(rev) < 1 && bL1.isDone()){
        //Lift1.spinFor(forward, 2, rev);
        bL.rotateTo(0, rev,false);
    }
    else {
      bL1.stop(hold);
    }
  }
  void resetAll(){
     all.rotateTo(0, rev, 100, velocityUnits::pct, true);
     all.stop();
     Controller1.Screen.print(green);
     Brain.Screen.clearScreen();
     Brain.Screen.print(white);

  }
  void score_macro () {
     // lower lift 1 step
     sM = true;
     Lift1.rotateTo(.9, rotationUnits::rev, 100, velocityUnits::pct, false);
   
     // open claw
     clamp1Off();
     waitUntil(Clamp1.isDone());

     // reset lift to full height
     liftUp();
   }
   void sMSet (){
     sM = false;
 
   }

   void turnTo(int A){
     rightDrive.spin(forward);
     rightDrive.spin(reverse);
     // Waits until the motor reaches a 90 degree turn and stops the Left and
     // Right Motors.
     waitUntil((Gyro.rotation(degrees) >= A));
     leftDrive.stop();
     rightDrive.stop();
     wait(1, seconds);


   }

    

//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                          Pre-Autonomous Functions                         //
//---------------------------------------------------------------------------//

 void pre_auton(void) {
   // Initializing Robot Configuration. DO NOT REMOVE!
   vexcodeInit();
   Gyro.calibrate();
    while(Gyro.isCalibrating()){
        wait(100, msec);
        Brain.SDcard.loadfile("calb.png", 0, 5);
        Brain.Screen.drawImageFromFile("calb.png", 0, 0);
    }
  
    Gyro.resetHeading(); // to set gyro 0 if not already
    Gyro.resetRotation();
   // All activities that occur before the competition starts
   // Example: clearing encoders, setting servo positions, ...
 }
//---------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//                              Autonomous Task                               //
//                                  2 Points                                  //
//                                 Win Point                                  //
//----------------------------------------------------------------------------//

 void autonomous(void) {
    auton = true; // is to activate line sensor only in  auton
    clampOn = false;// reps the state of the clamp (false = open & true = closed)
    //DRIVES UNTIL TALL NEUTRAL
    driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
    //driveBase.driveFor(forward, 75.4, inches); entire distance to middle goal
    driveBase.driveFor(forward, 69.420, inches); //fr the math works out to be around 69.4 inches
    driveBase.setDriveVelocity(25, percent);
    driveBase.driveFor(forward, 5.98, inches);

    //CLAMPS TALL NEUTRAL + LIFTS IT
    line1.changed(Aclamp1On);
    waitUntil(clampOn);// wait till clamp is closed by line sen
    Clamp1.stop(hold);//stop the Clamp
    Lift1.setVelocity(50, percentUnits::pct);
    Lift1.spinFor(.2, rev, false);


    //DRIVING TO RIGHT-SIDE ALLIANCE 
    driveBase.setDriveVelocity(100, percent);
    driveBase.driveFor(reverse, 45.4, inches);
    //no manual pid included here, may need to change later if overshooting occurs
    driveBase.turnToHeading(-45, rotationUnits::deg);
    bL.rotateTo(-4.8, rev, 100 , velocityUnits::pct);
    driveBase.driveFor(reverse, 35.2, inches); //switch to 35.4 if needed

    //doing wp - practically copied straight from right side 20p
    bL.setVelocity(100, percentUnits::pct);
    bL.rotateTo(-3.2,rev, false);
    waitUntil(bL.position(rotationUnits::rev) >= -3.3);
    pringle.spin(directionType::rev, 100, velocityUnits::pct);
    pringle.spinFor(reverse, 1.5, sec, 200, velocityUnits::pct);
    driveBase.turnToHeading(0, rotationUnits::deg);
    clampOn = false;

    //dont know why this is needed but kept it here just in case tbh
    Clamp1.setVelocity(100, percent);// set Clamp speed 
    auton = false;
    clamp1Off();
    wait(300, msec);
 }
//---------------------------------------------------------------------------// }

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//
 
 void usercontrol(void) {
   // User control code here, inside the loop
   auton = false;
   clampOn = false;
   Pring = 0;
   while (1) {
    Brain.Screen.drawImageFromFile("T.bmp", 20,20);
    
    
    std::cout<<Controller1.Axis3.value()<<std::endl;
    //have gyro print position for auton
   // Brain.Screen.clearScreen();
   // Brain.Screen.printAt(20, 80, "gyro (degrees)");
   // Brain.Screen.printAt(20, 120, "Reading =%f");
    if (RobotIsWorking == false){
      RobotIsWorking = true;
    }
     // this stops the robot for tokoy driting 
     float x = 0;
     float y = 0;
     if (Controller1.Axis3.position(pct) <= 10 && Controller1.Axis3.position(pct) >= -10) {
       x = 0;
     }
     else{
       x = Controller1.Axis3.position(pct);
     }
     if (Controller1.Axis2.position(pct) < 10 && Controller1.Axis2.position(pct) > -10) {
       y = 0;  
     
     }
     else {
       y = Controller1.Axis2.position(pct);
     }
     

       leftDrive.spin(directionType::fwd, x , velocityUnits::pct); 
       rightDrive.spin(directionType::fwd, y , velocityUnits::pct);
    
  

     if (sM == false){
       score_macro();

     }
     else{
       sM = true;

     }

     if (Pring == 1){
       
       //std::cout<<"Pring On"<<std::endl;
       pringle.spin(reverse, 200, velocityUnits:: pct); 
       if (Lift1.position(rotationUnits::rev) < .5){
          Lift1.setVelocity(100, percentUnits::pct);
          Lift1.rotateTo(.5, rev, false);
        }
        else if (pringle.isDone() && Lift1.position(rotationUnits::rev) < .5 ){
          Lift1.rotateTo(0, rev, false);
        }
        else {}

     }
     else{
       //std::cout<<"Pring Off"<<std::endl;
        pringle.stop(); 
     }
     
     //call back to run a void when button is presed 
       //Controller1.ButtonB.pressed(tankFwd);
       Controller1.ButtonL2.pressed(clamp1On);
       Controller1.ButtonL1.pressed(clamp1Off);
       Controller1.ButtonR1.pressed(liftUp);
       Controller1.ButtonR2.pressed(liftDown);
       Controller1.ButtonUp.pressed(bLUp);
       Controller1.ButtonDown.pressed(bLDown);
       Controller1.ButtonA.pressed(sMSet);
       Controller1.ButtonB.pressed(deScore);
       Controller1.ButtonLeft.pressed(pringON);
       Controller1.ButtonRight.pressed(bLReset);
       
       
    wait(20, msec); // Sleep the task for a short amount of time to
                     // prevent wasted resources.
   }
 
 }

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
