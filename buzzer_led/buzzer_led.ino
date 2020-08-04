const int buzzerPin = 3;
const int LED_R = 12;
const int LED_G = 13;

//const : 상수
const int c=261, d=294, e=329, f=349, g=391;
const int gS=415,a=440,aS=455,b=466,cH=523;
const int cSH=554,dH=587,dSH=622,eH=659,fH=698;
const int fSH=740,gH=784,gSH=830,aH=880;
//부저에서 PWM50% 대역에서 사용할 주파수 설정(31~65535HZ)

// LED 번갈아 켜기 위한 변수
int counter = 0;

void setup() {
 pinMode(buzzerPin,OUTPUT);
 pinMode(LED_R, OUTPUT);
 pinMode(LED_G, OUTPUT);

}

void loop() {
  firstSection();
  secondSection();

  beep(f,250);
  beep(gS,500);
  beep(f,350);
  beep(a,125);
  beep(cH,500);
  beep(a,375);
  beep(cH,125);
  beep(eH,650);
  delay(500);

  secondSection();

  beep(f,250);
  beep(gS,500);
  beep(f,375);
  beep(cH,125);
  beep(a,500);
  beep(f,375);
  beep(cH,125);
  beep(a,650);
  delay(1000);


}
void beep(int note, int duration){
  
  //부저로 소리를 재생하는 함수
  tone(buzzerPin,note,duration);

  //led
  if(counter % 2 ==0){
    digitalWrite(LED_R,HIGH);
    delay(duration);
    digitalWrite(LED_R,LOW);
  }else{
    digitalWrite(LED_G,HIGH);
    delay(duration);
    digitalWrite(LED_G,LOW);
  }

  noTone(buzzerPin);
  delay(50);
  counter++;
}

void firstSection(){
  beep(a,500);
  beep(a,500);
  beep(a,500);
  beep(f,350);
  beep(cH,150);
  beep(a,500);
  beep(f,350);
  beep(cH,150);
  beep(a,650);

  delay(500);

  beep(eH,500);
  beep(eH,500);
  beep(eH,500);
  beep(fH,350);
  beep(cH,150);
  beep(gS,500);
  beep(f,350);
  beep(cH,150);
  beep(a,650);

  delay(500);
}

void secondSection(){
  beep(aH,500);
  beep(a,300);
  beep(a,150);
  beep(aH,500);
  beep(gSH,325);
  beep(gH,175);
  beep(fSH,125);
  beep(fH,125);
  beep(fSH,250);
  delay(325);

  beep(aS,250);
  beep(dSH,500);
  beep(dH,325);
  beep(cSH,175);
  beep(b,125);
  beep(cH,250);
  delay(350);
}
