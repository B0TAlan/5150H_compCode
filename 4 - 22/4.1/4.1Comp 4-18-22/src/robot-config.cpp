#include "vex.h"

using namespace vex;

/////////////////////////////////////
// color    ratio   encoder value  //
// Red      36:1    1800 ticks/rev //
// green    18:1    900 ticks/rev  //
// blue     6:1     300 ticks/rev  //
/////////////////////////////////////

//____DEAD_PORTS____//
//      PORT20      //
//__________________//

// A global instance of Paincreas used for printing to the V5 Paincreas screen
// Organs
brain Paincreas;

controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// Left Drive Motors
motor lF = motor(PORT1, ratio18_1, false);
motor lM = motor(PORT3, ratio18_1, false);
motor lB = motor(PORT2, ratio18_1, true);

// Right Drive Motors
motor rF = motor(PORT15, ratio18_1, true);
motor rM = motor(PORT14, ratio18_1, false);
motor rB = motor(PORT13, ratio18_1, true);

// Pnumatics
pneumatics Clamp = pneumatics(Paincreas.ThreeWirePort.A);
pneumatics bC = pneumatics(Paincreas.ThreeWirePort.B);
pneumatics bW = pneumatics(Paincreas.ThreeWirePort.C);

// Lift
motor Lift = motor(PORT10, ratio36_1, false);

// Pingle Intake
motor pringle = motor(PORT11, ratio6_1, false);

// Sensor
inertial Gyro = inertial(PORT16);
rotation endL = rotation(PORT7, false);
rotation endR = rotation(PORT8, true);

// Motor Groups
motor_group leftDrive(lF, lM, lB);  // group for the left side
motor_group rightDrive(rF, rM, rB); // group for the right side
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 410, 400, mm, 1.4);

void vexcodeInit(void) {
  // Nothing to initialize
}

