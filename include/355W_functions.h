

#include "vex.h"
#include <iostream>
#include <cmath>

using namespace vex;

void driveFor(int power, float distance)
{
  float diameter= 3.25; //inches
  
  float degR =  distance/diameter;  // radians

  float deg = degR*180.0/3.1416;


  // Tell the motor what power/velocity it should drive at
  LeftFront.setVelocity(power, percent);
  RightFront.setVelocity(power, percent);
  LeftMiddle.setVelocity(power, percent);
  RightMiddle.setVelocity(power, percent);
  LeftBack.setVelocity(power, percent);
  RightBack.setVelocity(power, percent);

  // Its turning on the motor and telling it to stay
  // on until the motor rotat3es a certain number of degrees
  // The false/true tells the robot to excecute all comands
  //  at the same time until it reaches the end (true)
  LeftFront.spinFor(deg, degrees, false);
  RightFront.spinFor(deg, degrees, false);
  LeftMiddle.spinFor(deg, degrees, false);
  RightMiddle.spinFor(deg, degrees, false);
  LeftBack.spinFor(deg, degrees, false);
  RightBack.spinFor(deg, degrees, true);

  // turn motors off
  LeftFront.stop();
  RightFront.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
  LeftBack.stop();
  RightBack.stop();

  // wait a bit then exit
  wait(10, msec);
}

void drive(int power, float time)
{



  // Tell the motor what power/velocity it should drive at
  LeftFront.setVelocity(power, percent);
  RightFront.setVelocity(power, percent);
  LeftMiddle.setVelocity(power, percent);
  RightMiddle.setVelocity(power, percent);
  LeftBack.setVelocity(power, percent);
  RightBack.setVelocity(power, percent);

  // Its turning on the motor and telling it to stay
  // on until the motor rotat3es a certain number of degrees
  // The false/true tells the robot to excecute all comands
  //  at the same time until it reaches the end (true)
  LeftFront.spin(forward,power,percent);
  RightFront.spin(forward,power,percent);
  LeftMiddle.spin(forward,power,percent);
  RightMiddle.spin(forward,power,percent);
  LeftBack.spin(forward,power,percent);
  RightBack.spin(forward,power,percent);

  wait(time,seconds);

  // turn motors off
  LeftFront.stop();
  RightFront.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
  LeftBack.stop();
  RightBack.stop();

  // wait a bit then exit
  wait(10, msec);
}

// turn time is in seconds, power is in percent,
// forward dir is 1, backward is -1;
void turn(int dir, int power, float time)
{
  // turn motors on to turn right
  if (dir == 1)
  {

    LeftFront.spin(forward, power, percent);
    RightFront.spin(reverse, power, percent);
    LeftMiddle.spin(forward, power, percent);
    RightMiddle.spin(reverse, power, percent);
    LeftBack.spin(forward, power, percent);
    RightBack.spin(reverse, power, percent);
  }

  // turn motors on to turn left
  if (dir == -1)
  {

    LeftFront.spin(reverse, power, percent);
    RightFront.spin(forward, power, percent);
    LeftMiddle.spin(reverse, power, percent);
    RightMiddle.spin(forward, power, percent);
    LeftBack.spin(reverse, power, percent);
    RightBack.spin(forward, power, percent);
  }

  // wait until you get where you want to go
  wait(time, seconds);

  // turn motors off
  LeftFront.stop();
  RightFront.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
  LeftBack.stop();
  RightBack.stop();

  // wait a bit then exit
  wait(10, msec);
}

