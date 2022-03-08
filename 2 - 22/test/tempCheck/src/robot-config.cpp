#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor lf = motor(PORT1, ratio6_1, true);
motor lb = motor(PORT2, ratio6_1, true);
motor lm = motor(PORT3, ratio6_1, true);
motor rf = motor(PORT20, ratio6_1, false);
motor rb = motor(PORT13, ratio6_1, false);
motor rm = motor(PORT14, ratio6_1, false);
motor pringle = motor(PORT6, ratio18_1, false);
motor lift = motor(PORT11, ratio36_1, false);
pneumatics clamp = pneumatics(Brain.ThreeWirePort.A);
pneumatics bL = pneumatics(Brain.ThreeWirePort.A);

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