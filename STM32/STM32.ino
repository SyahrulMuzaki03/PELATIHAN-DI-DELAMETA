//INISIALISASI
int pinR=PB0;
int pinY=PB1;
int pinG=PA8;

int tombol1=PB15;
int tombol2=PB14;
int tombol3=PB13;

void setup() {
 Serial.begin(9600);
 pinMode(tombol1,INPUT);
 pinMode(tombol2,INPUT);
 pinMode(tombol3,INPUT);
 pinMode(pinR,OUTPUT);
 pinMode(pinY,OUTPUT);
 pinMode(pinG,OUTPUT);

}

void loop() {
 //BACA DATA
 int bacatombol1=digitalRead(tombol1);
 int bacatombol2=digitalRead(tombol2);
 int bacatombol3=digitalRead(tombol3);

 //PRINT TO SERIAl
 Serial.print("tombol1 : ");
 Serial.print(bacatombol1);
 Serial.print(" | ");
 Serial.print("tombol2 : ");
 Serial.print(bacatombol2);
 Serial.print(" | ");
 Serial.print("tombol3 : ");
 Serial.print(bacatombol3);
 Serial.println(); //UNTUK ENTER

 //LOGIKA
 if(bacatombol1==1){ //BUTTON1
 digitalWrite(pinR,HIGH);
 }else{
 digitalWrite(pinR,LOW);
 }

 if(bacatombol2==1){ //BUTTON2
 digitalWrite(pinY,HIGH);
 }else{
 digitalWrite(pinY,LOW);
 }

 if(bacatombol3==1){ //BUTTON3
 digitalWrite(pinG,HIGH);
 }else{
 digitalWrite(pinG,LOW);
 }
 
}
