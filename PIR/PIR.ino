const int PIRPin = 2;
const int ledPin = 13;


void setup() {
  pinMode(PIRPin,INPUT);
  pinMode(ledPin,OUTPUT);
  
  Serial.begin(9600);

  
}

void loop() {
  int value1 = digitalRead(PIRPin);
  Serial.println(value1);

  if(value1==HIGH){
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
  }else{
    digitalWrite(ledPin,LOW);
  }

}
