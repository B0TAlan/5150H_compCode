#include "vex.h"
#include "Classes.h"

bool mLoads = false;
bool prinLine = false;

void left20(){ // free
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
}

void right20(){// free
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
}

void rightMid(){// Matt
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
}

void leftMid(){// Aahil
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
}

void s_kill_me(){ // Alan :(
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;
}

void testing(){
  Movement_Controller robit;
  LiftShortcut lift;
  BackLiftShortcuts bL;
  ClampShortcuts clamp;

 robit.Drive(24, .03);
 robit.Point(180, .03);
 robit.Drive(24, .03);
 std::cout<<"end to drive test [A] to continue"<<std::endl;
 waitUntil(Controller1.ButtonA.pressing());
 robit.Pivot(90, .03, true);
 wait(2, sec);
 robit.Pivot(180, .03, false);
 std::cout<<"end to Pivot test [A] to continue"<<std::endl;
 waitUntil(Controller1.ButtonA.pressing());
 robit.Point(0, .03);
 robit.turnFor(25, .03, true, false);
 std::cout<<"end to Poin & turn for test"<<std::endl;
}