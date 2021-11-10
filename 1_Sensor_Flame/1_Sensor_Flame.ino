int pinFlame=A1;


void setup() {
 Serial.begin(9600);
}

void loop() {
 //BACA DATA
 int bacaFlame=analogRead(pinFlame);
     bacaFlame=map(bacaFlame,26,1017,100,0);

//PRINT SERIAL
 Serial.print("NILAI :");
 Serial.print(bacaFlame);
 Serial.println();

//LOGIKA
// analogWrite(bacaFlame);
 
}
