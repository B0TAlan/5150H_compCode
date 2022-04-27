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
  void Score(int vel, bool wait);
  void ClearWall(int vel, bool wait);
  void setPos(int pos);
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
  void Intake(int X, bool Wait);
  void Outtake(int X, bool Wait);
  void On(vex::directionType dir);
  void Off();
};

class Movement_Controller {
public:
  void customDrive(float target, float kp, float kd, float ki);
  void Drive(float target, float kp);

  void customTurn(float heading, float kp, float kd, float ki, bool left, bool right);
  void Point(float heading, float kp);
  void Pivot(float heading, float kp, bool Dir);
  void turnFor(float amount, float kp, bool Point, bool Dir);
};
