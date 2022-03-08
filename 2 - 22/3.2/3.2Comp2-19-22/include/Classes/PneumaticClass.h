#include "vex.h"

#ifndef PNEUMATICCLASS_H
#define PNEUMATICCLASS_H

class PneumaticControls{
  public:
  void setState(bool state) {

    Clamp.set(state);
    bL.set(state);
  }

  void getState() {

    std::cout << "Clamp = " << Clamp.value() << std::endl;
    std::cout << "bL = " << bL.value() << std::endl;
  }

};

PneumaticControls Pistions;

#endif