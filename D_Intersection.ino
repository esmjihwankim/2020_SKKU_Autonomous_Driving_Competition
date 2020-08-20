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


void intersection(){
  timedStop(15);
  timedDrive(0, 0.5, 3, false);
  timedDrive(0, 1, 5, true);
}
