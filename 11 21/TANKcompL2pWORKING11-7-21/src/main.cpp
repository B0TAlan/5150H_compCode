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
  
   Clamp1.rotateTo(-1.2, rev, false); 
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
 void dirveToPid(double inches){
   //PID settings and peramiters
   float error;
   float prevError;
   float integral = 0;
   float derivative = 1;
   double kP = 1;
   double kI = .01;
   double kD = 1;
   float speed = 100; 
   float ticks = (2.75*2*M_PI/(360)*inches);//conversion from ticks to inches 
  // while loop that tell robit to drive to Xinches and check how close
   while(1){
     Brain.Screen.clearScreen();
     Brain.Screen.print("%f %f", speed, integral);
     Controller1.Screen.clearLine();
     Controller1.Screen.print("%f %f", speed, integral);
     float averbLepos = leftDrive.position(rotationUnits:: raw) + rightDrive.position(rotationUnits:: raw)/2.0;
     error = ticks - averbLepos;
 
     if (error > ticks){
       rightDrive.stop(brake);
       leftDrive.stop(brake);
     }
     else if (error == 0) {
       rightDrive.stop(brake);
       leftDrive.stop(brake);
     }
     else if (error < ticks) {
  
       integral += error;
       derivative = error - prevError;
       //Controller1.Screen.print("%lf", error);
       //printf("%lf /n", error);
       speed = (error*kP) + (integral*kI) + (derivative*kD);
      prevError = error;
      Brain.Screen.print("%f %f", speed, integral);
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("%f %f", speed, integral);
      // Controller1.Screen.print("%lf /n", error);
      // printf("%lf /n", error);
       //printf("pogchamp");
       leftDrive.spin(reverse, speed, pct );
       rightDrive.spin(reverse, speed, pct );
       //rightDrive.spin(fwd, speed, pct );
       task::sleep(10);
       Controller1.Screen.clearLine();
     }
     else if(error == 0){
       rightDrive.stop(brake);
       leftDrive.stop(brake);
     }
     else {
       rightDrive.stop(brake);
       leftDrive.stop(brake);
     }
    }
   
   //rightDrive.stop(brake);
   //leftDrive.stop(brake);
 }
 //similar process of turning but requires own pid
 void turnTo(){
   double error = 0;
 
 
 
 }
 //pid eddited by alum
 void driveForward(double inches){
   //PID variables
   float threshold = 10; //exit loop while robot is within 10 ticks of target
   float error, prevError; //proportional terms
   float integral = 0; //ditto
   float derivative = 1; //ditto 
   float kP = 1, kI = .01, kD = 1; //change in time
   float dT = vex::timer(), prevTime = 0; //set delta time to current time
   float output;
   float targetTicks = 2.75*2*M_PI/(360*inches);//conversion from inches to ticks 
  //PID Loop
   while(fabs(error) > threshold){
     float currentPosition = (leftDrive.position(rotationUnits::raw) + rightDrive.position(rotationUnits::raw))/2.0;
     
     error = targetTicks - currentPosition; //distance between robot and target position
       if(dT > 0){ //prevent divide by 0 error
       integral += error * dT;
       derivative = (error - prevError) * dT;
       }
       prevError = error;
       dT = vex::timer::system() - prevTime;
 
       output = error*kP + integral*kI + derivative*kD;
      
       leftDrive.spin(reverse, output, volt);
       rightDrive.spin(reverse, output, volt);
      
       wait(20, msec);
     }
       rightDrive.stop(brake); //stop robot at target
       leftDrive.stop(brake);
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
   bL.setVelocity(100, percent);
   bL.spinFor(-1.75,rev);
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
   
    //driveForward(44);
 
   //dirveToPid(20);
   //Sart of BLock 1
    vexcodeInit();
    bL.setVelocity(100, percent);
    bL.spinFor(-1.75,rev, false);
    resetbL();
    driveBase.setDriveVelocity(80, percent);
    driveBase.driveFor(-2, inches);
    Clamp1.setVelocity(200, percent);
    bL.spinFor(-1.75, rev);
    driveBase.driveFor(-8, inches);
    bL.setVelocity(200, percent);
    //driveBase.driveFor(7, inches);
    bLoUp();
    bLrabDown();
    driveBase.turnFor(-180, rotationUnits::deg);
    driveBase.driveFor(-5, inches);
    driveBase.turnFor(-80, rotationUnits::deg, 50, velocityUnits::pct);
    driveBase.setDriveVelocity(200, percent);//set the speed of robot (speed up robot)
    driveBase.driveFor(forward, 38, inches);// drive 43 inches forward to closed distance between robot and mGoal
    driveBase.setDriveVelocity(15, percent);// slow down 
    driveBase.driveFor(forward, 7, inches);// drive 10 inches forward (i inch form mGaol)
 
    //driveBase.driveFor(8, inches);
    
    
  
  
 }
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//                              User Control Task                            //
//---------------------------------------------------------------------------//
 
 void usercontrol(void) {
   // User control code here, inside the loop
   //Lift1.spinFor(forward, 1.3, rev);
   Forward = true;
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
