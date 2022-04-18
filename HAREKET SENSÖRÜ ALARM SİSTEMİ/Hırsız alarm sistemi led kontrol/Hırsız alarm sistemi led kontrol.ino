int yesil=3;
int kirmizi=4;
int dugme1=11;
int dugme2=12;
int buzzer=10;
int pir=2;
bool alarm=false;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(dugme1,INPUT);
  pinMode(dugme2,INPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);

}

void loop() {
   if(digitalRead(dugme1)==HIGH){
    alarm=true;
    delay(5000);
    }
     if(digitalRead(dugme2)==HIGH){
    alarm=false;
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
