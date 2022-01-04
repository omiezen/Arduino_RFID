//#include <Keyboard.h>
#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9
 
RFID rfid(SS_PIN, RST_PIN);
 
int buzzPin = 3;
 
// Setup variables:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;
 
void setup()
{
Serial.begin(115200);
SPI.begin();
rfid.init();

//Keyboard.begin();
}
 
void loop()
{
 
if (rfid.isCard()) {
if (rfid.readCardSerial()) {
if (rfid.serNum[0] != serNum0
&& rfid.serNum[1] != serNum1
&& rfid.serNum[2] != serNum2
&& rfid.serNum[3] != serNum3
&& rfid.serNum[4] != serNum4
) {
/* With a new cardnumber, show it. */
//Serial.println(" ");
//Serial.println("Card found");
serNum0 = rfid.serNum[0];
serNum1 = rfid.serNum[1];
serNum2 = rfid.serNum[2];
serNum3 = rfid.serNum[3];
serNum4 = rfid.serNum[4];
 

String thisString = String(rfid.serNum[0], HEX);

thisString += String(rfid.serNum[1], HEX);
thisString += String(rfid.serNum[2], HEX);
thisString += String(rfid.serNum[3], HEX);
thisString += String(rfid.serNum[4], HEX);

Serial.println(thisString);

//buzzer
analogWrite(3,20);
delay(1000);
analogWrite(3,0);
} else {
/* If we have the same ID, just write a dot. */
//Serial.println(".");

}
}
}
 
rfid.halt();
}
