//masukan library newping
#include<NewPing.h>

//inisialisasi
int triger=3;
int echo=2;
int batas=200; //maksimal 400 cm
int buzz=4;
int R=5;
int Y=6;
int G=7;

NewPing cm(triger,echo,batas);

void setup() {
 Serial.begin(9600);
 pinMode(buzz,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 
 
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaJarak=cm.ping_cm();
  
  
  //PRINT TO SERIAL
  Serial.print("Data jarak :");
  Serial.print(bacaJarak);
  Serial.print(" cm");
  Serial.println();
  delay(500);

  //LOGIKA
  if(bacaJarak<=20 and bacaJarak!=0){
  Serial.print("BERENTI!");
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  }else if(bacaJarak >=21 and bacaJarak <=70){
  Serial.print("BAHAYA");
  digitalWrite(Y,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(buzz,HIGH);
  delay(100);
  }else
  Serial.print("AMAN");
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(buzz,LOW);

}
