#include "vex.h"
#include "MasterClass.h"

void SoloAwp(){
  /*Lift.rotateTo(.5, rev, true);// waits until lift raises to .5 revs to raise the lift over the Amgola
    driveBase.driveFor(fwd, 3, inches, 30, velocityUnits::pct);// drives tworads Amgoal to move the the clamp over the Amgoal
    clamp1Off();// opens clamp to drop pringle in Amgoal
    driveBase.driveFor(reverse, 5, inches, 30, velocityUnits::pct);// moves away form Amgoal
    driveBase.turnToHeading(90, rotationUnits::deg);// turns 90 degrees to move the second line of tiles on the feild 
    driveBase.driveFor(reverse, 20, inches, 50, velocityUnits::pct);// drive to the second row of tiles 
    driveBase.turnToHeading(180, rotationUnits::deg);// truns another 90 degrees in order to line up with next Amgoal
    driveBase.setStopping(brakeType::coast);// should change the the brake type so that it drifts to a stop but DNW
    bL.setVelocity(60, velocityUnits::pct);// set the backLift velocity to have be perfecly timed so it is all the down when the robot reaches other Amgoal
    bL.rotateTo(-4.8,rev, false);// lower the backLift all the way down in order to pick up the next Amgoal
    driveBase.driveFor(reverse, 90, inches, 40, velocityUnits::pct);// drive across the feel at half speed cause there is not neet to rush for solo awp
    driveBase.driveFor(reverse, 18, inches, 20, velocityUnits::pct);// manully cahnge the velocity so that the robot doesn't crash and burn
    bLD = true;// bool that represents whether backLift is down(true) or up(false)
    waitUntil(bL.position(rotationUnits::rev) == -4.8 || bLD == true);// waits for either the backLift pos is = to the lowest val or if the bool bLD is true 
    bL.rotateTo(-3.2,rev, false);// once the backLift is down and the robot is not moving, lift the back lift height to unload pringles
    waitUntil(bL.position(rotationUnits::rev) >= -3.3);// wait until the backLift is above a certin point to start the pring intank to dispence the pringles 
    pringle.spin(directionType::rev, 100, velocityUnits::pct);// start the pringle intake 
    wait(3, timeUnits::sec);// wait 3 sec to give time so that the pringels have time to fall onto Amgoal
    pringle.stop();// after 3 sec stop pringle intake
    Controller1.Screen.print("Pog");// print pog to controller cause its funny
    driveBase.setStopping(brakeType::hold);// DNW
    driveBase.turnToHeading(255, rotationUnits::rev);// turn to score last Amgoal
  */
}