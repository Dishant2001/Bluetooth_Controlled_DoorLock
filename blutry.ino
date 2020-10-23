#include<SoftwareSerial.h>
#include<Servo.h>
Servo door;
int a=-1;
SoftwareSerial blu(3, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blu.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,INPUT);
  door.attach(9);
  door.write(60);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  digitalWrite(11,LOW);
  if (blu.available())
  { 
    digitalWrite(5,LOW);
  digitalWrite(11,LOW);
    char data=blu.read();
    Serial.println(data);
     if(data=='o')
     {
       Serial.println("DOOR OPENED");
       a=1;
       digitalWrite(12,HIGH);
     }
     else if(data=='c')
     {
       Serial.println("DOOR CLOSED");
       a=0;
       digitalWrite(12,LOW);
     }
  }
  Serial.println(a);
  if(digitalRead(7)==HIGH or a==1)
  {
    door.write(180);
    delay(3000);
  }
  else if(digitalRead(7)!=HIGH or a==0)
  {
    door.write(60);
  }
}
