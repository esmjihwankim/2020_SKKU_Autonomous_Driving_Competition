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

  bool finishedMission = false;

  //임무 수행시까지 센싱을 통해 장애물 회피
  while(finishedMission != true)
  {
    //센싱
    sense();

    compute_steering = 0;
    compute_speed = 1;
    
    //장애물 20cm 전방에 있을 때
    if(gfCenterDistance <= 300)
    {
      //후진
      timedDrive(0, -1, 5, true, false);
      //좌회전
      timedDrive(-1, 0.6, 5, true, false);
      //우회전
      timedDrive(1, 0.6, 3, true, false);
      
      
    }
    //장애물 30cm 전방에 있을 때 좌회전 
    else if(gfCenterDistance <= 400)
    {
      timedDrive(-1, 0.6, 10, true, false);   
      timedDrive(0, 0.5, 5, true, 0);
    }


    //차선에 센서 닿았을 때 
    if(gbLeftIR != detect_ir)
    {
      compute_steering = 1;
      compute_speed = compute_speed * 0.4;
      finishedMission = true;
    } 
    else if(gbRightIR != detect_ir)
    {
      compute_steering = -1;
      compute_speed = compute_speed * 0.4;
    }

    nextMove();
  }
}
