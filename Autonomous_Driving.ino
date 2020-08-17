/*
 * Autonomous Driving Program 
 * **Developers**
 * QC,TEST/Design /HW/SW : 성균관대학교 바이오메카트로닉스 / 전자전공학부 권호성 (Hosung Kwon, SKKU)
 * Concept Planning, Idea Validation / SW : 성균관대학교 소프트웨어학과 소예림 (Yerim So, SKKU) 
 * SW Architecture / HW : 성균관대학교 바이오메카트로닉스 / 전자전기공학부 김지환 (Jihwan Kim, SKKU) 
 */

#include <Servo.h>
#include "_PinLocations.h"
#include "Motor.h"
#include "UltraSonic.h"

Servo servo;

float gfCenterDistance;
float gfLeftDistance;
float gfRightDistance;

//int state = 0;


// 자동차 튜닝 파라미터 =====================================================================
boolean detect_ir = true; // 검출선이 흰색 = true, 검정색 = false

float cur_steering;
float cur_speed;
float compute_steering;
float compute_speed;


// Setup & Loop =====================================================================
void setup() {
  Serial.begin(115200);
  servo.attach(SERVO_PIN);  //서보모터 초기화
  setPin();   //  _PinLocations.h 
 
  cur_steering = 0;
  compute_steering = 0;

  cur_speed = 0;
  compute_speed = 0;
  
  setDCSpeed(&cur_speed, &compute_speed);
  setSteering(servo, &cur_steering, &compute_steering);   //(servo, cur, nxt)
}


void loop() 
{

  compute_steering = cur_steering;
  compute_speed = cur_speed; 

  gfCenterDistance = getDistance(FC_TRIG, FC_ECHO);
  gfLeftDistance = getDistance(L_TRIG, L_ECHO);
  gfRightDistance = getDistance(R_TRIG, R_ECHO);
  
  //전방 물체 15cm 이내 거리에 있을 시 정지 
  if(gfCenterDistance <= 150) {
    compute_steering = 0;
    compute_speed = 0;  
  }


  //양쪽 차선 모두 검출되지 않음
  else if(digitalRead(IR_R) == detect_ir && digitalRead(IR_L) == detect_ir) {
    compute_steering = 0;
    compute_speed = 1; 
  }

  //오른쪽 차선 검
  else if(digitalRead(IR_R) != detect_ir) {
    compute_steering = -1;
    compute_speed = 0.1;
  }

  //왼쪽 차선 검출
  else if(digitalRead(IR_L) != detect_ir) {
    compute_steering = 1;
    compute_speed = 0.1;
  }

  setSteering(servo, &cur_steering, &compute_steering);
  setDCSpeed(&cur_speed, &compute_speed);

}
