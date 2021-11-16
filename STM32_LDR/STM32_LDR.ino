//INISIALISASI 
int ledR=PB0;
int ledY=PB1;
int ledG=PB10;
int sensorLDR=PA0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorLDR,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
}

void loop() {
  //BACA SENSOR / DATA
   int bacaLDR= analogRead(sensorLDR);
       bacaLDR= map(bacaLDR,32,4095,0,255);

  //PRINT KE SERIAL
   Serial.print("Nilai sensorLDR: ");
   Serial.print(bacaLDR);
   Serial.println(); //UNTUK ENTER 

  //LOGIKA PROGRAM
  analogWrite(ledR,bacaLDR);
}
