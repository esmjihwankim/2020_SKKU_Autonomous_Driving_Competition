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


void backwardParking()
{
  
  //정지 1.0 sec 
  timedStop(10);
  
  HM10.write("---Going Forward\n"); 
  //초음파센서 리딩 무시하고 직진
  timedDrive(0, 1, 3, NULL, true); 
  //전방 초음파센서 리딩 후 직진
  distancedDrive(0, 0.6, 200, 0); //310
  timedStop(10);
  
  //천천히 좌회전
  HM10.write("---Left - Forward\n");
  timedDrive(-0.4, 1, 10, NULL, false);
  delay(100);

  //후진 -- IR센서가 정지선 읽을 때까지
  HM10.write("---Reverse\n");
  timedDrive(0,-0.8, 10, NULL, true);
  reverse(false, NULL);

  //정지
  timedStop(10);

  //출발
  timedDrive(0, 1, 3, NULL, false);
  
}
