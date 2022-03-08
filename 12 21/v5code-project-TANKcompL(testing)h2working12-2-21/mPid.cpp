using namespace std;
#include <iostream>
#include "stdarg.h"
#include <cstring>
#include <string.h>
#include "main.cpp"

void moveFwdT(double target, double maxVoltage) {

    //chassis_Set PIDControl;
    
    // MACHINE STATE WHEN ENTERING FUNCTION, MACHINE STATE AFTER
    double enterAngle = Gyro.rotation();

    // CONVERSION FROM INCHES TO ENCODER TICKS
    target = ((target * 360) / (4 * M_PI)) * (36 / 84);

    double output = 0, Dt = 0, encoderAvrg = 0;
    double prevError = 0, prevTime = Brain.Timer;

    // SLEW COMPONENTS
    double volCapMax = 12, volCap = 0;

    // SLEW TUNABLE
    double acceleration = .07;

    // PID COMPONENTS
    double error = 0, integral = 0, derivetive = 0;

    // CONSTATNTS
    double Kp = .11, Ki = 0.009, Kd = .007;

    // BOUNDS
    double errorMargin = 5, integralBound = 20;

    // CORECTION VARIABLES
    double targetAngle = 0, correctionOutput = 0;

    double enterVal = ((leftDrive.position(deg) + rightDrive.position(deg)) /2);

    int sign = 1;
    // CALCULATES ERROR FOR FUNCTION TO RUN
    error = target - encoderAvrg;

    while (fabs(error) > errorMargin) {

      double sensorVal = ((leftDrive.position(deg) + rightDrive.position(deg)) /2) - enterVal;

      // AVERAGE BETWEEN ENCODER VALUES
      encoderAvrg = sensorVal;

      // FINDS THE DIFFRENCE BETWEEN THE TARGET AND ROBOT
      error = target - encoderAvrg;

      // CALCULATES DELTA TIME IN MSEC
      Dt = (Brain.Timer - prevTime) / 1000;

      // FINDS  INTEGRAL WITH CONSTANT MULTIPLIER, AND ERROR
      integral += error * Dt;

      // FINDS DRVITIVE USING ERROR, AND PREVIOUS
      // DIVIDES BY TIME
      derivetive = (error - prevError) / Dt;

      // UPDATES THE PREVIOUS ERROR
      prevError = error;

      if (error > integralBound) {
        integral = 0;
      }

      // CALCULATES THE VOLTS TO BE SENT TO THE MOTORS
      output = error * Kp + integral * Ki + derivetive * Kd;

      // FINDS IF POS OR NEG
      sign = fabs(output) / output;

      if (fabs(output) > maxVoltage) {
        output = maxVoltage * sign;
      }

      // Slew rate
      if (fabs(output) > volCapMax)
        output = volCapMax * sign;

      volCap += acceleration * sign;
      if (fabs(volCap) > fabs(volCapMax)) {
        volCap = volCapMax * sign;
      }

      if (fabs(output) > fabs(volCap)) {
        output = volCap;
      }

      // DIFFRENCE IN MACHINE STATE
      correctionOutput = targetAngle - (enterAngle - Gyro.rotation());

      // CHECKS MACHINE STATE
      if (fabs(enterAngle - Gyro.rotation()) > targetAngle) {
       leftDrive.spin(directionType::fwd, output + correctionOutput, voltageUnits::volt);
       rightDrive.spin(directionType::fwd, output - correctionOutput, voltageUnits::volt);
        // UPDATES MACHINE STATE TO BE DESIRABLE
        //PIDControl.move(output + correctionOutput, output - correctionOutput);

      }
      /*else if (fabs(enterAngle + Gyro.rotation()) < targetAngle) {
       leftDrive.spin(directionType::fwd, output - correctionOutput, voltageUnits::volt);
       rightDrive.spin(directionType::fwd, output + correctionOutput, voltageUnits::volt);
        // UPDATES MACHINE STATE TO BE DESIRABLE
        //PIDControl.move(output + correctionOutput, output - correctionOutput);

      }*/

      // IF MACHINE STATE DESIRABLE CONTINUE PID
      else {
        leftDrive.spin(directionType::fwd, output, voltageUnits::volt);
        rightDrive.spin(directionType::fwd, output, voltageUnits::volt);
      }
    
      // DEBUGGING
      std::cout << "power: " << output << std::endl;
      std::cout << "error: " << error << std::endl;

      // UPDATES PREVIOUS TIME
      prevTime = Brain.Timer;

      // ALLOWS FOR UDATES TO VALUES
      wait(15, msec);
    }

    // STOPS THE ROBOT PREVENTS FURTHER MOVEMENT
    //PIDControl.rest();
    leftDrive.stop(hold);
    rightDrive.stop(hold);
  }