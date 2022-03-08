#include "MasterAuton.h"
#include "MasterHeader.h"
#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

// reps whitch auton will run
bool runR = false;    // right auton
bool runL = false;    // left auton
bool runW = false;    // solo awp
bool runSK = false;   // skills
bool noRun = true;    // no auton
bool runRM = false; 
int opt = 6;          // index for menu
bool preATon = false; // states when pre auton is running
bool Dcont = false;
//^ to have it constly run only during pre auton

void clearPrint(int B, int C, int C2) {
  if (C == 1){
    Controller1.Screen.clearScreen();
  } 
  if (B == 1){
    Paincreas.Screen.clearScreen();
  }
  if (C2 == 1){
    Controller2.Screen.clearScreen();
  }
  if (C == 1 && B == 1  && C2 == 1){
    Controller1.Screen.clearScreen();
    Paincreas.Screen.clearScreen();
    Controller2.Screen.clearScreen();
  }    
}

void NAton() {
  // if no auton is selected just prits stuff to the screen
  Paincreas.Screen.setFont(mono60);
  // Paincreas.Screen.print("SADGE");
  
}

void gyroConfig() {
  Gyro.calibrate();              // start the gyro calabration
  while (Gyro.isCalibrating()) { // calabrates gyro
    std::cout << "Gyro is calibrating" << std::endl;
    wait(300, msec); // waits until teh calabration is done
  }
  std::cout << "Gyro is calibrated" << std::endl;
  Controller1.Screen.print("calibrated");
}

void menu() {
  // opt = 1;                       // sets index to 1

  // while (preATon == true) { // only during pre Auton
  Controller2.Screen.clearScreen();
  wait(30, msec);
  //^ clear controller screen
  // while (preATon == true) { // only during pre Auton
  switch (opt) {

  case 1:

    // Menu: Main Menu :index 1

    // prints autons & controls
    waitUntil(opt == 1); // waits till index = case
    Paincreas.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("R = Y | L = A");
    Controller2.Screen.setCursor(2, 1);
    Controller2.Screen.print("Skills = X | RM = Left");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("N/A = Right");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;

  case 2:

    // Menu: Right Auton :inex 2

    // prints autons & controls
    waitUntil(opt == 2);
    Controller2.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("Will run RightTon");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("RightTon selcected");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;

  case 3:

    // Menu: Left Auton :index 3
    // prints autons & controls
    waitUntil(opt == 3); // wait till index = case
    Paincreas.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("Will run LeftTon");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("LeftTon selcected");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = true;   // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;
  case 4:

    // Menu: solo awp :index 4
    // prints autons & controls
    waitUntil(opt == 4); // wait till index = case
    wait(30, msec);
    Paincreas.Screen.clearScreen();
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("solo Awp will run");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("Solo Awp");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;

  case 5:

    // Menu: No auton :index 5
    // prints autons & controls
    waitUntil(opt == 5); // wait un till index = case
    Paincreas.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("No AUTON WILL RUN");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("NO AUTON SELECTED");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;

  case 0:
    // Menu: Page 2 :index 0
    // prints autons & controls
    waitUntil(opt == 0); // wait till index = case
    Paincreas.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("Right Mid will run");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("Right Mid");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = false; // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;

  case 6:
    // Menu: No auton :index 6
    // prints autons & controls
    waitUntil(opt == 6); // wait un till index = case
    Paincreas.Screen.clearScreen();
    wait(30, msec);
    Controller2.Screen.setCursor(1, 1);
    Controller2.Screen.print("Skills auton will run");
    Controller2.Screen.setCursor(3, 1);
    Controller2.Screen.print("press B to go back");
    Paincreas.Screen.clearScreen();
    Paincreas.Screen.setFont(mono60);
    Paincreas.Screen.print("Skills");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = true;  // will not run skills
    // prints state for debuging
    std::cout << "rState = " << runR << std::endl;
    std::cout << "LState = " << runL << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

    break;
  }
  vex::task::sleep(40);
  //}
}

void setR() { // set index to 2
  opt = 2;
  menu();
}

void setL() { // set index to 3
  opt = 3;
  menu();
}

void noTon() { // set index to 5
  opt = 5;
  menu();
}

void setW() { // set index to 4
  opt = 4;
  menu();
}

void back() { // set index to 1

  opt = 1;
  menu();
}

void setSK() { // set index to 6
  opt = 6;
  menu();
}

void p2() { // set index to 0
  opt = 0;
  menu();
}

void menuInput() {
    opt = 1;
    menu();
    // change to if presseing 
    Controller2.ButtonY.pressed(setR); // sets runR to true
    Controller2.ButtonA.pressed(setL); // sets runL to true
    // Controller2.ButtonDown.pressed(p2);    // sets runW
    Controller2.ButtonX.pressed(setSK); // sets runW to true
    // Controller2.ButtonDown.pressed(setSK); // sets runSK to true
    Controller2.ButtonRight.pressed(noTon); // sets noRun to true
    Controller2.ButtonRight.pressed(p2);
    Controller2.ButtonB.pressed(back);      // return to index 1

    // redBPressed(2);
    // blueBPressed(3);
  
}

void menuOutput() {
  preATon = false;

  if (runL) { // if runL = true
     left20();         // run the left auton
  } else if (runR) { // if runR = true
     right20();        // run right side auton
  } else if (noRun) { // if noRun = true
    NAton();          // run this mostly empty void
  } else if (runW) {  // if runW = true
    // soloWP();         // run the solo awp
  } else if (runSK) { // if runSK = true
    Skills();         // run the skill auton
  }else if (runRM) { // if runSK = true
    rightMid(); 
  }  
}