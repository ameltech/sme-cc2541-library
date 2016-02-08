/*
  userButton.ino

  Example to sohws how send data through the BLE module on the Smarteverything

  Created: 01/01/2016 10:32:11 PM

   Author: development

*/

#include <Arduino.h>
#include "cc2541.h"


char led;
bool bounce = false;
long referenceTime;



// the setup function runs once when you press reset or power the board
void setup() 
{
  smeBle.begin();
  
  SerialUSB.begin(115200);

  // LED & User Button are already initialized by the SME core.
  // it is not required to do here
  
}

// the loop function runs over and over again forever
void loop() 
{

  if (isButtonOnePressed()) {

    char *str = "abcdefghi";
    char len = strlen(str);
    
    smeBle.write(str,len);
      
    SerialUSB.write("Sending : "); 
    SerialUSB.println("  Len" : );
    SerialUSB.print(len, HEX);
    SerialUSB.println(" ");

         
    ledYellowOneLight(HIGH);
    referenceTime = millis();
  } else if (isButtonTwoPressed()) {
    bounce = true;
    BLE.write("B2 ");
    ledYellowTwoLight(HIGH);
    referenceTime = millis();
  }

  if ((millis() - referenceTime) > 2000) {
    referenceTime = millis();
    ledYellowOneLight(LOW);
    ledYellowTwoLight(LOW);
  }
}

