#include"main.h"

//HELPER
void setClamp(int power){
  clamp = power;


}

//Driver control
void setClampOn(){

  clamp.move_absolute(.65,127);
  if (clamp.get_position() >= .6){
    std::cout<<"pog"<<std::endl;
    clamp.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  int  clampPower= 0;


}

void setClampOff(){

  clamp.move_absolute(.0,127);
  if (clamp.get_position() <= .1){
    std::cout<<"pog"<<std::endl;
    clamp.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  }
  int  clampPower= 0;


}

void clampControl(){
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
    setClampOn();
  }
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
    setClampOff();
  }


}
