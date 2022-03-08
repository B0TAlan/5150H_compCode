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
 motor_group all(bL1,bL2,Lift1, Clamp1);
 smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);
//--------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ Gloabal Vars ------------------------------------------------------//
 int Forward = 2;
 bool resetDriveSensors = false;
 bool liftH1= false;
 bool liftH0 = false;
 bool sM = true;// used to make the scoring macro repeat 
 bool auton = true;// was used to trigger line sensor in auton (not needed)
 bool clampOn = false;// used to have the robot to wait for the clamp close in auton 
 bool setDS =true;// was to make 
 bool Arcade = false;
 bool RobotIsWorking = false;
 int Pring = 0;
 int Prong = 0;
 int allTemp[2][8] ={{0,0,0,0,0,0,0,0},{1,2,14,15,7,11,12,18}};
 bool bLD= false;
 bool col = 5;
//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------- voids ---------------------------------------------------------//
  void pringON(){
    if (Pring >= 1){
      Pring  = 0;
    }
    else if (Pring < 1){
       Pring = 1;
    }
    else{
      Pring = 0;
    }
    
  }
  void clamp1On(){
   Clamp1.setVelocity(100, percent);
   
    Clamp1.rotateTo(-.65, rev, true);
    
    Clamp1.stop(hold);
    
  }
  void Aclamp1On(){
   if(auton == true && line1.value(pct) <= 30){
     Clamp1.setVelocity(100, percent);
     
      Clamp1.rotateTo(-.6, rev, false); 
      waitUntil(Clamp1.isDone());
      
      clampOn = true;
    }
    

    

  }
  void clamp1Off(){
    Clamp1.setVelocity(100,percent);
   
    Clamp1.rotateTo( -.1, rev, false);
    waitUntil(Clamp1.isDone());
    clampOn = true;
    Clamp1.stop();
   
  }
  void bLReset(){
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
   //Brain.SDcard.loadfile("Alan.png", 0, 0);
   //Brain.Screen.drawImageFromFile("smol1.bmp", 0,0);
    Gyro.resetHeading();
    Gyro.resetRotation();
    std::cout<<Clamp1.value()<<std::endl;
    Lift1.rotateTo(.5, rev, true);
    driveBase.driveFor(fwd, 3, inches, 30, velocityUnits::pct);
    clamp1Off();
    driveBase.driveFor(reverse, 5, inches, 30, velocityUnits::pct);
    //driveBase.turnFor(93, rotationUnits::deg);
    driveBase.turnToHeading(90, rotationUnits::deg);
    driveBase.driveFor(reverse, 20, inches, 50, velocityUnits::pct);
    //driveBase.turnFor(94, rotationUnits::deg);
    driveBase.turnToHeading(180, rotationUnits::deg);
    driveBase.setStopping(brakeType::coast);
    bL.setVelocity(60, velocityUnits::pct);
    bL.rotateTo(-4.8,rev, false);
    driveBase.driveFor(reverse, 90, inches, 40, velocityUnits::pct);
    driveBase.driveFor(reverse, 18, inches, 20, velocityUnits::pct);
    //driveBase.driveFor(reverse, 5, inches, 20, velocityUnits::pct);
    bLD = true;
    waitUntil(bL.position(rotationUnits::rev) == -4.8 || bLD == true);
    bL.rotateTo(-3.2,rev, false);
    waitUntil(bL.position(rotationUnits::rev) >= -3.3);
    pringle.spin(directionType::rev, 100, velocityUnits::pct);
    wait(3, timeUnits::sec);
    pringle.stop();
    Controller1.Screen.print("Pog");
    driveBase.setStopping(brakeType::hold);
    driveBase.turnToHeading(255, rotationUnits::rev);
    

    
 }
//---------------------------------------------------------------------------// }

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//
 
 void usercontrol(void) {
   // User control code here, inside the loop
   auton = false;
   Forward = true;
   clampOn = false;
   Pring = 0;
   Prong = 0;
   while (1) {
   // Brain.SDcard.appendfile("T.bmp", 0,0);
    //Brain.SDcard.loadfile("T.bmp", 0, 0);
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
