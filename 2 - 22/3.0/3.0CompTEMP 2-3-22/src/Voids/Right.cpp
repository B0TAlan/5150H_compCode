#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

void right20(){
  driveBase.driveFor(fwd, 24, distanceUnits::in, 20, velocityUnits::pct);
  Brain.Screen.drawImageFromFile("hamsP.png", 100, 100);
}

void right40(){
  switch(int a =2){
    case 1:
     break;
    case 2:
     break;

  }


}