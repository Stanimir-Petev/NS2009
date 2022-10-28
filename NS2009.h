#ifndef _NS2009_H_
#define _NS2009_H_

#define DEFAULT_NS2009_ADDR 0x48 //10010000
#define THRESHOLD_Z 10  // this is a threshold value on how hard the touch screen must be touched to react

#define NS2009_READ_X 0xC0
#define NS2009_READ_Y 0xD0
#define NS2009_READ_Z 0xE0

#define SCREEN_X_PIXEL 240
#define SCREEN_Y_PIXEL 320

class NS2009
{
  int Address;
  bool FlipX, FlipY;
  unsigned int ReadRegister(unsigned char Command);
public:
  int X, Y;
  bool Touched;
  NS2009 (void);
  NS2009 (unsigned char _Address);
  NS2009 (bool _FlipX, bool _FlipY);
  NS2009 (unsigned char _Address, bool _FlipX, bool _FlipY);
  void Scan();
};
#endif
