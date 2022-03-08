#include "robot-config.h"
#include <iostream>

class MotorControl{
  public:

    //const char Bt;

    void Brake(brakeType mode){
      Lf.stop(mode);
      Lb.stop(mode);
      Lm.stop(mode);
      Rf.stop(mode);
      Rb.stop(mode);
      Rm.stop(mode);

    }

    void setVel(int Lp, int Rp){
      Lf.spin(fwd ,Lp, voltageUnits::volt); //set the motors to the intended speed
      Lb.spin(fwd ,Lp, voltageUnits::volt);
      Lm.spin(fwd ,Lp, voltageUnits::volt);
      Rf.spin(fwd ,Rp, voltageUnits::volt);
      Rb.spin(fwd ,Rp, voltageUnits::volt);
      Rm.spin(fwd ,Rp, voltageUnits::volt);


    }

    void printVal(){
      std::cout<<"lf = "<<Lf.value()<<std::endl;
      std::cout<<"lb = "<<Lb.value()<<std::endl;
      std::cout<<"lm = "<<Lm.value()<<std::endl;
      std::cout<<"Rf = "<<Rf.value()<<std::endl;
      std::cout<<"Rb = "<<Rb.value()<<std::endl;
      std::cout<<"Rm = "<<Rm.value()<<std::endl;


    }



};


extern MotorControl Motors;
