using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lf;
extern motor lb;
extern motor rf;
extern motor rb;
extern motor clamp;
extern motor lift;
extern motor ag1;
extern motor pringle;
extern motor ag2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );