//Library NewPing
#include <NewPing.h>

//Inisialisasi pembuatan variable
int triger=PA2;
int echo=PA3;
int batas=200; //Maksimal 400 cm

NewPing cm(triger,echo,batas);

void setup() {
 Serial.begin(9600);
}

void loop() {
 //Program dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 
 //Print ke Serial
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500);
}
