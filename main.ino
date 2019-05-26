//Project by Ashfaque Khan and Aziz Lokhandwala
//Code by Aziz Lokhandwala
//Here output are servo and led both but I am still figuring out to get exact location of target so that servo could point out to target direction

//Here myservo is the angle setting servo for gun view an myservo1 is the trigger servo for actuatijng the trigger.

#include <Servo.h>
Servo myservo;
int i = Serial.read(); 
char val;
int ledPin = 13;
Servo myservo1;
int loc =0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
  myservo1.attach(10);
  
}

void loop() {
if(Serial.available()){
    val = Serial.read();
 }
if(val=='1'){
  digitalWrite(ledPin,HIGH);
  i = map(i, 0, 1023,0,180);
  myservo.write(i);
  for(loc = 0; loc<=180;loc++){
    myservo1.write(loc);
   }
 }
 
else{
  digitalWrite(ledPin,LOW);
   i = map(i, 0, 1023,180,0);
  myservo.write(i);
  for(loc = 180; loc>=0;loc++){
    myservo1.write(loc);
    }
}
delay(20);
}
