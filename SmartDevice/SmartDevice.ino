// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 53

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1);
  }
  logEvent("System Initlisation");
}

void loop() {
  // put your main code here, to run repeatedly:
  airConditioning();
  panicRoom();
  drivewayNotificiationSystemProcess();
  delay(250);
}

/*
 Using the temperature, determine if the fan should be on or off.
 @params none
 @return none
*/
void airConditioning() {

}

/*
 If the user presses the panic button (crash sensor), sound the alarm (piezo)
 @params none
 @return none
*/
void panicRoom() {

}



/*
 If the user presses the panic button (crash sensor), sound the alarm (piezo)
 @params none
 @return none
*/
void drivewayNotificiationSystemProcess() {

}




