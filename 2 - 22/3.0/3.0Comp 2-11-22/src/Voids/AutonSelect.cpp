#include "ButtonClass.h"
#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>


// creates a on screen button
lcdButton redButton(120, 22, 230, 35, "Right", "#252525", "#FF2525", 2);
lcdButton blueButton(480 - 120, 22, 230, 35, "Left", "#252525", "#2525FF", 2);

// reps whitch auton will run
bool runR = false;    // right auton
bool runL = false;    // left auton
bool runW = false;    // solo awp
bool runSK = false;   // skills
bool noRun = true;    // no auton
int opt = 6;          // index for menu
bool preATon = false; // states when pre auton is running
bool Dcont = false;
//^ to have it constly run only during pre auton

void clearPrint(int B, int C) {
  if (C == 1)
    Controller1.Screen.clearScreen();
  else if (B == 1)
    Brain.Screen.clearScreen();
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

void NAton() {
  // if no auton is selected just prits stuff to the screen
  Brain.Screen.setFont(mono60);
  // Brain.Screen.print("SADGE");
  Brain.Screen.drawImageFromFile("ham.png", 235, 0);
}

void redBPressed(int i) {
  //^ if the on screen button is pressed set the index to i
  if (redButton.pressing())
    opt = i;
  else {
  }
}

void blueBPressed(int i) {
  //^ if the on screen button is pressed set the index to i
  if (blueButton.pressing())
    opt = i;
  else {
  }
}

void gyroConfig() {
  Gyro.calibrate();              // start the gyro calabration
  while (Gyro.isCalibrating()) { // calabrates gyro
    std::cout << "Gyro is calabrating" << std::endl;
    Brain.Screen.drawImageFromFile("(s)kils.png", 0, 0);
    wait(200, msec); // waits until teh calabration is done
  }
  std::cout << "Gyro is calabrated" << std::endl;
}

void menu() {
  // opt = 1;                       // sets index to 1

  // while (preATon == true) { // only during pre Auton
  Controller1.Screen.clearScreen();
  wait(30, msec);
  //^ clear controller screen
  // while (preATon == true) { // only during pre Auton
  switch (opt) {

  case 1:

    // Menu: Main Menu :index 1

    // prints autons & controls
    waitUntil(opt == 1); // waits till index = case
    Brain.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("R = Y | L = A");
    Controller1.Screen.setCursor(2, 1); 
    Controller1.Screen.print("Awp = X");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("N/A = Right");
    redButton.draw();  // drawn onscreen button
    blueButton.draw(); // drawn onscreen button

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
    Controller1.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Will run RightTon");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("press B to go back");
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("RightTon selcected");

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
    Brain.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Will run LeftTon");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("press B to go back");
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("LeftTon selcected");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = true;  // will not run left
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
    Brain.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("solo Awp will run");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("press B to go back");
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("Solo Awp");

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
    Brain.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("No AUTON WILL RUN");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("press B to go back");
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("NO AUTON SELECTED");

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
    waitUntil(opt == 6); // wait till index = case
    Brain.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("SoloWp = Right");
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Skills = Left");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("NoTon = X");

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
    Brain.Screen.clearScreen();
    wait(30, msec);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Skills auton will run");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("press B to go back");
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("Skills");

    // Output
    noRun = false; // will not run a auton
    runR = false;  // will not run right
    runL = false;  // will not run left
    runW = false;  // will not run solo awp
    runSK = true; // will not run skills
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

void menuInput() {
  opt = 1;
  menu();
  while (preATon == true && Dcont == false) { // only during pre Auton

    Controller1.ButtonY.pressed(setR); // sets runR to true
    Controller1.ButtonA.pressed(setL);  // sets runL to true
    //Controller1.ButtonDown.pressed(p2);    // sets runW
    Controller1.ButtonX.pressed(setW);    // sets runW to true
    Controller1.ButtonDown.pressed(setSK); // sets runSK to true
    Controller1.ButtonRight.pressed(noTon);    // sets noRun to true
    Controller1.ButtonB.pressed(back);     // return to index 1
    
    redBPressed(2);
    blueBPressed(3);

    if (Dcont == true)
      break;
    

    wait(20, msec);
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
  } else if (runSK) {  // if runSK = true
    skills();         // run the skill auton
  }
}