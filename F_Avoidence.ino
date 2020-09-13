/*
 * 회피주행 
 * 
 *    Used Variables:
 *    float gfCenterDistance;
      float gfLeftDistance;
      float gfRightDistance;  
 *    
 *    bool gbLeftIR;
      bool gbRightIR;   

      compute_speed 
      compute_steering

      void distancedDrive(float rightLeft, float forwardBack, int sensorPosition, bool untilCloser, int specifiedDistance)
      void timedDrive(float rightLeft, float forwardBack, int specifiedTime, int sensorPosition, bool senseLine, int caliConstant)

 */


void avoidence()
{
  finalStage = true;
  
  timedStop(10);
    
  //전방 20cm 장애물 나타날때까지 전진 
  distancedDrive(0, 0.4, 0, true, 230);

  //좌회전
  timedDrive(-0.6, 0.4, 6, NULL, true, NULL);

  //직진
  timedDrive(0, 0.4, 5, NULL, true, NULL);

  //보정
  timedDrive(0.3, 0.4, 3, NULL, true, NULL);

  //towards turning line
  timedDrive(-0.1, 0.1, 2, NULL, true, NULL); 

}
