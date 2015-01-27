// Do not remove the include below
#include "IMU.h"
#include <ITG3200.h>
#include <Arduino.h>
#include <Wire.h>

//The setup function is called once at startup of the sketch

ITG3200 gyro;
int x;
int y;
int z;
void setup() {
	Serial.begin(115200);
	gyro = ITG3200();
	gyro.init(ITG3200_ADDR_AD0_HIGH);
	Serial.println("Calibrating Gyro...");
	gyro.zeroCalibrate(1000, 2);
}

// The loop function is called in an endless loop
void loop() {
	delay(2000);
	gyro.readGyroRawCal(&x, &y, &z);
	Serial.print(x);
	Serial.print(" ");
	Serial.print(y);
	Serial.print(" ");
	Serial.print(z);
	Serial.print("\n");
}
