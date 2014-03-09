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

    This forms header enabling the Arduino to read data from the Melexis
    MLX90614 Infra Red thermometer for non contact temperature measurements.

    Many items herein originated in Lara Booth's 2012 NanoSatisfi library.
    https://github.com/ArduSat/video-tutorials/tree/master/NanoSatisfi_MLX90614
    I have added a little more functionality where required

    ***************************************************************************
*/

#ifndef MLX90614_h
#define MLX90614_h

#include <Arduino.h>
#include <Wire.h>

#define TEMP_AMB 0x06
#define TEMP_OBJ 0x07

class MLX90614
{
  public:
  //constructor
  MLX90614(); 
    
  //public methods
  float getAmbTemp(int address);
  float getObjTemp(int address);
   
  private:
  //class-only methods
  double getReading(int address, unsigned char ttype);
  
  //global variable
  double factor;
 
};

#endif