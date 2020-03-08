//#include<SoftwareSerial.h>
//
///* Create object named bt of the class SoftwareSerial */ 
//SoftwareSerial bt(2,3); /* (Rx,Tx) */  
//
//void setup() {
//  bt.begin(38400); /* Define baud rate for software serial communication */
//  Serial.begin(38400); /* Define baud rate for serial communication */
//}
//
//void loop() {
//  
//    if (bt.available()) /* If data is available on serial port */
//    {
//     Serial.println(bt.read()); /* Print character received on to the serial monitor */
//    }
//}

#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

int sensorPin = A0;

int sensorValue = 0;

void setup() {

BTserial.begin(38400); }

void loop() {

BTserial.print(43);
delay(200);

}
