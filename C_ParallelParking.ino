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

void parallelParking()
{   
  //정지 1초
  timedStop(10);

  //센싱 없이 0.3s 주행 
  timedDrive(0, 1, 5, NULL, true);

  //왼쪽 초음파센서로 거리 유지하며 1s 주행
  timedDrive(0, 0.4, 12, -1, false);

  //우회전, 후진
  timedDrive(1, -0.8, 10, NULL, false);

  //좌회전, 후진 :: 오른쪽 센서가 15cm 이하의 값을 읽을때까지
  distancedDrive(-1, -1, 150, 1);

  //정지
  timedStop(10); 
  
  //좌회전, 주차장 탈출
  timedDrive(-1, 0.4, 6, NULL, false);

  //우회전, 탈출
  timedDrive(1, 0.4, 3, NULL, true);

}
