#include <MLX90614.h>
#include <Wire.h>

MLX90614 mlx;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    Serial.println("Setup.");
}

void loop() {
    // Set device address (0x55 is the factory set default address)
    measure(0x55);
    // Wait a little
    delay(2000);

    measure(0x5A);
    // Wait a little
    delay(2000);
}

void measure(int address) {
	// Show which one we are measuring
	Serial.print("Sensor ID: ");
	Serial.print(address);
    // Get object temperature
    Serial.print(", Object temp: ");
    Serial.print(mlx.getObjTemp(address));
    Serial.print(" C");
    // Get ambient temperature
    Serial.print(", Ambient temp: ");
    Serial.print(mlx.getAmbTemp(address));
    Serial.println(" C");	
}