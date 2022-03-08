#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
// Organs 
brain Brain;

controller Controller1 = controller(primary);

//Left Drive Motors
motor lF = motor(PORT1, ratio6_1, true);
motor lM = motor(PORT3, ratio6_1, true);
motor lB = motor(PORT2, ratio6_1, true);

//Right Drive Motors
motor rF = motor(PORT20, ratio6_1, false);
motor rM = motor(PORT14, ratio6_1, false);
motor rB = motor(PORT13, ratio6_1, false);

//Pnumatics
pneumatics Clamp = pneumatics(Brain.ThreeWirePort.A);
pneumatics bL = pneumatics(Brain.ThreeWirePort.B);

//Lift
motor Lift = motor(PORT11, ratio36_1, false);

//Pingle Intake
motor pringle = motor(PORT6, ratio6_1, false);

//Sensor
inertial Gyro = inertial(PORT9);

//Motor Groups
motor_group leftDrive(lF,lM, lB);// group for the left side
motor_group rightDrive(rF,rM, rB);// group for the right side
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 410, 400, mm, .5);

void vexcodeInit(void) {
  // Nothing to initialize
}