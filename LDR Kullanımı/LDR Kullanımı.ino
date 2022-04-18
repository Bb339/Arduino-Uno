#include <Servo.h>
int led=3;
int servo = 9;
Servo motor;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
motor.attach(9);
pinMode(led, OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
 int ldr_deger=analogRead(A1);
 Serial.println(ldr_deger);
 if(ldr_deger<=65){// karanlıksa
  digitalWrite(led, HIGH);
  motor.write(180);
    delay(250);
 }
 else{
   digitalWrite(led, LOW);//aydınlıksa
    motor.write(0);
    delay(250);
 }
 delay(500);
}
