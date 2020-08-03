int redLED=6;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED,OUTPUT);
  

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED,HIGH);
  delay(100); //1.5초 지속
  digitalWrite(redLED,LOW);
  delay(100);


  
}
