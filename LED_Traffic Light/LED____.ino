int red = 6;
int yel = 8;
int gre = 11;
int a=0;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(yel,OUTPUT);
  pinMode(gre,OUTPUT);
}

void loop() {
  if(a<5){
    digitalWrite(yel,HIGH);
    delay(3000);
    digitalWrite(red,HIGH);
    if(digitalRead(red)==HIGH){
      digitalWrite(yel,LOW);
      delay(5000);
      digitalWrite(yel,HIGH);
      delay(2000);
      digitalWrite(red,LOW);
      digitalWrite(yel,LOW);
    }
    if(digitalRead(yel)==LOW && digitalRead(red)==LOW){
      digitalWrite(gre,HIGH);
      delay(15000);
      digitalWrite(gre,LOW);
    }
    a++;
  
    
  }
}
