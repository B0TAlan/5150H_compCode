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

void skills_me(){ // Alan :(
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
 robit.Pivot(90, .03, true, false);
 robit.Pivot(180, .03, false, true);
}