void GyroTurnLeft(float speed, float angle, float TargetError)
{

  float xgyroInit = MyGyro.angle();

  float target_angle = xgyroInit - angle;

  if(target_angle<0) target_angle = target_angle + 360;

  // right turn
  LeftFront.spin(reverse, speed, percent);
  RightFront.spin(forward, speed, percent);
  LeftMiddle.spin(reverse, speed, percent);
  RightMiddle.spin(forward, speed, percent);
  LeftBack.spin(reverse, speed, percent);
  RightBack.spin(forward, speed, percent);

  while (1)
  {

    //        std::cout<< MyGyro.angle()<< std::endl;

    float xgyro = MyGyro.angle();

    float error = xgyro-target_angle;

    if(std::abs(error) < TargetError) break;

    //        std::cout<<"xgyro = " << xgyro <<", " << "error = " << error << std::endl;

    wait(0.010, seconds);
  }
  LeftFront.stop();
  RightFront.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
  LeftBack.stop();
  RightBack.stop();

  return;
}

void GyroTurnRight(float speed, float angle, float TargetError)
{

  // float xgyroInit = MyGyro.angle();

  // float target_angle = xgyroInit + angle;

  //   if(target_angle>360) target_angle = target_angle - 360;

  // right turn
  LeftFront.spin(forward, speed, percent);
  RightFront.spin(reverse, speed, percent);
  LeftMiddle.spin(forward, speed, percent);
  RightMiddle.spin(reverse, speed, percent);
  LeftBack.spin(forward, speed, percent);
  RightBack.spin(reverse, speed, percent);

  while (1)
  {

    // std::cout<< MyGyro.angle()<< std::endl;

    //  float xgyro = MyGyro.angle();

    //  float error = xgyro-target_angle;

    //    if(std::abs(error) < TargetError) break;

    // std::cout<<"xgyro = " << xgyro <<", " << "ygyro = " << ygyro << std::endl;

    wait(0.010, seconds);
  }
  LeftFront.stop();
  RightFront.stop();
  LeftMiddle.stop();
  RightMiddle.stop();
  LeftBack.stop();
  RightBack.stop();

  return;
}



void Drivetrain(){
    
// axis value
  float a3 = 0.0;
  float a1 = 0.0;

// axis threshold squared (10%)
  float t3 = 100.0;
  float t1 = 100.0;

  float a23 = 0.0;
  float a22 = 0.0;

  float t23 = 100.0;
  float t22 = 100.0;

  int i = 0;

  while(1==1)
  {

    i++;

    wait(0.01, seconds);

    // drivetrain controller part
    a3 = driveController1.Axis3.position();
    a1 = driveController1.Axis1.position();

    if(a3*a3 > t3 || a1*a1 > t1){  //either going straight or turning

      // this combination of a3 and a1 values will do the correct thing 
      // if you are going forward, backward, left, or gight
      LeftFront.spin(forward,a3+a1,percent);
      RightFront.spin(forward,a3-a1,percent);
      LeftMiddle.spin(forward,a3+a1,percent);
      RightMiddle.spin(forward,a3-a1,percent);
      LeftBack.spin(forward,a3+a1,percent);
      RightBack.spin(forward,a3-a1,percent);
    
    }else{
  
      LeftFront.stop(coast);
      RightFront.stop(coast);
      LeftMiddle.stop(coast);
      RightMiddle.stop(coast);
      LeftBack.stop(coast);
      RightBack.stop(coast);

    }

    // intake and scoring mechanism part
    // this needs to be updated depending on what bottons, joy sticks they want to use
    a23=driveController2.Axis3.position();
    a22=driveController2.Axis2.position();



    if(a23*a23 > t23){
      FrontIntake.spin(forward,0.9*a23,percent); 
    }else{
      FrontIntake.stop();
    }
    


    if(driveController2.ButtonR1.pressing()){ 
      ConveyorBelt.spin(forward,90,percent);

    }else{
      ConveyorBelt.stop();
    }

    if(a22*a22 > t22){
      BackRoller.spin(forward,0.95*a23,percent); 
    }else{
      BackRoller.stop();
    }
    
//L1 button backroller forward
if(driveController2.ButtonL1.pressing()||driveController2.ButtonL2.pressing()){ 
    
  if(driveController2.ButtonL1.pressing()){ 
      BackRoller.spin(reverse,90,percent);
  
    }   
//L2 button backroller reverse
    if(driveController2.ButtonL2.pressing()){ 
      BackRoller.spin(forward,90,percent);
    

    }
  }else{
      BackRoller.stop();
  }   
  
    



    if(driveController1.ButtonL1.PRESSED){ 
      Scraper.set(true);  //extend
      
      
    }
    if(driveController1.ButtonR1.PRESSED){
      Scraper.set(false);  //extend
      
  
    }

   
  }
}

