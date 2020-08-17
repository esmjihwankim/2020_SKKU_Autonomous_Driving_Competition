
/*
 * Receives information from Ultrasound sensor
 */

 #define MAX_DISTANCE 2000; // 초음파 센서의 최대 감지거리

inline float getDistance(int trig, int echo) 
{
  
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW); 
  

  unsigned long duration = pulseIn(echo, HIGH, 5000);
  if(duration == 0)
  {
    delayMicroseconds(200);
    return MAX_DISTANCE;
  }
  else
  {
    delayMicroseconds(200);
    return duration * 0.17;
  }
    
}
