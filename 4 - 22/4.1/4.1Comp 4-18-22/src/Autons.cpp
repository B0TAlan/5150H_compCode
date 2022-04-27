#include "vex.h"
#include "Classes.h"
#include "Functions.h"

bool mLoads = false;
bool prinLine = false;

Movement_Controller robit;
DriveBaseControler base;
LiftShortcut lift;
BackLiftShortcuts bL;
ClampShortcuts clamp;
PringleShortcuts pringTake;

void left20(){ // free

}

void right20(){// free

  lift.lock();
  clamp.OF();
  robit.Drive(41, 10);
  clamp.Cloes();
  lift.Idle(60, false);
  robit.Drive(-30, 6);
  robit.customPoint(275, .1, .002, .0001, 6);
  bL.Open();
  robit.Drive(-8, 12);
  bL.Close();

  // TURN //
  // MATCH LOADS//
  if(prinLine == true){
    // TURN TO PRING LINE //
    // LIFT LIFT //
    // DIVE & INTAKE LINE //
    // RETURN TO SCORE //
  } else if (mLoads == true) {
    // TURN TO WALL //
    // LIFT LIFT //
    // DRIVE BACK AND FORWARD FOR MATCH LOADS //
  } else{
    base.Brake(hold);
  }

}

void rightMid(){// Matt
  
 
}

void leftMid(){// Aahil
  
 
}

void s_kill_me(){ // Alan :(
  
}

void testing(){

  lift.lock();
  robit.customPoint(275, .1, .045, .00004, 6);
  //robit.customDrive(8, .1, .06, .001, 12);
  //robit.Pivot(180, 6);
  //robit.turnFor(90, 12, false);

  //robit.customPivot(90, .1, 0.004, 0.00004, 12, right);
  //robit.customPoint(95, .13, 9.8, .00005);
 //robit.customDrive(24, .015, .1, .15);
 //wait(40, msec);
 //robit.Drive(-24, .015);
 //robit.customPoint(90, .2, .002, .0000/*7*/) .1, .002, .00014;
 //.3,0,0 off by 3ish  .2, 20, .00009
 // .3, .001, 0 off by 2ish
 //  .3, .0015, .00009 off by 1ish
 //robit.Drive(24, .03);
 /*std::cout<<"end to drive test [A] to continue"<<std::endl;
 waitUntil(Controller1.ButtonA.pressing());
 robit.Pivot(90, .03, true);
 wait(2, sec);
 robit.Pivot(180, .03, false);
 std::cout<<"end to Pivot test [A] to continue"<<std::endl;
 waitUntil(Controller1.ButtonA.pressing());
 robit.Point(0, .03);
 robit.turnFor(25, .03, true, false);
 std::cout<<"end to Poin & turn for test"<<std::endl;*/
}