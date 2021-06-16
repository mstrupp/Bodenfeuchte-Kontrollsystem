// Projekt Mikrocontroller
// Messen der Bodenfeuchte und Anzeige auf einem Display
//
// Created 03.06.2020
// By Michael Strupp

#include "TM1637.h" // For communication to the display

// Pin definitions
const int displayCLK = 2; // yellow
const int displayDIO = 3; // white
const int sensorPIN = A0; // blue
const int ledPIN = 8; // green

// Settings
const int brightness = 2; // Value from 0 (darkest) to 7 (brightest)
const int threshold = 450; // Values above this threshold trigger the watering alarm

// Global variables
TM1637 display(displayCLK, displayDIO); // Display object

void setup() {
  display.init(); // Initialize and clear display
  display.set(brightness);
  // Display Welcome message
  display.displayStr("HALLO");
  delay(2000);
  // Set Warning LED pin as output
  pinMode(8, OUTPUT);
}

void loop() {
  int val;
  val = analogRead(sensorPIN);
  // Show the value on the display
  display.displayNum(val);
  // Aktivate the alarm LED if the soil is dry
  if (val >= threshold) {
    digitalWrite(ledPIN, HIGH);
  } else {
    digitalWrite(ledPIN, LOW);
  }
  
  delay(100);
}
