#include "vex.h"

bool cOn = false;

void clampOpen(){
  Clamp.set(true);

  wait(300, msec);

  cOn = false;
}

void clampCloes(){
  Clamp.set(false);

  wait(300, msec);

  cOn = true;
}