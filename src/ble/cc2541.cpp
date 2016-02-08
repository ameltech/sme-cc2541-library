/*
 * cc2541.cpp
 *
 * Created: 01/01/2016 22:15:38
 *  Author: development
 */
 #include <Arduino.h>
 #include "cc2541.h"
 #include <Uart.h>

static bool _rx_ready = false;

void
Cc2541::handleRxData(uint8_t inChar)
{
     if (cur_dir == RX && !_rx_ready) {
         
         if (rx.idx == 2) {
             if ((rx.data[rx.idx]  == '0xab') &&
                 (inChar == '0xad')) {
                     rx.idx = 1;
                     return; // rewind
             }
             rx.data[rx.idx] = inChar;
             _rx_ready = true;
         }  if  (rx.idx <= 1) {       
             rx.data[rx.idx++] = inChar;
         }          
     } else if (cur_dir == TX) {
         tx.data[tx.idx] =inChar; 
  
         if (tx.idx == 2) {
             if ((cur_dir_len != tx.data[2]) ||
                 (tx.data[0] != 0xab) ||
                 (tx.data[1] != 0xa5)) {
                 cur_dir_len = 0;
                 memset (&tx, 0, sizeof(bleMsgT));
                 cur_dir = RX;
                 return;
                 // error
             }   else {
                 cur_dir_len = 0;
                 memset (&tx, 0, sizeof(bleMsgT));
                 cur_dir = RX;
                 return;
             }          
         }   
         tx.idx++; 
     }
 }


 char
 Cc2541::getRxData(void)
 {
     _rx_ready = false;
     return rx.data[2];
 }
 
 bool
 Cc2541::rxDataReady(void)
 {
     // read if rx data is ready
     return (_rx_ready == true);
 }

 /****************************************************************************/
 /*                               Public APIs                                */
 /****************************************************************************/


 bool
 Cc2541::available(void)
 {

    while (BLE.available()) {
          // get the new byte
         char inChar = (char)BLE.read();
         handleRxData(inChar);
         
         if (rxDataReady()) {
             return true; 
         }             
    }
    return false;
 }
 
 char
 Cc2541::read(void)
 {
    return getRxData();
 }
 
 void
 Cc2541::writeChar(const char data)
 {
     BLE.print((const char) 1);
     BLE.print((const char)data);
     cur_dir  = TX;
     cur_dir_len = 1;
 }
 
 
 void
 Cc2541::write(const char *data, char len)
 {
     BLE.write((const int) len);

     for (uint8_t i = 0 ; i < len; ++i) {
         BLE.write(data[i]);
     }
     cur_dir  = TX;
     cur_dir_len = len;
 }


 
Cc2541::Cc2541(void)
{
     
    memset (&rx, 0, sizeof(bleMsgT));
    memset (&tx, 0, sizeof(bleMsgT));
    cur_dir = RX;
}

void Cc2541::begin(void) {
    BLE.begin(115200);
}



Cc2541  smeBle;
