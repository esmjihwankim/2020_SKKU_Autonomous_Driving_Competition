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


void backwardParking(){
  
  //정지 1.0 sec 
  timedStop(10);

  //직진 //gfCenterDistance
  HM10.write("---Going Forward\n"); 
  distancedDrive(0, 0.5, 70, 0);

  //우회전 후진
  HM10.write("---Right - back\n");
  timedDrive(1, -0.8, 6, NULL, false);
  
  //천천히 좌회전
  HM10.write("---Left - Forward\n");
  distancedDrive(-1, 0.5, 100, 1);
  
  //후진 -- IR센서가 정지선 읽을 때까지
  HM10.write("---Reverse\n");
  reverse(true, 1);

  //정지
  timedStop(10);

  //출발
  timedDrive(0, 1, 10, 1, false);
  
}
