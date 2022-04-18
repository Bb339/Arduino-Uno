#include <Keypad.h>
#include <Servo.h>
int touchPin = 3;
int ledOpen=4;
int ledClose=2;

const byte satir = 4;
const byte sutun = 4;

int control=0;
int counter=0;

String enter_password;
String password="#1234";
Servo myservomotor;
char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//keypadı set ediyoruzzzz
byte satir_pinleri[satir] = {13, 12, 11,10 };
byte sutun_pinleri[satir] = {9, 8, 7, 6};

Keypad mahmut = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);

void setup()
{
  Serial.begin(9600);
  myservomotor.attach(3);
  myservomotor.write(0);
  pinMode(touchPin, INPUT);
  pinMode(ledOpen, OUTPUT);
  pinMode(ledClose, OUTPUT);
}

void loop()
{
  tus = mahmut.getKey();
  if (tus != NO_KEY)
  {
    Serial.print(tus);
 
      if(tus =='#'){
      control=1;
      }
    if(tus =='A'){
      for(int value=0; value<90; value++){
         myservomotor.write(value);
         digitalWrite(ledOpen,1);
         digitalWrite(ledClose,0);
      }
    }
    if(tus =='B'){
      for(int value=90; value>1; value--){
         myservomotor.write(value);
         digitalWrite(ledOpen,0);
         digitalWrite(ledClose,1);
      }
    }
    if(control==1){
      enter_password=enter_password+tus;
      counter++;
      Serial.print("şifre"+enter_password);
      
    if(enter_password==password){
      Serial.print("kapı açıldı");
    for(int value=0; value<90; value++){
      myservomotor.write(value);
    }
    digitalWrite(ledOpen,1);
    digitalWrite(ledClose,0);
    delay(2000);
    digitalWrite(ledOpen,0);
    enter_password="";
        control=0;
        counter=0;
    }
    else if((enter_password !=password)&&(counter>4)){
      Serial.print("hatalı giriş");
       for(int value=90; value>1; value--){
         myservomotor.write(value);
      }
        digitalWrite(ledOpen,0);
         digitalWrite(ledClose,1);
         delay(2000);
         digitalWrite(ledClose,0);
         enter_password="";
         control=0;
         counter=0;
    }
    
    }
    
  }
 if(digitalRead(touchPin) == HIGH)
  {
 myservomotor.write(0);
   delay(100);
  }
  else if(digitalRead(touchPin) ==LOW)
  {
 myservomotor.write(150);
      delay(100);
  }
}
