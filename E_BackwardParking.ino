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

  //stop for 1.5 sec 
  timedStop(15);
  
  //천천히 좌회전
  timedDrive(-1, 0.6, 10, false);

  //직진 
  timedDrive(0, 1, 5, true);
  
  //후진 -- IR센서가 정지선 읽을 때까지
  reverseParking();

  //정지
  timedStop(15);

  //출발
  timedDrive(0, 1, 10, true);
}
