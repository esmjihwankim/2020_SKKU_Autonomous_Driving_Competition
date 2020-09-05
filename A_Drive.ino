
inline void drive()
{
  compute_steering = cur_steering;
  compute_speed = cur_speed; 

  //모든 센서 센싱
  sense();

  //전방 물체 10cm 이내 거리에 있을 시 정지 
  if(gfCenterDistance <= 100) 
  {
    compute_steering = 0;
    compute_speed = 0;  
  }

  //양쪽 차선 모두 검출되지 않음
  else if(gbRightIR == detect_ir && gbLeftIR == detect_ir)
  {
    giRightIRCnt = 0; giLeftIRCnt = 0; giIRDifference = 0;
    compute_steering = 0;
    compute_speed = 1; 
    
    if(finalStage == true) compute_speed = 0.1;
  }
  
  //양쪽 차선 모두 검출
  else if (gbRightIR != detect_ir && gbLeftIR != detect_ir)
  {
    compute_steering = 0;
    compute_speed = 0;
    
    if(abs(giRightIRCnt) > abs(giLeftIRCnt)) //오른쪽이 먼저 들어갔을 때 시간차와 이에 따른 조향 계산
      giIRDifference = -1 * (giRightIRCnt - giLeftIRCnt) / 2.0;
    else //왼쪽이 먼저 들어갔을때 
      giIRDifference = (giLeftIRCnt - giRightIRCnt) / 2.0;
    
    Serial.print("giIRDifference:::");
    Serial.println(giIRDifference);
    HM10.write("giIRDifference:::");
    HM10.print(giIRDifference);
    HM10.write("\n");
    delay(5);
    
    //Course Mission
    HM10.write("***Increasing Stage Number\n");
    iStageNumber++;
    proceedMission(giIRDifference);   //Course.ino
  }

  //차선검출
  else if(gbRightIR != detect_ir) 
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

  nextMove(); 
  Serial.print(giRightIRCnt);
  Serial.println();
}


//센서 감지
inline void sense()
{
  //실시간 적외선센서 인식
  gbLeftIR = digitalRead(IR_L);
  gbRightIR = digitalRead(IR_R);
  
  //실시간 초음파센서 인식 
  gfCenterDistance = getDistance(FC_TRIG, FC_ECHO);
  gfLeftDistance = getDistance(L_TRIG, L_ECHO);
  gfRightDistance = getDistance(R_TRIG, R_ECHO);

  //미션 중 로그 프린트
  if(bInMission == true)
  {
    iTimeCount++;
    Serial.println(iTimeCount);
    Serial.print("Center Distance  ");
    Serial.println(gfCenterDistance);
    Serial.print("Left Distance  ");
    Serial.println(gfLeftDistance);
    Serial.print("Right Distance  ");
    Serial.println(gfRightDistance);
  }
}


//자동차 다음 동작 추상화 함수 
inline void nextMove() 
{
  setDCSpeed(&cur_speed, &compute_speed);
  setSteering(servo, &cur_steering, &compute_steering);  
}
