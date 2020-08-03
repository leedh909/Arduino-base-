int red = 3;
int green = 12;
int button = 9;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button)==LOW){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }else{
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
  }


}
