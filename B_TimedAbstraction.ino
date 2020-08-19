/*
 * **Important**
 * 미션 수행을 위한 async 타이머 이용 Driving -- For General Use
 * Abstraction layer for missions, for example, parallel/backward parking
 * Performs Designated Task for a given time period
 * 
 * 0. Stop for XX seconds
 * 1. Steer straight/right/left and drive forward/backward for XX seconds. 
 *    If there is a 
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
inline void timedDrive(int rightLeft, int forwardBack, int specifiedTime, bool enableIR)
{
  setTimer(); 
  
  while(iTimeCount <= specifiedTime)
  {
    compute_steering = rightLeft;
    compute_speed = forwardBack;

    
    if(enableIR == true) 
    {
      if(gbLeftIR != detect_ir)
      {
        compute_speed = 0.3;
        compute_steering = 1;
      }
      else if(gbRightIR != detect_ir)
      {
        compute_speed = 0.3;
        compute_steering = -1;
      }

    }
    
    nextMove();
  }
  
  stopTimer(); 
}


//when parking
void park(int rightLeft, int specifiedDistanced, bool enableIR)
{
  //for parallel parking 
  if(enableIR == false) 
  {
    
  }
  //for backward parking 
  else {
    
  }
  
}
