/*
 * **Important**
 * 미션 수행을 위한 async 타이머 이용 Driving 
 * Abstraction layer for missions, for example, parallel/backward parking
 * Performs Designated Task in async for a given time period
 * 
 * 0. Stop for XX seconds
 * 1. Steer straight/right/left and drive forward/backward for XX seconds. 
 *    
 *    
 *    float gfCenterDistance;
      float gfLeftDistance;
      float gfRightDistance;  
 *    
 *    bool gbLeftIR;
      bool gbRightIR;
 */

//타이머 세팅
inline void setTimer()
{
  iTimeCount = 0;
  bInMission = true;
  MsTimer2::set(100, sense); //100ms period
  MsTimer2::start();
}

//타이머 중지
inline void stopTimer()
{
  bInMission = false;
  MsTimer2::stop();
  iTimeCount = 0;
}


//Stops for a designated amount of time 
//specifiedTime == 10 means specifiedTime = 1 second
void timedStop(int specifiedTime)
{
  setTimer();
  while(iTimeCount <= specifiedTime) 
  { 
    compute_steering = 0;
    compute_speed = 0;
    nextMove();
  }
  stopTimer();
}


//Drives for a designated amount of time 
//with response to IR sensors included
inline void timedDrive(int rightLeft, float forwardBack, int specifiedTime, bool senseLine, bool senseStop)
{
  setTimer(); 
  
  while(iTimeCount <= specifiedTime)
  {
    compute_steering = rightLeft;
    compute_speed = forwardBack;

    
    if(senseLine == true) 
    {
      if(gbLeftIR != detect_ir)
      {
        compute_speed = 1;
        compute_steering = 1;
      }
      else if(gbRightIR != detect_ir)
      {
        compute_speed = 1;
        compute_steering = -1;
      }

    }

    if(senseStop == true){
      if(gbLeftIR != detect_ir && gbRightIR != detect_ir){
        break;
      }
    }
    
    nextMove();
  }
  
  stopTimer(); 
}


//when parking using ultrasonic sensor 
void distancedDrive(int rightLeft, float forwardBack, int specifiedDistance)
{
  setTimer();
  
  //move until the right sensor becomes close to the wall
  while (gfRightDistance > specifiedDistance)
  {
    compute_steering = rightLeft;
    compute_speed = forwardBack;

    //when imepediment placed in front
    if(gfCenterDistance < 300)
    {
      compute_steering = -1;
    }
 
    //when line sensed
    if(gbLeftIR != detect_ir)
    {
      compute_steering = 1;
    } 
    else if(gbRightIR != detect_ir)
    {
      compute_steering = -1;
    }
    
    nextMove();
  }

  stopTimer();
}


void reverse(bool bSenseIR)
{
  setTimer();

  //move backwards until line is sensed by both sensors
  while(gbLeftIR == detect_ir || gbRightIR == detect_ir)
  {
    compute_steering = 0;
    compute_speed = -0.4;

    //when car too close to wall during parking
    if(gfLeftDistance < 100 && gfRightDistance > 100)
    {
      compute_steering = 1;
    }
    else if(gfLeftDistance > 100 && gfRightDistance < 100)
    {
      compute_steering = -1;
    }

    if(bSenseIR == true) 
    {
      //when line sensed
      if(gbLeftIR != detect_ir)
      {
        compute_steering = 1;
      } 
      else if(gbRightIR != detect_ir)
      {
        compute_steering = -1;
      }
    }

    
    //when the car is parked and left and right ultrasonic sensors ar sensing less than 15cm
    if(gfLeftDistance < 200 && gfRightDistance < 200 || gbLeftIR != detect_ir && gbRightIR != detect_ir){
      break;
    }
    nextMove();
  }
  
  stopTimer();
}
