/*
	Simple example for NS2009 touch screen.
	On the terminal will be printed the coordinates of the point where the touch screen is pressed.
	You can choose different constructor for the TS object based on which address your NS2009 has (default being 0x48)
	and whether or not you want to invert the X and/or Y axis.

  There are 2 methods for calibration:
  1) no parameters - in this case you have to touch the display in 2 opposite corners of the screen
  2) pass the data as 4 parameters for the min/max x/y - they could be empirically derived through measurement of the NS2009 registers from I2C reading
  if not a default values are set in the NS2009.h header file
*/

#include <Wire.h>
#include "NS2009.h"

// choose constructor that fits your needs
NS2009 TS;                                      // address is the default one (0x48), no flip around X and Y axis
//NS2009 TS(DEFAULT_NS2009_ADDR);               // address is the selected one, no flip around X and Y axis
//NS2009 TS(true, false);                       // address is the default one (0x48), X axis is flipped, Y is not
//NS2009 TS(DEFAULT_NS2009_ADDR, false, true);  // address is the selected one, X axis not flipped, Y is flipped

void setup()
{
  Serial.begin(115200);
  delay (500);
  Wire.begin();
  //TS.Calibrate ();                          // touch 2 of the opposite corners to gain values and calibrate the touch screen
  //TS.Calibrate (200, 3850, 400, 3920);      // alternatively you can set a constant values for MinX, MaxX, MinY, MaxY from I2C reading of the registers of the NS2009
}

void loop()
{
  TS.Scan ();
  if (TS.Touched)
  {
    Serial.printf("X=%3.d, RawX=%4d;     Y=%3.d RawY=%4d\n\r", TS.X, TS.RawX, TS.Y, TS.RawY);
    delay (50);
  }
}