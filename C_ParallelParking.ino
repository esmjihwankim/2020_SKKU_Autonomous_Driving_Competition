/* 평행주차 
 * Uses Functions:
 * void timedStop(int specifiedTime)
 * void timedDrive(int rightLeft, int forwardBack, int specifiedTime, bool enableIR)
 * void park(int rightLeft, int specifiedDistanced, int enableIR)

 * RightLeft: 
 * 
 * 
 * 
 */

void parallelParking()
{   
  //정지
  timedStop(10);
  
  //정지선 지나 1.5초
  timedDrive(0, 1, 10, true);
  timedStop(20);
  
  //우회, 후진
  
  
  //좌회전, 후진 
  
  

  //바퀴 왼쪽, 탈출
 
 
}
