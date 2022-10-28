/*
	Simple example for NS2009 touch screen.
	On the terminal will be printed the coordinates of the point where the touch screen is pressed.
	You can choose different constructor for the TS object based on which address your NS2009 has (default being 0x48)
	and whether or not you want to invert the X and/or Y axis.
*/

#include <Wire.h>
#include <NS2009.h>

// choose constructor that fits your needs
NS2009 TS;                                      // address is the default one (0x48), no flip around X and Y axis
//NS2009 TS(DEFAULT_NS2009_ADDR);               // address is the selected one, no flip around X and Y axis
//NS2009 TS(true, false);                       // address is the default one (0x48), X axis is flipped, Y is not
//NS2009 TS(DEFAULT_NS2009_ADDR, false, true);  // address is the selected one, X axis not flipped, Y is flipped

void setup()
{
  Serial.begin(115200);
  Wire.begin();
}

void loop()
{
  TS.Scan ();
  if (TS.Touched)
  {
    Serial.printf("%3.d (0x%2.X)  %3.d (0x%3.X)\n", TS.X, TS.X, TS.Y, TS.Y);
    delay (50);
  }
}