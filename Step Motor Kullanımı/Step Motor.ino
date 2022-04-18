#include <Stepper.h>

const int adim = 200;  // Step motorun 360 derece yapması için gerekli adım sayısı.

// Step motorun bağlantı şemasına göre arduinoya tanımladığımız pinler.
Stepper step(adim, 8, 9, 10, 11);

void setup() {
  // Step motor hızını setSpeed ie belirliyoruz.
  step.setSpeed(60);
  // Serial port ekranına yazmak için başlatıyoruz.
  Serial.begin(9600);
}

void loop() {
  // Step motorun ileriye dönmesi.
  Serial.println("İleri");
  step.step(adim);
  delay(500);

    // Step motorun geriye dönmesi.
  Serial.println("Geri");
  step.step(-adim);
  delay(500);
}
