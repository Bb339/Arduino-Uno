int eskiDeger=500;
int buzzer=9;
int deger;

void setup() {
    Serial.begin(9600);
 pinMode(buzzer, OUTPUT);

}

void loop() {
  
  deger=analogRead(A0);
 if(deger>eskiDeger){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
   Serial.print("DEĞER : ");
  Serial.println(deger);
}
else{
   digitalWrite(buzzer, LOW);
     Serial.print("DEĞER : ");
  Serial.println(deger);
}
}
