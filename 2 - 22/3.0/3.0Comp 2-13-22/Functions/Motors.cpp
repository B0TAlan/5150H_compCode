#include <vex.h>

// Helper
void setLiftVel(int p) {

  Lift.spin(fwd, p, volt);
  // sets the velocity of the lift motor 

  if (Lift.position(rotationUnits::rev) >= 2 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes max hight stop the lift
    Lift.stop(hold);
  } else if (Lift.position(rotationUnits::rev) <= .08 && Controller1.ButtonR1.pressing()) {
    // if the lift reashes min hight stop the lift
    Lift.setVelocity(0, pct);
    Controller1.rumble(rumbleLong);
  }
}

// Lift Control
void liftControl() {
  int liftPower = 12.0 * (Controller1.ButtonR1.pressing() - Controller1.ButtonR2.pressing());
  // uses R1.pressing() and R2.pressing() as a constant (1 || 0) 
  // so that the lift will run @ 12 volts(up) or -12 volts(down)

  setLiftVel(liftPower);
}

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
   if (Pring)
    pringle.spin(reverse, 600, rpm);
  else
    pringle.stop(coast);
}

// Pringle intake Control p1
void pringleIntake(){
 if (Controller2.ButtonR1.pressing()){
   pringle.spin(fwd, 40, pct);
   Lift.spinToPosition(.1, rotationUnits::rev);
  } 
 else if(Controller2.ButtonR2.pressing()){
   pringle.spin(reverse, 40, pct);
   Lift.spinToPosition(.1, rotationUnits::rev);
  } 
  else
    pringle.stop(coast);
}