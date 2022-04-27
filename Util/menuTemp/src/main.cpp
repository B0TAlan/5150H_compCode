/*------------------------------------------------------------------------------------------*/
/*                                                                                          */
/*    this is a basic temlate for a auton selection menu                                    */
/*                                                                                          */
/*    to use put all your auton in their on .cpp file with a .h with the same               */
/*      name then copie ButtonClass.h & Menu.h into your include folder then                */
/*       #include your autons in Menu.h setup your Output() method and set it up            */
/*         in main.cpp like its is down below                                               */
/*                                                                                          */
/*    how the buttons work:                                                                 */
/* lcdButton buttonName(x, y, width, height, "text", "innerHex", "outerHex", sizeOfBorder); */
/*                                                                                          */
/*      buttonName.enable() prints button @ x,y || buttonName.disable() hides button        */
/*                                                                                          */
/*                                                                                          */
/*                  menu templete made by: Alan Schneider ~ 5150H                           */
/*                 button config made by: Andrew Simonson ~ 96807B                          */
/*              (https://www.vexforum.com/t/vexcode-button-generator/72450)                 */
/*                                                                                          */
/*------------------------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

// this is using the comp template btw

#include "vex.h"
#include "exampleMenu.h"

using namespace vex;

// A global instance of competition
competition Competition;
//className objectName;
   exampleMenu menu;
// define your global instances of motors and other devices here

void pre_auton(void) {
  menu.Input(); // starts the input for the menu
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  // ..........................................................................
  menu.Output();// send the output of the menu
  // ..........................................................................
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
