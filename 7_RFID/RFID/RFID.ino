//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>

//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 
 if (content== "A732894B"){//Sesuaikan dengan ID kartu anda
 Serial.println("Selamat datang SYAHRUL MUZAKI!");
 }else if(content=="0584D54790D100"){
 Serial.println("SELAMAT DATANG DEZANI");
 }else{
 Serial.println("TIDAK TERDAFTAR");
}
}
