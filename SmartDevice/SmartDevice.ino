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

// DFRobot Motor
int E2 = 11;
int M2 = 10;

// Crash Sensor / Button
#define crashSensor 7

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

  //DFRobot Motor
  pinMode(M2, OUTPUT);

  // Crash Sensor / Button
  pinMode(crashSensor, INPUT);

  logEvent("System Initilisation");
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
  int speedValue;
  int crashSensorValue = digitalRead(crashSensor);
  if (crashSensorValue == 0) {
    logEvent("Button Pressed");
    speedValue = 0;  // Can be 0-255.
  } else {
    
    speedValue = 255;  // Can be 0-255.
  }
  digitalWrite(M2, HIGH);
  analogWrite(E2, speedValue);  //PWM Speed Control
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
