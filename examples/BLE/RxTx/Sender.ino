/*
  userButton.ino

  Example to sohws how a BLE Bidirectional communication works on the Smarteverything

  Created: 01/01/2016 10:32:11 PM

   Author: development

*/

#include <Arduino.h>
#include "cc2541.h"


char led;
bool bounce = false;
long referenceTime;



void ledLight(boolean _light) {
    char light = HIGH;

    if (!_light)
    light = LOW;

    switch (led) {

        case 'G':
        case 'g':
        ledGreenLight(light);
        break;

        case 'R':
        case 'r':
        ledRedLight(light);
        break;

        case 'B':
        case 'b':
        ledBlueLight(light);
        break;
    }

}


// the setup function runs once when you press reset or power the board
void setup() {
  smeBle.begin();
  
  SerialUSB.begin(115200);
 // Serial1.begin(115200);
 
  ledYellowOneLight(LOW);
  ledYellowTwoLight(LOW);

  // LED & User Button are already initialized by the SME core.
  // it is not required to do here
  
}

// the loop function runs over and over again forever
void loop() 
{
  volatile char data;

  while (smeBle.available()) {

    data = smeBle.read();

    SerialUSB.print(data, HEX);
    SerialUSB.print(" ");

    switch (data) {

      case '1':
        ledLight(true);
        break;

      case '0':
        ledLight(false);
        break;

      case 't':
      case 'T':
        bounce = false;
        break;
      default:
        led = data;
        break;

    }
  }

  if (isButtonOnePressed() && !bounce) {
    bounce = true;
    //BLE.write("B1 ");  
    char *str = "abcdefghi";
    char len = strlen(str);
    
    //BLE.write(len); 
    smeBle.write(str,len);
      
    SerialUSB.write(str); 
    SerialUSB.print(" ");
    SerialUSB.print(len, HEX);
    SerialUSB.print(" ");
    
         
    ledYellowOneLight(HIGH);
    referenceTime = millis();
  } else if (isButtonTwoPressed() && !bounce) {
    bounce = true;
    BLE.write("B2 ");
    ledYellowTwoLight(HIGH);
    referenceTime = millis();
  }

  if ((millis() - referenceTime) > 2000) {
    referenceTime = millis();
    bounce = false;
      ledYellowOneLight(LOW);
    ledYellowTwoLight(LOW);
  }
}

