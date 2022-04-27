#ifndef MENU_H
#define MENU_H

#include "ButtonClass.h"
#include "Autons.h"
#include "vex.h"

lcdButton rightBut(120, 22, 230, 35, "Right", "#252525", "#FF2525", 2);        
lcdButton leftBut(360, 22, 230, 35, "Left", "#252525", "#2525FF", 2);  

lcdButton pLineBut(120, 130, 55, 55, "Line", "#A020F0", "#BF40BF", 2);
lcdButton mLoad(360, 130, 55, 55, "Loads", "#0000FF.", "#ADD8E6", 2);

lcdButton right20But(120, 52, 230, 35, "right20But", "#252525", "#2525FF", 2);
lcdButton right40But(360, 52, 230, 35, "Right40", "#252525", "#FF2525", 2);  
lcdButton Mid(240, 122, 230, 35, "MidGoal", "#252525", "#2525FF", 2);

lcdButton skillBut(120, 72, 230, 35, "Skills", "#252525", "#2525FF", 2);
lcdButton awpBut(360, 72, 230, 35, "Awp", "#252525", "#2525FF", 2);

lcdButton NoBut(240, 122, 430, 35, "No Auton", "#252525", "#2525FF", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#2525FF", 2);
lcdButton loading(240, 136, 480, 272, "loading", "#ffffff", "#ffffff", 2);

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
  int index = 14;
  int i;
  int pI;

  void debug(){
    std::cout << "rState = " << runR << "," << runRM << "," << runR40 << std::endl;
    std::cout << "pring = " << pring << std::endl;
    std::cout << "lState = " << runL << "," << runLM << "," << runL40 << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

  }

  void Index() {
    switch (index) {
    case 1:
      wait(30,msec);
      i = 1;
      Paincreas.Screen.clearScreen();
      runMenu = true;
      rightBut.enable();
      leftBut.enable();
      skillBut.enable();
      awpBut.enable();
      NoBut.enable();
      backBut.disable();
      pLineBut.disable();
      mLoad.disable();

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
       pring = false;
      debug();
      runMenu = true;
      break;
    case 2:
      wait(30,msec);
      i = 2;
      pI = 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("Right selected");

      backBut.setSize(230, 35);
      right20But.enable();
      right40But.enable();
      Mid.enable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      awpBut.disable();
      NoBut.disable();
      pLineBut.disable();
      mLoad.disable();
      wait(500, msec);
      backBut.enable();
      
      debug();
      break;
    case 3:
      wait(30,msec);
      i = 3;
      pI = 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(blue);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("Left20 slected");
      Paincreas.Screen.setCursor(2, 3);
      Paincreas.Screen.print("Vamos Hacer");
      backBut.setSize(230, 35);
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();
      pLineBut.disable();
      mLoad.disable();

      runL = true;
      debug();
      break;
    case 4:
      wait(30,msec);
      i = 4;
      pI = 2;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("RightMid slected");
      Paincreas.Screen.setCursor(2, 3);
      if (pring == false){
        Paincreas.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Paincreas.Screen.print("Vamos Hacer, load");
      }
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();
      pLineBut.enable();
      mLoad.enable();

      runRM = true;
      debug();
      break;
    case 5:
      wait(30,msec);
      i = 5;
      pI = 2;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("right20But selected");
      Paincreas.Screen.setCursor(2, 3);
      if (pring == false){
        Paincreas.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Paincreas.Screen.print("Vamos Hacer, load");
      }
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();
      pLineBut.enable();
      mLoad.enable();

      runR = true;
      debug();
      break;
    case 6:
      wait(30,msec);
      i = 6;
      pI = 2;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(red);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("Right40 slected");
       
      Paincreas.Screen.setCursor(2, 3);
      if (pring == false){
        Paincreas.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Paincreas.Screen.print("Vamos Hacer, load");
      }
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();
      pLineBut.enable();
      mLoad.enable();

      runR40 = true;
      debug();
      break;
    case 7:
        loading.enable();
        disableAll();
        break;
    case 8:
      wait(30,msec);
      i = 8;
      pI = 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(green);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
       
      Paincreas.Screen.print("skills slected");
      Paincreas.Screen.setCursor(2, 3);
      Paincreas.Screen.print("Vamos Hacer");
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();

      runSK = true;
      debug();
      break;
    case 9:
      wait(30,msec);
      i = 9;
      pI = 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(green);
      Paincreas.Screen.setCursor(1, 3);
      Paincreas.Screen.setFont(fontType::mono30);
      Paincreas.Screen.print("awp slected");
       
      Paincreas.Screen.setCursor(2, 3);
      Paincreas.Screen.print("Vamos Hacer");
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();

      runW = true;
      debug();
      break;
    case 10:
      wait(30,msec);
      i = 10;
      pI = 1;
      int X = rand() % 20 + 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setFont(fontType::prop60);

      if (X == 20){
        Paincreas.Screen.setPenColor(green);
      }else if (X == 1) {
        Paincreas.Screen.setPenColor(red);
      }else{
         
      }

      Paincreas.Screen.setCursor(1, 7);
      Paincreas.Screen.print(X);
      backBut.enable();
      right20But.disable();
      right40But.disable();
      Mid.disable();
      rightBut.disable();
      leftBut.disable();
      skillBut.disable();
      Mid.disable();
      right40But.disable();
      awpBut.disable();
      NoBut.disable();

      noRun = true;

      debug();
      break;
     
    }
  }

  void setR() {
    index = 2;
    Index();
  }
  void setRM() {
    index = 4;
    Index();
  }
  void setR20() {
    index = 5;
    Index();
  }
  void setR40() {
    index = 6;
    Index();
  }

  void setL() {
    index = 3;
    Index();
  }
  void setSK() {
    index = 8;
    Index();
  }
  void setW(){
    index =9;
    Index();
  }
  void back() {
    runMenu = true;
    Input();
    Index();
  }

  void select() { runMenu = false; }

  void d20() {
    index = 10;
    Index();
  }

  void pL(){
    pring = false;
    index = 7;
    Index();
    wait(300, msec);
    index = i;
    Index();
  }

  void mL(){
    pring = true;
    index = 7;
    Index();
    wait(300, msec);
    index = i;
    Index();
  }
  void disableAll(){
    backBut.disable();
    right20But.disable();
    right40But.disable();
    Mid.disable();
    rightBut.disable();
    leftBut.disable();
    skillBut.disable();
    Mid.disable();
    right40But.disable();
    awpBut.disable();
    NoBut.disable();
    pLineBut.disable();
    mLoad.disable();
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
        index = pI;
        Index();
      }else if (NoBut.pressing()){
        d20();
      }else if (awpBut.pressing()) {
        setW();
      }else if (right20But.pressing()) {
        setR20();
      }else if (pLineBut.pressing()) {
        pL();
      }else if (mLoad.pressing()) {
        mL();
      }else if (Mid.pressing()){
        setRM();
      }else if (right40But.pressing()){
        setR40();
      }


      wait(30, msec);
    }
    std::cout << "menu ended" << std::endl;
  }

  void Output() {
    Paincreas.Screen.clearScreen();
    runMenu = false;
    disableAll();
    if (runL) {
      left20();
    } else if (runR) {
      right20();
    }else if (runSK) {
      //Skills();
    }else if (runW) {
      testing();
      //NoTon();
    }else if (noRun) {
      //NoTon();
    } else if (runRM) {
      rightMid();
    }else if (runR40){
      right40();
    }else {
      //NoTon();
    }
  }

  void Off(){
    runMenu = false;
  }
};

#endif