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

  //왼쪽으로 꺾어 선에 붙은 후 벽면 모서리 센싱할 때까지 직진
  timedDrive(-1, 0.4, 2, true, false);
  timedDrive(0, 1, 10, true, false);

  //우회전, 후진
  timedDrive(1, -0.8, 10, false, false);
  
  //좌회전, 후진 
  distancedDrive(-1, -1, 180);

  //정지
  timedStop(10);

  //좌회전, 주차장 탈출
  timedDrive(-1, 0.4, 6, true, false);

  //우회전, 탈출
  timedDrive(1, 0.4, 3, true, false);

}
