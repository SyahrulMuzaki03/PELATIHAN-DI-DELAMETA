//INISIALISASI
int ledR=PB0;
int ledY=PB1;
int ledG=PB10;
int sensorPIR=PA8;

void setup() {
  Serial.begin(9600);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(sensorPIR,INPUT);
}

void loop() {
  //BACA SENSOR
  int bacaPIR=digitalRead(sensorPIR);

  //PRINT TO SERIAL
  Serial.print("Nilai PIR= ");
  Serial.print(bacaPIR);
  Serial.println();

  //LOGIKA
  if(bacaPIR==0){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledY,LOW);
  digitalWrite(ledR,LOW);
  }else{
  digitalWrite(ledR,HIGH);
  digitalWrite(ledY,LOW);
  digitalWrite(ledG,LOW);
 }
}
