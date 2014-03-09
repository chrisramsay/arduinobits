/*
    This file is part of the arduinobits library.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    ***************************************************************************

    This forms the main class for enabling the Arduino to read data from
    the Melexis MLX90614 Infra Red thermometer for non contact temperature 
    measurements.

    Many items herein originated in Lara Booth's 2012 NanoSatisfi library.
    https://github.com/ArduSat/video-tutorials/tree/master/NanoSatisfi_MLX90614
    I have added a little more functionality where required

    ***************************************************************************
*/
#include "MLX90614.h"

//constructor
MLX90614::MLX90614()
{
  //sets common values
  factor = 0.02; // MLX90614 has a resolution of .02
}
   
// Get the reading from the sensor
double MLX90614::getReading(int address, unsigned char ttype)
{
  int data_low, data_high, pec;
  double tempData;

  tempData = 0x0000;
  // Begin transmission with device
  Wire.beginTransmission(address);
  // Send register address to read - 0x06 for ambient, 0x07 for object
  Wire.write(ttype);
  // The 'mysterious' repeated start
  Wire.endTransmission(0);
  // Request three bytes from device
  Wire.requestFrom(address, 3); 
    
  // Wait for three bytes to become available
  while(Wire.available() <3);
  // Read first byte
  data_low = Wire.read();
  // Read second byte
  data_high = Wire.read();
  // Read checksum 
  pec = Wire.read();
  // Terminate transmission
  Wire.endTransmission();
     
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  // Taken from bildr forum on MLX90614
  tempData = (double) (((data_high & 0x007F) << 8) + data_low);
  // Multiply by resolution and account for error to convert to Kelvin
  return (tempData * factor) - 0.01;
}

// Returns object temperature in degrees Celsius
float MLX90614::getObjTemp(int address)
{
  return (float) getReading(address, TEMP_OBJ) - 273.15;
}

// Returns ambient temperature in degrees Celsius
float MLX90614::getAmbTemp(int address)
{
  return (float) getReading(address, TEMP_AMB) - 273.15;
}
