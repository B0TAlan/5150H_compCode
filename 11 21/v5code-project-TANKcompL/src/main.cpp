/*                      .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .-------.        \'---'/    //
     _|~~ ~~  |_       /`"""`\\  ((
   =(_|_______|_)=    / /_,_\ \\  \\
     |:::::::::|      \_\\_'__/ \  ))
     |:::::::[]|       /`  /`~\  |//
     |o=======.|      /   /    \  /
jgs  `"""""""""`  ,--`,--'\/\    /
                   '-- "--'  '--'*/
//          Monkey Code          //             

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----//
 // Robot Configuration:
 // [Name]               [Type]        [Port(s)]
 // Controller1          controller                    
 // MotorLf              motor         14              
 // MotorLb              motor         2               
 // MotorRf              motor         20              
 // MotorRb              motor         12              
 // Clamp1               motor         9               
 // Lift1                motor         11              
 // bL1                  motor         18              
 // Gyro                 inertial      6               
 // bL2                  motor         8               
// ---- END VEXCODE CONFIGURED DEVICES -----//

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// MotorLf              motor         14              
// MotorLb              motor         2               
// MotorRf              motor         20              
// MotorRb              motor         12              
// Clamp1               motor         9               
// Lift1                motor         11              
// bL1                  motor         18              
// Gyro                 inertial      6               
// bL2                  motor         8               
// line1                line          A               
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;

//--------------------------------------------------- Groups ---------------------------------------------------------//
 // A global instance of competition
 competition Competition;
 // defind both motor group to stream line mapping to controller
 motor_group leftDrive(MotorLf,MotorLb);
 motor_group rightDrive(MotorRf,MotorRb);
 motor_group bL(bL1,bL2);
 //defind drivetrian to stream line auton 
 //drivetrain driveBase(leftDrive,rightDrive,12.56, 16, 16,distanceUnits::in);
 smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 320, 40, mm, 1);
 //defind events and voids for vis sen later in the seasons 
//--------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ Gloabal Vars ------------------------------------------------------//
 //Bool to setup macro to inverse controls
 int Forward = 1;
 //bool to stop PID and start
 bool drivePID = true;
 //bool to reset sensors for auton
 bool resetDriveSensors = false;
 //////
 bool sM = true;
 bool auton = true;
 bool clampOn = false;
 //defind void to allow inverse controls via toggle
