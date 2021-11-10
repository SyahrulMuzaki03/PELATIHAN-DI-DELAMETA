#include<NewPing.h>

//INISIAL
int triger = 5;
int echo = 4;
int batas = 400;

NewPing cm(triger,echo,batas);

void setup() {
  // BACA SENSOR
  Serial.begin(115200);

}

void loop() {
  int bacaJarak=cm.ping_cm();

  //PRINT TO SERIAL
  Serial.print(" Data Jarak: ");
  Serial.print(bacaJarak);
  Serial.print(" cm ");
  Serial.println();
  delay(500);

}
