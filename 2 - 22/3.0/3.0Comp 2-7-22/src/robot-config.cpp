#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller Controller1 = controller(primary);
motor Lf = motor(PORT1, ratio6_1, true);
motor Lb = motor(PORT2, ratio6_1, true);
motor Lm = motor(PORT3, ratio6_1, true);
motor Rf = motor(PORT14, ratio6_1, false);
motor Rb = motor(PORT15, ratio6_1, false);
motor Rm = motor(PORT16, ratio6_1, false);
pneumatics Clamp = pneumatics(Brain.ThreeWirePort.A);
motor Lift = motor(PORT11, ratio36_1, false);
pneumatics bL = pneumatics(Brain.ThreeWirePort.B);
inertial Gyro = inertial(PORT6);
line line1 = line(Brain.ThreeWirePort.A);
motor pringle = motor(PORT12, ratio6_1, false);
encoder end1 = encoder(Brain.ThreeWirePort.C);
encoder end2 = encoder(Brain.ThreeWirePort.G);
motor_group leftDrive(Lf,Lb, Lm);// group for the left side
motor_group rightDrive(Rf,Rb, Rm);// group for the right side
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);


void vexcodeInit(void) {
  // Nothing to initialize
}