//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------- voids ---------------------------------------------------------//
 //tank forwards
 void tankFwd(){
   if(Forward ==0){
     Forward = 1;
   }
   else if (Forward == 1) {
     Forward = 0;
   }
   else{}
  
   
 } 
 //tank reverse
 void tankRev(){
   Controller1.ButtonB.pressed(tankFwd);
   
 
 }
 //vic poses 
 void willIWon(){
 
   Brain.Screen.print("ooh ooh ah ah, MONNNNKEEEEY CODE ");
   driveBase.turnFor(360, degrees);
 
 
 }
 // defind macro for claw1
 void clamp1On(){
  Clamp1.setVelocity(100, percent);
  
   Clamp1.rotateTo(-1.2, rev, true); 
   clampOn = true;
 }
 void Aclamp1On(){
  Clamp1.setVelocity(100, percent);
  
   Clamp1.rotateTo(-1.2, rev, false); 
   waitUntil(Clamp1.isDone());
   clampOn = true;
 }
 void clamp1Off(){
   Clamp1.setVelocity(100,percent);
  
   Clamp1.rotateTo( 0, rev, false);
 
 }
 
 //voids to set macros for lift 
 void liftUp(){
   Lift1.setVelocity(200, percent);
   //Lift1.spinFor(forward, 2, rev);
   Lift1.rotateTo(5, rev);
 }
 void liftDown(){
   Lift1.setVelocity(200, percent);
   //Lift1.spinFor(reverse, 2, rev);
   Lift1.rotateTo(0,rev);
 }
 void bLrabDown(){//down
   bL.setVelocity(200, percent);
   //Lift1.spinFor(reverse, 2, rev);
   bL.rotateTo(-1.75,rev, false);
 }
 void bLoUp(){//up
   bL.setVelocity(200, percent);
   bL.rotateTo(0,rev, false);
   
   
 }
 
 //---------Pid_Land---------------//
 
 
 
 
 
 //pid to drive forward
 void driveFwd(double inches) {
     timer Timer;
     double error = 6;
     double integral = 0;
     double derivative = 0;
     double integralBound = 20;
     double prevTime = 0, prevError = 0;
     double kp = 0.7, ki = 0.001, kd = 0.008;
     double errorMargin = 5;
     double output = 0;
     float ticks = (2.75*2*M_PI/(360)*inches);
     //if(inches > 0){}
     //if(inches < 0){}
     while (fabs(error) > errorMargin) {
 
        double sensorVal = (leftDrive.current() + rightDrive.current())/2.0;
 
        error = ticks - sensorVal;
 
        integral += error;
 
        if (error > integralBound || integral > ticks || error == 0) {
          integral = 0;
        }
      
        derivative = (error - prevError) / Timer - prevTime;
 
        output = error * kp + integral * ki + derivative * kd;
 
        //std::cout << output << std::endl;
 
       leftDrive.spin(fwd, output, voltageUnits::volt);
       rightDrive.spin(fwd, output, voltageUnits::volt);
        prevError = error;
        prevTime = Timer;
        wait(15, msec);
      }
      // PIDcontrol.rest();
   }
 
 //--------------------------------//
 //void to reset bL sens so macros for teleop can be used in auton 
 void resetbL(){
   bL.setPosition(0, degrees);
 }
 
 // Scoring macro
   // A assignment
   // lowers lift 1 step > opens claw > reset lift > back up???
   void score_macro () {
     // lower lift 1 step
     sM = true;
     Lift1.spinFor(reverse, 1,rev);
   
     // open claw
     Clamp1.spinFor(forward,1,rev);
     Clamp1.stop();
     wait(30,msec);
   
     // reset lift to full height
     Lift1.spinFor(forward,1,rev);
   
     // back up
     driveBase.setDriveVelocity(100,percent);
     driveBase.driveFor(reverse,1,inches);
   }
   void sMSet (){
     sM = false;
 
   }
   
   void gTurnTo(){
  //spin motors in oppisite directions to turn 
   leftDrive.spin(forward, 250, rpm);
   rightDrive.spin(reverse, 250, rpm);
   // stop motors onces gyro = X degrees 
  // waitUntil((Gyro.rotation(degrees) >= X));
    
   
   //wait(1, seconds);
   waitUntil(Gyro.rotation(degrees)>= 90);
    rightDrive.stop();
     leftDrive.stop();
    
    /*if(Gyro.rotation(degrees)>= 90){
     Brain.Screen.clearScreen();
     Brain.Screen.printAt(20, 80, "gyro (degrees)");
     Brain.Screen.printAt(20, 120, "Reading =%f");
     // stop motors
     rightDrive.stop();
     leftDrive.stop();
 
   }*/
   
   
 }
//--------------------------------------------------------------------------------------------------------------------//



