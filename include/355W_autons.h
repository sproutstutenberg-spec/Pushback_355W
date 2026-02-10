

#include "vex.h"
//#include "355W_config.h"
#include <iostream>
#include <cmath>


using namespace vex;


void auto_left_blue(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }

  
//Drive forward
      driveFor(30,-24.0);

 // wait(2,seconds);
//turn 90 degrees to the left
  GyroTurnLeft(20,90,5);
    
//  wait(2,seconds);
//Drive forward and hit the scorer
  drive(-20,7);

//  wait(2,seconds);
//Dispense the ball
   ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(10,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

}







void auto_right_blue(){

  while(1==1){

    if(!MyGyro.isCalibrating()) break;

  }
//drive forward
  driveFor(30,-24.0);

 // wait(2,seconds);
//Turn to the left
  GyroTurnLeft(20,75,5);
    
//  wait(2,seconds);
//drive forward and hit the goal
  drive(-20,4);

//  wait(2,seconds);
//Dispense the ball
   ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(2,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

}




void auto_right_red(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }
    //drive forward
 driveFor(30,-24.0);

 // wait(2,seconds);
//turn left 90 degrees
  GyroTurnLeft(20,83,5);
    
//  wait(2,seconds);
//drive forward and hit the goal
  drive(-20,7);

//  wait(2,seconds);
//dispense the ball
   ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(10,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

}
   


void auto_dummy(){}


void auto_left_red(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }
//drive forward
    driveFor(30,-24.0);

 // wait(2,seconds);
//turn 90 degrees left
  GyroTurnLeft(20,-90,5);
    
//  wait(2,seconds);
//drive forward and hit the goal
  drive(-20,7);

//  wait(2,seconds);
//dispense the ball
   ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(10,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

}
void auto_skills_park(){

  while(1==1){

    if(!MyGyro.isCalibrating()) break;

  }
drive(30,.3);
wait(.5,seconds);
drive(-50,2);
}

/* this is the big one */
void auto_skills(){

    while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }
 //Drive forward
      driveFor(40,-50.0);
  

 // wait(2,seconds);
//turn 90 degrees to the left
  GyroTurnRight(30,88,3);
    
  wait(.01,seconds);
//Drive forward and hit the scorer
      drive(-30,3);

//  wait(2,seconds);
//Dispense the ball
   ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(3,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();
   
  Scraper.set(true);

  drive(30,3);
    FrontIntake.spin(forward,90,percent);

    ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(forward,90,percent); 

    wait(5,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

   FrontIntake.stop();

    drive(-30,3);

     FrontIntake.spin(forward,90,percent);

    ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(reverse,90,percent); 

    wait(5,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

   FrontIntake.stop();

   drive(30,3);

    FrontIntake.spin(forward,90,percent);

    ConveyorBelt.spin(forward,90,percent);

   BackRoller.spin(forward,90,percent); 

    wait(5,seconds);

   ConveyorBelt.stop();

   BackRoller.stop();

   FrontIntake.stop();
}
