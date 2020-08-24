
/*
 * 초음파센서 값을 받아 10cm 거리 유지하도록 설계. +-1cm 오차범위 허용
 */
 
inline void calibrate(int sensorPosition)
{
  int specifiedDistance = 100;
  int errorRange = 20;
  
  //좌측
  if(sensorPosition == -1)
  {
    if(gfLeftDistance > specifiedDistance + errorRange)
    {
      compute_steering = -0.1;
    }
    else if (gfLeftDistance < specifiedDistance - errorRange)
    {
      compute_steering = 0.1;
    }
  }

  //전방
  else if (sensorPosition == 0)
  {
    
  }
  
  //우측
  else if (sensorPosition == 1)
  {
    if(gfRightDistance > specifiedDistance + errorRange)
    {
      compute_steering = 0.1;
    }
    else if (gfRightDistance < specifiedDistance - errorRange)
    {
      compute_steering = -0.1;
    }
  }

}
