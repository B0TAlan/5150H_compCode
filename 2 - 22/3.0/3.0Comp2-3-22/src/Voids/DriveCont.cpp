#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>


void tankCont(){
  float x = Controller1.Axis3.value();
  float y = Controller1.Axis2.value();
   if (fabs(x) < 10){
     x =0;

  }

  if (fabs(y) < 10){
    y =0;

  }

  Lf.spin(fwd, x, voltageUnits::volt);
  Lb.spin(fwd, x, voltageUnits::volt);
  Lm.spin(fwd, x, voltageUnits::volt);
  Rf.spin(fwd, y, voltageUnits::volt);
  Rb.spin(fwd, y, voltageUnits::volt);
  Rm.spin(fwd, y, voltageUnits::volt);

}