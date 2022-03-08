#include "ButtonClass.h"
#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>


lcdButton redButton(120, 22, 230, 35, "this is a test oga booga", "#252525", "#FF2525", 2);
//^ creates a on screen button

// reps whitch auton will run
bool runR = false; // right auton
bool runL = false; // left auton
bool runW = false; // solo awp
bool noRun = true; // no auton
int opt = 6;       // index for menu
bool preATon = false;
//^ to have it constly run only during pre auton

void setR() { // set index to 2
  if (opt != 2)
    opt = 2;
}

void setL() { // set index to 3
  if (opt != 3)
    opt = 3;
}

void noTon() { // set index to 5
  if (opt != 5)
    opt = 5;
}

void setW() { // set index to 4
  if (opt != 4)
    opt = 4;
}

void back() { // set index to 1
  if (opt != 1)
    opt = 1;
}

void p2() { // set index to 6
  if (opt != 6)
    opt = 6;
}

void NAton() {
  // if no auton is selected just prits stuff to the screen
  Brain.Screen.setFont(mono60);
  // Brain.Screen.print("SADGE");
  Brain.Screen.drawImageFromFile("ham.png", 100, 100);
}

void redBProssed(int i) {
  //^ if the on screen button is pressed set the index to i
  if (redButton.pressing())
    opt = i;
  else {
    opt = 1;
  }
}

void menuInput() {
  opt = 1;                       // sets index to 1
  Gyro.calibrate();              // start the gyro calabration
  while (Gyro.isCalibrating()) { // calabrates gyro
    std::cout << "Gyro is calabrating" << std::endl;
    wait(200, msec); // waits until teh calabration is done
    std::cout << "Gyro is calabrated" << std::endl;
  }
  //while (preATon == true) { // only during pre Auton
    Controller1.Screen.clearScreen();
    //^ clear controller screen
    while (preATon == true) { // only during pre Auton
    switch (opt) {

    case 1:

      // Menu: Main Menu :index 1

      // prints autons & controls
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("RightTon =");
      Controller1.Screen.setCursor(2, 1);        ///////////////////////////////////
      Controller1.Screen.print("LeftTon =");     // RightTon =     RightButton   //
      Controller1.Screen.setCursor(1, 5);        // LeftTon =      LeftButton    //
      Controller1.Screen.print("RightButton");   //                              //
      Controller1.Screen.setCursor(2, 5);        // More           Down          //
      Controller1.Screen.print("LeftButton");    //////////////////////////////////
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("More");
      Controller1.Screen.setCursor(3, 5);
      Controller1.Screen.print("Down");
      redButton.draw();

      // Controls
      Controller1.ButtonRight.pressed(setR); // sets runR to true
      Controller1.ButtonLeft.pressed(setL);  // sets runL to true
      Controller1.ButtonDown.pressed(p2);    // jumps to 2nd page(index 6)
      Controller1.ButtonB.pressed(back);     // returns to index 1
      redBProssed(2); // if onscreen button is pressed set index to 2
      
      // Output
      noRun = true; // will not run a auton
      runR = false; // will not run right
      runL = false; // will not run left
      runW = false; // will not run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;

    case 2:

      // Menu: Right Auton :inex 2

      // prints autons & controls
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("Will run RightTon");
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("press B to go back");
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(mono60);
      Brain.Screen.print("RightTon selcected");

      // Controls
      while (preATon == true) { // only during pre Auton
      Controller1.ButtonB.pressed(back); // return to index 1
      Brain.Screen.pressed(back);        // return to index 1
      }

      // Output
      noRun = false; // will run a auton
      runR = true;   // will run right
      runL = false;  // will not run left
      runW = false;  // will not run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;

    case 3:

      // Menu: Left Auton :index 3
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("Will run LeftTon");
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("press B to go back");
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(mono60);
      Brain.Screen.print("LeftTon selcected");

      // Controls
      Controller1.ButtonB.pressed(back); // return to index 1
      Brain.Screen.pressed(back);        // return to index 1
      Controller1.rumble("---");
      //^ idk wanted to see if controller would rumble

      // Output
      noRun = false; // wil run a auton
      runR = false;  // will not run Right auton
      runL = true;   // will run Left auton
      runW = false;  // will not run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;
    case 4:

      // Menu: solo awp :index 4
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("solo Awp will run");
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("press B to go back");
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(mono60);
      Brain.Screen.print("Solo Awp");

      // Controls
      Controller1.ButtonB.pressed(back); // return to index 1
      Brain.Screen.pressed(back);        // return to index 1
      Controller1.rumble("__.");

      // Output
      noRun = false; // will run a auton
      runR = false;  // will not run Right auton
      runL = false;  // will not run Left auton
      runW = true;   // will run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;

    case 5:

      // Menu: No auton :index 5
      // prints autons & controls
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("No AUTON WILL RUN");
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("press B to go back");
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(mono60);
      Brain.Screen.print("NO AUTON SELECTED");

      // Controls
      Controller1.ButtonB.pressed(back); // return to index 1
      Brain.Screen.pressed(back);        // return to index 1
      Controller1.rumble("._.");
      //^ differnt pattern cause why not

      // Output
      noRun = true; // no auton will run
      runR = false; // will not run Right auton
      runL = false; // will not run Left auton
      runW = false; // will not run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;

    case 6:
      // Menu: Page 2 :index 6
      // prints autons & controls
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print("SoloWp =");
      Controller1.Screen.setCursor(2, 1);
      Controller1.Screen.print("NoTon =");
      Controller1.Screen.setCursor(1, 3);
      Controller1.Screen.print("RightButton");
      Controller1.Screen.setCursor(2, 3);
      Controller1.Screen.print("X");
      Controller1.Screen.setCursor(3, 1);
      Controller1.Screen.print("Less");
      Controller1.Screen.setCursor(3, 3);
      Controller1.Screen.print("Down");

      // Controls
      Controller1.ButtonRight.pressed(setW); // sets runW to true
      Controller1.ButtonX.pressed(noTon);    // sets NAton to true
      Controller1.ButtonUp.pressed(back);    // return to index 1
      Controller1.ButtonB.pressed(back);     // return to index 1

      // Output
      noRun = true; // will not run a auton
      runR = false; // will not run Right auton
      runL = false; // will not run left auton
      runW = false; // will not run solo awp
      // prints state for debuging
      std::cout << "rState" << runR << std::endl;
      std::cout << "LState" << runL << std::endl;
      std::cout << "WState" << runW << std::endl;
      std::cout << "NoTon" << noRun << std::endl;

      break;
    }
  }
}

void menuOutput() {
  preATon = false;

  if (runL) {         // if runL = true
    left20();         // run the left auton
  } else if (runR) {  // if runR = true
    right20();        // run right side auton
  } else if (noRun) { // if noRun = true
    NAton();          // run this mostly empty void
  } else if (runW) {  // if runW = true
    soloWP();         // run the solo awp
  }
}