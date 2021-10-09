#include <Servo.h>
const int echo = 8;
const int trigger = 7;
const int servo = 9;

int distance;
long duration;
int pos;

Servo myservo;
void setup() 
{

pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(trigger,OUTPUT);
myservo.attach(servo);
myservo.write(0);
Serial.begin(9600);
}
void Sanitizer(){
  Serial.print("Servo is moving");
  for (int i=0;i<4;i++)
  {
   Serial.print("...");
   }
 myservo.write(45);
  delay(100);
 myservo.write(90);
  delay(100);
 myservo.write(135);
  delay(100);
 myservo.write(120); //Adjust how far you want the servo to go.
  delay(1000);
 myservo.write(00);
  delay(3000);
}
void loop() 
{
//Distance calculation
digitalWrite(trigger,LOW);
delay(500);

digitalWrite(trigger,HIGH);
delay(100);
digitalWrite(trigger,LOW);

duration = pulseIn(echo, HIGH);

distance = duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

//Servo job 
//cm
if(distance<1)
{ 
  Sanitizer();
}
}