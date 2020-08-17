
#define SERVO_PIN 9     // 서보모터1 연결핀
#define IR_R A4  //  적외선센서 우측 핀
#define IR_L A3  // 적외선센서 좌측 핀

#define M1_PWM 5   // DC모터1 PWM 핀 왼
#define M1_DIR1 7   // DC모터1 DIR1 핀
#define M1_DIR2 8   // DC모터 1 DIR2 핀

#define M2_PWM 6   // DC모터2 PWM 핀
#define M2_DIR1 11   // DC모터2 DIR1 핀
#define M2_DIR2 12   // DC모터2 DIR2 핀

#define FC_TRIG 13   // 전방 초음파 센서 TRIG 핀
#define FC_ECHO 10  // 전방 초음파 센서 ECHO 핀
#define L_TRIG A2  // 좌측 초음파 센서 TRIG 핀
#define L_ECHO A1  // 좌측 초음파 센서 ECHO 핀
#define R_TRIG A5   // 우측 초음파 센서 TRIG 핀
#define R_ECHO 2  // 우측 초음파 센서 ECHO 핀


void setPin(void) 
{

  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);

  pinMode(FC_TRIG, OUTPUT);
  pinMode(FC_ECHO, INPUT);
  
  pinMode(L_TRIG, OUTPUT);
  pinMode(L_ECHO, INPUT);
  
  pinMode(R_TRIG, OUTPUT);
  pinMode(R_ECHO, INPUT);

  pinMode(M1_PWM, OUTPUT);
  pinMode(M1_DIR1, OUTPUT);
  pinMode(M1_DIR2, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M2_DIR1, OUTPUT);
  pinMode(M2_DIR2, OUTPUT);
  
}
