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
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>
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
// Gyro                 inertial      6               
// bL2                  motor         8               
// line1                line          A               
// pringle              motor         12              
// bLR                  rotation      10              
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>
//--------------------------------------------------- Groups ---------------------------------------------------------//
 // A global instance of competition
 competition Competition;
 // defind both motor group to stream line mapping to controller
 motor_group leftDrive(MotorLf,MotorLb);// group for the left side
 motor_group rightDrive(MotorRf,MotorRb);// group for the right side
 motor_group bL(bL1,bL2);// group for back Lift (bL)
 motor_group all(bL1,bL2,Lift1, Clamp1);
 //defind drivetrian to stream line auton
 //group includes left right side, and internal for accurate turnning
 smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);
 //defind events and voids for vis sen later in the seasons
//--------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ Gloabal Vars ------------------------------------------------------//
 //Bool to setup macro to inverse controls
 int Forward = 0;
 //bool to stop PID and start
 bool drivePID = true;
 //bool to reset sensors for auton
 bool resetDriveSensors = false;
 bool liftH1= false;
 bool liftH0 = false;
 //----------------------------//
 bool sM = true;// used to make the scoring macro repeat
 bool auton = true;// was used to trigger line sensor in auton (not needed)
 bool clampOn = false;// used to have the robot to wait for the clamp close in auton
 bool setDS =true;// was to make
 bool Arcade = false;
 bool RobotIsWorking = false;
 int Pring = 2;
 int Prong = 0;
 int contAVal[4] ={0,0,0,0};
 int cont = 2;
 bool rp = false;
 //defind void to allow inverse controls via toggle
//--------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------- voids ---------------------------------------------------------//
 //tank forwards
  void pringOFF(){
    if (Prong == 1){
      Pring = 2;
    }
    else if (Prong ==2){
       Pring = 1;
    }
    else{
      Prong = 1;
      
    }
  }
  void pringSet(){
    rp = false;
    if (Pring == 1){
      Pring  = 2;
    }
    else if (Pring == 2){
       Pring = 1;
    }
    else{
      Pring = 1;
      rp = false;
    }
  }
  void prongSet(){
    rp = true;
    if (Prong >= 1){
      Prong  = 0;
    }
    else if (Pring < 1){
       Prong = 1;
       rp = false;
    }
    else{
      Prong = 0;
      rp = false;
    }
  }
  void setCont(){
     if (cont == 2){
        cont = 1;
     }
     else if (cont == 1){
       cont = 2;
     }
     else {
       cont = 1;
     }
  }
  void when() {
   //Lift1.rotateTo(.5, rev, 100, velocityUnits::pct, false);

   if (Pring == 1){
         //task spinPring(when);
         pringle.spin(reverse, 100, velocityUnits::pct);
         std::cout << "on" << std::endl;
         Controller1.ButtonRight.released(pringOFF);

        // Pring = false;
        // pringle.stop();
       }
       else if (Pring == 0 )  {

         pringle.stop();
         std::cout << "off" << std::endl;
        Controller1.ButtonRight.released(pringSet);
       }
   }

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

    Clamp1.rotateTo(-.6, rev, true);

    Clamp1.stop(hold);

  }
  void Aclamp1On(){
   Clamp1.setVelocity(100, percent);

    Clamp1.rotateTo(-.6, rev, false);
    waitUntil(Clamp1.isDone());

    clampOn = true;
  }
  void clamp1Off(){
    Clamp1.setVelocity(100,percent);

    Clamp1.rotateTo( -.1, rev, true);

    Clamp1.stop();

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
    else {

    }
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
  void set4Pring(){
    if (Lift1.position(rotationUnits::rev) < .2){
      Lift1.setVelocity(100, percentUnits::pct);
      Lift1.rotateTo(.2, rev, false);
    }
    else {}

  }
  void resetAll(){
     all.rotateTo(0, rev, 100, velocityUnits::pct, true);
     all.stop();
     Controller1.Screen.print(green);
     Brain.Screen.clearScreen();
     Brain.Screen.print(white);

  }

  void setF(){
     if (Forward == 1){
       Forward = 0;
     }
     else if (Forward == 0){
       Forward = 1;
     }
     else {
       Forward = 0;
     }

  }


  //---------Pid_Land---------------//


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
     Lift1.rotateTo(.9, rotationUnits::rev, 100, velocityUnits::pct, false);

     // open claw
     clamp1Off();
     waitUntil(Clamp1.isDone());


     // reset lift to full height
     liftUp();

     // back up
     //driveBase.setDriveVelocity(100,percent);
     //driveBase.driveFor(reverse,1,inches, false);
   }
   void sMSet (){
     sM = false;
 //cwon
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
  /*
    */

 }

