#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>


int allTemp[2][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {1, 2, 14, 15, 7, 11, 12,18}}; // an area to log   temps and their port #

void displayTemp() {
  
    Brain.Screen.setFont(mono20);
    Brain.Screen.clearLine(1, black);
    Brain.Screen.setCursor(Brain.Screen.row(), 1);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("pringle(C)[12] = ");

    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("leftFront(C)[1] = ");

    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("leftBack(C)[2] = ");

    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("rightFront(C)[14] = ");

    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("rightBack(C)[15] = ");

    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("clamp state = ");

    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("lift(C)[11] = ");

    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("bL state = ");

    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("aG2(C) = ");

    Brain.Screen.setCursor(1, 15);
    Brain.Screen.print(pringle.temperature(celsius));

    Brain.Screen.setCursor(2, 15);
    Brain.Screen.print(Lf.temperature(celsius));

    Brain.Screen.setCursor(3, 15);
    Brain.Screen.print( Lb.temperature(celsius));

    Brain.Screen.setCursor(4, 15);
    Brain.Screen.print( Rf.temperature(celsius));

    Brain.Screen.setCursor(5, 15);
    Brain.Screen.print( Rb.temperature(celsius));

    Brain.Screen.setCursor(6, 15);
    Brain.Screen.print(Clamp.value());

    Brain.Screen.setCursor(7, 15);
    Brain.Screen.print(Lift.temperature(celsius));

    Brain.Screen.setCursor(8, 15);
    Brain.Screen.print(bL.value());
  
}
void tempcheck() {
  allTemp[0][0] =  Lf.temperature(temperatureUnits::celsius);
  allTemp[0][1] =  Lb.temperature(temperatureUnits::celsius);
  allTemp[0][2] =  Rf.temperature(temperatureUnits::celsius);
  allTemp[0][3] =  Rb.temperature(temperatureUnits::celsius);
  allTemp[0][4] = Lift.temperature(temperatureUnits::celsius);
  allTemp[0][5] = pringle.temperature(temperatureUnits::celsius);
  for (int i = 0; i > 8; i++) {
    if (allTemp[0][i] >= 48) {
      std::cout << "Port: " << allTemp[1][i] << allTemp[0][i] << std::endl;
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(0, 0);
      Controller1.Screen.print("port:");
      Controller1.Screen.setCursor(1, 0);
      Controller1.Screen.print(allTemp[1][i]);
      Controller1.Screen.print(allTemp[0][i]);
    }
  }
}

void checkTemp(){

  if(Brain.Screen.pressing())
    displayTemp();
  else {
    
  }

}

