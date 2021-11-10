int tombol1=2;
int sensorIR=3;

int R=5;
int Y=6;
int G=7;

void setup() {
 Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  //BACA DATA
  int bacaTombol1=digitalRead(tombol1);
  int bacaIR=digitalRead(sensorIR);

  //PRINT SERIAL
  Serial.print("Tombol 1 :");
  Serial.print(bacaTombol1);
  Serial.print("| Sensor IR: ");
  Serial.print(bacaIR);
  Serial.println();

  //LOGIKA
  if (bacaIR==0){
    digitalWrite(R,HIGH); 
  }else{
    digitalWrite(R,LOW);
  }
}
