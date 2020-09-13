/* 후진주지
 * Used Functions:
void timedStop(int specifiedTime)
inline void timedDrive(int rightLeft, float forwardBack, int specifiedTime, int ultrasonicSensor, bool senseLine)
void distancedDrive(int rightLeft, float forwardBack, int ultrasonicValue, int specifiedDistance)
void reverse(bool bWillSenseIR, int ultrasonicSensor)
 * 
 * Remember 
 * forwardBack == 1 -> 100% speed in forward direction
 * specifiedTime == 10 -> 1 second 
 * specifiedDistance == 120 -> 12CM
 */


void backwardParking(float timeDifference)
{

  int state = 0;
  
  //정지 1.0 sec 
  timedStop(10);
  //정지선 평형 보정
  correctStoplineDirection(timeDifference, 0.3, 2);
  
  HM10.write("---Going Forward\n"); delayMicroseconds(20);
  //초음파센서 리딩 무시하고 직진
  timedDrive(0, 0.2, 1, NULL, true, NULL); 
  //전방 초음파센서 리딩 후 직진 - 시험주행 때 distance 값 ::: 310시험주행 때 distance 값 ::: 310
  distancedDrive(0.2, 0.2, 0, true, 110); 
  timedStop(10);


  /* 앞에 장애물 없을 때까지 우회전-후진 + 좌회전-전진 */
  while(gfCenterDistance < 200)
  {
    //우회전, 후진
    HM10.write("--Right - Back\n");
    timedDrive(0.2, -0.3, 2, NULL, false, NULL);
    timedStop(5);

    //뒤로 뺀 후 전방센서 거리가 지나치게 크면 -> 진입시 왼쪽벽과 충돌가능   
    if(gfCenterDistance > 230)
    {
      state = 1;
      break;
    }
 
    //좌회전, 전진
    HM10.write("---Left - Forward\n");
    timedDrive(-0.3, 0.3, 2, NULL, false, NULL);
    timedStop(5);

    HM10.write("gfCenterDistance::"); delayMicroseconds(25); HM10.println(gfCenterDistance); delayMicroseconds(25);
    HM10.write("gfLeftDistance::"); delayMicroseconds(25); HM10.println(gfLeftDistance); delayMicroseconds(25);
    HM10.write("gfRightDistance::"); delayMicroseconds(25); HM10.println(gfRightDistance); delayMicroseconds(25);  
  } //loop end : Cannot be detected as sensing angle not perpendicular


  /* 후진 전 좌회전 마무리 + 도로에서 정렬 맞추기 */
  //전진 후 전방센서와 벽이 20cm 이상일 때 
  if(state == 0) 
  {
    HM10.write("\n--state 0::\n\n"); delayMicroseconds(25); 
    timedDrive(0, -0.1, 1, NULL, false, NULL);
    timedDrive(-0.3, 0.1, 15, NULL, true, NULL);
  }
  //뒤로 뺀 후 전방센서와 벽이 23cm 이상일때 
  else if(state == 1)  
  {
    HM10.write("\n--state 1::\n\n"); delayMicroseconds(25);
    timedDrive(0, 0.1, 1, NULL, false, NULL); 
    timedDrive(-0.3, 0.1, 12, NULL, true, NULL);
  }

  timedDrive(0, 0.1, 2, 1, true, 90); 
  timedStop(5);
  
  //후진 -- IR센서가 정지선 읽을 때까지
  if(gfRightDistance > 120)
  {
    HM10.write("---Set Direction:::gfRight > 120\n"); delayMicroseconds(25); 
    timedDrive(0.2, -0.4, 3, NULL, false, NULL); 
    timedDrive(-0.1, -0.4, 1, NULL, false, NULL);
    timedStop(5);
  }
  else if(gfRightDistance > 110)
  {
    HM10.write("---Set Direction:::gfRight > 110\n"); delayMicroseconds(25); 
    timedDrive(0.2, -0.4, 2, NULL, false, NULL);
    timedDrive(-0.1, -0.4, 1, 1, false, 90);
  }
  
  else if(gfRightDistance > 100)
  {
    HM10.write("---Set Direction:::gfRight > 100\n"); delayMicroseconds(25);
    timedDrive(0.2, -0.4, 1, NULL, false, NULL);
    timedDrive(-0.1, -0.4, 4, 1, false, 90);
    timedStop(5);
  }
  else if(gfRightDistance < 90)
  {
    HM10.write("---Set Direction:::gfRight < 90\n"); delayMicroseconds(25); 
    timedDrive(0.1, -0.4, 2, NULL, false, NULL);
    timedDrive(0, -0.4, 2, 1, false, 90);
    timedStop(5);
  }
  else 
  {
    HM10.write("---Set Direction:::already in appropriate position\n"); delayMicroseconds(25);
    timedDrive(0.1, -0.4, 3, NULL, false, NULL);
    timedDrive(0, -0.4, 2, 1, false, 90);
    timedStop(5);
  }
  
  
  HM10.write("---Ignore Sensor reading and Reverse\n"); delayMicroseconds(25); 
  timedDrive(0, -0.4, 10, 1, false, 90);
  HM10.write("---Reverse\n"); delayMicroseconds(25); 
  reverse(false, 1);

  //정지
  timedStop(10);

  //탈출
  if(gfRightDistance > 120) 
  {
    timedDrive(0.3, 0.1, 1, NULL, false, NULL);
    timedDrive(0.1, 0.1, 2, NULL, true, NULL);
  }

  else if(gfRightDistance > 100)
  {
    timedDrive(0.2, 0.1, 2, NULL, false, NULL);
    timedDrive(0.1, 0.1, 2, NULL, true, NULL);
  }
  
  else if(gfRightDistance < 50)
  {
    timedDrive(-0.1, 0.1, 1, NULL, false, NULL);
    timedDrive(-0.1, 0.1, 2, NULL, true, NULL);
  }
  else
  {
    timedDrive(0, 0.1, 1, NULL, false, NULL);
    timedDrive(0, 0.1, 2, NULL, true, NULL);
  }
  
  timedDrive(0, 0.3, 9, 1, true, 50); 
  
}
