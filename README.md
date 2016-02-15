# SmartEverything TI CC2541 BLE Arduino Library

An [Arduino](http://arduino.cc) library for creating custom BLE peripherals with [CC2541](http://www.ti.com/product/CC2541).

It enables you to create more customized BLE Peripheral's providing a 2 way communication.

This library interacts with the CC2541 Image (TI "BLE Bridge" Example).
The related data transfer algorithm is described here:

[![Gitter](http://processors.wiki.ti.com/index.php/SerialBLEbridge_V_1.4.1](http://processors.wiki.ti.com/index.php/SerialBLEbridge_V_1.4.1)


The library provides a transparent RX - TX transmission hiding to the user the interaction with the TI BLE Bridge protocol.

Notice: 
- To receive data from the SME a Central Application needs to Subscribe to Attribute FFF4.
- To send data to the SME a Central Application needs to write on Attribute FFF3 accordingley to the BLE Bridge protocol.


## Compatible Hardware

### [Texas Instruments CC2541 ](http://www.ti.com/product/CC2541)

 * [SmartEverything FOX](http://www.smarteverything.it) with [Arduino Add-on](http://www.arduino.cc/en/Guide/Libraries#toc3)

**Note:** The CC2541 is connected to the Smart Everything throught the pluggable TDK SESUB-PAN-T2541 module. The communication between the CC2541 and the SME is done through a USART interface.


## Usage

### Download Library

#### Arduino

#### Using the Arduino IDE Library Manager

1. Choose ```Sketch``` -> ```Include Library``` -> ```Manage Libraries...```
2. Type ```BLEBridge``` into the search box.
3. Click the row to select the library.
4. Click the ```Install``` button to install the library.

#### Using Git
```sh
cd ~/Documents/Arduino/libraries/
git clone https://github.com/ameltech/sme-cc2541-library/  sme-cc2541-library
```


## Releases  
---  
#### v1.0.0 First Release  


## Examples
See [examples](examples) folder.


## License Information
-------------------

Copyright (c) Amel Technology. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA



## Useful Links
 * [@Texas Instruments Home Page](http://processors.wiki.ti.com/index.php)'s 
[BLE Smart Wiki](http://processors.wiki.ti.com/index.php/Category:BluetoothLE)
   * Starting point for TI BLE support and documentation.
   * 
* [@LightBLue Home Page] (https://itunes.apple.com/it/app/lightblue/id639944780?mt=12)
 * Useful OSX Application  to test the RX  RX/TX Data.
 * 
* [@B-BLE Home Page] (https://play.google.com/store/apps/details?id=com.billy.billylightblue)
 * Useful App to test the RX/TX Data from Android smartphones.

