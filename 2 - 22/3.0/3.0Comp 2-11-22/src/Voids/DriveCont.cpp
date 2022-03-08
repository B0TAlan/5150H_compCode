#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void tankCont() {
  while (1) {
    // used to set dead band to avoid drift
    float x = Controller1.Axis3.value();// value of the left stick 
    float y = Controller1.Axis2.value();// value of the right stick
    float sen = .75;
    float outputL;
    float outputR;
    if (fabs(x) < 10) { // if x is over deadband(10)
      x = 0;// set x to zero 
    }

    if (fabs(y) < 10) { // if x is over deadband(10)
      y = 0;// set y to 0
    }
    
    if (fabs(x) >= 120){
      outputL = x * sen;
    }else {
     outputL = x;
    }
    if (fabs(y) >= 120){
      outputR = y * sen;
    }else {
     outputR = y;
    }

    // set x & y to the corrasponding motors
    Lf.spin(fwd, outputL, voltageUnits::volt);
    Lb.spin(fwd, outputL, voltageUnits::volt);
    Lm.spin(fwd, outputL, voltageUnits::volt);
    Rf.spin(fwd, outputR, voltageUnits::volt);
    Rb.spin(fwd, outputR, voltageUnits::volt);
    Rm.spin(fwd, outputR, voltageUnits::volt);

    wait(20, msec);
  }
  
}


void arcadeCont(){
  Brain.Screen.drawImageFromFile("test1.png", 220, 0);
  while(1){
    // used to set dead band to avoid drift
    float x = Controller1.Axis1.value();// value of Turn
    float y = Controller1.Axis3.value();// value of Power
    float t = 0 , p = 0;
    int sen = 1; 

    t = (x * sen)/ 10.58;// set t to axis 4 for turning
    p = (y * sen)/ 10.58;// set p to axis 2 for power

    float outputL = t + p;// output for left motrors 
    float outputR = -t + p;// output for right motrors 

    if (fabs(t) < 10) { // if x is over deadband(10)
      x = 0;// set x to zero 
    }

    if (fabs(p) < 10) { // if x is over deadband(10)
      y = 0;// set y to 0
    }

    // set outputL & outputR to the corrasponding motors
    Lf.spin(fwd, outputL, voltageUnits::volt);
    Lb.spin(fwd, outputL, voltageUnits::volt);
    Lm.spin(fwd, outputL, voltageUnits::volt);
    Rf.spin(fwd, outputR, voltageUnits::volt);
    Rb.spin(fwd, outputR, voltageUnits::volt);
    Rm.spin(fwd, outputR, voltageUnits::volt);
  
    wait(20, msec);
  }
}