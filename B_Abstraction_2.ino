/*
 * Abstraction 2
 * Helps the vehicle to place itself on the road without 
 * 
 */


//정지선에서 앞으로 이동할 때 정지선을 밟은 시간차를 이용해 도로 위에서 차의 정렬을 맞춤



//차량이 회전할 때 센싱을 통해 벽과 거리를 유지하게 함.
inline void sensedTurn(int rightLeft, int specifiedTime)
{
  setTimer(); //지속적인 센싱, 타이밍 ISR

  if(gfLeftDistance < 30) 
  {
    compute_steering = 0.3;
  }
  else if(gfLeftDistance < 40)
  {
    
  }
  else if(gfLeftDistance < 50)
  {
    
  }

  stopTimer();  
}



//차가 도로상에서 기울어있는지 확인하는 함수 
inline int checkPositionOnRoad(int iaPosition[30])
{
  //how much the vehicle is tilted on the road 

  
}
