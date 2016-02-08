# Arduino BLE Fox Library

An [Arduino](http://arduino.cc) library for creating custom BLE peripherals with [Nordic Semiconductor](http://www.nordicsemi.com)'s [nRF8001](http://www.nordicsemi.com/eng/Products/Bluetooth-R-low-energy/nRF8001),  [nR51822](http://www.nordicsemi.com/eng/Products/Bluetooth-R-low-energy/nRF51822) or
[CC2541](http://www.ti.com/product/CC2541).

Enables you to create more customized BLE Peripheral's compared to the basic UART most other Arduino BLE libraries provide

This library interacts with the CC2541 Image (TI "BLE Bridge" Example).
The related data transfer algorithm is described here:

[![Gitter](http://processors.wiki.ti.com/index.php/SerialBLEbridge_V_1.4.1](http://processors.wiki.ti.com/index.php/SerialBLEbridge_V_1.4.1)

http://processors.wiki.ti.com/index.php/SerialBLEbridge_V_1.4.1

The Arduino library incapsulates the TI protocol providing a 
transparent RX - TX transmission hiding to the user the protocol details.


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
git clone https://github.com/axelelettronica/arduino-BLEBridge BLEBridge
```


## Examples
See [examples](examples) folder.

## License

This libary is [licensed](LICENSE) under the [MIT Licence](http://en.wikipedia.org/wiki/MIT_License).

## Useful Links
 * [@Texas Instruments Home Page](http://processors.wiki.ti.com/index.php)'s 
[BLE Smart Wiki](http://processors.wiki.ti.com/index.php/Category:BluetoothLE)
   * Starting point for TI BLE support and documentation.



