#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>
#define motor_pin 9  
#include <FaBoLCD_PCF8574.h>
LiquidCrystal_I2C  lcd(0x27,16,2);
#define  DHTPIN 2 
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);


void setup() {
   lcd. begin ();
   pinMode(motor_pin , OUTPUT);
  lcd. print( " Adim Adim Arduino " );
 delay ( 1000 );
  dht.begin ();

}

void loop() {
int temp = dht. readTemperature ();
  int hum = dht. readHumidity ();

  lcd. clear ();

  lcd. setCursor ( 0 , 0 );
  lcd. print ( " Sicaklik: " );
  lcd. print (temp);
  lcd.print( " C " );

  lcd. setCursor ( 0 , 1 );
  lcd. print ( " Nem: % " );
  lcd. print (hum);

  delay ( 2000 );


   if (temp > hum){ // Eğer nem değperi çalışma sınırının üstündeyse(kuruysa) yap;
  
//digitalWrite(buzzer_pin, HIGH);  //buuzerı 2sn ye çalıştırır
delay(2000);

//digitalWrite(buzzer_pin, LOW);  //buzzerı susturur
digitalWrite(motor_pin, LOW);  // röleyi durdurup  motorun çalışmasını 5 sn sağlar
delay(5000);

 digitalWrite(motor_pin, HIGH);  //röleyi çalıştırıp motorun 5 sn durmasını sağlar
 delay(5000);

 }

 else{   //aksi halde 


// digitalWrite(buzzer_pin, LOW); //buzzerı sustur
 digitalWrite(motor_pin, HIGH);  //röleyi çalıştır.

 }


 


}
