// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011
/*
QUESTO FUNZIONA CON ATTINY85 @8MHz
12-08-2018
*/
#include <Arduino.h>
#include <TinyWireM.h>
#if defined ARDUINO_AVR_ATTINYX5
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(3, 4); // RX, TX
#else
 #define mySerial Serial
#endif
void setup() {
  mySerial.begin (9600);

  // Leonardo: wait for serial port to connect
  //while (!mySerial)
  //  {
  //  }


}  // end of setup
void loop() {
  mySerial.println ();
  mySerial.println ("I2C scanner. Scanning ...");
  byte count = 0;

  TinyWireM.begin();                    // initialize I2C lib
  for (byte i = 8; i < 120; i++)
  {
    mySerial.print ("address: ");
    mySerial.println (i, DEC);
    TinyWireM.beginTransmission (i);
    if (TinyWireM.endTransmission () == 0)
      {
      mySerial.print ("Found address: ");
      mySerial.print (i, DEC);
      mySerial.print (" (0x");
      mySerial.print (i, HEX);
      mySerial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  mySerial.println ("Done.");
  mySerial.print ("Found ");
  mySerial.print (count, DEC);
  mySerial.println (" device(s).");
  delay(1000);

}
