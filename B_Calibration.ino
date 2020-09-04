
/*
 * 초음파센서 값을 받아 10cm 거리 유지하도록 설계. +-x cm 오차범위 허용
 */

 
inline void lineSensed()
{
  //오른쪽 차선 검출   
  if(gbRightIR != detect_ir) 
  {
    giRightIRCnt = giRightIRCnt + 0.02; 
    compute_steering = -giRightIRCnt;
    compute_speed = 0.1;
  }
  //왼쪽 차선 검출
  else if(gbLeftIR != detect_ir)
  {
    giLeftIRCnt = giLeftIRCnt + 0.02;
    compute_steering = giLeftIRCnt;
    compute_speed = 0.1;
  }
  else if(gbRightIR == detect_ir && gbLeftIR == detect_ir)
  {
    giLeftIRCnt = 0;
    giRightIRCnt = 0; 
  }
  
}

//distancing vehicle with surrounding wall
inline void calibrate(int sensorPosition, int distance)
{
  int specifiedDistance = distance;
  float steer = 0.1;
  
  //좌측
  if(sensorPosition == -1)
  {    
    if(gfLeftDistance > specifiedDistance)
    {
      compute_steering = -steer;
    } 
    else if (gfLeftDistance < specifiedDistance)
    {
      compute_steering = steer;
    }
  }
  
  //우측
  else if (sensorPosition == 1)
  {
    if(gfRightDistance > specifiedDistance)
    {
      compute_steering = steer;
    }
    else if (gfRightDistance < specifiedDistance)
    {
      compute_steering = -steer;
    }
  }
}


//정지선에서 앞으로 이동할 때 정지선을 밟은 시간차를 이용해 도로 위에서 차의 정렬을 맞춤
inline void correctStoplineDirection(float timeDifference, float forwardBack, int specifiedTime)
{
  setTimer();

  while(iTimeCount <= specifiedTime)
  {
    compute_steering = timeDifference; 
    compute_speed = 0.4;
    nextMove();
  }

  stopTimer();
  
  compute_steering = 0;
  compute_speed = forwardBack;
  nextMove();
  
}
