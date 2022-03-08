#include "stdarg.h"
#include "vex.h"
#include <cstring>
#include <iostream>
#include <string.h>

void lUp() {
  
  while (Controller1.ButtonR1.pressing() && Lift1.position(rev) <= 2) {
    Lift1.spin(fwd, 100, velocityUnits::pct);
  }
  Lift1.stop(hold);
  
}

void lDown() {
  
  while (Controller1.ButtonR2.pressing() && Lift1.position(rev) >= .1) {
    Lift1.spin(reverse, 100, velocityUnits::pct);
  }
  Lift1.stop(hold);
  
}


//--------------------------------Old--------------------------//
void liftUp() { // raises the lift up to 2 steps

  if (Lift1.position(rev) < 1.35) {  // if the lift is not @ 1st step
    Lift1.setVelocity(200, percent); // make the lift go fast
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(1.35, rev,
                   false); // raise lift to the 1st step used to get over the
                           // platform to score mgoals on platform

  } else if (Controller1.ButtonR1.pressing() &&
             Lift1.position(rev) >= 1.35) { // if R1 is being pressed and the
                                            // lift is @ the 1st step
    Lift1.setVelocity(200, percent);        // make it go fast
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(2, rev, false); // lift to max height (2nd step)

  } else {
  }
}
void liftDown() {                    // just the oppiste of the lift up fintion
  if (Lift1.position(rev) <= 2) {    // if the lift is below max height go to  z
    Lift1.setVelocity(200, percent); // set lift speed
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(0, rev,
                   false); // set the lift to defualt position(all the way down)
  } else if (Controller1.ButtonR2.pressing() &&
             Lift1.position(rev) >
                 1.35) { // if the lift is above 1st step go to 1st step
    Lift1.setVelocity(200, percent); // make it fast
    // Lift1.spinFor(forward, 2, rev);
    Lift1.rotateTo(1.35, rev, false); // sets lift to 1st step
  } else {
  }
}
void deScore() { // used to balnced platform ore to score mgoals
  // lift.spinFor(fwd, 13, inches, 100, velocityUnits::pct);
  Lift1.rotateTo(
      .8, rotationUnits::rev, 60, velocityUnits::pct,
      true); // a middle step ro help score the mgoal during auton skills
}
void score_macro () {
     // lower lift 1 step
     sM = true;
     Lift1.rotateTo(.9, rotationUnits::rev, 100, velocityUnits::pct, false);
   
     // open claw
     clamp1Off();
     waitUntil(Clamp1.isDone());

     // reset lift to full height
     liftUp();
   }
   void sMSet (){
     sM = false;
 
   }
