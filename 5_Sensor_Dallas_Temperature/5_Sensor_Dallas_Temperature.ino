//LIBRARY ONEWIRE DAN DALASTEMPERATURE
#include<OneWire.h>
#include<DallasTemperature.h>

//INISIALISASI VARIABLE
int sensorSuhu=2;
int pinBuzzer=3;

//MANGGIL LIBRARAY
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  //MENENTUKAN FUNGSIONALITAS DARI FIN PADA MICROCONTROLLER
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  sensors.begin(); //MEMANGGIL FUNGSI
  

}

void loop() {
  //BACA DATA / SENSOR
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0); //MEMBACA DATA DI INDEX 0 PADA ONE WIRE

  //PRINT TO SERIAL
  Serial.print("BACA SUHU : ");
  Serial.print(bacaSuhu);
  Serial.print(" C ");
  Serial.println();

  //LOGIKA
  if(bacaSuhu >31){
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
  }
  
}
