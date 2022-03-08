#include"main.h"

//helper
void setDrive(int left, int right){
  lf = left;
  lb = left;
  rf = right;
  rb = right;


}


//teleOP
void setDriveMotors(){
  int Lstick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int Rstick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(abs(Lstick) < 10)
      Lstick = 0;
  if(abs(Rstick) < 10)
      Rstick = 0;
  setDrive(Lstick, Rstick);


}
