using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern line line1;
extern motor Clamp1;
extern light Light1;
extern signature viz1__YG;
extern signature viz1__RG;
extern signature viz1__BG;
extern signature viz1__PRING;
extern signature viz1__SIG_5;
extern signature viz1__SIG_6;
extern signature viz1__SIG_7;
extern vision viz1;
extern controller Controller1;
extern motor lf;
extern motor lb;
extern motor rf;
extern motor rb;
extern inertial Gyro;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );