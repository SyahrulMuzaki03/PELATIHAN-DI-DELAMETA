//library
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <NewPing.h>

//inisialisasi
String uidString;
int buzzer=2;
int servo=3;
int triger=4;
int echo=5;
int batas=200;
int kunci=0;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo;
NewPing cm(triger, echo, batas);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(servo,OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(servo);
  bunyibuzzeroke();
  Serial.println("TEMPELKAN KARTU!");
}


void loop() {
  //BACA SENSOR
  int bacaJarak=cm.ping_cm();

  //LOGIKA
  if(mfrc522.PICC_IsNewCardPresent() and kunci==0){
  readRFID();
  Serial.print("tag UID; ");
  Serial.println(uidString);
  Serial.print("Nilai Jarak : ");
  Serial.println(bacaJarak);
  
  if(uidString=="A-A8-90-15"){
  kunci=1;
  Serial.println("BERHASIL");
  delay(1000);
  myservo.write(90);
  delay(1000);
  Serial.println("SILAHKAN MASUK!");
  bunyibuzzeroke();
  }else{
  kunci=0;
  Serial.println("GAGAL");
  bunyibuzzersalah();
  }
  }

  if(bacaJarak<=20 and bacaJarak !=0 and kunci==1){
  kunci=0;
  bunyibuzzeroke();
  Serial.println("SUDAH MASUK");
  delay(300);
  myservo.write(0);
  delay(1000);
  Serial.println("TEMPELKAN KARTU!");
  }
}


void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  bunyibuzzeroke();
  uidString=String(mfrc522.uid.uidByte[0],HEX)+"-"+
  String(mfrc522.uid.uidByte[1],HEX)+"-"+
  String(mfrc522.uid.uidByte[2],HEX)+"-"+
  String(mfrc522.uid.uidByte[3],HEX);
  uidString.toUpperCase();
}

void bunyibuzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void bunyibuzzersalah(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(100);  
}
