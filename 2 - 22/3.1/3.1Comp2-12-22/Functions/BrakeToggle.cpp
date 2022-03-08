#include "vex.h"

int brakeMode = 1;

brakeType driveBrake;

void setDriveMode(){
  if (brakeMode == 1){
    driveBrake = coast;
  }
  if(brakeMode == 2){
    driveBrake = hold;
  }

}

