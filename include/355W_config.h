


#include "vex.h"

using namespace vex;

vex::brain       Brain;

motor LeftFront = motor(PORT18, ratio36_1, true);
motor LeftMiddle = motor(PORT17, ratio36_1, true);
motor LeftBack = motor(PORT16, ratio36_1, true);

motor RightFront = motor(PORT13, ratio36_1, false);
motor RightMiddle = motor(PORT12, ratio36_1, false);
motor RightBack = motor(PORT11, ratio36_1, false);

motor ConveyorBelt = motor(PORT3, ratio36_1, true);
motor FrontIntake = motor(PORT2, ratio36_1, false);
motor BackRoller = motor(PORT1, ratio36_1, true);

inertial MyGyro = inertial(PORT4);

digital_out Scraper = digital_out(Brain.ThreeWirePort.A);



controller driveController1 = controller(primary);
controller driveController2 = controller(partner);