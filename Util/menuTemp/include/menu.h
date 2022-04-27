#ifndef MENU_H
#define MENU_H
/*/////////////////////////////////////////////////////*/
/* this is a menu used for tipping point (2021 - 2022) */
/*        you can look @ this if you need help         */
/*/////////////////////////////////////////////////////*/


#include "ButtonClass.h"
#include "Autons.h"
#include "vex.h"
// creates buttons here //

lcdButton NoBut(240, 162, 430, 35, "No Auton", "#252525", "#ffffff", 2);
lcdButton backBut(240, 220, 230, 35, "Back", "#252525", "#ffffff", 2);
lcdButton loading(240, 136, 480, 272, "loading", "#ffffff", "#ffffff", 2);

class Menu {// creats calss [can be named what ever]
private:

  int index = 14;// used to change the size of the case for the menu
  int pI;// used to map submenus to the pervious one
  int opt;// used to rep which option was selected
  bool runMenu;

  void debug(){// prints to terminal what auton hase been selected
    std::cout << "Option = " << opt << std::endl;
    std::cout << "pring = " << pring << std::endl;
    

  }

  void Index() {// menus & sub menus
    switch (index) {
    case 1: //main menus
      wait(30,msec);
  
      
      opt = 0;
      debug();
      
      break;
    case 2: // Option 1 
      wait(30,msec);
      opt = 1;
      pI = 1;// maps to main menu
      

      backBut.enable();
      
      debug();
      break;
    case 3: // Option 2 
      wait(30,msec);
      opt = 2;
      pI = 1; // maps to main menu
      
      backBut.enable();
      debug(); // prints states to terminal
      break;
    case 4:
      wait(30,msec);
      opt = 3;
      pI = 2;// maps to submenu 2
      
      backBut.enable();
      
      debug();
      break;
    case 5: // Option 4
      wait(30,msec);
      opt = 4;
      pI = 2;
      
      backBut.enable();
      
      debug();
      break;
    case 6:
      wait(30,msec);
      opt = 5;
      pI = 2;
      
      backBut.enable();
      
      debug();
      break;
    case 7: // used as a loading screen while gyro calabrates & to refesh menu
        loading.enable();
        disableAll();// nothing else is enable bause this is only used to refesh menu
        break;
    case 8: // Option 6
      wait(30,msec);
      opt = 6;
      pI = 1;
     
      backBut.enable();
     
      debug();
      break;
    case 9:
      wait(30,msec);
      opt = 7;
      pI = 1;
      
      backBut.enable();
      
      debug();
      break;
    case 10:
      wait(30,msec); // roll a d20 jusk cause 
      opt = 0;// does nothing
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
      

      debug();
      break;
     
    }
  }
//-------------Control methods-------------//
  void set2() {// jumps to case 2:
    index = 2;
    Index();// refeshes menu after changing index
  }
  void set4() {// jumps to case 4:
    index = 4;
    Index();
  }
  void set5() {// jumps to case 5:
    index = 5;
    Index();
  }
  void set6() {// jumps to case 6:
    index = 6;
    Index();
  }

  void set3() {// jumps to case 3:
    index = 3;
    Index();
  }
  void set8() {// jumps to case 8:
    index = 8;
    Index();
  }
  void set9(){// jumps to case 9:
    index =9;
    Index();
  }
  

  void d20() {// jumps to case 10:
    index = 10;
    Index();
  }

  
  void disableAll(){// turns off all buttons 
    backBut.disable();
    
  }

public:
  void Input() {
    index = 1;
    Index();
    runMenu = true;
    while (runMenu == true) { // while the menu is running check...
      /*if (Button1.pressing()) {// if button pressed run this
        setL();
      } else if (Button2.pressing()) {
        setR();
      }else if (Button3.pressing()) {
        setSK();
      } else if (Button4.pressing()) {
        setL();
      } else if (backBut.pressing()) {
        index = pI;
        Index();
      }else if (NoBut.pressing()){
        d20();
      }else if (Button5.pressing()) {
        setW();
      }else if (right20But.pressing()) {
        setR20();
      }*/


      wait(30, msec);
    }
    std::cout << "menu ended" << std::endl;
  }

  void Output() {
    Brain.Screen.clearScreen();
    runMenu = false;// stops reading inputs 
    disableAll();// disables menu buttons
    if (opt == 1) {// checks state then runs corresponding auton
      //left20();
    } else if (opt == 1) {
      // auton 1
    }else if (opt == 2) {
      // auton 2
    }else if (opt == 3) {
      // auton 3
    }else if (opt == 4) {
      // auton 4
    } else if (opt == 5) {
      // auton 4
    }else {
     
    }
  }

  void Off(){// did not use 
    runMenu = false;// turns off menu
  }
};

#endif