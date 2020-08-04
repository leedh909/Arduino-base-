int buzzerPin =3;

void setup() {
  pinMode(buzzerPin,OUTPUT);

}

void loop() {
  PWM(펄스 폭 진동: 0~255)을 통해서 소리를 낸다.
  ~표시 있는 핀 사용
  analogWrite(buzzerPin,64); //PWM 25% 적용
  delay(1000);  //1초 대기

  analogWrite(buzzerPin,128); //50% 적용
  delay(1000);  //1초 대기

  analogWrite(buzzerPin,256); //100% 적용
  delay(1000);  //1초 대기

}
