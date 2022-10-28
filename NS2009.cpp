#include <Wire.h>
#include "NS2009.h"

NS2009::NS2009 (void)
{
  Address = DEFAULT_NS2009_ADDR;
  FlipX = false;
  FlipY = false;
}

NS2009::NS2009 (unsigned char _Address)
{
  Address = _Address;
  FlipX = false;
  FlipY = false;
}

NS2009::NS2009 (bool _FlipX, bool _FlipY)
{
  Address = DEFAULT_NS2009_ADDR;
  FlipX = _FlipX;
  FlipY = _FlipY;
}

NS2009::NS2009 (unsigned char _Address, bool _FlipX, bool _FlipY)
{
  Address = _Address;
  FlipX = _FlipX;
  FlipY = _FlipY;
}

unsigned int NS2009::ReadRegister(unsigned char Command)
{
  unsigned char ReadData[2], i=0;
  Wire.beginTransmission(Address);
  Wire.write(&Command, 1);
  Wire.endTransmission();
  Wire.requestFrom(Address, 2);
  while (Wire.available())
    ReadData[i++] = Wire.read();
  return (ReadData[0] << 4) | (ReadData[1] >> 4);
}

void NS2009::Scan()
{
  Touched = (ReadRegister(NS2009_READ_Z) > THRESHOLD_Z);
  X = ReadRegister(NS2009_READ_X) * SCREEN_X_PIXEL / 4096;
  Y = ReadRegister(NS2009_READ_Y) * SCREEN_Y_PIXEL / 4096;
  if (FlipX)
    X = SCREEN_X_PIXEL - X;
  if (FlipY)
    Y = SCREEN_Y_PIXEL - Y;
}
