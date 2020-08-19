
//평행주차 
inline void parallelParking()
{   
  //정지
  setTimer();
  while(iTimeCount < 15) { //stop for less than 1 second
    compute_steering = 0;
    compute_speed = 0;
    nextMove();
  }
  stopTimer();
  
  
  //정지선 지나 1.5초
  setTimer(); 
  while(iTimeCount < 20){
    compute_steering = 0;
    
    if(gbLeftIR != detect_ir)
    {
      compute_steering = 1;
    }
    else if(gbRightIR != detect_ir)
    {
      compute_steering = -1;
    }
    
    compute_speed = 1;
    nextMove();
  }
  stopTimer();
  
  //정지
  
  

  //바퀴 오른쪽, 후진
 

  
  //바퀴 왼쪽, 후진 
  
  

  //바퀴 왼쪽, 탈출
 
 
}
