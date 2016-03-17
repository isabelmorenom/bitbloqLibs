#ifndef LINEFOLLOWER_h
#define LINEFOLLOWER_h
#include "Arduino.h"

class LineFollower
{
public:
	LineFollower();
	LineFollower(int pinLeft, int pinRight);
	void init (int pinLeft, int pinRight);
	int * read();
	int readLeftSensor();
	int readRightSensor();
private:
	int _pinLeft;
	int _pinRight;
};

#endif //LINEFOLLOWER_h