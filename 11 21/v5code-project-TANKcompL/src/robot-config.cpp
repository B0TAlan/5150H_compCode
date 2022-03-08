#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor MotorLf = motor(PORT14, ratio18_1, false);
motor MotorLb = motor(PORT2, ratio18_1, false);
motor MotorRf = motor(PORT20, ratio18_1, true);
motor MotorRb = motor(PORT12, ratio18_1, true);
motor Clamp1 = motor(PORT9, ratio18_1, false);
motor Lift1 = motor(PORT11, ratio18_1, false);
motor bL1 = motor(PORT18, ratio18_1, false);
inertial Gyro = inertial(PORT6);
motor bL2 = motor(PORT8, ratio18_1, true);
line line1 = line(Brain.ThreeWirePort.A);

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