#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int yesil=3;
int kirmizi=4;
int dugme1=11;
int dugme2=12;
int buzzer=10;
int pir=2;
bool alarm=false;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("  HIRSIZ ALARM  ");
  lcd.setCursor(4, 1);
  lcd.print(" SISTEMI   ");
   
  pinMode(buzzer,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(dugme1,INPUT);
  pinMode(dugme2,INPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(dugme1)==HIGH){
    
    alarm=true;

    lcd.clear(); 
    lcd.print(" Sistem acik= ");
    lcd.print((bool)alarm,1);
    delay(5000);
    lcd.setCursor(0, 1);
    lcd.print("Hareketlilik var");
    
    }
    
    if(digitalRead(dugme2)==HIGH){
    alarm=false;
  
    lcd.clear(); 
    lcd.print("Sistem kapali= ");
    lcd.print((bool)alarm,1);
    lcd.setCursor(0, 1);
    lcd.print("kontrol altinda");
    }
    
  Serial.print("ALARM : ");
  Serial.println(alarm);
  
  if(alarm==true){
    digitalWrite(yesil,HIGH);
    digitalWrite(kirmizi,LOW);
    
    if(digitalRead(pir)==HIGH){
      
    while(digitalRead(dugme2)==LOW){
      
       digitalWrite(buzzer,HIGH);
       delay(250);
       digitalWrite(buzzer,LOW);
       delay(250);
    }
    
    }
    
  }
  
  else{
    
  digitalWrite(yesil,LOW);
  digitalWrite(kirmizi,HIGH);
   
  }
  
}
