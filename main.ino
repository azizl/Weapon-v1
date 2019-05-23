//Project by Ashfaque Khan and Aziz Lokhandwala
//Code by Aziz Lokhandwala
//Here output are servo and led both but I am still figuring out to get exact location of target so that servo could point out to target direction

#include <Servo.h>
Servo myservo;

char val;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
if(Serial.available()){
    val = Serial.read();
}
if(val=='1'){
  digitalWrite(ledPin,HIGH);
  val = map(val, 0, 1023,0,180);
  myservo.write(val);
}
else{
  digitalWrite(ledPin,LOW);
   val = map(val, 0, 1023,180,0);
  myservo.write(val);
}
delay(20);
}
