//INISIALISASI 
int pinFlame=A1;
int pinBuzzer =5;




void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  
}

void loop() {
  //BACA SENSOR
  int bacaFlame= analogRead(pinFlame);
      bacaFlame=map(bacaFlame,26,1017,100,0);

  //PRINT TO SERIAL
  Serial.print("Nilai : ");
  Serial.print(bacaFlame);
  Serial.println();
  
  

  //LOGIKA
  if(bacaFlame<=26){
    Serial.println("Aman");
  }else if(bacaFlame>=26 and bacaFlame<=80){
    Serial.println("Warning Silahkan Periksa");
    digitalWrite(pinBuzzer,HIGH);
    delay(300);
    digitalWrite(pinBuzzer,LOW);
    delay(300);
  }else{
    Serial.println("Waspada Harap Mengungsi");
    digitalWrite(pinBuzzer,HIGH);
    delay(100);
    digitalWrite(pinBuzzer,LOW);
    delay(100);
  }
 
 
}
