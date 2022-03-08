#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
line line1 = line(Brain.ThreeWirePort.A);
motor Clamp1 = motor(PORT21, ratio18_1, false);
light Light1 = light(Brain.ThreeWirePort.C);
/*vex-vision-config:begin*/
signature viz1__YG = signature (1, 0, 0, 0, 0, 0, 0, 3, 0);
signature viz1__RG = signature (2, 8213, 8797, 8505, -1187, -559, -873, 3, 0);
signature viz1__BG = signature (3, -4283, -3599, -3941, 9425, 11099, 10262, 3, 0);
vision viz1 = vision (PORT9, 50, viz1__YG, viz1__RG, viz1__BG);
/*vex-vision-config:end*/
controller Controller1 = controller(primary);
motor lf = motor(PORT14, ratio18_1, false);
motor lb = motor(PORT2, ratio18_1, false);
motor rf = motor(PORT20, ratio18_1, true);
motor rb = motor(PORT12, ratio18_1, true);
inertial Gyro = inertial(PORT6);

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