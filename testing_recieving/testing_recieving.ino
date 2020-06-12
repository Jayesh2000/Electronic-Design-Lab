#include <SoftwareSerial.h>

byte recieveData; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() > 0){
  recieveData = Serial.read();
  if(recieveData == 48)
  for(int i = 65;i <= 90;i++){
    Serial.print(char(i));
    delay(50);
  }
}
delay(200);
}
