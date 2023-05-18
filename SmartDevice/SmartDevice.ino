// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 53

// Traffic Lights - LED Outputs
#define ledRed A0
#define ledYellow A1
#define ledGreen A2

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
    while (1)
      ;
  }

  // Traffic Lights - LED Outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  logEvent("System Initlisation");
}

void loop() {
  // trafficLightTest();


  airConditioning();
  panicRoom();
  drivewayNotificiationSystemProcess();
  delay(250);
}

void trafficLightTest() {
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  delay(500);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledGreen, LOW);
  delay(500);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(500);
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
