//INISIALISASI
int syahrul_pinR=PB0;
int syahrul_pinY=PB1;
int syahrul_pinG=PA8;
int syahrul_tombol1=PA15;
int syahrul_tombol2=PA12;
int syahrul_tombol3=PA11;
int syahrul_kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(syahrul_tombol1,INPUT);
  pinMode(syahrul_tombol2,INPUT);
  pinMode(syahrul_tombol3,INPUT);
  pinMode(syahrul_pinR,OUTPUT);
  pinMode(syahrul_pinY,OUTPUT);
  pinMode(syahrul_pinG,OUTPUT);
}

void loop() {
  //BACA DATA
  int(bacasyahrul_tombol1)=digitalRead(syahrul_tombol1);
  int(bacasyahrul_tombol2)=digitalRead(syahrul_tombol2);
  int(bacasyahrul_tombol3)=digitalRead(syahrul_tombol3);
  

  //PRINT TO SERIAL
  Serial.print("syahrul_tombol1: ");
  Serial.print(bacasyahrul_tombol1);
  Serial.print(" | ");
  Serial.print("syahrul_tombol2: ");
  Serial.print(bacasyahrul_tombol2);
  Serial.print(" | ");
  Serial.print("syahrul_tombol3: ");
  Serial.print(bacasyahrul_tombol3);
  Serial.println();

  //LOGIKA
  if(bacasyahrul_tombol1==1 and syahrul_kunci==0){ //TOMBOL1
  delay(100);
  syahrul_kunci=1;
  digitalWrite(syahrul_pinR,HIGH);
  }else if(bacasyahrul_tombol1==1 and syahrul_kunci==1){
  delay(100);
  syahrul_kunci=0;
  digitalWrite(syahrul_pinR,LOW);
  }

  if(bacasyahrul_tombol2==1 and syahrul_kunci==0){//TOMBOL2
  delay(100);
  syahrul_kunci=1;
  digitalWrite(syahrul_pinY,HIGH);
  }else if(bacasyahrul_tombol2==1 and syahrul_kunci==1){
  delay(100);
  syahrul_kunci=0;
  digitalWrite(syahrul_pinY,LOW);
  }

  if(bacasyahrul_tombol3==1 and syahrul_kunci==0){//TOMBOL3
  delay(100);
  syahrul_kunci=1;
  digitalWrite(syahrul_pinG,HIGH);
  }else if(bacasyahrul_tombol3==1 and syahrul_kunci==1){
  delay(100);
  syahrul_kunci=0;
  digitalWrite(syahrul_pinG,LOW);
  }

}
