
//dose not work is not continuous and dose not invert 
/*bool Forward = true;
    // move if states to void call voidses 
    //if up is preesed bool = true 
    if (Controller1.ButtonUp.pressing()) {

      Forward = true;


    }
    //if right pressed bool = false 
    if (Controller1.ButtonRight.pressing()) {

      Forward = false;


    }
    //
    if (Forward){
      
        leftDrive.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
        rightDrive.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      
    }
    else (Forward = false); {
      
        leftDrive.spin(directionType::rev,Controller1.Axis3.value(), velocityUnits::pct);
        rightDrive.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);
        */

 //first atemp at pid but was not formated properly and there was a easier way to implemnt 
 /*
//PID settings
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;

int error = 0;//snesorValue - desiredValue :potionial val
int prevError;// postioin 20milsec ago
int drivative;//
int totalError;//

//auton settings 
int disiredvalue = 200;

//PID varables for use 
int drivePidTo(double inches) {
   while(drivePIDB){
    //get motor position
    int leftMotorPostion = leftDrive.position(degrees);
    int rightMotorPostion = rightDrive.position(degrees);
    int avergePosition = (leftMotorPostion + rightMotorPostion)/2; // get mean of motor positions

    prevError=error;
    vex::task::sleep(20);
  }
  return 1;
}
 */
 //vex::task mGoal(drivePID);
 
/* old code
// basic auton to grab ymgoal then grab colord mgoal inconsitent 
  Brain.Screen.print("Snack Bot Best Bot");
  Lift1.spinFor(forward, 1, rev);
  driveBase.driveFor(forward, 53,inches);
  //Clamp1.spinFor(forward, 1, rev);
  driveBase.turnFor(right, 10, degrees);
  driveBase.driveFor(reverse, 55,inches);
  driveBase.turnFor(right, 15, degrees);

*/


void badPID(){
    /*PID settings BAD PID
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;
double turnkP = 0.0;
double turnkI = 0.0;
double turnkD = 0.0;

int error ;//snesorValue - desiredValue :potionial val
int prevError =0;// postioin 20milsec ago
int derivative;// error-prevError :speed
int totalError = 0;// = totalerror + error

int turnError ;//snesorValue - desiredValue :potionial val
int turnPrevError =0;// postioin 20milsec ago
int turnDerivative;// error-prevError :speed
int turnTotalError = 0;// = totalerror + error

bool resetDriveSensors = false;

//auton settings 
int disiredValue = 200;
int disiredTurnValue = 0;
//PID varables for use 
int drivePidTo(double inches) {
  while(drivePID){

    if (resetDriveSensors){
      resetDriveSensors = false;
      leftDrive.setPosition(0, degrees);
      rightDrive.setPosition(0, degrees);

    }
    //get motor position
    int leftMotorPostion = leftDrive.position(degrees);
    int rightMotorPostion = rightDrive.position(degrees);
    /////////////////////////////////////////////////////
    //Lateral Movement Pid
    /////////////////////////////////////////////////////////////////////////////////////////////
    int avergePosition = (leftMotorPostion + rightMotorPostion)/2; // get mean of motor positions
    //potental
    error = avergePosition - disiredValue;
    //derivitve 
    derivative = error - prevError;
    //intergral
    //totalError += error;
    
    double lateralMotorPower = (error * kP + derivative )/12.0;
    /////////////////////////////////////////////////////////////////////////////
    
    ////////////////////
    //Turning Movement Pid
    ////////////////////////////////////////////////////////////////////////////
    int turnDiffernce = leftMotorPostion - rightMotorPostion; // get mean of motor positions
    //potental
    turnError = turnDiffernce - disiredTurnValue;
    //derivitve 
    turnDerivative = turnError - turnPrevError;
    //intergral
   // turnTotalError += turnError;
    
    double turnMotorPower = (turnError * turnkP + turnDerivative)/12.0;

    ////////////////////////////////////////////////////////////////////////////
    rightDrive.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt );
    leftDrive.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt );
    vex::task::sleep(20);
  }
  return 1;
}*/




}
//12.56, 16, 16 // old driveTrain units for godTon

/*///////////////////////////////////////////////////

int mGoalF() {
     
    while(auton == true){
     Brain.Screen.print(line1.value(analogUnits::pct));
     Brain.Screen.clearLine();
     if ( line1.value(percent) < 60 || line1.value(percent) == 0){
       Clamp1.rotateTo(-1.2, rotationUnits::rev,100,velocityUnits::pct, true);
       waitUntil(Clamp1.isDone());
       clampOn =true;
       
     }
     else if (line1.value(percent) > 60) {
  
       Clamp1.rotateTo(0, rev);
       waitUntil(Clamp1.position(rev)== 0);
       clampOn = false;
     } 
     
    }
    
    return 1;
   }  
   task grabMGoal = task(mGoalF);*/
   /*//////////////////////////////////////////////////
      auton = true;
   clampOn = false;
    //driveForward(44);
   //driveBase.setDriveVelocity(100, percentUnits::pct);
   //dirveToPid(20);
   //Sart of BLock 1
    vexcodeInit();

    driveBase.setDriveVelocity(100, percent);
    driveBase.driveFor(37, inches, true);
    driveBase.setDriveVelocity(30, percent);
    driveBase.driveFor(8, inches, 15, velocityUnits:: pct, true);
    //driveBase.driveFor(5, inches, 20, velocityUnits:: pct, true);
    //auton = true;
    //task grabMGoal(mGoalF);
    Aclamp1On();
    waitUntil(clampOn == true);
    Clamp1.stop();
    driveBase.driveFor(-40, inches, 80, velocityUnits::pct,true);
    bL.setVelocity(100, percent);
    bL.spinFor(-1.75,rev, false);
    resetbL();
    
    //driveBase.driveFor(-10, inches, 50, velocityUnits::pct,true);
    //-----------------------------------------------------------//
    driveBase.turnToHeading(262, ::deg, 80, velocityUnits::pct);
    bL.spinFor(-1.6,rev, true);
    driveBase.driveFor(-14, inches, 30, velocityUnits:: pct, true);
    bLUp();
   // bL.setVelocity(100, percent);
   // bLDown();
    //driveBase.driveFor(-12, inches, 50, velocityUnits:: pct, true);
    
    //driveBase.turnFor(-90, rotationUnits::deg, 80, velocityUnits:: pct, true);
    //driveBase.driveFor(7, inches, 80, velocityUnits::pct,true);
    //bLDown();
    //driveBase.driveFor(-15, inches, 30, velocityUnits::pct,true)*/