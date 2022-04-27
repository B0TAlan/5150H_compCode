#include "vex.h"
#include "Classes.h"
#include "Functions.h"

bool pring = false;

Movement_Controller robit;
DriveBaseControler base;
LiftShortcut lift;
BackLiftShortcuts bL;
ClampShortcuts clamp;
PringleShortcuts pringTake;

void left20(){ // needs tuning

  lift.lock();
  lift.setPos(0);
  clamp.OF();
  robit.Drive(41, 11);
  clamp.Cloes();
  lift.Idle(60, false);
  robit.Drive(-38, 8);
  //robit.Pivot(300, 6);
  robit.customPivot(310, .35, 0.0002, 0.00004, 8);
  bL.Open();
  robit.customDrive(-10.5, .1, .06, .001, 4);
  bL.Close();
  robit.customPivot(220, .2, 0.0002, 0.0003, 8);
  lift.ClearWall(80, true);
  pringTake.On(reverse);
  robit.Drive(15, 6);
  robit.Drive(-15, 6);
  robit.Drive(15, 6);
  robit.Drive(-15, 6);


}

void right20(){// about 11 sec

  lift.lock();
  clamp.OF();
  robit.Drive(41, 10);
  clamp.Cloes();
  lift.Idle(60, false);
  robit.Drive(-30, 8);
  robit.customPoint(270, .1, .03, .00004, 6);
  bL.Open();
  robit.customDrive(-8, .1, .06, .001, 4);
  bL.Close();
  
  lift.P(100, true);
  robit.customPoint(0, .1, .04, .00004, 6);
  robit.customDrive(4, .1, .06, .001, 4);
  robit.customPivot(0, .2, 0.0002, 0.0003, 8);
  pringTake.On(reverse);
  robit.Drive(26, 10);
  robit.Drive(-28, 6);
  bL.Open();
  

  // TURN //
  // MATCH LOADS//
  if(!pring){

    // TURN TO PRING LINE //
    // LIFT LIFT //
    // DIVE & INTAKE LINE //
    // RETURN TO SCORE //
  } else if (pring) {
    // TURN TO WALL //
    // LIFT LIFT //
    // DRIVE BACK AND FORWARD FOR MATCH LOADS //
  } else{
    base.Brake(hold);
  }

}

void rightMid(){// Matt
  if(!pring){
    Paincreas.Screen.print("snort");
    // TURN TO PRING LINE //
    // LIFT LIFT //
    // DIVE & INTAKE LINE //
    // RETURN TO SCORE //
  } else if (pring) {
    Paincreas.Screen.print("feeding");
    // TURN TO WALL //
    // LIFT LIFT //
    // DRIVE BACK AND FORWARD FOR MATCH LOADS //
  } else{
    base.Brake(hold);
  }
 
}

void right40(){
  lift.lock();
  clamp.OF();
  robit.Drive(40, 12);
  clamp.Cloes();
  //lift.Idle(60, false);
  robit.Drive(-26, 10);
  clamp.OF();
  lift.Min(100, true);
  //robit.customDrive(-8, .1, .06, .001, 4);
  robit.Drive(-16, 8);
  robit.customPivot(325, .2, 0.0002, 0.0001, 8);
  robit.Drive(51, 11);
  clamp.Cloes();
  robit.Drive(-37, 10);
  clamp.Open();
  robit.customDrive(-4, .1, .06, .001, 4);
  robit.customPoint(265, .24, .01, .000034, 6);
  bL.Open();
  robit.Drive(-16, 6);
  bL.Close();


  /*//robit.Drive(-18, 8);
  robit.customPivot(105, .3, 0.0002, 0.00004, 8, left, false);
  //robit.customPivot(115, .2, 0.0002, 0.0003, 8);
  bL.Open();
  robit.customDrive(-14, .1, .06, .001, 4);
  bL.Close();*/
  


}

void s_kill_me(){ // Alan :(
  
}

void testing(){

  lift.lock();
  robit.Drive(-16, 8);
  //robit.customPoint(324, .23, .01, .00004, 6);
  robit.customPivot(325, .2, 0.0002, 0.0001, 8);
  //robit.customPoint(317, .15, .01, .000055, 6);
  //robit.customPoint(275, .1, .045, .00004, 6);
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