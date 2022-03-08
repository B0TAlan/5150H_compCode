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
   while(auton == true && clampOn == false){
        if (line1.value(percentUnits::pct) <=68){
          Clamp1.rotateTo(-.55, rotationUnits::rev,100,velocityUnits::pct, false);
          //std::cout<<Clamp1.position(rev)<<std::endl;
          waitUntil(Clamp1.position(rev)<= -.52);
          clampOn= true;
          Clamp1.stop(brake);
          break;
          }

          
  } 
    

    

  }
  void clamp1Off(){
    Clamp1.setVelocity(100,percent);
   
    Clamp1.rotateTo( -.1, rev, true);
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
    else if (Controller1.ButtonDown.pressing() && bLR.position(rev) >= 2.3 && bL1.isDone()){
        //Lift1.spinFor(forward, 2, rev);
        bL.rotateTo(-4.8,rev, false);
    }
    else { }
    
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

    void tempchec(){
      allTemp[0][0] = MotorLf.temperature(temperatureUnits::celsius);
      allTemp[0][1] = MotorLb.temperature(temperatureUnits::celsius);
      allTemp[0][2] = MotorRf.temperature(temperatureUnits::celsius);
      allTemp[0][3] = MotorRb.temperature(temperatureUnits::celsius);
      allTemp[0][4] = Lift1.temperature(temperatureUnits::celsius);
      allTemp[0][5] = pringle.temperature(temperatureUnits::celsius);
      allTemp[0][6] = Clamp1.temperature(temperatureUnits::celsius);
      allTemp[0][7] = bL1.temperature(temperatureUnits::celsius);
      for(int i = 0;i >8; i++){
        if(allTemp[0][i] >= 48){
          std::cout<<"Port: "<<allTemp[1][i]<<allTemp[0][i]<<std::endl;
          continue;
        }
        else {
           continue;
        }
      }
    }

//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                          Pre-Autonomous Functions                         //
//---------------------------------------------------------------------------//

 void pre_auton(void) {
   // Initializing Robot Configuration. DO NOT REMOVE!
   vexcodeInit();
    Gyro.calibrate();
    
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
    auton = true;
    driveBase.setDriveVelocity(80, percent);//set the speed of robot (speed up robot)
    driveBase.driveFor(44,inches);
    driveBase.setDriveVelocity(20, velocityUnits::pct);//set the speed of robot (slow down robot)
    driveBase.driveFor(5,inches,false);
    line1.changed(Aclamp1On);
    waitUntil(clampOn == true);
    Clamp1.stop(hold);
    Lift1.rotateTo(.15, rotationUnits::rev, 100, velocityUnits::pct,false);
    driveBase.setDriveVelocity(80, percent);//set the speed of robot (speed up robot)
    driveBase.driveFor(-40,inches);
    Clamp1.spinFor(.4, rotationUnits::rev, 100, velocityUnits::pct, false);
    waitUntil(Clamp1.position(rev)>= -.5);
    driveBase.driveFor(3,inches,false);
    driveBase.turnToHeading(375, rotationUnits::deg);
    driveBase.driveFor(-3,inches,false);
    driveBase.turnToHeading(312, rotationUnits::deg);
    driveBase.driveFor(-6,inches);
    pringle.spin(reverse, 100, velocityUnits::pct);
    //for(int i = 0; i <= 3; i++){
     //if(clampOn == false){
      // std::cout<<"no"<<std::endl;
      // line1.changed(Aclamp1On);
       //driveBase.setDriveVelocity( 5, percent);
       //driveBase.drive(forward);// drive 10 inches forward (i inch form mGaol)
      // waitUntil(clampOn==true) ;
      // std::cout<<"ye"<<std::endl;
     //}
     
     //else if (clampOn == true ){
     //  break;
     //}
   // }
  
    // ----=[1st]=---- 1st goal ----=[1st]=---- //
    /*driveBase.setDriveVelocity(80, percent);//set the speed of robot (speed up robot)
    driveBase.driveFor(39,inches);
    
    wait(500,msec);

    driveBase.setDriveVelocity(15, velocityUnits::pct);//set the speed of robot (slow down robot)
    driveBase.driveFor(23,inches);
    Clamp1.setVelocity(80, percentUnits::pct);
    Clamp1.spinFor(-.6,rev);
    
    driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
    driveBase.driveFor(-61,inches);
    Clamp1.rotateTo(0,deg);

    // ----=[2nd]=---- 2nd goal ----=[2nd]=---- //

    driveBase.turnFor(-98,deg);
    driveBase.driveFor(6,inches);

    bL.setVelocity(100,percent);
    bL.spinFor(-4.7,rev);

    driveBase.driveFor(-10,inches);

    bL.rotateTo(-3.2,rev);

    pringle.setVelocity(100,percent);
    pringle.spinFor(-10,rev);*/
    
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
    std::cout<<Controller1.Axis3.value()<<std::endl;
    //have gyro print position for auton
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(20, 80, "gyro (degrees)");
    Brain.Screen.printAt(20, 120, "Reading =%f");
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
