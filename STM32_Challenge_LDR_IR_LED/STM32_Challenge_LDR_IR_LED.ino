//INISIALISASI
int ledR=PB0;
int ledY=PB1;
int ledG=PB10;
int sensorIR=PA8;
int sensorLDR=PA0;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorIR,INPUT);
  pinMode(sensorLDR,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT); 
}

void loop() {
  //BACA DATA / SENSOR
  int(bacaIR)=digitalRead(sensorIR);
  int(bacaLDR)=analogRead(sensorLDR);
      bacaLDR=map(bacaLDR,32,4095,0,255);

  //PRINT TO SERIAL
  Serial.print("NilaiIR : ");
  Serial.print(bacaIR);
  Serial.print(" | ");
  Serial.print("NilaiLDR : ");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  if(bacaIR==0 and kunci==0){
  kunci=1; 
  }else if(bacaIR==0 and kunci==1){
  kunci=0;
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledY,LOW);
  }
  
  if(bacaLDR<=60 and kunci==1){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledY,LOW);
  digitalWrite(ledR,LOW);
  }
  
  else if(bacaLDR>=60 and bacaLDR<=200 and kunci==1){
  digitalWrite(ledY,HIGH);
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  }
  
  else if(bacaLDR>=200 and kunci==1){
  digitalWrite(ledR,HIGH);
  digitalWrite(ledY,LOW);
  digitalWrite(ledG,LOW); 
  }
}
