int tombol1=2;
int R=5;
void setup() {
 Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT);

}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  Serial.println("Kondisi tombol :" + String(bacaTombol1) + " Volt" );

  if (bacaTombol1==1){
    digitalWrite(R,HIGH);
  }else{
    digitalWrite(R,LOW);
 }
 
}
