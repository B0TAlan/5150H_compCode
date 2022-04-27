#pragma once

// Drivebase Shortcuts
class DriveBaseControler {
public:
  void Brake(vex::brakeType mode);
  void Reset();
  void Move(int L, int R);
  void MoveL(int L);
  void MoveR(int R);
};

// Subsytem Shortcuts
class LiftShortcut {
public:
  void Max(int vel, bool wait);
  void Min(int vel, bool wait);
  void Idle(int vel, bool wait);
  void P(int vel, bool wait);
  void Score(int vel, bool wait);
  void ClearWall(int vel, bool wait);
  void setPos(int pos);
  void lock();
  void unLock();
};

class ClampShortcuts {
private:
  bool state;

public:
  bool closed = false;
  void Open();
  void Cloes();
  void OF();
  void CF();
};

class BackLiftShortcuts {
private:
  bool state;

public:
  bool bLOff = true;
  void Open();
  void Close();
  void OF();
  void CF();
};

class PringleShortcuts {
public:
  void Intake(int X, vex::timeUnits time);
  void Outtake(int X, vex::timeUnits time);
  void On(vex::directionType dir);
  void Off();
};

class Movement_Controller {
private:
  float maxPow = 13;
  float acceleration = 0;

public:
  void customDrive(float target, float kp, float kd, float ki, float Volts);
  void Drive(float target, float Volts);

  void customPoint(float heading, float kp, float kd, float ki, float Volts);
  void customPivot(float heading, float kp, float kd, float ki, float Volts);
  void Point(float heading, float Volts);
  void Pivot(float heading, float Volts);
  void turnFor(float amount, float Volts, bool Point);
};
