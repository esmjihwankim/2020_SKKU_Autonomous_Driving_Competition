/*
 * Course.h - Has tasks listed for a specific circuit 
 * Created by Jihwan Kim, 18 August 2020
 */

#include "Arduino.h"
#include <Servo.h>

 class Course
{
private:
  int _iStageNumber;


public:
  Course(int stageNumber, Servo servo);

  //코스정보에 따른 동작 수행
  void proceedMission();
  

  //평행주차 
  void parallelParking();

  //교차로 
  void intersection();

  //후진주차
  void backwardParking();

  //회피주행
  void impedimentAvoidance();
};
