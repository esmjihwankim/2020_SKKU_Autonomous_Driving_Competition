/* 평행주차 
 * Used Functions:
 * void timedStop(int specifiedTime)
 * void timedDrive(int rightLeft, float forwardBack, int specifiedTime, bool enableIR)
 * void distancedDrive(int rightLeft, float forwardBack, int specifiedDistance)
 * 
 * Remember 
 * forwardBack == 1 -> 100% speed in forward direction
 * specifiedTime == 10 -> 1 second 
 * specifiedDistance == 120 -> 12CM
 */

void parallelParking()
{   
  //정지 1초
  timedStop(10);

  //왼쪽으로 꺾어 라인에 붙어 라인을 센싱할 때까지 직진
  timedDrive(-1, 0.4, 2, true, false);
  timedDrive(0, 1, 12, true, false);

  //**예외상황
  //차가 주차공간의 벽면에 가까워 있다면 다른 경로로 주차
  sense();
  if(gfCenterDistance < 200 && gfRightDistance < 300)
  {
    //우회전, 후진
    timedDrive(1, -0.8, 5, false, false);

    //좌회전, 후진
    distancedDrive(-1, -1, 180);

    //후진
    timedDrive(0, -0.8, 3, false, false);

  } 
  else
  {
    //우회전, 후진
    timedDrive(1, -0.8, 10, false, false);
  
    //좌회전, 후진 
    distancedDrive(-1, -1, 180);
  }

  //정지
  timedStop(10); 
  
  //좌회전, 주차장 탈출
  timedDrive(-1, 0.4, 6, true, false);

  //우회전, 탈출
  timedDrive(1, 0.4, 3, true, false);

}
