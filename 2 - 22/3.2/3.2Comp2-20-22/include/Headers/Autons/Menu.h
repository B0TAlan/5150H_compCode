#ifndef  MENU_H
#define MENU_H

#include "../Autons/Menu.cpp"

extern bool runR;
extern bool runL;
extern bool noRun;
extern int opt;
extern bool preATon;

extern void menuInput();
extern void menuOutput();
extern void menu();
extern void gyroConfig();
extern void clearPrint(int B, int C, int C2);

#endif