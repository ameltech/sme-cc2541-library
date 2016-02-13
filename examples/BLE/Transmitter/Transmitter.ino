/*
  Transmitter.ino

  Example demonstrating how to send data the SmartEveryting (Peripheral BLE device) to a 
  PC/Smartphone App (Central BLE device)
  
  Pressing Button 1 will send a string, while pressing Button 2 will send a single character.

  NOTICE: Any character will be sent via BLE on the attribute 0xFFF4.
          The Host needs to subscribe to 0xFFF4 attribute to get notified.
 
  Created: 01/01/2016 10:32:11 PM

   Author: development

*/

#include <Arduino.h>
#include "cc2541.h"


char led;
long referenceTime;
bool bounce = false;

char *str = "abcdefghi";

// the setup function runs once when you press reset or power the board
void setup() 
{
  smeBle.begin();
  
  SerialUSB.begin(115200);
  ledYellowOneLight(LOW);
  ledYellowTwoLight(LOW);
  
}


// the loop function runs over and over again forever
void loop() 
{

  if (isButtonOnePressed() && !bounce) {
    bounce = true; 

    char len = strlen(str);
    smeBle.write(str,len);
      
    SerialUSB.print("Sending : "); 
    SerialUSB.println(str);
    SerialUSB.print("  Len : ");
    SerialUSB.print(len, HEX);
    SerialUSB.println(" ");
    
    ledYellowOneLight(HIGH);
    referenceTime = millis();
    
  } else if (isButtonTwoPressed() && !bounce) {
    bounce = true;
       
    smeBle.writeChar(0xab);
    SerialUSB.print("Sending : "); 
    SerialUSB.println("0xab");
    SerialUSB.print("  Len : ");
    SerialUSB.println(1, HEX);
        
    ledYellowTwoLight(HIGH);
    referenceTime = millis();
  }

  if ((millis() - referenceTime) > 1000) {
    bounce = false;
    referenceTime = millis();
    ledYellowOneLight(LOW);
    ledYellowTwoLight(LOW);
  }
}

