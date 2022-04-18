const int x_ekseni = A0;
const int y_ekseni = A1;
const int buton = 7;
int x_durum;
int y_durum;
int b_durum;
void setup() {
  
Serial.begin(9600);
pinMode(buton, INPUT);
}

void loop() {
  x_durum = analogRead(x_ekseni);
  y_durum = analogRead(y_ekseni);
  b_durum = digitalRead(buton);
  Serial.print("buton durumu = ");
  Serial.println(b_durum);
  Serial.print("x durumu = ");
  Serial.println(x_durum);
  Serial.print("y durumu = ");
  Serial.println(y_durum);
   Serial.println("**************************************");
   delay(1000);
  
}
