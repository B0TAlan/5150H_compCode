#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

void clamp1On(){
   Clamp1.setVelocity(100, percent);
   
    Clamp1.rotateTo(-.65, rev, true);
    
    Clamp1.stop(hold);
    
  }
   void Aclamp1On(){
   while(auton == true && clampOn == false){
     if (line1.value(percentUnits::pct) <=68){
       Clamp1.rotateTo(-.55, rotationUnits::rev,100,velocityUnits::pct, false);
       //std::cout<<Clamp1.position(rev)<<std::endl;
       waitUntil(Clamp1.position(rev)<= -.52);
       clampOn= true;
       Clamp1.stop(brake);
       break;
     }
     else if (line1.value(percentUnits::pct) >68){
        for(int i = 0; i < 3; i++){
          driveBase.setDriveVelocity(5, velocityUnits::pct);

          if(clampOn == true){
            break;
          }
        }


     }

   } 
    
  }
  void clamp1Off(){
    Clamp1.setVelocity(100,percent);
   
    Clamp1.rotateTo( -.1, rev, true);
    clampOn = true;
    Clamp1.stop();
   
  }