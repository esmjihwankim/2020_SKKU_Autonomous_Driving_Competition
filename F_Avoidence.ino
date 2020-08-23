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
  timedStop(15);
  
  //센싱
  sense();

  compute_steering = 0;
  compute_speed = 0.4;
    
  //장애물 15cm 전방에 있을 때
  if(gfCenterDistance <= 150)
  {
    HM10.write("---Object 15cm in front\n");
    //후진
    timedDrive(0, -1, 2, true, false);
      
    //좌회전
    while(gfCenterDistance <= 200)
    {
      sense();
      timedDrive(-1, 0.6, 3, true, false);
    }
    timedDrive(-0.5, 0.6, 2, true, false);

    //직진
    timedDrive(0, 0.4, 3, true, 0);
      
    //우회전
    timedDrive(1, 0.6, 3, true, false);

  }
    
  //장애물 30cm 전방에 있을 때  
  else if(gfCenterDistance <= 300)
  {
    HM10.write("---Object 30cm in front\n");

    //좌회전
    while(gfCenterDistance <= 300)
    {
       timedDrive(-1, 0.6, 1, true, false);
    }
    timedDrive(-1, 0.6, 2, true, false);   
    //직진
    timedDrive(0, 0.5, 3, true, 0);

    //우회전 - 방향잡기
    timedDrive(1, 0.5, 3, true, 0);
    
  }
  
  //장애물 전방에 센싱되지 않음 || 멀리 있음  
  else if(gfCenterDistance > 500)
  {
    HM10.write("---Object Not detected / far away\n");
    timedDrive(-1, 0.6, 4, true, false);
    timedDrive(0, 0.6, 2, true, false);
    timedDrive(1, 0.6, 2, true, false);
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
