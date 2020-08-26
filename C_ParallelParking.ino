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

  //벽 등장할때까지 직진 
  distancedDrive(0, 1, 200, -1);
  
  

  //왼쪽 초음파센서로 거리 유지하며 2.5s 주행
  HM10.write("---timedDrive straight for 1.2s\n");
  timedDrive(0, 0.5, 25, -1, false);

  //우회전, 후진
  timedDrive(0.5, -0.8, 10, NULL, false);

  //좌회전, 후진 :: 오른쪽 센서가 10cm 이하의 값을 읽을때까지
  distancedDrive(-1, -0.5, 100, 1);

  //정지
  timedStop(10); 
  
  //좌회전, 주차장 탈출
  timedDrive(-0.5, 0.4, 6, NULL, false);

  //우회전, 탈출
  timedDrive(0.5, 0.4, 3, NULL, true);

}
