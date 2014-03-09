/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef MLX90614_h
#define MLX90614_h

#include "Arduino.h"

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
  void getReading(int address, int ttype);
  
  //global variable
  double factor;
  double tempData;
 
};

#endif