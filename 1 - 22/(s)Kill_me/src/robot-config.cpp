#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorLf = motor(PORT1, ratio6_1, true);
motor MotorLb = motor(PORT2, ratio6_1, true);
motor MotorRf = motor(PORT14, ratio6_1, false);
motor MotorRb = motor(PORT15, ratio6_1, false);
motor Clamp1 = motor(PORT7, ratio18_1, false);
motor Lift1 = motor(PORT11, ratio36_1, false);
motor bL1 = motor(PORT18, ratio18_1, false);
inertial Gyro = inertial(PORT9);
line line1 = line(Brain.ThreeWirePort.A);
motor pringle = motor(PORT12, ratio18_1, false);
rotation bLR = rotation(PORT10, false);
motor bL2 = motor(PORT20, ratio18_1, false);
motor_group leftDrive(MotorLf,MotorLb);// group for the left side 
motor_group rightDrive(MotorRf,MotorRb);// group for the right side 
motor_group bL(bL1,bL2);// group for back Lift (bL)
motor_group all(bL1,bL2,Lift1, Clamp1);// used for testing DNU
smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);
 //^all drive motors including the Intergral sensor to simplfy auton and have acurate turring
 
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}