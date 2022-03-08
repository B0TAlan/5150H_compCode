#ifndef MENU_H
#define MENU_H

#include "ButtonClass.h"
#include "Autons.h"
#include "vex.h"


lcdButton rightBut(120, 22, 230, 35, "Right20", "#252525", "#FF2525", 2);
lcdButton leftBut(360, 22, 230, 35, "Left20", "#252525", "#2525FF", 2);
lcdButton right40But(120, 72, 230, 35, "RightMid", "#252525", "#FF2525", 2);
lcdButton lef40But(360, 72, 230, 35, "LeftMid", "#252525", "#2525FF", 2);
lcdButton skillBut(120, 122, 230, 35, "Skills", "#252525", "#2525FF", 2);
lcdButton awpBut(360, 122, 230, 35, "Dick Check", "#252525", "#2525FF", 2);
lcdButton NoBut(240, 220, 430, 35, "No Auton", "#252525", "#2525FF", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#2525FF", 2);

class testMenu {
private:
  bool runL = false;
  bool runR = false;
  bool runW = false;  // solo awp
  bool runSK = false; // skills
  bool noRun = false; // no auton
  bool runRM = false;
  bool runMenu = false;
  int index = 4;

  void Index() {
    switch (index) {
    case 1:
      Controller1.Screen.clearScreen();
      Paincreas.Screen.clearScreen();
      Controller1.Screen.print("right = right & left = left");
      rightBut.draw();
      leftBut.draw();
      skillBut.draw();
      lef40But.draw();
      right40But.draw();
      awpBut.draw();
      NoBut.draw();

      runL = false;
      runR = false;
      std::cout << runL << std::endl;
      std::cout << runR << std::endl;
      break;
    case 2:
      Controller1.Screen.clearScreen();
      Paincreas.Screen.clearScreen();
      Controller1.Screen.print("Right slected");
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("Right slected");
      backBut.draw();

      runL = false;
      runR = true;
      std::cout << runL << std::endl;
      std::cout << runR << std::endl;
      break;
    case 3:
      Controller1.Screen.clearScreen();
      Paincreas.Screen.clearScreen();
      Controller1.Screen.print("Left slected");
      backBut.draw();

      runL = true;
      runR = false;
      std::cout << runL << std::endl;
      std::cout << runR << std::endl;
      break;
    case 4:
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setFont(fontType::prop60);
      Paincreas.Screen.setCursor(1, 7);
      Paincreas.Screen.print(rand() % 20 + 1);
      backBut.draw();
      break;
    }
  }

  void setR() {
    index = 2;
    Index();
  }

  void setL() {
    index = 3;
    Index();
  }

  void back() {
    index = 1;
    runMenu = false;
    Index();
  }

  void select() { runMenu = true; }

  void dickCheck() {
    index = 4;
    Index();
  }

public:
  void Input() {
    index = 1;
    Index();

    while (!runMenu) {
      if (Controller1.ButtonLeft.pressing()) {
        setL();
      } else if (Controller1.ButtonRight.pressing()) {
        setR();
      } else if (Controller1.ButtonB.pressing()) {
        back();
      } else if (rightBut.pressing()) {
        setR();
      } else if (leftBut.pressing()) {
        setL();
      } else if (backBut.pressing()) {
        back();
      } else if (Controller1.ButtonA.pressing()) {
        select();
      }else if (awpBut.pressing()){
        dickCheck();
      }


      wait(30, msec);
    }
    std::cout << "menu ended" << std::endl;
  }

  void Output() {
    Paincreas.Screen.clearScreen();
    runMenu = false;
    if (runL) {
      Awp();
    } else if (runR) {
    }
  }
};

testMenu Menu;

#endif