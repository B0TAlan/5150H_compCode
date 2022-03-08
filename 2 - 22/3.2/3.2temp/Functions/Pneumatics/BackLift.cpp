#include "vex.h"
#include "vex.h"

bool bLD = false;

void bLOpen(){
  bL.set(false);

  wait(300, msec);

  bLD = false;
}

void bLClose(){
  bL.set(true);

  wait(300, msec);
  
  bLD = true;
}