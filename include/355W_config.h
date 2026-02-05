


#include "vex.h"

using namespace vex;

vex::brain       Brain;

motor LeftFront = motor(PORT18, ratio18_1, true);
motor LeftMiddle = motor(PORT17, ratio18_1, true);
motor LeftBack = motor(PORT16, ratio18_1, true);

motor RightFront = motor(PORT13, ratio18_1, false);
motor RightMiddle = motor(PORT12, ratio18_1, false);
motor RightBack = motor(PORT11, ratio18_1, false);

motor ConveyorBelt = motor(PORT3, ratio6_1, true);
motor FrontIntake = motor(PORT2, ratio18_1, false);
motor BackRoller = motor(PORT1, ratio18_1, true);

inertial MyGyro = inertial(PORT4);

digital_out Scraper = digital_out(Brain.ThreeWirePort.A);



controller driveController1 = controller(primary);
controller driveController2 = controller(partner);