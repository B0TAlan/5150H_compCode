/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature RMGOAL = vex::vision::signature (1, 3259, 4663, 3960, -987, -563, -774, 1.9, 0);
vex::vision::signature BMGOAL = vex::vision::signature (2, -3305, -2835, -3070, 6223, 7131, 6676, 3, 0);
vex::vision::signature YMGOAL = vex::vision::signature (3, 335, 703, 518, -2647, -2213, -2430, 3, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::code RB = vex::vision::code (red, black );
vex::vision::code BB = vex::vision::code (black, blue );
vex::vision::code YB = vex::vision::code (black, yellow );
vex::vision viz = vex::vision (vex::PORT16, 41, RMGOAL, BMGOAL, YMGOAL, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/