//---------------------------------------------------------------------------//
//                          Pre-Autonomous Functions                         //
//                             Calabrate Inertial                            //
//                              Set back Lift(bL)                            //
//---------------------------------------------------------------------------//

 void pre_auton(void) {
   // Initializing Robot Configuration. DO NOT REMOVE!
   vexcodeInit();
   Gyro.isCalibrating();
   bL.setVelocity(100, percent);
   bL.rotateTo(-1.75,rev);
   resetbL();
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
   //////////////////////
   //Notes
   //basic auton that is a place holder until Pid coding is done and tested 
   //robot will drive forward about 53
   ///////////////////////
   auton = true;
   clampOn = false;
    //driveForward(44);
   //driveBase.setDriveVelocity(100, percentUnits::pct);
   //dirveToPid(20);
   //Sart of BLock 1
    vexcodeInit();
    //mGoalF();
    //
    driveFwd(46);
    driveBase.setDriveVelocity(100, percent);
    driveBase.driveFor(37, inches, true);
    driveBase.setDriveVelocity(30, percent);
    driveBase.driveFor(20, inches, 30, velocityUnits:: pct, true);
    //driveBase.driveFor(5, inches, 20, velocityUnits:: pct, true);
    //auton = true;
    //task grabMGoal(mGoalF);
    line1.changed(Aclamp1On);
    waitUntil(clampOn == true);
    //driveBase.driveFor(6, inches, 30, velocityUnits:: pct, true);
    Clamp1.stop();
    bL.setVelocity(100, percent);
    bL.spinFor(-1.75,rev, false);
    resetbL();
    driveBase.driveFor(-60, inches, 80, velocityUnits::pct,true);
    //driveBase.driveFor(-10, inches, 50, velocityUnits::pct,true);
    //-----------------------------------------------------------//
    driveBase.turnToHeading(262, ::deg, 80, velocityUnits::pct);
    bL.spinFor(-1.6,rev, true);
    driveBase.driveFor(-6, inches, 30, velocityUnits:: pct, true);
   // bL.setVelocity(100, percent);
   // bLrabDown();
    //driveBase.driveFor(-12, inches, 50, velocityUnits:: pct, true);
    
    //driveBase.turnFor(-90, rotationUnits::deg, 80, velocityUnits:: pct, true);
    //driveBase.driveFor(7, inches, 80, velocityUnits::pct,true);
    //bLrabDown();
    //driveBase.driveFor(-15, inches, 30, velocityUnits::pct,true);



    /*driveBase.setDriveVelocity(80, percent);
    driveBase.driveFor(38, inches, true);
    driveBase.setDriveVelocity(20, percent);
    driveBase.driveFor(8, inches,true);
    clamp1On();
    driveBase.setDriveVelocity(100, percent);
    driveBase.driveFor(-45, inches,false);*/
   
    
    
  
  
 }
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//
 
 void usercontrol(void) {
   // User control code here, inside the loop
   //Lift1.spinFor(forward, 1.3, rev);
   Forward = true;
   clampOn = false;
   while (1) {
     //have gyro print position for auton
     Brain.Screen.clearScreen();
     Brain.Screen.printAt(20, 80, "gyro (degrees)");
     Brain.Screen.printAt(20, 120, "Reading =%f");
 
       // this stops the robot for tokoy driting 
       int x = Controller1.Axis3.value();
       int y = Controller1.Axis2.value();
       if (abs(x) < 5) {
         leftDrive.stop();//dosen't match cause its dumb
       leftDrive.setVelocity(0, percent);
       }
     
     
       else {
       leftDrive.setVelocity(x, percent);
 
       }
       if (abs(y) < 5) {
         rightDrive.stop();
       rightDrive.setVelocity(0, percent);
       
     }
     
     
     else {
     rightDrive.setVelocity(y, percent);
 
     }
       
     if (Forward == 1){
         leftDrive.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
         rightDrive.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
         Controller1.Screen.print("Forwards");
         Controller1.Screen.clearLine();
    }
    else if (Forward == 0) {
         leftDrive.spin(directionType::rev,Controller1.Axis3.value(), velocityUnits::pct);
         rightDrive.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);
         Controller1.Screen.print("Reverse");
         Controller1.Screen.clearLine();
         }
     else {
 
         }
       if (sM == false){
         score_macro();
 
       }
       else{
         sM = true;
 
       }
 
 
     //call back to run a void when button is presed 
       Controller1.ButtonB.pressed(tankFwd);
       Controller1.ButtonL2.pressed(clamp1On);
       Controller1.ButtonL1.pressed(clamp1Off);
       Controller1.ButtonR1.pressed(liftUp);
       Controller1.ButtonR2.pressed(liftDown);
       Controller1.ButtonUp.pressed(bLoUp);
       Controller1.ButtonDown.pressed(bLrabDown);
       Controller1.ButtonA.pressed(sMSet);
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
    // printf("%d /n", error);
     wait(100, msec);
   }
 }
//---------------------------------------------------------------------------//

/////////////////////////////
//   ||| /||||||||||||     //
//   || /|||||||||||||     //
//   | /||||||||||||||     //
//  ///// /   \  /  \      // 
// /   /  \___/  \__/      //
//                         //
//   Snack Bot Best Bot    //  
/////////////////////////////
