#define irsensor A0
#define led 2
void setup() {
  pinMode(led, OUTPUT);
  pinMode(irsensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  int irdeger = analogRead(irsensor);
  Serial.print("Sensör Değer: ");
  Serial.println(irdeger);
  delay(500);
  if (irdeger<500){
    digitalWrite(led,HIGH);
  }
  else {
     digitalWrite(led,LOW);
  }
}
