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
lcdButton awpBut(360, 122, 230, 35, "Awp", "#252525", "#2525FF", 2);
lcdButton NoBut(240, 220, 430, 35, "No Auton", "#252525", "#2525FF", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#2525FF", 2);

class testMenu {
private:
  bool runL = false;  // left 20
  bool runR = false;  // right 20
  bool runRM = false; // right mid
  bool runLM = false; // left mid
  bool runR40 = false;// right 40
  bool runL40 = false;// left 40
  bool runW = false;  // solo awp
  bool runSK = false; // skills
  bool noRun = false; // no auton
  bool runMenu = false;
  int index = 10;

  void debug(){
    std::cout << "rState = " << runR << "," << runRM << "," << runR40 << std::endl;
    std::cout << "lState = " << runL << "," << runLM << "," << runL40 << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;
  }

  void Index() {
    switch (index) {
    case 1:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      runMenu = true;
      rightBut.draw();
      leftBut.draw();
      skillBut.draw();
      lef40But.draw();
      right40But.draw();
      awpBut.draw();
      NoBut.draw();

       runL = false;
       runR = false;
       runRM = false;
       runLM = false;
       runR40 = false;
       runL40 = false;
       runW = false;
       runSK = false;
       noRun = false;
       runMenu = false;
      debug();
      runMenu = true;
      break;
    case 2:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("Right20 slected");
      backBut.draw();

      
      runR = true;
      debug();
      break;
    case 3:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(blue);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("Left20 slected");
      backBut.draw();

      runL = true;
      debug();
      break;
    case 4:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("RightMid slected");
      backBut.draw();

      runRM = true;
      debug();
      break;
    case 5:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(blue);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("LeftMid slected");
      backBut.draw();

      runLM = true;
      debug();
      break;
    case 6:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(green);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("skills slected");
      backBut.draw();

      runSK = true;
      debug();
      break;
    case 7:
      wait(30,msec);
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(green);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono60);
      Paincreas.Screen.print("awp slected");
      backBut.draw();

      runW = true;
      debug();
      break;
    case 8:
      wait(30,msec);
      int X = rand() % 20 + 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setFont(fontType::prop60);

      if (X == 20){
        Paincreas.Screen.setPenColor(green);
      }else if (X == 1) {
        Paincreas.Screen.setPenColor(green);
      }else{
        Paincreas.Screen.setPenColor(white);
      }

      Paincreas.Screen.setCursor(1, 7);
      Paincreas.Screen.print(X);
      backBut.draw();

      noRun = true;

      debug();
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
  void setSK() {
    index = 6;
    Index();
  }
  void setW(){
    index =7;
    Index();
  }
  void back() {
    runMenu = true;
    Input();
    Index();
  }

  void select() { runMenu = false; }

  void d20() {
    index = 8;
    Index();
  }

public:
  void Input() {
    index = 1;
    Index();
    runMenu = true;
    while (runMenu == true) {
      if (leftBut.pressing()) {
        setL();
      } else if (rightBut.pressing()) {
        setR();
      }else if (skillBut.pressing()) {
        setSK();
      } else if (leftBut.pressing()) {
        setL();
      } else if (backBut.pressing()) {
        index = 1;
        Index();
      }else if (NoBut.pressing()){
        d20();
      }else if (awpBut.pressing()) {
        setW();
      }


      wait(30, msec);
    }
    std::cout << "menu ended" << std::endl;
  }

  void Output() {
    Paincreas.Screen.clearScreen();
    runMenu = false;
    if (runL) {
      left20();
    } else if (runR) {
      right20();
    }else if (runSK) {
      Skills();
    }else if (runW) {
      Awp();
    }
  }

  void Off(){
    runMenu = false;
  }
};

testMenu Menu;

#endif