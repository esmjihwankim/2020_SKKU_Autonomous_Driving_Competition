/* 교차로
 *  
 * Used Functions:
 * void timedStop(int specifiedTime)
 * void timedDrive(int rightLeft, float forwardBack, int specifiedTime, bool enableIR)
 * void park(int rightLeft, float forwardBack, int specifiedDistance, bool enableIR)
 * 
 * Remember 
 * forwardBack == 1 -> 100% speed in forward direction
 * specifiedTime == 10 -> 1 second 
 * specifiedDistance == 120 -> 12CM
 */


void intersection(bool recognizeLine){
  timedStop(15);
  timedDrive(0, 0.4, 2, recognizeLine, false);
  timedDrive(0, 0.4, 5, true, false);
}
