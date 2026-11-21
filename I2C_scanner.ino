/*===================================================================
                      I2C DEVICE SCANNER
=====================================================================
Description:
  This program identifies devices connected to the I²C bus by scanning 
  all valid addresses and returning the addresses of detected devices.

Programmer:
  Felicity M. De Asis
  Shanna Dale R. Dela Torre
  Rhile L. Galpo

Date:
  10 Nov 2026
---------------------------------------------------------------------*/
#include <Wire.h>

// GPIOs
const uint8_t SDA_PIN = 21;
const uint8_t SCL_PIN = 22;

// Variables
bool device_found = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
}

void I2C_scanner(){
  Serial.println("\nScanning...");

  // 7-bit address
  for(byte address = 1; address < 127; address++) {
  //------------------------------------------------------------------- 
    // Set the target I2C slave address
    Wire.beginTransmission(address);

    // Sends START > SLAVE ADDRESS > WAIT ACK (slave returns 0 for acknowledgment)
    if(Wire.endTransmission() == 0) {
      device_found = true;
      Serial.printf("Found device at 0x%02X\n", address);
    }
  //--------------------------------------------------------------------
  }

  if (!device_found)
    Serial.println("No I2C device found.");
}

void loop() {
  I2C_scanner();
  delay(5000);
}