

#include "vex.h"
//#include "355W_config.h"
#include <iostream>
#include <cmath>


using namespace vex;


void auto_left_blue(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }

    driveFor(40,-2.2*360);



    GyroTurnRight(20,80,5);

    

}




void auto_right_blue(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }

    

}




void auto_right_red(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }

   

}



void auto_left_red(){

  while(1==1){

        if(!MyGyro.isCalibrating()) break;

    }

   

}