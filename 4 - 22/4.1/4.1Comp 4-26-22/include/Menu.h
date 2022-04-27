#ifndef MENU_H
#define MENU_H

#include "ButtonClass.h"
#include "Autons.h"
#include "vex.h"

lcdButton rightBut(120, 22, 230, 35, "Right", "#252525", "#FF2525", 2);        
lcdButton leftBut(360, 22, 230, 35, "Left", "#252525", "#2525FF", 2);  

lcdButton pLineBut(120, 130, 55, 55, "Line", "#c400ff", "#c400ff", 2);
lcdButton mLoad(360, 130, 55, 55, "Loads", "#0c00ff", "#0c00ff", 2);

lcdButton right20But(120, 72, 230, 35, "Right20", "#252525", "#2525FF", 2);
lcdButton right40But(360, 72, 230, 35, "Right40", "#252525", "#FF2525", 2);  
lcdButton Mid(240, 142, 250, 35, "MidGoal", "#252525", "#f4ff00", 2);

lcdButton skillBut(120, 92, 230, 35, "Skills", "#252525", "#1fff00", 2);
lcdButton awpBut(360, 92, 230, 35, "Testing", "#252525", "#f4ff00", 2);

lcdButton NoBut(240, 162, 430, 35, "No Auton", "#252525", "#ffffff", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#ffffff", 2);
lcdButton loading(240, 136, 480, 272, "loading", "#ffffff", "#ffffff", 2);

class testMenu {
private:
  //bool runL = false;  // left 20
  //bool runR = false;  // right 20
  //bool runRM = false; // right mid
  //bool runLM = false; // left mid
  //bool runR40 = false;// right 40
  //bool runL40 = false;// left 40
  //bool runW = false;  // solo awp
  //bool runSK = false; // skills
  //bool noRun = false; // no auton
  bool runMenu = false;
  int opt;
  int index = 14;
  int i;
  int pI;

  void debug(){
    //std::cout << "rState(20, M, 40) = " << runR << "," << runRM << "," << runR40 << std::endl;
    std::cout << "Option = " << opt << std::endl;
    std::cout << "pring = " << pring << std::endl;
    //std::cout << "lState = " << runL << std::endl;
    //std::cout << "WState = " << runW << std::endl;
    //std::cout << "SKState = " << runSK << std::endl;
    //std::cout << "NoTon = " << noRun << std::endl;
    //std::cout << "Option = " << opt << std::endl;

    if (/*runL*/ opt == 1) {
      
      std::cout << "Left 20" << std::endl;
      std::cout << "   " << std::endl;
    } else if (/*runR*/ opt == 3) {
      
      std::cout << "Right 20" << std::endl;
      std::cout << "   " << std::endl;
    }else if (/*runSK*/ opt == 5) {
      
      std::cout << "Skills" << std::endl;
      std::cout << "   " << std::endl;
    }else if (/*runW*/ opt == 6) {
      
      std::cout << "Awp / Testing" << std::endl;
      std::cout << "   " << std::endl;
      //NoTon();
    }else if (/*runRM*/ opt == 2) {
      
      std::cout << "Right Mid" << std::endl;
      std::cout << "   " << std::endl;
    }else if (/*runR40*/ opt == 4){
      
      std::cout << "Right 40" << std::endl;
      std::cout << "   " << std::endl;
    }else {
      std::cout << "   " << std::endl;
    }

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
      right20But.disable();
      right40But.disable();
      Mid.disable();

       opt = 0;
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

      opt = 0;
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

      opt = 1;
      //runL = true#;
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

      opt = 2;
      //runRM = true#;
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
      Paincreas.Screen.print("right20 selected");
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

      opt = 3;
      //runR = true#;
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
      pLineBut.disable();
      mLoad.disable();

      opt = 4;
      ///runR40 = true#;
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

      opt = 5;
      //runSK = true#;
      debug();
      break;
    case 9:
      wait(30,msec);
      i = 9;
      pI = 1;
      Paincreas.Screen.clearScreen();
      Paincreas.Screen.setPenColor(yellow);
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

      opt = 6;
      //runW = true#;
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
      opt = 0;
      //noRun = true#;

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
    if (/*runL*/ opt == 1) {
      left20();
    } else if (/*runR*/ opt == 3) {
      right20();
    }else if (/*runSK*/ opt == 5) {
      s_kill_me();
    }else if (/*runW*/ opt == 6) {
      testing();
      //NoTon();
    }else if (/*runRM*/ opt == 2) {
      rightMid();
    }else if (/*runR40*/ opt == 4){
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