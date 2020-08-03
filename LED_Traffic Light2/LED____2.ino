int red = 6;
int yel = 8;
int gre = 11;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(yel,OUTPUT);
  pinMode(gre,OUTPUT);
}

void loop() {
  changeLights();
  delay(15000);
}

void changeLights(){
  //초록색 led off, 파란색 led on
  digitalWrite(gre,LOW);
  digitalWrite(yel,HIGH);
  delay(3000);
  
  //파란색 led off, 빨간색 led on
  digitalWrite(yel,LOW);
  digitalWrite(red,HIGH);
  delay(5000);

  //파란색
  digitalWrite(yel,HIGH);
  delay(2000);

  //파란색, 빨간색 led off
  digitalWrite(yel,LOW);
  digitalWrite(red,LOW);

  //초록색 led on
  digitalWrite(gre,HIGH);
  
}
