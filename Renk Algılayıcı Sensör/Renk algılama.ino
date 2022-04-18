#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int s0 = A3;  
const int s1 = A4;  
const int s2 =A1;  
const int s3 = A2;  
const int out = A0;   
const int LED = 13;   


int kirmizi = 0;  
int yesil = 0;  
int mavi = 0;  
int maviLed=5;
int kirmiziLed=4;
int yesilLed=3;
void setup()   
{  
  Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();
  lcd.print(" RENK ALGILAYICI ");
  lcd.setCursor(4, 1);
  lcd.print(" SENSOR ");
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(LED, OUTPUT);
  pinMode(out, INPUT);   
  pinMode(yesilLed,OUTPUT);
  pinMode(kirmiziLed,OUTPUT);
   pinMode(maviLed,OUTPUT);
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  
} 
 
void loop() 
{  
  Renk_al();
  Serial.print("Kırmızı : ");  
  Serial.println(kirmizi, DEC);  
  Serial.print("Yeşil : ");  
  Serial.println(yesil, DEC);  
  Serial.print("Mavi : ");  
  Serial.println(mavi, DEC);  

  if (kirmizi < mavi && kirmizi < yesil && kirmizi < 60)
  {  
      if (kirmizi <=10 && yesil <=10 && mavi <=10){ 
     Serial.println("  ");   
  } else{
   Serial.println("Algılanan Renk : Kırmızı"); 
       lcd.clear(); 
    lcd.print(" RENK = KIRMIZI ");
    delay(1000);
             digitalWrite(yesilLed,LOW);
    digitalWrite(kirmiziLed,HIGH);
      digitalWrite(maviLed,LOW); 
  }
}  
else if (mavi < kirmizi && mavi < yesil)   
  {  
      if (kirmizi <=10 && yesil <=10 && mavi <= 10){
     Serial.println("  ");  
  }else {
  Serial.println("Algılanan Renk : Mavi"); 
   lcd.clear(); 
    lcd.print("   RENK = MAVI ");
    delay(1000);
             digitalWrite(yesilLed,LOW);
    digitalWrite(kirmiziLed,LOW);
      digitalWrite(maviLed,HIGH); 
    }
     
  }  
  else if (yesil < kirmizi && yesil < mavi)  
  {  
    if (kirmizi <= 10 && yesil <=10 && mavi <= 10){
     Serial.println("  ");   
  } else{
   Serial.println("Algılanan Renk : Yeşil");
 
    lcd.clear(); 
    lcd.print("  RENK = YESIL ");
    delay(1000);
          digitalWrite(yesilLed,HIGH);
    digitalWrite(kirmiziLed,LOW);
      digitalWrite(maviLed,LOW); 
    } 
  }  
  else{
  Serial.println();  
  }
  Serial.println();  
  delay(2000);
}

void Renk_al()  // Renk algılamamızı sağlayan fonksiyonumuz ...
{    
  digitalWrite(LED, HIGH);
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  kirmizi = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  mavi = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  yesil = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(LED, LOW);
}
 
