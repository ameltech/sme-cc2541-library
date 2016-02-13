/*
  Receiver.ino

  Example demonstrating how a PC/Smartphone App (Central BLE device) can be used to 
  drive the RGB led through the BLE module on the Smarteverything (Peripheral BLE device).
     
  - BLE -> Serial : Any character written by the Central device, on the writable attribute 0xFFF3, 
                    is showed on the Arduino console.
                    
    NOTICE: The protocol to be used is <len> <char 1> <char 2> ... <char len>
 
    Example triggering the RGB Blue led:
        Light on  :  <02><62><31>          (0x62 and 0x31 are the ascii for 'B' and '1')
        Light off :  <02><62><30>  
  
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

