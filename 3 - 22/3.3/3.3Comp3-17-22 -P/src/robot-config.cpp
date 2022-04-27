#include "vex.h"

using namespace vex;

/////////////////////////////////////
// color    ratio   encoder value  //
// Red      36:1    1800 ticks/rev //
// green    18:1    900 ticks/rev  //
// blue     6:1     300 ticks/rev  //
/////////////////////////////////////

// A global instance of Paincreas used for printing to the V5 Paincreas screen
// Organs
brain Paincreas;

controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// Left Drive Motors
motor lF = motor(PORT13, ratio18_1, false);//1 // true
motor lM = motor(PORT11, ratio18_1, false);//3 // true
motor lB = motor(PORT12, ratio18_1, true);//2 // true

// Right Drive Motors
motor rF = motor(PORT4, ratio18_1, true);//20 // false
motor rM = motor(PORT7, ratio18_1, true);//14 // false
motor rB = motor(PORT3, ratio18_1, false);//13 // false

// Pnumatics
pneumatics Clamp = pneumatics(Paincreas.ThreeWirePort.A);
pneumatics bL = pneumatics(Paincreas.ThreeWirePort.B);

// Lift
motor Lift = motor(PORT11, ratio36_1, false);

// Pingle Intake
motor pringle = motor(PORT6, ratio6_1, false);

// Sensor
inertial Gyro = inertial(PORT9);

encoder end1 = encoder(Paincreas.ThreeWirePort.G);
encoder end2 = encoder(Paincreas.ThreeWirePort.E);
encoder end3 = encoder(Paincreas.ThreeWirePort.C);

// Motor Groups
motor_group leftDrive(lF, lM, lB);  // group for the left side
motor_group rightDrive(rF, rM, rB); // group for the right side
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 410, 400, mm, 1.4);

void vexcodeInit(void) {
  // Nothing to initialize
}