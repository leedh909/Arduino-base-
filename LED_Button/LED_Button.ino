int sw = 10;
int greenLED = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(sw,INPUT_PULLUP);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw)==LOW){
    digitalWrite(greenLED,HIGH);
  }else{
    digitalWrite(greenLED,LOW);
  }
}
