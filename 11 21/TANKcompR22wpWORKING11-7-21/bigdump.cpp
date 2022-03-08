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

// ---- START VEXCODE CONFIGURED DEVICES ----
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
// ---- END VEXCODE CONFIGURED DEVICES ----


// ALL CODE IN GREEN IS OLD OR NOT WORKING  //

#include "vex.h"
using namespace vex;

// A global instance of competition
competition Competition;
// defind both motor group to stream line mapping to controller
motor_group leftDrive(MotorLf,MotorLb);
motor_group rightDrive(MotorRf,MotorRb);
motor_group bL(bL1,bL2);
//defind drivetrian to stream line auton 
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 320, 40, mm, 1);//smart drive adds gyro and softwar can clac the # 
//defind events and voids for vis sen later in the seasons 

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
//----------------------------------------------------voids----------------------------------------------------------//
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
//-------------------------------------------------------------------------------------------------------------------// 
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  //-------PID TEST-------//
  //vexcodeInit();
  

  
  //driveBase.turnFor(90, rotationUnits::deg, 100 , velocityUnits::pct);
  //driveBase.turnFor(90, rotationUnits::deg, 100 , velocityUnits::pct);





  ///////////////////////
  //Sart of BLock 1 // grab the first nutral mGoal linup for 
   // set bL and reset the sensors 
   vexcodeInit();
   bL.setVelocity(100, percent);
   bL.spinFor(-1.75,rev);
   resetbL();
  // driveBase.setTurnVelocity(200, percent);
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
   driveBase.turnFor(-90, rotationUnits::deg, 100 , velocityUnits::pct);// 43 = 90 degrees ish due demisinons of drive base are wrong
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
   bLUp();
   Clamp1.setVelocity(200, percent);
   driveBase.turnFor(-28, degrees);
   //Clamp1.spinFor(1.1 ,rev);
   //driveBase.turnFor(-21.5, degrees);
  ///////////////////////////////*/
  /*/Start of Block 3 // atamept the the nutral Mgoal and scroe then park for telop
  /////////////////////////////////////
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(40, inches);
   driveBase.setDriveVelocity(20, percent);
   driveBase.driveFor(16, inches);
   clamp1On();
   driveBase.setDriveVelocity(200, percent);
   driveBase.driveFor(-45, inches);
   driveBase.turnFor(25, degrees);
   driveBase.driveFor(-25, inches);
   ///////////////////////////////////////*/
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
 
 
 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

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
      Controller1.ButtonA.pressed(score_macro);
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