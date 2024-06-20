/*
    Project name : ESP8266 GPS Module
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-gps-module
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Create an instance of the TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port for the GPS module
SoftwareSerial ss(12, 14);  // RX, TX

void setup() {
    Serial.begin(115200);  // Initialize serial communication for debugging
    ss.begin(9600);        // Initialize the software serial port at 9600 baud
}

void loop() {
    // This sketch displays information every time a new sentence is correctly encoded.
    while (ss.available() > 0) {
        gps.encode(ss.read());
    }

    if (gps.location.isUpdated()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
        Serial.print("Altitude: ");
        Serial.println(gps.altitude.meters());
        Serial.print("Speed: ");
        Serial.println(gps.speed.kmph());
        Serial.print("Satellites: ");
        Serial.println(gps.satellites.value());
        Serial.print("HDOP: ");
        Serial.println(gps.hdop.value());
    }

    delay(1000);  // Wait for 1 second before reading again
}
