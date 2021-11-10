#include<SPI.h>
#include<MFRC522.h>
#include <LiquidCrystal_I2C.h>

String uidString;

int buzz=2;
int infrared=3;
int kunci=0;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  //Create MRFC522 Instance
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
  pinMode(infrared,INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzoke();
  Serial.println("TEMPELKAN KARTU!");
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
  
}

void loop() {
  int bacaIR=digitalRead(infrared);
  
  if(mfrc522.PICC_IsNewCardPresent() and kunci==0){
  readRFID();
  Serial.print("tag UID; ");
  Serial.println(uidString);
  if(uidString=="CA-0-E7-80"){
  kunci=1;
  Serial.println("BERHASIL");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("BERHASIL");
  delay(1000);
  Serial.println("Silahkan Masuk!");
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Silahkan Masuk!");
  bunyibuzzoke();
  }else{
  kunci=0;  
  Serial.println("GAGAL");
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("GAGAL");
  delay(500);
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
  bunyibuzzgagal();
  
  }
  }

if(bacaIR==0 && kunci==1){
  kunci=0;
  bunyibuzzoke();
  Serial.println("SUDAH MASUK");
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("SUDAH MASUK");
  delay(500);
  Serial.println("PALANG DITUTUP");
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("PALANG DITUTUP");
  delay(500);
  Serial.println("TEMPELKAN KARTU");
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU!");
}
}


void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Sound the buzzer when a card is read
  bunyibuzzoke();
  //
  uidString=String(mfrc522.uid.uidByte[0],HEX)+"-"+
  String(mfrc522.uid.uidByte[1],HEX)+"-"+
  String(mfrc522.uid.uidByte[2],HEX)+"-"+
  String(mfrc522.uid.uidByte[3],HEX);
  uidString.toUpperCase();
}

void bunyibuzzoke(){
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);
}

void bunyibuzzgagal(){
  digitalWrite(buzz,HIGH);
  delay(1000);
  digitalWrite(buzz,LOW);
  delay(100);  
}
