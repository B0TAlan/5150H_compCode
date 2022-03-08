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

// ---- START VEXCODE CONFIGURED DEVICES ---//
 // Robot Configuration:
 // [Name]               [Type]        [Port(s)]
 // MotorLf              motor         14              
 // Controller1          controller                    
 // MotorLb              motor         2               
 // MotorRf              motor         20              
 // MotorRb              motor         12              
 // Lift1                motor         11              
 // bL1                  motor         18              
 // bL2                  motor         8               
 // Gyro                 inertial      6               
 // Clamp1               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES -----//


// ALL CODE IN GREEN IS OLD OR NOT WORKING  //

#include "vex.h"
using namespace vex;
//--------------------------------------------------- Groups ---------------------------------------------------------//
 // A global instance of competition
 competition Competition;
 // defind both motor group to stream line mapping to controller
 motor_group leftDrive(MotorLf,MotorLb);
 motor_group rightDrive(MotorRf,MotorRb);
 motor_group bL(bL1,bL2);
 //defind drivetrian to stream line auton 
 smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 320, 40, mm, 1);//smart drive adds gyro and softwar can clac the # 
//--------------------------------------------------------------------------------------------------------------------// 

//------------------------------------------------ Gloabal Vars ------------------------------------------------------//
 //Bool to setup macro to inverse controls
 int Forward = 1;
 //bool to stop PID and start
 bool drivePID = true;
 //bool to reset sensors for auton
 bool resetDriveSensors = false;
 //bool to have score macro repeat
 bool sM = true;
 //defind void to allow inverse controls via toggle
 //tank forwards
//--------------------------------------------------------------------------------------------------------------------// 

//---------------------------------------------------- voids ---------------------------------------------------------//
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
 //victory poses 
 void willIWon(){

  Brain.Screen.print("ooh ooh ah ah, MONNNNKEEEEY CODE ");
  driveBase.turnFor(360, degrees);


 }
 // defind macro for claw1
 void clamp1On(){
  Clamp1.setVelocity(100, percent);
 
  Clamp1.rotateTo(-1.2, rev, false); 
 }
 void clamp1Off(){
  Clamp1.setVelocity(100,percent);
 
  Clamp1.rotateTo( 1, rev, false);

 }
 //voids to set macros for lift 
 void liftUp(){//rotat lift up to score
  Lift1.setVelocity(200, percent);
  //Lift1.spinFor(forward, 2, rev);
  Lift1.rotateTo(5.5, rev);
 }
 void liftDown(){//set lift to zero
  Lift1.setVelocity(200, percent);
  //Lift1.spinFor(reverse, 2, rev);
  Lift1.rotateTo(0,rev);
 }
 void bLDown(){//down
  bL.setVelocity(200, percent);
  //Lift1.spinFor(reverse, 2, rev);
  bL.rotateTo(-1.75,rev);
 }
 void bLUp(){//up
  bL.setVelocity(200, percent);
  bL.rotateTo(0,rev);
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


 
 // void with pid control for auton so that void can be called (DOES NOT)


 void basic(double inches) {
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

      prevError = error;
      prevTime = Timer;
      wait(15, msec);
    }
    // PIDcontrol.rest();
 }

 //similar process of turning but requires own pid not working 
 void turnToPid(){
  double error = 0;



 }
 //void to reset bL sens so macros for teleop can be used in auton 
 void resetbL(){
  bL.setPosition(0, degrees);
 }
 void gTurnTo(int Y){
  //spin motors in oppisite directions to turn 
  leftDrive.spin(forward, 250, rpm);
  rightDrive.spin(reverse, 250, rpm);
  // stop motors onces gyro = X degrees 
  // waitUntil((Gyro.rotation(degrees) >= X));
   
  
  //wait(1, seconds);
  while (Gyro.rotation(degrees)>= Y){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(20, 80, "gyro (degrees)");
    Brain.Screen.printAt(20, 120, "Reading =%f");


  }
  // stop motors
  rightDrive.stop();
  leftDrive.stop();
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
 
 
 	// Stuff to loop (I.E. Checking sensors)
 
   Gyro.calibrate();
   //set the bL for auton and teleop
   bL.setVelocity(100, percent);
   bL.spinFor(-1.75,rev);
   resetbL();
   Clamp1.setPosition(0, degrees);
 }
//---------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//                              Autonomous Task                               //
//                                 40 Points                                  //
//----------------------------------------------------------------------------//
 
 void autonomous(void) {
   //-------PID TEST-------//
   vexcodeInit();
   bL.setVelocity(100, percent);
   bL.spinFor(-1.75,rev, false);
   resetbL();
   bL.setVelocity(100, percent);
   driveBase.setDriveVelocity(100, percent);//set the speed of robot (speed up robot)
   driveBase.driveFor(forward, 38, inches);// drive 43 inches forward to closed distance between robot and mGoal
   driveBase.setDriveVelocity(15, percent);// slow down 
   driveBase.driveFor(forward, 6, inches);// drive 6 inches forward (i inch form mGaol)
   Clamp1.setVelocity(200, percent);
   Clamp1.spinFor(-1.1 ,rev); //manual close Clamp
   wait(10, msec);
   driveBase.setDriveVelocity(200, percent);//set the speed of robot (speed up robot)
   driveBase.driveFor(forward, -18, inches);// drive 43 inches forward to closed distance between robot and mGoal
   driveBase.turnFor(122, rotationUnits::deg, 80 , velocityUnits::pct);//try -150
   bLDown();
   driveBase.driveFor(forward, -25, inches);
   driveBase.setDriveVelocity(20, percent);
   driveBase.driveFor(forward, -7, inches);
   bLUp();
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(forward, 40, inches);
   driveBase.turnFor(40, rotationUnits::deg, 80 , velocityUnits::pct);//try -150
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(forward, 15, inches);
 }
//----------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//
 
 void usercontrol(void) {
   // User control code here, inside the loop
   //Lift1.spinFor(forward, 1.3, rev);
   Forward = true;
   while (1) {
     //Clamp1.setPosition(0, rev);
     // print the gyro readings on cortex for calabrating auton
     Brain.Screen.clearScreen();
     Brain.Screen.printAt(20, 80, "gyro (degrees)");
     Brain.Screen.printAt(20, 120, "Reading =%f");
     
       // this stops the robot form tokyo driting 
       int x = Controller1.Axis3.value();
       int y = Controller1.Axis2.value();
       if (abs(x) < 6) {
         leftDrive.stop();
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
     // NOT WORKING: to invert controls to use bL better during teleop
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
 
 
 
     //call back to run a void when button is presed to use for teleop
       Controller1.ButtonB.pressed(tankFwd);
       Controller1.ButtonL2.pressed(clamp1On);
       Controller1.ButtonL1.pressed(clamp1Off);
       Controller1.ButtonR1.pressed(liftUp);
       Controller1.ButtonR2.pressed(liftDown);
       Controller1.ButtonUp.pressed(bLUp);
       Controller1.ButtonDown.pressed(bLDown);
       Controller1.ButtonA.pressed(sMSet);
     wait(20, msec); // Sleep the task for a short amount of time to
                     // prevent wasted resources.
   }
 
 }


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


///////////////////////////