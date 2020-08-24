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
  MsTimer2::set(100, sense); //100us period
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




//정해진 시간동안 주행하며 센서와 물체간 거리 유지 - 초음파센서 값 필요 없으면 ultrasonicSensor = 0 으로 설정
//Drives for a designated amount of time. Response to ultrasonic and IR sensors included
//ultrasonic sensor ==>    -1 : Left, 0 : Center, 1 : Right, null : none
inline void timedDrive(int rightLeft, float forwardBack, int specifiedTime, int sensorPosition, bool senseLine)
{
  setTimer(); 
  int specifiedDistance = 100;

  //주어진 시간동안 함수 실행
  while(iTimeCount <= specifiedTime)
  {
    compute_steering = rightLeft;
    compute_speed = forwardBack;

    //거리두기
    calibrate(sensorPosition);

    //IR센서를 이용해 라인 벗어나지 않도록
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
    
    nextMove();
  }
  
  stopTimer(); 
}




//특정 센서가 정해진 거리에 닿으면 정지
//when parking using ultrasonic sensor
//ultrasonicSensor::: -1 : Left
void distancedDrive(int rightLeft, float forwardBack, int specifiedDistance, int sensorPosition)
{
  setTimer();

  if(sensorPosition == -1)
  {
    //move until the right sensor becomes close to the wall
    while (gfLeftDistance > specifiedDistance)
    {
      compute_steering = rightLeft;
      compute_speed = forwardBack;
   
      //when line sensed
      if(gbLeftIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = 1;
      } 
      else if(gbRightIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = -1;
      }
      
      nextMove();
    }
   
  }
  else if(sensorPosition == 0)
  {
    //move until the right sensor becomes close to the wall
    while (gfCenterDistance > specifiedDistance)
    {
      compute_steering = rightLeft;
      compute_speed = forwardBack;
   
      //when line sensed
      if(gbLeftIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = 1;
      } 
      else if(gbRightIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = -1;
      }
      
      nextMove();
    }
    
  }
  
  else if(sensorPosition == 1)
  {
    //move until the right sensor becomes close to the wall
    while (gfRightDistance > specifiedDistance)
    {
      compute_steering = rightLeft;
      compute_speed = forwardBack;
   
      //when line sensed
      if(gbLeftIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = 1;
      } 
      else if(gbRightIR != detect_ir)
      {
        compute_speed = forwardBack;
        compute_steering = -1;
      }
      
      nextMove();
    }
    
  }
  
  stopTimer();
}


//후진 로직 
void reverse(bool bWillSenseIR, int sensorPosition)
{
  setTimer();

  //정지선 다다를때까지 후진
  //move backwards until line is sensed by both sensors
  while(gbLeftIR == detect_ir || gbRightIR == detect_ir)
  {
    compute_steering = 0;
    compute_speed = -0.4; 

    //초음파센서 값 읽어 후진할 때 거리 유지 
    //오차범위 +- 1cm 
    calibrate(sensorPosition);
    
    if(bWillSenseIR == true) 
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

    nextMove();
  }
  
  stopTimer();
}
