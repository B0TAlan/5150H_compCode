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
// ham                  motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;

//--------------------------------------------------- Groups ---------------------------------------------------------//
 // A global instance of competition
 competition Competition;
 // defind both motor group to stream line mapping to controller
 motor_group leftDrive(MotorLf,MotorLb);// group for the left side 
 motor_group rightDrive(MotorRf,MotorRb);// group for the right side 
 motor_group bL(bL1,bL2);// group for back Lift (bL)
 //defind drivetrian to stream line auton 
 //group includes left right side, and internal for accurate turnning 
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
 //----------------------------//
 bool sM = true;// used to make the scoring macro repeat 
 bool auton = true;// was used to trigger line sensor in auton (not needed)
 bool clampOn = false;// used to have the robot to wait for the clamp close in auton 
 bool setDS =true;// was to make 
 bool Arcade = false;
 bool RobotIsWorking = false;
 //defind void to allow inverse controls via toggle
//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------- voids ---------------------------------------------------------//
 //tank forwards
 void tankFwd(){
   while(Arcade == true){
     leftDrive.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
     rightDrive.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);

     Controller1.Screen.print("Arcade");
     Controller1.Screen.clearLine();
   }
  
   
 } 
 //tank reverse
 void tankRev(){
   Arcade = true;
   
   
 
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
   Lift1.rotateTo(6, rev);
 }
 void liftDown(){
   Lift1.setVelocity(200, percent);
   //Lift1.spinFor(reverse, 2, rev);
   Lift1.rotateTo(0,rev);
 }
 void bLDown(){//down
   bL.setVelocity(200, percent);
   //Lift1.spinFor(reverse, 2, rev);
   bL.rotateTo(-1.75,rev, false);
 }
 void bLUp(){//up
   bL.setVelocity(200, percent);
   bL.rotateTo(0,rev, false);
   
   
 }
 
 //---------Pid_Land---------------//
 
 void driveForward(double inches){
   //PID variables
   timer Timer;
   float threshold = 10; //exit loop while robot is within 10 ticks of target
   float error = 0.0, prevError; //proportional terms
   float integral = 0; //ditto
   float derivative = 1; //ditto 
   float kP = 1, kI = .01, kD = 1; //change in time
   float dT = Timer, prevTime = 0; //set delta time to current time
   float output;
   float targetTicks = 2.75*2*M_PI/(360*inches);//conversion from inches to ticks 
  //PID Loop
   while(fabs(error) > threshold){
     Controller1.Screen.clearScreen();
     Controller1.Screen.print("%f %f, speed, integral");
     printf("%f %f, speed, integral");
     float currentPosition = (leftDrive.position(rotationUnits::raw) + rightDrive.position(rotationUnits::raw))/2.0;
     
     error = targetTicks - currentPosition; //distance between robot and target position
       if(dT > 0){ //prevent divide by 0 error
       integral += error * dT;
       derivative = (error - prevError) * dT;
       }
       prevError = error;
       dT = Timer - prevTime;
 
       output = error*kP + integral*kI + derivative*kD;
      
       leftDrive.spin(reverse, output, volt);
       rightDrive.spin(reverse, output, volt);
      
       wait(20, msec);
     }
       rightDrive.stop(brake); //stop robot at target
       leftDrive.stop(brake);
 }
 
 
 
 
 //pid to drive forward
 /*void driveFwd(double inches) {
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
   }*/
 
 //--------------------------------//
 //void to reset bL sens so macros for teleop can be used in auton 
 void resetbL(){
   bL.setPosition(0, degrees);
 }
 // reset drive motors 4 PID
 void resetDrive(){
   leftDrive.setPosition(0, degrees);
   rightDrive.setPosition(0, degrees);
 }
 // Scoring macro
   // A assignment
   // lowers lift 1 step > opens claw > reset lift > back up???
   void score_macro () {
     // lower lift 1 step
     sM = true;
     Lift1.spinFor(reverse, 1,rev);
   
     // open claw
     Clamp1.spinFor(fwd,1,rev);
     Clamp1.stop();
     wait(30,msec);
   
     // reset lift to full height
     Lift1.spinFor(fwd,1,rev);
   
     // back up
     driveBase.setDriveVelocity(100,percent);
     driveBase.driveFor(reverse,1,inches);
   }
   void sMSet (){
     sM = false;
 //cwon
   }
   void deScore() {
     //lift.spinFor(fwd, 13, inches, 100, velocityUnits::pct);
     Lift1.rotateTo(3.5, rotationUnits::rev, 100, velocityUnits::pct);
   }
   void gTurnTo(){
   //spin motors in oppisite directions to turn 
   leftDrive.spin(fwd, 250, rpm);
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
  /* void driveForward(double inches){
    //PID variables
    timer  Timer;
    float threshold = 10; //exit loop while robot is within 10 ticks of target
    float error, prevError; //proportional terms
    float integral = 0; //ditto
    float derivative = 1; //ditto 
    float kP = 1, kI = .01, kD = 1; //change in time
    float dT = Timer, prevTime = 0; //set delta time to current time
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
        dT = Timer - prevTime;

        output = error*kP + integral*kI + derivative*kD;

        leftDrive.spin(reverse, output, volt);
        rightDrive.spin(reverse, output, volt);

        wait(20, msec);
      }
        rightDrive.stop(brake); //stop robot at target
        leftDrive.stop(brake);
   }
    */
   
 }
 void driveForwardp(double inches){
    //PID variables
    timer  Timer;
    float threshold = 10; //exit loop while robot is within 10 ticks of target
    float error = 0.0, prevError; //proportional terms
    float integral = 0; //ditto
    float derivative = 1; //ditto 
    float kP = 1, kI = .01, kD = 1; //change in time
    float dT = Timer, prevTime = 0; //set delta time to current time
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
        dT = Timer - prevTime;
        
        output = error*kP + integral*kI + derivative*kD;

        leftDrive.spin(reverse, output, volt);
        rightDrive.spin(reverse, output, volt);

        wait(20, msec);
      }
        rightDrive.stop(brake); //stop robot at target
        leftDrive.stop(brake);

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
   //bL.setVelocity(100, percent);
   //bL.rotateTo(-1.75,rev);
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
   drivePID = true;
   
   //basic auton that is a place holder until Pid coding is done and tested 
   //robot will drive forward about 53
   ///////////////////////
   //driveForward(48);
    //driveForwardp(40);
   

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
      if (RobotIsWorking == false){
        RobotIsWorking = true;


      }
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
       
     if (Arcade == false){
         leftDrive.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
         rightDrive.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
         Controller1.Screen.print("Tank");
         Controller1.Screen.clearLine();
    }
    else if (Arcade == true) {
         tankFwd();
         //leftDrive.spin(directionType::rev,Controller1.Axis3.value(), velocityUnits::pct);
         //rightDrive.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);
         //Controller1.Screen.print("Reverse");
         //Controller1.Screen.clearLine();
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
       //Controller1.ButtonB.pressed(tankFwd);
       Controller1.ButtonL2.pressed(clamp1On);
       Controller1.ButtonL1.pressed(clamp1Off);
       Controller1.ButtonR1.pressed(liftUp);
       Controller1.ButtonR2.pressed(liftDown);
       Controller1.ButtonUp.pressed(bLUp);
       Controller1.ButtonDown.pressed(bLDown);
       Controller1.ButtonA.pressed(sMSet);
       Controller1.ButtonB.pressed(deScore);
       Controller1.ButtonX.pressed(tankRev);
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
