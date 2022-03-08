#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

void reseEncoders(){
  end1.resetRotation();
  end2.resetRotation();
}

void setMotorVel(int r, int l){
  leftDrive.spin(directionType::fwd, l, voltageUnits::volt);
   rightDrive.spin(directionType::fwd, r, voltageUnits::volt);
}

void stopDrive(){
  leftDrive.stop(coast);
  rightDrive.stop(coast);
}

void translate(int units, int volts){
  int errorBand = 10;
  int encodeVal = (end1.rotation(rotationUnits::raw) + end2.rotation(rotationUnits::raw)) / 2;  
  if (end1.rotation(rotationUnits::raw) == 0 && end1.rotation(rotationUnits::raw) == 0){
     encodeVal = 0;
  }
 //reset encoders
  reseEncoders();
 //drive until units
 while (encodeVal < units){
   leftDrive.setStopping(coast);
   rightDrive.setStopping(coast);
   setMotorVel(volts, volts);
   vex::task::sleep(10);
 }
 setMotorVel(-10, -10);
 vex::task::sleep(100);
 stopDrive();
 

}