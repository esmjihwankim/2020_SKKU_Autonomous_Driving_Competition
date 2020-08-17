
/*
 * Controls Servo and DC Motor 
 */

// 앞바퀴 조향
inline void setSteering(Servo servo, float* cur_Steering, float* nxt_Steering) 
{
  int angle_offset = 90; // 서보 모터 중앙각 오프셋 (단위: 도) 마이너스 값에서 바퀴가 왼쪽으로 정렬되고 플러스 값에서 오른쪽으로 정렬됨
  int angle_limit = 150; // 서보 모터 회전 제한 각 (단위: 도)
  
  *cur_Steering = constrain(*nxt_Steering, -1, 1);    // constrain -1 ~ 1 값으로 제한
                                                     // -1 : 왼쪽  1 : 오른쪽 
          
  float angle = *cur_Steering * angle_limit;                           
  int desiredServoAngle = angle + 90;
  desiredServoAngle = constrain(desiredServoAngle, 30, 150);
  servo.write(desiredServoAngle);

}


// 뒷바퀴 모터회전
inline void setDCSpeed(float* curSpeed, float* nxtSpeed)
{
  //튜닝 파라미터 
  float max_pwm = 130;
  float min_pwm = 70;

  int punch_pwm = 200; // 정지 마찰력 극복 출력 (0 ~ 255)
  int punch_time = 50; // 정지 마찰력 극복 시간 (단위 msec)
  int stop_time = 300; // 전진후진 전환 시간 (단위 msec)
  
  *nxtSpeed = constrain(*nxtSpeed, -1, 1);

  //움직이는 중 반대방향으로 가야하거나 움직이다가 정지해야 한다면 정지
  if( (*curSpeed * *nxtSpeed < 0) || (*curSpeed != 0 && *nxtSpeed == 0) )  
  {
    *curSpeed = 0;
    digitalWrite(M1_PWM, 0);
    digitalWrite(M1_DIR1, LOW);
    digitalWrite(M1_DIR2, LOW);

    digitalWrite(M2_PWM, 0);
    digitalWrite(M2_DIR1, LOW);
    digitalWrite(M2_DIR2, LOW);

    delay(stop_time);
  }


  //정지상태에서 i) 전진 ii) 후진
  if(*curSpeed == 0 && *nxtSpeed !=0)
  {
    //전진 
    if(*nxtSpeed > 0)
    {
      digitalWrite(M1_PWM, punch_pwm);
      digitalWrite(M1_DIR1, HIGH);
      digitalWrite(M1_DIR2, LOW);

      digitalWrite(M2_PWM, punch_pwm);
      digitalWrite(M2_DIR1, HIGH);
      digitalWrite(M2_DIR2, LOW);
    }

    //후진
    else if(*nxtSpeed < 0)
    {
      digitalWrite(M1_PWM, punch_pwm);
      digitalWrite(M1_DIR1, LOW);
      digitalWrite(M1_DIR2, HIGH);

      digitalWrite(M2_PWM, punch_pwm);
      digitalWrite(M2_DIR1, LOW);
      digitalWrite(M2_DIR2, HIGH);
    }
    
    delay(punch_time);
  }

  //주행상태에서 i)전진 ii)후진 
  if(*nxtSpeed != 0)
  {
    int pwm = abs(*nxtSpeed) * (max_pwm - min_pwm) + min_pwm;  // 0 ~ 255로 변환

    //전진
    if(*nxtSpeed > 0)
    {
      analogWrite(M1_PWM, pwm);
      digitalWrite(M1_DIR1, HIGH);
      digitalWrite(M1_DIR2, LOW);

      analogWrite(M2_PWM, pwm);
      digitalWrite(M2_DIR1, HIGH);
      digitalWrite(M2_DIR2, LOW);
    }
    
    //후진
    if(*nxtSpeed < 0)
    {
      analogWrite(M1_PWM, pwm);
      digitalWrite(M1_DIR1, LOW);
      digitalWrite(M1_DIR2, HIGH);

      analogWrite(M2_PWM, pwm);
      digitalWrite(M2_DIR1, LOW);
      digitalWrite(M2_DIR2, HIGH);
    }

  }


  *curSpeed = *nxtSpeed;
  Serial.println("#300");
}
