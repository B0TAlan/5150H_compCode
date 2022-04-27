#ifndef MENU_H
#define MENU_H
/*/////////////////////////////////////////////////////*/
/* this is a menu used for tipping point (2021 - 2022) */
/*        you can look @ this if you need help         */
/*/////////////////////////////////////////////////////*/


#include "ButtonClass.h"
#include "Autons.h"
#include "vex.h"
// creates buttons  //
lcdButton rightBut(120, 22, 230, 35, "right20But", "#252525", "#FF2525", 2);        
lcdButton leftBut(360, 22, 230, 35, "Left20", "#252525", "#2525FF", 2);  

lcdButton pLineBut(120, 130, 55, 55, "Line", "#A020F0", "#BF40BF", 2);
lcdButton mLoad(360, 130, 55, 55, "MLoads", "#0000FF.", "#ADD8E6", 2);

lcdButton right20But(120, 52, 230, 35, "right20But", "#252525", "#2525FF", 2);
lcdButton right40But(360, 52, 230, 35, "Right40", "#252525", "#FF2525", 2);  
lcdButton Mid(240, 122, 230, 35, "MidGoal", "#252525", "#2525FF", 2);

lcdButton skillBut(120, 72, 230, 35, "Skills", "#252525", "#2525FF", 2);
lcdButton awpBut(360, 72, 230, 35, "Awp", "#252525", "#2525FF", 2);

lcdButton NoBut(240, 122, 430, 35, "No Auton", "#252525", "#2525FF", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#2525FF", 2);
lcdButton loading(240, 136, 480, 272, "loading", "#ffffff", "#ffffff", 2);

class exampleMenu {// creats calss [can be named what ever]
private:
/*//////////////////////////////////////////////////////////////////////*/
/*      this is an old method i used for the out of the menu            */
/*      it worked well enough but was overkill                          */
/*      now in the templete (menu.h) it uses one an int                 */
/*      which each option being a differnt value                        */
/*//////////////////////////////////////////////////////////////////////*/

  // bools used to select auton 
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
  int index = 14;// used to change the size of the case for the menu
  int i;// used to refesh by jumping to laoding screen 
  int pI;// used to map submenus to the pervious one

  void debug(){// prints to terminal what auton hase been selected
    std::cout << "rState = " << runR << "," << runRM << "," << runR40 << std::endl;
    std::cout << "pring = " << pring << std::endl;
    std::cout << "lState = " << runL << "," << runLM << "," << runL40 << std::endl;
    std::cout << "WState = " << runW << std::endl;
    std::cout << "SKState = " << runSK << std::endl;
    std::cout << "NoTon = " << noRun << std::endl;

  }

  void Index() {// menus & sub menus
    switch (index) {
    case 1: //main menus
      wait(30,msec);
      i = 1; // did not use 
      Brain.Screen.clearScreen();
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
      pI = 1;// maps to main menu
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(red);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("Right selected");

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
      pI = 1; // maps to main menu
      Brain.Screen.clearScreen();// print config
      Brain.Screen.setPenColor(blue);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("Left20 slected");
      Brain.Screen.setCursor(2, 3);
      Brain.Screen.print("Vamos Hacer");
      backBut.setSize(230, 35);// did not use 
      // disables all buttons then enalbles the back button
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

      runL = true; //  set bool to rep that auton
      debug(); // prints states to terminal
      break;
    case 4:
      wait(30,msec);
      i = 4;
      pI = 2;// maps to submenu 2
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(red);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("RightMid slected");
       
      if (pring == false){
        Brain.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Brain.Screen.print("Vamos Hacer, load");
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
      pLineBut.enable();// selcted between 2 routes
      mLoad.enable();

      runRM = true;
      debug();
      break;
    case 5:
      wait(30,msec);
      i = 5;
      pI = 2;
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(red);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("right20But selected");
      Brain.Screen.setCursor(2, 3);
      if (pring == false){
        Brain.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Brain.Screen.print("Vamos Hacer, load");
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
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(red);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("Right40 slected");
       
      Brain.Screen.setCursor(2, 3);
      if (pring == false){
        Brain.Screen.print("Vamos Hacer, line");
      }else if (pring == true) {
        Brain.Screen.print("Vamos Hacer, load");
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
    case 7: // used as a loading screen while gyro calabrates & to refesh menu
        loading.enable();
        disableAll();// nothing else is enable bause this is only used to refesh menu
        break;
    case 8:
      wait(30,msec);
      i = 8;
      pI = 1;
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(green);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
       
      Brain.Screen.print("skills slected");
      Brain.Screen.setCursor(2, 3);
      Brain.Screen.print("Vamos Hacer");
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
      Brain.Screen.clearScreen();
      Brain.Screen.setPenColor(green);
      Brain.Screen.setCursor(1, 3);
      Brain.Screen.setFont(fontType::mono30);
      Brain.Screen.print("awp slected");
       
      Brain.Screen.setCursor(2, 3);
      Brain.Screen.print("Vamos Hacer");
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
      wait(30,msec); // roll a d20 jusk cause 
      i = 10;
      pI = 1;
      int X = rand() % 20 + 1;
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(fontType::prop60);

      if (X == 20){
        Brain.Screen.setPenColor(green);
      }else if (X == 1) {
        Brain.Screen.setPenColor(red);
      }else{
         
      }

      Brain.Screen.setCursor(1, 7);
      Brain.Screen.print(X);
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

  void setR() {// jumps to case 2:
    index = 2;
    Index();// refeshes menu after changing index
  }
  void setRM() {// jumps to case 4:
    index = 4;
    Index();
  }
  void setR20() {// jumps to case 5:
    index = 5;
    Index();
  }
  void setR40() {// jumps to case 6:
    index = 6;
    Index();
  }

  void setL() {// jumps to case 3:
    index = 3;
    Index();
  }
  void setSK() {// jumps to case 8:
    index = 8;
    Index();
  }
  void setW(){// jumps to case 9:
    index =9;
    Index();
  }
  void back() {// did not use 
    runMenu = true;
    Input();
    Index();
  }

  void select() { runMenu = false; } //  did not use 

  void d20() {// jumps to case 10:
    index = 10;
    Index();
  }

  void pL(){           // selects route 1 then refeshes menu 
    pring = false;     //by jumping to loading screen then back to case i:
    index = 7;
    Index();
    wait(300, msec);
    index = i;
    Index();
  }

  void mL(){           // selects route 1 then refeshes menu      
    pring = true;      // by jumping to loading screen then back to case i:
    index = 7;
    Index();
    wait(300, msec);
    index = i;
    Index();
  }
  void disableAll(){// turns off all buttons 
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
    while (runMenu == true) { // while the menu is running check...
      if (leftBut.pressing()) {// if button pressed run this
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
    Brain.Screen.clearScreen();
    runMenu = false;// stops reading inputs 
    disableAll();// disables menu buttons
    if (runL) {// checks state then runs corresponding auton
      //left20();
    } else if (runR) {
      right20();
    }else if (runSK) {
      //Skills();
    }else if (runW) {
      //NoTon();
    }else if (noRun) {
      //NoTon();
    } else if (runRM) {
      //rightMid();
    }else {
      //NoTon();
    }
  }

  void Off(){// did not use 
    runMenu = false;// turns off menu
  }
};

#endif