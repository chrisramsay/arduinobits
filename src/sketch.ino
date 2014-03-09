#include <MLX90614.h>
#include <Wire.h>

MLX90614 mlx;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    Serial.println("Setup.");
}

void loop() {
    // Set device address
    int address = 0x55;
    // Get object temperature
    Serial.print("Object temp : ");
    Serial.print(mlx.getObjTemp(address));
    Serial.println(" C");
    // Get ambient temperature
    Serial.print("Ambient temp: ");
    Serial.print(mlx.getAmbTemp(address));
    Serial.println(" C");
    delay(1000);
}