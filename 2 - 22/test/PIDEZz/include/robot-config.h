using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Lf;
extern motor Lb;
extern motor Rf;
extern motor Rb;
extern motor Rm;
extern motor Lm;
extern inertial Gyro;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );