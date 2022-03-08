using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor MotorLf;
extern controller Controller1;
extern motor MotorLb;
extern motor MotorRf;
extern motor MotorRb;
extern motor Lift1;
extern motor bL1;
extern motor bL2;
extern inertial Gyro;
extern motor Clamp1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );