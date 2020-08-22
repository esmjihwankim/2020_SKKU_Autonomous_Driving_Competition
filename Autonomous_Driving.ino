/*
 * Autonomous Driving Program 
 * **Developers**
 * QC,TEST/Design /HW/SW : 성균관대학교 바이오메카트로닉스 / 전자전공학부 권호성 (Hosung Kwon, SKKU)
 * Concept Planning, Idea Validation / SW : 성균관대학교 소프트웨어학과 소예림 (Yerim So, SKKU) 
 * SW Architecture / HW : 성균관대학교 바이오메카트로닉스 / 전자전기공학부 김지환 (Jihwan Kim, SKKU) 
 */
#include <MsTimer2.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "_PinLocations.h"
#include "Motor.h"
#include "UltraSonic.h"

SoftwareSerial HM10(BT_TX, BT_RX);
Servo servo;

float gfCenterDistance;
float gfLeftDistance;
float gfRightDistance;

bool gbLeftIR;
bool gbRightIR;

bool bInMission = false;
int iStageNumber = 0;
unsigned int iTimeCount = 0; //timer 시간 :: MsTimer2는 miliseconds 단위 


// 자동차 튜닝 파라미터 =====================================================================
bool detect_ir = true; // 검출선이 흰색 = true, 검정색 = false

float cur_steering = 0;
float cur_speed = 0;
float compute_steering = 0;
float compute_speed = 0;


// Setup & Loop =====================================================================
void setup() {
  Serial.begin(9600);
  HM10.begin(9600);
  servo.attach(SERVO_PIN);  //서보모터 초기화
  setPin();   //  _PinLocations.h 
  
  nextMove();
}


void loop() 
{
  drive();    //Drive 
}
