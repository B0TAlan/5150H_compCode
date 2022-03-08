#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

bool auton = false;
bool cOn = false;

void clampOn() {
  Clamp.set(true);
    waitUntil(Clamp.value() == true);
    cOn = true;
}

void clampOff() {
  Clamp.set(false);
    waitUntil(Clamp.value() == false);
    cOn = false;
}


void AclampOn(){
  while(auton == true && cOn == false){
    if (line1.value(percentUnits::pct) <=68){
     Clamp.set(true);
      //std::cout<<Clamp1.position(rev)<<std::endl;
      waitUntil(Clamp.value() == true);
      cOn= true;
      break;
    }
    else if (line1.value(percentUnits::pct) >68){
      for(int i = 0; i < 3; i++){
        driveBase.setDriveVelocity(5, velocityUnits::pct);

        if(cOn == true){
          break;
        }
      }


    }

   } 
    
  }

  