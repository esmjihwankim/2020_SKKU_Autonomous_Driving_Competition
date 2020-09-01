/*
 * Abstraction 2
 * Helps the vehicle to place itself on the road straight
 */

inline void lineSensed()
{
  //오른쪽 차선 검출   
  if(gbRightIR != detect_ir) 
  {
    giRightIRCnt = giRightIRCnt + 0.02; 
    compute_steering = -giRightIRCnt;
    compute_speed = 0.1;
  }
  //왼쪽 차선 검출
  else if(gbLeftIR != detect_ir)
  {
    giLeftIRCnt = giLeftIRCnt + 0.02;
    compute_steering = giLeftIRCnt;
    compute_speed = 0.1;
  }
  else if(gbRightIR == detect_ir && gbLeftIR == detect_ir)
  {
    giLeftIRCnt = 0;
    giRightIRCnt = 0; 
  }
  
}


//차량이 회전할 때 센싱을 통해 벽과 거리를 유지하게 함.
inline void sensedTurn(int rightLeft, int specifiedTime)
{
  
}



//차가 도로상에서 기울어있는지 확인하는 함수 
inline int checkPositionOnRoad(int iaPosition[30])
{
  //how much the vehicle is tilted on the road 

  
}
