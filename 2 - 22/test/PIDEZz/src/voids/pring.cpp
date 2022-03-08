#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void pringON() {
  if (Pring != 1) {
    Pring = 1;
  } else if (Pring != 2) {
    Pring = 2;
  } else {
    Pring = 1;
  }
}