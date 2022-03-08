using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor MotorLf;
extern motor MotorLb;
extern motor MotorRf;
extern motor MotorRb;
extern motor Clamp1;
extern motor Lift1;
extern motor bL1;
extern inertial Gyro;
extern motor bL2;
extern line line1;
extern motor pringle;
extern rotation bLR;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );