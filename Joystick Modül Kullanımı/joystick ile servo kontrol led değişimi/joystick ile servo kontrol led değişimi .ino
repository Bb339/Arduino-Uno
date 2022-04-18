#include <Servo.h>

Servo motor;

int xPin = A0;
int yPin = A1;
int butonPin = 2;

int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11; 

int xEkseni;
int yEkseni;
int buton;

void setup()
{
  motor.attach(3);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(butonPin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  xEkseni = analogRead(xPin);
  
  yEkseni = analogRead(yPin);
 
  buton = digitalRead(butonPin);
  

  Serial.print("Buton:");
  Serial.print(buton);
  Serial.print("  X:");
  Serial.print(xEkseni);
  Serial.print("  Y:");
  Serial.println(yEkseni);
  
 
  if(xEkseni == 0)
  {
    digitalWrite(led1, HIGH);
      motor.write(xEkseni);
  }
  if(xEkseni == 1023)
  {
    digitalWrite(led2, HIGH);
      motor.write(xEkseni);
  }


  if(yEkseni == 0)
  {
    digitalWrite(led3, HIGH);
      motor.write(yEkseni);
  }
  if(yEkseni == 1023)
  {
   digitalWrite(led4, HIGH);
      motor.write(yEkseni);
  }


  if(buton == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  delay(10);
}
