using namespace vex;

extern brain Brain;
extern controller Controller1;
extern motor Lf;
extern motor Lb;
extern motor Rf;
extern motor Rb;
extern motor Lift;
extern motor bL1;
extern inertial Gyro;
extern line line1;
extern motor pringle;
extern rotation bLR;
extern encoder end1;
extern encoder end2;
extern pneumatics Clamp;
extern motor_group leftDrive;
extern motor_group rightDrive;
extern smartdrive driveBase;
extern motor Lm;
extern motor Rm;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
