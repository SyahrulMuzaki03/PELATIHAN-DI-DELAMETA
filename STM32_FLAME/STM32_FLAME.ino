//INISIALISASI
int ledR=PB0;
int ledY=PB1;
int ledG=PB10;
int sensorFlame=PA0;

void setup() {
  Serial.begin(9600);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(sensorFlame,INPUT);
}

void loop() {
  //BACA SENSOR
  int bacaFlame=analogRead(sensorFlame);
      bacaFlame=map(bacaFlame,168,4095,100,0);
      
  //PRINT TO SERIAL
  Serial.print("Nilai Flame: ");
  Serial.print(bacaFlame);
  Serial.println();
  delay(500);

  //LOGIKA
  if(bacaFlame>=0 and bacaFlame<=30){
    digitalWrite(ledG,HIGH);
    digitalWrite(ledR,LOW);
    digitalWrite(ledY,LOW);
  }else if(bacaFlame>=31 and bacaFlame<=60){
    digitalWrite(ledY,HIGH);
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,LOW);
  }else{
    digitalWrite(ledR,HIGH);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,LOW);
  }
}
  
