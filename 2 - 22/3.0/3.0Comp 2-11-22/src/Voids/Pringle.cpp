#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

int Pring = 2;

void setPring(){
   if (Pring == 1) {
    Pring = 2;
  } else if (Pring == 2 && Controller1.ButtonLeft.pressing()) {
    Pring = 1;
  } /*else {
    Pring = 1;
  }
  if(Pring != 0){// if Ping not 0 (off)
    Pring = 0;// set Pring to 0
  }  
  else if(Pring != 1){// if Ping not 1 (on)
    Pring = 1;// set Pring to 1
  }*/
}

void pringOn(){
  if (Pring == 1 && Controller1.ButtonLeft.pressing()) {
    Pring = 2;
  } else if (Pring == 2 && Controller1.ButtonLeft.pressing()) {
    Pring = 1;
  }

}

void pringControl(){

  pringOn();
  
  switch (Pring) { //used to control the state of the pringle intake
    case 1: // if Pring = 1 stop the intake
      pringle.stop();
      break;

    case 2: 
    //^ if Pring = 2 start the intake and set the lift to intake height
      pringle.spin(reverse, 70, velocityUnits::pct);
      break;
    }

    wait(10, msec);
}