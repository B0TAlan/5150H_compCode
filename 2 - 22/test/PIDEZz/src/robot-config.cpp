#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorLf = motor(PORT1, ratio6_1, true);//
motor MotorLb = motor(PORT2, ratio6_1, true);//
motor MotorRf = motor(PORT20, ratio6_1, false);//
motor MotorRb = motor(PORT15, ratio6_1, false);//
motor MotorRm = motor(PORT16, ratio6_1, false);//
motor MotorLm = motor(PORT3, ratio6_1, false);//
inertial Gyro = inertial(PORT9);
//motor_group all(bL1,bL2,Lift1, Clamp1);// used for testing DNU
//smartdrive driveBase = smartdrive(leftDrive, rightDrive, Gyro, 319.19, 342.9, 203.2, mm, .5);
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
