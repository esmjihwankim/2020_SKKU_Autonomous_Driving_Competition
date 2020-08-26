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
 */


void avoidence()
{
  timedStop(10);
  
  //센싱
  sense();
    
  //장애물 15cm 전방에 있을 때
  if(gfCenterDistance <= 200)
  {
    HM10.write("---Object 20cm in front\n");
    //후진
    timedDrive(1, -1, 4, NULL, false);
      
    //좌회전
    timedDrive(-1, 0.6, 5, NULL, false);

    //직진
    timedDrive(0, 0.4, 3, NULL, false);
      
    //우회전
    timedDrive(1, 0.6, 3, NULL, false);

  }
  //장애물 30cm 전방에 있을 때  
  else if(gfCenterDistance <= 300)
  {
    HM10.write("---Object 30cm in front\n");

    //좌회전
    timedDrive(-1, 0.6, 5, NULL, false);   
    //직진
    timedDrive(0, 0.5, 3, NULL, false);
    
  }  
  //장애물 전방에 센싱되지 않음 || 멀리 있음  
  else if(gfCenterDistance > 500)
  {
    HM10.write("---Object Not detected/far away\n");
    timedDrive(-1, 0.6, 4, NULL, false);
    timedDrive(0, 0.6, 2, NULL, false);
  }

  
  //차선에 센서 닿았을 때 
  if(gbLeftIR != detect_ir)
  {
    compute_steering = 1;
    compute_speed = 0.1;
    nextMove();
  } 
  else if(gbRightIR != detect_ir)
  {
    nextMove();
    compute_steering = -1;
    compute_speed = 0.1;
  }
  
}