/*
void Drivetrain()
{

  float a3 = 0.0;
  float a1 = 0.0;

  float t3 = 100.0;
  float t1 = 100.0;

  float a23 = 0.0;
  float a22 = 0.0;
  float a21 = 0.0;
  float a20 = 0.0;
  float a19 = 0.0;

  float t23 = 100.0;
  float t22 = 100.0;
  float t21 = 100.0;
  float t20 = 100.0;
  float t19 = 100.0;

  int i = 0;

  while (1 == 1)
  {

    i++;

    wait(0.01, seconds);

    a3 = driveController1.Axis3.position();
    a1 = driveController1.Axis1.position();

    if (a3 * a3 > t3 || a1 * a1 > t1)
    {

      LeftFront.spin(forward, a3 + a1, percent);
      RightFront.spin(forward, a3 - a1, percent);
      LeftMiddle.spin(forward, a3 + a1, percent);
      RightMiddle.spin(forward, a3 - a1, percent);
      LeftBack.spin(forward, a3 + a1, percent);
      RightBack.spin(forward, a3 - a1, percent);
    }
    else
    {

      LeftFront.stop(coast);
      RightFront.stop(coast);
      LeftMiddle.stop(coast);
      RightMiddle.stop(coast);
      LeftBack.stop(coast);
      RightBack.stop(coast);
    }

    // scoring mechanism controller attachment
    a23 = driveController2.ButtonL1.pressing(); // Front Intake
    a22 = driveController2.ButtonL2.pressing(); // Front Intake
    a21 = driveController2.Axis2.position();    // Conveyor Belt
    a20 = driveController2.ButtonR1.pressing(); // Back Roller
    a19 = driveController2.ButtonR2.pressing(); // Back Roller
  
  // Front intake

    if (a23 > 0)
    {
      FrontIntake.spin(forward, 0.75 * a23, percent);
    }

    else if (a22 > 0)
    {
      FrontIntake.spin(reverse, 0.75 * a22, percent);
    }

    {
      FrontIntake.stop(coast);
    }
  // conveyor belt
  if (a21 * a21 > t21)
  {
    ConveyorBelt.spin(forward, 0.75 * a21, percent);
  }
  else

    // Back Roller

    if (a20 > 0)
    {
      BackRoller.spin(forward, 0.75 * a20, percent);
    }
  // else

  if (a19 > 0)
  {
    BackRoller.spin(reverse, 0.75 * a19, percent);
  }
  //  else

  // pneumatics
  if (driveController2.ButtonL1.PRESSED)
  {
    Scraper.set(true); // extends pneumatic arm to lower scraper
    // I don't know if it should be true or false
  }
  else

      if (driveController2.ButtonL1.PRESSED)
  {
    Scraper.set(false);
  }
  }
    return;
}


  if(a22*a22 > t22){
    Wheels.spin(forward,a22,percent);

  }else{
    Wheels.stop();

  }

  if(driveController2.ButtonL1.PRESSED){
    Pneumatic1.set(true);  //extend


  }
  if(driveController2.ButtonR1.PRESSED){
    Pneumatic1.set(false);  //extend


  }
  if(driveController1.ButtonL1.PRESSED){
    Pneumatic2.set(true);  //extend


  }
  if(driveController1.ButtonR1.PRESSED){
    Pneumatic2.set(false);  //extend


  }
*/    
