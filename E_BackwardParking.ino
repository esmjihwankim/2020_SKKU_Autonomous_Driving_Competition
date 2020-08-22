/* 후진주지
 * Used Functions:
 * void timedStop(int specifiedTime)
 * void timedDrive(int rightLeft, float forwardBack, int specifiedTime, bool enableIR)
 * void distancedDrive(int rightLeft, float forwardBack, int specifiedDistance, bool enableIR)
 * 
 * Remember 
 * forwardBack == 1 -> 100% speed in forward direction
 * specifiedTime == 10 -> 1 second 
 * specifiedDistance == 120 -> 12CM
 */


void backwardParking(){
  
  //정지 1.5 sec 
  timedStop(15);

  //직진
  HM10.write("---Going Forward\n");
  timedDrive(0, 0.5, 10, true, true);

  //우회전 후진
  HM10.write("---Right - back\n");
  timedDrive(1, -0.8, 6, false, false);
  
  //천천히 좌회전
  HM10.write("---Left - Forward\n");
  timedDrive(-1, 1, 6, false, false);
  
  //후진 -- IR센서가 정지선 읽을 때까지
  HM10.write("---Reverse\n");
  timedDrive(0, -1, 10, true, false);
  reverse(false);

  //정지
  timedStop(15);

  //출발
  timedDrive(0, 1, 10, true, false);
  
}
