/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Scruf                                            */
/*    Created:      Sat Dec 04 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// lf                   motor         1               
// lb                   motor         2               
// rf                   motor         14              
// rb                   motor         15              
// clamp                motor         7               
// lift                 motor         11              
// ag1                  motor         18              
// pringle              motor         12              
// ag2                  motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>
using namespace vex;
int allTemp[6] ={0,0,0,0,0,0};
//------------------------- 𝕮𝖔𝖓𝖋𝖎𝖌 -------------------------//
  void tempchec(){
      allTemp[0] = lf.temperature(temperatureUnits::celsius);
      allTemp[0] = lb.temperature(temperatureUnits::celsius);
      allTemp[0] = lm.temperature(temperatureUnits::celsius);
      allTemp[0] = rf.temperature(temperatureUnits::celsius);
      allTemp[0] = rb.temperature(temperatureUnits::celsius);
      allTemp[0] = rm.temperature(temperatureUnits::celsius);
      for(int i = 0;i >700; i++){
        if(allTemp[i] >= 48){
          std::cout<<"driveBase overheat "<<std::endl;
        }
      }
    }
   int main() {
     // Initializing Robot Configuration. DO NOT REMOVE!
     vexcodeInit();
     
   
     while(1){
       Brain.Screen.setFont(mono20);
       Brain.Screen.clearLine(1, black);
       Brain.Screen.setCursor(Brain.Screen.row(), 1);
//---------------------------------------------------------//
   
//------------------------ 𝕳𝖊𝖆𝖉𝖎𝖓𝖌𝖘 ------------------------//
    Brain.Screen.setCursor(1 , 1);
    Brain.Screen.print("pringle(C) = ");

    Brain.Screen.setCursor(2 , 1);
    Brain.Screen.print("leftFront(C) = ");

    Brain.Screen.setCursor(3 , 1);
    Brain.Screen.print("leftBack(C) = ");

    Brain.Screen.setCursor(4 , 1);
    Brain.Screen.print("leftMid(C) = ");

    Brain.Screen.setCursor(5 , 1);
    Brain.Screen.print("rightFront(C) = ");

    Brain.Screen.setCursor(6 , 1);
    Brain.Screen.print("rightBack(C) = ");

    Brain.Screen.setCursor(7 , 1);
    Brain.Screen.print("rightMid(C) = ");

    Brain.Screen.setCursor(8 , 1);
    Brain.Screen.print("lift(C) = ");

//---------------------------------------------------------//
   
//------------------------ 𝕽𝖊𝖆𝖉𝖎𝖓𝖌𝖘 ------------------------//
    Brain.Screen.setCursor(1 , 15);
    Brain.Screen.print(pringle.temperature(celsius));
     
    Brain.Screen.setCursor(2 , 15);
    Brain.Screen.print(lf.temperature(celsius));
     
    Brain.Screen.setCursor(3 , 15);
    Brain.Screen.print(lb.temperature(celsius));

    Brain.Screen.setCursor(4 , 15);
    Brain.Screen.print(lm.temperature(celsius));
     
    Brain.Screen.setCursor(5 , 15);
    Brain.Screen.print( rf.temperature(celsius));
     
    Brain.Screen.setCursor(6 , 15);
    Brain.Screen.print( rb.temperature(celsius));

    Brain.Screen.setCursor(7 , 15);
    Brain.Screen.print( rm.temperature(celsius));

    Brain.Screen.setCursor(8 , 15);
    Brain.Screen.print( lift.temperature(celsius));

    wait(200, msec);
     }
     }
//---------------------------------------------------------//