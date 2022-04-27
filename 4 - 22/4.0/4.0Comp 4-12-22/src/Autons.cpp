#include "vex.h"
#include "Classes.h"
#include "Functions.h"

bool mLoads = false;
bool prinLine = false;
bool AutoDone = false;

void left20(){ // free
  Movement_Controller robit;
  DriveBaseControler base;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;
}

void right20(){// free
  Movement_Controller robit;
  DriveBaseControler base;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;

  lift.lock();
  clamp.OF();
  robit.Drive(45.5, .015);
  clamp.Cloes();
  robit.Drive(-22.5, .02);
  lift.Idle(100, true);
  robit.customPoint(270, .15, .002, .0000);
  bL.Open();
  robit.Drive(4, .013);
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
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;
}

void leftMid(){// Aahil
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;
}

void s_kill_me(){ // Alan :(
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;
}

void testing(){
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
  AutoDone = false;

  lift.lock();
  robit.customPivot(90, .1, .1, .000055, true, false);
 // robit.customPoint(95, .13, 9.8, .00005);
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