#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>


void left20(){
  Brain.Screen.setFillColor(white);
  Brain.Screen.drawRectangle(0, 0, 480, 272);
  Controller1.Screen.print("Made you look ;)");
  Brain.Screen.drawImageFromFile("hamsB.bmp", 100, 100);


}