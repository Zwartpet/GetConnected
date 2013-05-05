#include <Wire.h>;
#include <inttypes.h>;

void init_leds(){
 Wire.begin();
 
 sendData(0x06, 0x00); //binair 00000110, 00000000 //Zet alle 8 poorten op GP0 op output
 sendData(0x07, 0x00); //binair 00000111, 00000000 //Zet alle 8 poorten op GP1 op output
}

void sendData(uint8_t byte1, uint8_t byte2)
{
  Wire.beginTransmission(0x20);
  Wire.write(byte1);
  Wire.write(byte2);
  Wire.endTransmission();
}

void flash(int led){
  sendData(0x00, 0x00); //eerst alles uit
  delay(500);
  if(led == 1){
    sendData(0x00, 0x08);
  }else if(led == 2){
    sendData(0x00, 0x04);
  }else if(led == 3){
    sendData(0x00, 0x02);
  }else if(led == 4){
    sendData(0x00, 0x01);
  }
}
