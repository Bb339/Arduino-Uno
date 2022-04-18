#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pir = 8;
int servo = 9;
int hareket;
Servo motor;
void setup() {
  motor.attach(9);
  pinMode(pir, INPUT);

}

void loop() {
  hareket = digitalRead(8);
  if (hareket = HIGH) {
 lcd.begin();
  lcd.backlight();
  lcd.print("    SAYFAMIZA  ");
  lcd.setCursor(0, 1);
  lcd.print("   HOSGELDINIZ ");
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(550);
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(180);
    delay(250);
    motor.write(0);
    delay(250);
    motor.write(90);

  }
  else {
    motor.write(90);
  }
}
