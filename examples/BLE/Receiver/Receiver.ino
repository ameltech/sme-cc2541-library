/*
  userButton.ino

  Example showing Data received from the BLE module on the Smarteverything

  Created: 01/01/2016 10:32:11 PM

   Author: development

*/

#include <Arduino.h>
#include "cc2541.h"

char led;

void ledLight(boolean _light) 
{
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
 
  led = 0;   
  // LED & User Button are already initialized by the SME core.
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

      default:
        led = data;
        break;

    }
  }
  delay(10);
}

