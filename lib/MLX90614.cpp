#include "MLX90614.h"

//constructor
MLX90614::MLX90614()
{
  //sets common values
  factor = 0.02; // MLX90614 has a resolution of .02
}
   
//modifies tempData into temperature in Kelvin
double MLX90614::getReading(int address, unsigned char ttype)
{
  int data_low, data_high, pec;
  double tempData

  tempData = 0x0000; //zero out the data
  Wire.beginTransmission(address); //begins transmission with device
  Wire.write(ttype); //sends register address to read
  Wire.endTransmission(0); //repeated start
     
  Wire.requestFrom(address, 3); //request three bytes from device
    
  while(Wire.available() <3); //wait for three bytes to become available
  data_low = Wire.read(); //read first byte
  
  data_high = Wire.read(); //read second byte
  pec = Wire.read(); //read checksum 
     
  Wire.endTransmission(); //terminate transmission
     
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  // Taken from bildr forum on MLX90614
  tempData = (double) (((data_high & 0x007F) << 8) + data_low);
  return (tempData * factor) - 0.01; //multiply by resolution and account for error to convert to Kelvin
}

//returns object temperature in degrees Celsius
float MLX90614::getObjTemp(int address)
{
  return (float) getReading(address, TEMP_OBJ) - 273.15; //convert from Kelvin to Celsius
}

//returns ambient temperature in degrees Celsius
float MLX90614::getAmbTemp(int address)
{
  return (float) getReading(address, TEMP_AMB) - 273.15; //convert from Kelvin to Celsius
}
