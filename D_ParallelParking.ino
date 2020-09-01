/* 평행주차 
 * Used Functions:
 * 

void timedStop(int specifiedTime)
inline void timedDrive(int rightLeft, float forwardBack, int specifiedTime, int ultrasonicSensor, bool senseLine)
void distancedDrive(int rightLeft, float forwardBack, int ultrasonicValue, int specifiedDistance)
void reverse(bool bWillSenseIR, int ultrasonicSensor)

gfCenterDistance
gfRightDistance
gfLeftDistance
 * 
 * Remember 
 * forwardBack == 1 -> 100% speed in forward direction
 * specifiedTime == 10 -> 1 second 
 * specifiedDistance == 120 -> 12CM
 */

void parallelParking(float timeDifference)
{   
  //정지 1초
  HM10.write("---timedStop\n");
  timedStop(10);

  //보정 
  correctStoplineDirection(timeDifference, 0.5, 1);

  //벽 등장할때까지 직진 
  HM10.write("---Wall Appears\n");
  distancedDrive(0, 0.6, 1, true, 200);

  //오른쪽 초음파센서로 벽이 20cm 거리에 없을때까지 직진 & calibration 
  HM10.write("---Wall Disappears\n");
  distancedDrive(0, 0.6, 1, false, 200);

  //오른쪽 초음파센서로 벽이 20cm 거리에 생길때까지 직진
  distancedDrive(0, 0.6, 1, true, 200);

  //우회전, 후진
  timedDrive(0.4, -0.8, 4, NULL, false);
  timedStop(5);
  timedDrive(0.5, -0.8, 5, NULL, false);
  timedStop(5);

  //좌회전, 후진 :: Timed
  timedDrive(-1, -0.8, 8, NULL, false);
  timedStop(5);

  //전방 초음파센서 센싱 후, 25cm 거리보다 가까우면 후진
  if(gfRightDistance >= 50 && gfRightDistance <= 150 && gfCenterDistance <= 250)
  { 
    HM10.write("---finalize Parking:::too far from wall");
    timedDrive(0, -0.8, 2, NULL, false);
  } 
  else if(gfLeftDistance <= 300) //주차선에서 벗어났을 때
  {
    timedDrive(-0.3, 0.5, 10, NULL, true);
    timedStop(5);
    timedDrive(0.6, -0.5, 2, NULL, true);
    timedStop(5);
    timedDrive(-1, -0.6, 8, NULL, true);
  }

  //정지
  timedStop(10);   


  //탈출로직 
  if(gfRightDistance < 100) //close to right 
  {
    //좌회전, 주차장 탈출 
    timedDrive(-0.8, 0.8, 6, NULL, false);
    //직진
    timedDrive(0, 0.2, 1, NULL, false);
    //우회전, 탈출
    timedDrive(0.5, 0.2, 5, NULL, true);
    //천천히 직진
    timedDrive(0, 0.2, 10, NULL, true);
  }
  else if(gfRightDistance > 150) //far from right
  {
    //좌회전, 주차장 탈출 
    timedDrive(-0.5, 0.8, 3, NULL, false);
    //직진
    timedDrive(0, 0.2, 1, NULL, false);
    //우회전, 탈출
    timedDrive(0.3, 0.2, 2, NULL, true);
    //천천히 직진
    timedDrive(0, 0.2, 10, NULL, true);
  }
  
  else
  {
    //좌회전, 주차장 탈출
    timedDrive(-0.5, 0.8, 6, NULL, false);
  
    //직진
    timedDrive(0, 0.2, 1, NULL, false);
  
    //우회전, 탈출
    timedDrive(0.3, 0.2, 4, NULL, true);
  
    //천천히 직진
    timedDrive(0, 0.2, 10, NULL, true);
  }
  
}
