
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C  lcd(0x27,16,2);
const int TrigPin = 9;
const int EchoPin = 8;
const int yled = 5;
const int sled = 3;
const int kled = 6;
const int buzzer = 12;

int mesafe ;
int sure;

void setup()
{
  lcd.begin ();
  lcd.setBacklight(HIGH);
  Serial.begin(9600);
  pinMode(TrigPin , OUTPUT);
  pinMode(EchoPin , INPUT);
  pinMode(yled, OUTPUT);
  pinMode(sled, OUTPUT);
  pinMode(kled, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  digitalWrite(TrigPin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(TrigPin , LOW);
  sure = pulseIn (EchoPin , HIGH);
  mesafe = (sure / 2) / 28.5;
  Serial.println(mesafe);
  
  if(mesafe <=10){
  digitalWrite(kled, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(kled, LOW);
  digitalWrite(buzzer, LOW);
  delay(90);

  lcd.home();
  lcd.print("Mesafe= ");
  lcd.print((int)mesafe,1);
  lcd.print(" cm ");
  
 }

 
  else if(mesafe <=30){
  digitalWrite(sled, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(350);
  digitalWrite(sled, LOW);
  digitalWrite(buzzer, LOW);
  delay(250);
  
  lcd.home();
  lcd.print("Mesafe= ");
  lcd.print((int)mesafe,1);
  lcd.print(" cm ");

 }

  else if(mesafe <=50){
  digitalWrite(yled, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(750);
  digitalWrite(yled, LOW);
  digitalWrite(buzzer, LOW);
  delay(650);
  
  lcd.home();
  lcd.print("Mesafe= ");
  lcd.print((int)mesafe,1);
  lcd.print(" cm ");

 }

 
  }
