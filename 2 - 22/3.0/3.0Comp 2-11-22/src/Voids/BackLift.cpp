#include "vex.h"
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>

bool bLD = false;// bool that represents whether backLift is down(true) or up(false)

void bLDown() {
  bL.set(true);
  bLD = true;
}

void bLUp() {
  bL.set(false);
  bLD = false;
}