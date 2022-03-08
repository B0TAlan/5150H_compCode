#include <vex.h>


// Helper
bool Pring = false;

void setPingle() {
 if(Pring)
    Pring = false;
 else if (!Pring)
    Pring = true;
}

// Pringle intake Control p1
void spinPringle(){
   if (Controller1.ButtonLeft.pressing() && pringle.isDone())
    pringle.spin(reverse, 600, rpm);
  else if(Controller1.ButtonLeft.pressing() && pringle.isSpinning()){
    pringle.stop(coast);
  }
  else{
    pringle.stop(coast);
  }
}

// Pringle intake Control p1
void pringleIntake(){
 if (Controller2.ButtonR2.pressing()){
   pringle.spin(fwd, 80, pct);
   
  } 
 else if(Controller2.ButtonR1.pressing()){
   pringle.spin(reverse, 80, pct);
   
  } 
  else
    pringle.stop(coast);
  
  
}
