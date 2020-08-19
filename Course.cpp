
#include "Course.h"

int _iStageNumber;
bool _completed = false; 
Servo _servo;

float _curSpeed;
float _nxtSpeed;

//Constructor 
Course::Course(int iStageNumber, Servo servo)
{
  _iStageNumber = iStageNumber;
  _servo = servo;
}

void Course::proceedMission(){
  
    switch(_iStageNumber){
      case 1:
        Serial.println("#100 Parallel Parking");
        parallelParking();
        _iStageNumber+=1;
        break;

      case 2:
        Serial.println("#200 Intersection 1");
        intersection();
        _iStageNumber+=1;
        break;

      case 3: 
        Serial.println("#300 Intersection 2");
        intersection();
        _iStageNumber+=1;
        break;

      case 4:
        Serial.println("#400 Backward Parking Stage 1");
        backwardParking();
        _iStageNumber+=1;
        break;

      case 5: 
        Serial.println("#500 Backward Parking Stage 2");
        impedimentAvoidance();
        _iStageNumber+=1;
        break;

      default:
        Serial.println("#Error:Unidentified Course Location");
        break;
    }
}


//평행주차 
void Course::parallelParking()
{
}

//교차로 
void Course::intersection()
{
  
}

//후진주차
void Course::backwardParking()
{
  
}


//회피주행
void Course::impedimentAvoidance()
{
  
}
