//INISIALISASI 
int ledR=PB0;
int ledY=PB1;
int ledG=PB10;
int sensorIR=PA8;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorIR,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
}

void loop() {
  //BACA SENSOR
  int bacaIR=digitalRead(sensorIR);

  //PRINT TO SERIAL
  Serial.print("Nilai sensorIR : ");
  Serial.print(bacaIR);
  Serial.print(" | ");
  Serial.print("kunci : ");
  Serial.print(kunci);
  Serial.println(); //UNTUK ENTER

  //LOGIKA
  if(bacaIR==0 and kunci==0){ //jika(){
    delay(300);
    kunci=1;
    digitalWrite(ledR,HIGH);
  }else if(bacaIR==0 && kunci==1){  //selain itu jika(){
    delay(300);
    digitalWrite(ledR,LOW);
    kunci=0;
  }
}
