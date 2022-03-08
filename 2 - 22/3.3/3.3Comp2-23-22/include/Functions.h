#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern void pringleIntake();

extern void liftControl();

extern bool cOn;

extern void clampOpen();
extern void clampCloes();

extern bool bLD;

extern void bLOpen();
extern void bLClose();

extern vex::brakeType driveBrake;

extern void setBrake();

extern void logTank();

extern void clearPrint(int B, int C, int C2);
extern void gyroConfig();

#endif