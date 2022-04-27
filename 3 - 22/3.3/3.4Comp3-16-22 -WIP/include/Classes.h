#pragma once
using namespace vex;

//Drivebase Shortcuts
class DriveBaseControl{};

// Subsytem Shortcuts
class LiftShortcut{
  public:
  void Max(int vel, bool wait);
  void Min(int vel, bool wait);
  void Idle(int vel, bool wait);
  void Score(int vel, bool wait);
  void ClearWall(int vel, bool wait);
  void setPos(int pos);
};


class ClampShortcuts{
  public:
  bool closed = false;
  void Open();
  void Cloes();
  void OF();
  void CF();
};


class BackLiftShortcuts{
  public:
  bool bLOff = true;
  void Open();
  void Close();
  void OF();
  void CF();
};

class PringleShortcuts{
  void Intake(int X, bool Wait);
  void Outtake(int X, bool Wait);
  void On(directionType dir);
  void Off();
};