timer t;

 void moveFwd(double target, double maxVoltage) {// scale 0 to 12 mvolt

    //chassis_Set PIDControl;

    // MACHINE STATE WHEN ENTERING FUNCTION, MACHINE STATE AFTER
    double enterAngle = Gyro.rotation();

    // CONVERSION FROM INCHES TO ENCODER TICKS
    target = ((target * 360) / (4 * M_PI)) * (36 / 84);

    double output = 0, Dt = 0, encoderAvrg = 0;
    double prevError = 0, prevTime = t.time(msec);

    // SLEW COMPONENTS
    double volCapMax = 12, volCap = 0;

    // SLEW TUNABLE
    double acceleration = .07;

    // PID COMPONENTS
    double error = 6, integral = 0.01, derivetive = 0.1;

    // CONSTATNTS
    double Kp = .11, Ki = 0.009, Kd = .007, kt = 0;

    // BOUNDS
    double errorMargin = 4, integralBound = 20;

    // CORECTION VARIABLES
    double targetAngle = 0, correctionOutput = 0;

    double enterVal = ((leftDrive.position(deg) + rightDrive.position(deg)) /2);

    int sign = 1;
    // CALCULATES ERROR FOR FUNCTION TO RUN
    error = target - encoderAvrg;

    while (fabs(error) < errorMargin) {

      double sensorVal = ((leftDrive.position(deg) + rightDrive.position(deg)) /2) - enterVal;

      // AVERAGE BETWEEN ENCODER VALUES
      encoderAvrg = sensorVal;

      // FINDS THE DIFFRENCE BETWEEN THE TARGET AND ROBOT
      error = target - encoderAvrg;

      // CALCULATES DELTA TIME IN MSEC
      Dt = (t.time(msec) - prevTime) / 1000;

      // FINDS  INTEGRAL WITH CONSTANT MULTIPLIER, AND ERROR
      integral += error * Dt;


      // FINDS DRVITIVE USING ERROR, AND PREVIOUS
      // DIVIDES BY TIME
      derivetive = (error - prevError) / Dt;

      // UPDATES THE PREVIOUS ERROR
      prevError = error;

      if (fabs(error) > integralBound) {
        integral = 0;
      }

      // CALCULATES THE VOLTS TO BE SENT TO THE MOTORS
      output = error * Kp + integral * Ki + derivetive * Kd;

      // FINDS IF POS OR NEG
      sign = fabs(output) / output;

      if (fabs(output) > maxVoltage) {
        output = maxVoltage * sign;
      }

      // Slew rate
      if (fabs(output) > volCapMax)
        output = volCapMax * sign;

      volCap += acceleration * sign;
      if (fabs(volCap) > fabs(volCapMax)) {
        volCap = volCapMax * sign;
      }

      if (fabs(output) > fabs(volCap)) {
        output = volCap;
      }

      // DIFFRENCE IN MACHINE STATE
      correctionOutput = targetAngle - (enterAngle - Gyro.rotation())*kt;

      // CHECKS MACHINE STATE
      if (fabs(enterAngle - Gyro.rotation()) > targetAngle) {
       leftDrive.spin(directionType::fwd, output + correctionOutput, voltageUnits::volt);
       rightDrive.spin(directionType::fwd, output - correctionOutput, voltageUnits::volt);
        // UPDATES MACHINE STATE TO BE DESIRABLE
        //PIDControl.move(output + correctionOutput, output - correctionOutput);

      }
      else if (fabs(enterAngle + Gyro.rotation()) < targetAngle) {
       leftDrive.spin(directionType::fwd, output - correctionOutput, voltageUnits::volt);
       rightDrive.spin(directionType::fwd, output + correctionOutput, voltageUnits::volt);
        // UPDATES MACHINE STATE TO BE DESIRABLE
        //PIDControl.move(output + correctionOutput, output - correctionOutput);

      }

      // IF MACHINE STATE DESIRABLE CONTINUE PID
      else {
        leftDrive.spin(directionType::fwd, output, voltageUnits::volt);
        rightDrive.spin(directionType::fwd, output, voltageUnits::volt);
      }

      // DEBUGGING
      std::cout << "power: " << output << std::endl;
      std::cout << "error: " << error << std::endl;

      // UPDATES PREVIOUS TIME
      prevTime = t.time(msec);

      // ALLOWS FOR UDATES TO VALUES
      wait(15, msec);
    }

    // STOPS THE ROBOT PREVENTS FURTHER MOVEMENT
    //PIDControl.rest();
    leftDrive.stop(hold);
    rightDrive.stop(hold);
  }
 void wscreen(){
    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(white);
    Controller1.Screen.clearScreen();
    Controller1.Screen.print(";)");


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
   while (Gyro.isCalibrating()) {
     wait(100, msec);
   }

  //bL.setVelocity(100, percent);
   //bL.rotateTo(-3.2,rev);
   //resetbL();
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
   moveFwd(100, 12);
   /*Notes
   driveBase.driveFor(fwd, 10, inches, 50, velocityUnits::pct);
   bL.rotateTo(-4.5,rev, true);
   driveBase.driveFor(fwd, 15, inches, 50, velocityUnits::pct);
   pringle.spin(reverse, 100, percentUnits::pct);
   wait(300, msec);
   pringle.stop();
   auton = true;
   line1.changed(Aclamp1On);
   waitUntil(clampOn == true);
   driveBase.driveFor(30, inches, 100, velocityUnits::pct);
   driveBase.turnFor(-90, rotationUnits::deg, 60, velocityUnits::pct);
   Brain.Screen.setFillColor(white);
   moveFwd(55, 12);*/
   //wait(30, msec);
   /*driveBase.driveFor(48, inches, 100, velocityUnits::rpm);
   waitUntil(driveBase.isDone());
   driveBase.driveFor(6, inches, 10, velocityUnits::rpm,false);
   line1.changed(Aclamp1On);*/
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
   cont = 2;
   Forward = 0;
   clampOn = false;
   Pring = 1;
   //bL.setVelocity(100, percent);
   //bL.rotateTo(-3.2,rev, false);
   //resetbL();
   //bL.setPosition(0, rev);
   //pringON();
   std::cout<<Controller1.Axis3.position(pct)<<Controller1.Axis2.position(pct)<<std::endl;
   contAVal[0] = Controller1.Axis3.position(pct);
   contAVal[1] = Controller1.Axis2.position(pct);
   contAVal[2] = Controller1.Axis1.position(pct);
   contAVal[3] = Controller1.Axis4.position(pct);
   while (1) {
     std::cout<<cont<<std::endl;
     int X = Controller1.Axis3.value();
     int Y = Controller1.Axis2.value();
     int W = Controller1.Axis3.value();
     int Z = Controller1.Axis1.value();
     switch(cont){
       case 1:
         
         leftDrive.spin(directionType::fwd,X, velocityUnits::pct);
         rightDrive.spin(directionType::fwd,Y, velocityUnits::pct);
         Controller1.Screen.clearScreen();
         Controller1.Screen.print("Tank");
         Controller1.Screen.clearLine();
         std::cout<<contAVal[0]<<contAVal[1]<<std::endl;
         break;

       case 2:
        
         leftDrive.spin(directionType::fwd,W, velocityUnits::pct);
         MotorRb.spin(directionType::fwd,W, velocityUnits::pct);
         MotorRf.spin(directionType::rev,W, velocityUnits::pct);
         Controller1.Screen.clearScreen();
         Controller1.Screen.print("arcade");
         Controller1.Screen.clearLine();
         
         break;
     }
     switch(Pring){
       case 1:
       pringle.stop();
       break;

       case 2:
       pringle.spin(fwd, 200, velocityUnits:: pct);
         std::cout<<"prongTake"<<std::endl;
         if (Lift1.position(rotationUnits::rev) < .2){
            Lift1.setVelocity(100, percentUnits::pct);
            Lift1.rotateTo(.3, rev, false);
          }
          else if (pringle.isDone() && Lift1.position(rotationUnits::rev) <= .2 ){
            Lift1.rotateTo(0, rev, false);


          }
          else {}
          break;


     }
     std::cout<<bLR.position(rev)<<std::endl;
     //have gyro print position for auton
     Brain.Screen.clearScreen();
     Brain.Screen.printAt(20, 80, "gyro (degrees)");
     Brain.Screen.printAt(20, 120, "Reading =%f");
      if (RobotIsWorking == false){
        RobotIsWorking = true;


      }
       // this stops the robot for tokoy driting
       float x = Controller1.Axis3.value();
       float y = Controller1.Axis2.value();
       if (fabs(x) < 10) {
         leftDrive.stop();//dosen't match cause its dumb
       leftDrive.setVelocity(0, percent);
       }


       else {
       leftDrive.setVelocity(x, percent);

       }
       if (fabs(y) < 10) {
         rightDrive.stop();
       rightDrive.setVelocity(0, percent);

     }


     else {
     rightDrive.setVelocity(y, percent);

     }

    /* if (Arcade == false){
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

         }*/
       if (sM == false){
         score_macro();

       }
       else{
         sM = true;

       }
       /*if (Pring == 1 && rp == false){

         //std::cout<<"Pring On"<<std::endl;
         pringle.spin(reverse, 200, velocityUnits:: pct);
         std::cout<<"pringTake"<<std::endl;
         if (Lift1.position(rotationUnits::rev) < .2){
            Lift1.setVelocity(100, percentUnits::pct);
            Lift1.rotateTo(.3, rev, false);
          }
          else if (pringle.isDone() && Lift1.position(rotationUnits::rev) <= .2 ){
            Lift1.rotateTo(0, rev, false);
    

          }
          else {}

       }
       else if (Prong == 1 && rp == true){
         pringle.spin(fwd, 200, velocityUnits:: pct);
         std::cout<<"prongTake"<<std::endl;
         if (Lift1.position(rotationUnits::rev) < .2){
            Lift1.setVelocity(100, percentUnits::pct);
            Lift1.rotateTo(.3, rev, false);
          }
          else if (pringle.isDone() && Lift1.position(rotationUnits::rev) <= .2 ){
            Lift1.rotateTo(0, rev, false);


          }
          else {}
       }
       else{
         //std::cout<<"Pring Off"<<std::endl;
          pringle.stop();

       }*/
       if (pringle.temperature(celsius) >= 55){

         std::cout<<"Thats one spicy Pringel"<<std::endl;
         Controller1.Screen.print("spicy pring");
         Controller1.Screen.clearLine();
         //std::cout<<pringle.temperature(celsius)<<std::endl;
       }
       else{


       }
       if (Forward == 0){


       }



       //if (Pring > 1) {
        //  Pring = 0;
        //}*/


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
       Controller1.ButtonY.pressed(resetAll);
       Controller1.ButtonLeft.pressed(pringSet);
       Controller1.ButtonRight.pressed(setCont);


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
