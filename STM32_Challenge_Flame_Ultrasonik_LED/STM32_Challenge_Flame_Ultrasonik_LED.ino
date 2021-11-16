//LIBRARY
#include <NewPing.h>

//INISIALISASI VARIABLE
int ledR        = PB0;
int ledY        = PB1;
int ledG        = PB15;
int sensorFlame = PA0;
int triger      = PA2;
int echo        = PA3;
int batas       = 200; //MAKSIMAL 400 CM
int kunci       = 0;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(sensorFlame,INPUT);

}

void loop() {
  //BACA DATA / SENSOR
  int bacaFlame = analogRead(sensorFlame);
      bacaFlame = map(bacaFlame,168,4095,1,0);
  int bacaJarak = cm.ping_cm();

  //PRINT TO SERIAL
  Serial.print("NILAI SENSOR FLAME : ");
  Serial.print(bacaFlame);
  Serial.print(" | Data Jarak : ");
  Serial.print(bacaJarak);
  Serial.print(" | KUNCI : ");
  Serial.print(kunci);
  Serial.println();
  delay(500);

  //LOGIKA
  if(bacaFlame==1 and kunci==0){
    delay(300);
    kunci=1;
  }else if(bacaFlame==1 and kunci==1){
    delay(300);
    kunci=0;
  }

  //LOGIKA BACA JARAK JAUH
   if(kunci==true){
    if(bacaJarak <=20 and bacaJarak !=0){
      digitalWrite(ledR,HIGH);
      digitalWrite(ledY,HIGH);
      digitalWrite(ledG,HIGH);
      delay(100);
      digitalWrite(ledR,LOW);
      digitalWrite(ledY,LOW);
      digitalWrite(ledG,LOW);
    }else if (bacaJarak >=21 and bacaJarak <=50){
      digitalWrite(ledR,HIGH);
      digitalWrite(ledY,HIGH);
      digitalWrite(ledG,HIGH);
      delay(1000);
      digitalWrite(ledR,LOW);
      digitalWrite(ledY,LOW);
      digitalWrite(ledG,LOW);
    }else{
      digitalWrite(ledR,HIGH);
      delay(100);
      digitalWrite(ledR,LOW);
      delay(100);
      digitalWrite(ledY,HIGH);
      delay(100);
      digitalWrite(ledY,LOW);
      delay(100);
      digitalWrite(ledG,HIGH);
      delay(100);
      digitalWrite(ledG,LOW);
      delay(100);
      digitalWrite(ledY,HIGH);
      delay(100);
      digitalWrite(ledY,LOW);
      delay(100);
      digitalWrite(ledR,HIGH);
      delay(100);
      digitalWrite(ledR,LOW);
      delay(100);
    }
   }

   if(kunci==false){
      digitalWrite(ledR,LOW);
      digitalWrite(ledY,LOW);
      digitalWrite(ledG,LOW);
   }

}
