/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Scruf                                            */
/*    Created:      Sun Nov 07 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// line1                line          A               
// Clamp1               motor         21              
// Light1               light         C               
// viz1                 vision        9               
// Controller1          controller                    
// lf                   motor         14              
// lb                   motor         2               
// rf                   motor         20              
// rb                   motor         12              
// Gyro                 inertial      6               
// ---- END VEXCODE CONFIGURED DEVICES ----
bool auton = true;
#include "vex.h"

using namespace vex;
motor_group leftDrive(lf,lb);
motor_group rightDrive(rf,rb);
smartdrive driveBase(leftDrive, rightDrive, Gyro);
event checkYG = event();
event checkRG = event();
event checkBG = event();

void yG (){
 Brain.Screen.setFont(mono40);
 Brain.Screen.clearLine(1, black);
 Brain.Screen.setCursor(Brain.Screen.row(), 1);
 Brain.Screen.setCursor(1, 1);
 viz1.takeSnapshot(viz1__YG);
 if (viz1.objectCount > 0) {
    Brain.Screen.print("they call me mello yello");
  } else {
    Brain.Screen.print("No yello Object");
  }
  task::sleep(100);
}
void rG (){
 Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(3, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(3, 1);
  viz1.takeSnapshot(viz1__RG);
  if (viz1.objectCount > 0) {
    Brain.Screen.print("roese are red violets are blue when vex water game uwu");
  } else {
    Brain.Screen.print("No Red Object");
  }
  task::sleep(100);
}
void bG (){
 Brain.Screen.setFont(mono40);
 Brain.Screen.clearLine(5, black);
 Brain.Screen.setCursor(Brain.Screen.row(), 1);
 Brain.Screen.setCursor(5, 1);
 viz1.takeSnapshot(viz1__BG);
 if (viz1.objectCount > 0) {
    Brain.Screen.print("its blue yaba de yaba do");
  } else {
    Brain.Screen.print("No bule Object");
  }
 task::sleep(100);
  
}
int X = 0; // the X coradante of object
int Y = 0; // The Y Cordanate of object 
int centerFOV = 158; // The center of viz sen FOV
int OKErrorX = 50; // the acceptable offset of pixles form object 
int OKErrorY = 100;
void aRG(){
 while(1){
   viz1.takeSnapshot(viz1__BG); 
   if (viz1.largestObject.exists){
     Brain.Screen.print("roese are red violets are blue when vex water game uwu");
     Controller1.Screen.print("roese are red violets are blue when vex water game uwu");
     X = viz1.largestObject.centerX;
     if(X < (centerFOV-OKErrorX)){
       leftDrive.spin(directionType::rev, 25, velocityUnits::pct);
       rightDrive.spin(directionType::fwd, 25, velocityUnits::pct);
     }
     else if(X > centerFOV + OKErrorX){
       leftDrive.spin(directionType::fwd, 25, velocityUnits::pct);
       rightDrive.spin(directionType::rev, 25, velocityUnits::pct);
     }
     else if(X == (centerFOV-OKErrorX) ||X == centerFOV + OKErrorX){
      leftDrive.stop(brake);
      leftDrive.stop(brake);
     }
     else{
       leftDrive.stop(brake);
       leftDrive.stop(brake);
     }
     Y = viz1.largestObject.centerY;
     if(Y > centerFOV + OKErrorY){
       leftDrive.spin(directionType::rev, 25, velocityUnits::pct);
       rightDrive.spin(directionType::rev, 25, velocityUnits::pct);
     }
     else if(Y < (centerFOV-OKErrorY)){
       leftDrive.spin(directionType::fwd, 25, velocityUnits::pct);
       rightDrive.spin(directionType::fwd, 25, velocityUnits::pct);
     
     }
     else if(Y == (centerFOV-OKErrorY) ||Y == centerFOV + OKErrorY){
      leftDrive.stop(brake);
      leftDrive.stop(brake);
     }
     else{
       leftDrive.stop(brake);
       leftDrive.stop(brake);
     }
  }
  else {
     leftDrive.stop(brake);
     leftDrive.stop(brake);
  }
  
  task::sleep(100);

 }


  
}
int Trun(double degrees, double vel){
   
   leftDrive.spin(directionType::rev, vel, percentUnits::pct);
   rightDrive.spin(directionType::rev, vel, percentUnits::pct);
   waitUntil(Gyro.rotation() == degrees);
    driveBase.stop(hold);
   auton = false;
 
  return 1;
}
void clamp1On(){//close calmp
 Clamp1.setVelocity(100, percent);
 // Clamp1.setPosition(0, rev);
  Clamp1.rotateTo(-1.3, rev);
  //Clamp1.stop(brake); 
  //Clamp1.stop();
  //wait(1,msec);
 
}


void mGoalF() {

  
   if ( line1.value(percent) < 60 || line1.value(percent) == 0){
 
     Clamp1.rotateTo(1.2, rev, 100, velocityUnits::pct,true);
 
   }
   else if (line1.value(percent) > 60) {

     Clamp1.rotateTo(0, rev);
   
   } 
 }


int main() {
  auton = false;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  checkBG(bG);
  checkYG(yG);
  checkRG(aRG);
 while(1){
  checkRG.broadcastAndWait();
  checkBG.broadcastAndWait();
  checkYG.broadcastAndWait();
  if ( line1.value(percent) < 60 || line1.value(percent) == 0){
     viz1.setLedColor(0,255,0);
     viz1.setBrightness(line1.value(pct));
     //clamp1On();
     task::sleep(100);
   }
   else if (line1.value(percent) > 60) {
     viz1.setBrightness(line1.value(pct));
     viz1.setLedColor(255,0,0);
     //Clamp1.rotateTo(0, rev);
     task::sleep(100);
  }
 
 }

   /*if ( line1.value(percent) < 60 || line1.value(percent) == 0){
 
     clamp1On();
 
   }
   else if (line1.value(percent) > 60) {

     Clamp1.rotateTo(0, rev);

  }
 }*/

}