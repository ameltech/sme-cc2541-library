/*
  SerialCommunication.ino

  Example demonstrating a BLE Bidirectional cummunication between a PC/Smartphone App (Central BLE device)
  and the SmartEveryting USB console (Peripheral BLE)

  - Serial -> BLE : Any character edited on the USB Arduino console will be sent via BLE  
                    on the attribute 0xFFF4 to the central device.
                    NOTICE: The Host needs to subscribe to 0xFFF4 attribute to get notified.
                    
  - BLE -> Serial : Any character written by the Central device, on the writable attribute 0xFFF3, 
                    is showed on the Artiono console.
                    NOTICE: The protocol to be used is <len> <char 1> <char 2> ... <char len>
 
  Created: 01/01/2016 10:32:11 PM

   Author: development

*/

#include <Arduino.h>
#include "cc2541.h"


// the setup function runs once when you press reset or power the board
void setup() {
  smeBle.begin();
  
  SerialUSB.begin(115200);

  while (!SerialUSB) {
       ;
  }
    
  SerialUSB.println("Any charachtrer on the console will be sent through the BLE link:");

  ledYellowOneLight(LOW);
  ledYellowTwoLight(LOW);
}

// the loop function runs over and over again forever
void loop() 
{
  volatile char data;

  while(SerialUSB.available()) { 
    // get the new byte: 
    char inChar = (char)SerialUSB.read(); 
    smeBle.writeChar(inChar);
  }
    
  while (smeBle.available()) {
    data = smeBle.read();

    SerialUSB.print(data, HEX);
    SerialUSB.print(" ");
  }
}

