#define buzzer_pin 10  //buzzer_pin i 11 e ata
#define motor_pin 5    //motor_pin i 9  a ata
#define nem_sensoru A0  //nem_sensoru A0 girişine ata
#define calisma_siniri 600 // çalışma sınırını 600 olarak belirledik
int nem_degeri = 0;  //nem değeri değişkemini başlangıçta 0 olarak kabul ettik


void setup(){
pinMode(buzzer_pin , OUTPUT); // buzzer pin (11. pin)  çıkış olarak belirlendi
pinMode(motor_pin , OUTPUT);  // motor pin ( 9.pin)   çıkış olarak belirlendi 
Serial.begin(9600);  //serial haberleşmenin hızını ayarlıyoruz.
}


void loop() {
nem_degeri = analogRead(nem_sensoru);  //nem sensöründeki analog değer okunup nem değerine aktarılıyor.
Serial.println(nem_degeri);  //nem değeri serial porta yazdırılıyor.
 if (nem_degeri > calisma_siniri){ // Eğer nem değperi çalışma sınırının üstündeyse(kuruysa) yap;
  
digitalWrite(buzzer_pin, HIGH);  //buuzerı 2sn ye çalıştırır
delay(2000);

digitalWrite(buzzer_pin, LOW);  //buzzerı susturur
digitalWrite(motor_pin, LOW);  // röleyi durdurup  motorun çalışmasını 5 sn sağlar
delay(5000);

 digitalWrite(motor_pin, HIGH);  //röleyi çalıştırıp motorun 5 sn durmasını sağlar
 delay(5000);

 }

 else{   //aksi halde 


 digitalWrite(buzzer_pin, LOW); //buzzerı sustur
 digitalWrite(motor_pin, HIGH);  //röleyi çalıştır.

 }

}
