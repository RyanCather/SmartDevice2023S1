// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

// Traffic Lights - LED Outputs
#define ledRed A0
#define ledYellow A1
#define ledGreen A2

int E1 = 6;
int M1 = 7;

// Servo
#include <Servo.h>
Servo myservo;

// Moisture Sensor
#define moisturePin A5

// Sonar - HC-SR04
#define echoPin 6   // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A4  //attach pin D3 Arduino to pin Trig of HC-SR04

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
  
  pinMode(M1, OUTPUT);

  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");

  // Traffic Lights - LED Outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  pinMode(M1, OUTPUT);

  // Moisture Sensor
  pinMode(moisturePin, INPUT);

  // Sonar - HC-SR04
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);   // Sets the echoPin as an INPUT

  // Servo
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  logEvent("System Initialisation...");
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
