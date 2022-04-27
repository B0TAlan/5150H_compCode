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
public:
  bool closed = false;
  void Open();
  void Cloes();
  void OF();
  void CF();
};

class BackLiftShortcuts {
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

class PID_Controller {
public:
  void customDrive(float target, float kp, float kd, float ki);
  void customTurn(float heading, float kp, float kd, float ki);
  void Drive(float target, float kp, float kd, float ki);
  void Turn(float heading, float kp, float kd, float ki);
  void fodom();
};
