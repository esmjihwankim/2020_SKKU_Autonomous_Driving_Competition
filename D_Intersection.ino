/* 교차로
 *  
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


void intersection(bool willSenseLine)
{
  timedStop(10);
  timedDrive(0, 0.4, 1, NULL, willSenseLine);
  timedDrive(0, 0.4, 10, NULL, true);
}
