#include"main.h"

//HELPER
void setLift(int power){
  lift = power;


}

//Driver control
void setLiftMotor(){
  int  liftPower= 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  setLift(liftPower);

}
