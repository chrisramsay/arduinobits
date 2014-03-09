#include <MLX90614.h>
#include <Wire.h>

MLX90614 mlx;

void setup() {
	Serial.begin(9600);
    Wire.begin();
	Serial.println("Setup.");
}

void loop() {
	float celsius = 0;
    int address = 0x55;
    celsius = mlx.getObjTemp(address);
    Serial.print("Temperature: ");
    Serial.print(celsius);
    Serial.println(" C");
    delay(1000);
}