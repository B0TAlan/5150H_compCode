#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// DriveCode.cpp
extern vex::brakeType driveBrake;

extern void setBrake();

extern void logTank();
extern void marioKart();

// Funcrions.cpp

// Pingle Intake
extern void pringleIntake();
extern void singlePringle();
extern void pushingP();

// Lift
extern bool Lock;
extern void liftControl();
extern void liftLock();
extern void liftUnLock();
extern void liftLocker();
extern void lockLift();

// Clamp
extern bool cOn;

extern void clampOpen();
extern void clampCloes();

// Back Lift
extern bool bLD;

extern void bLOpen();
extern void bLClose();

// extra
extern void clearPrint(int B, int C, int C2);
extern void gyroConfig();

extern void buildIssue();

extern void setState(bool clamp, bool baL);

extern void gyroReadings();

#endif