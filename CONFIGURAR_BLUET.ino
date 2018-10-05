#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // TX, RX

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Configuracion:");
}

void loop() 
{ 
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

