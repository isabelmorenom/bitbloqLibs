#include "BitbloqUS.h"

//****** US ******//
US::US(){
}

US::US(int pinTrigger, int pinEcho, unsigned long timeOut){
  US::init(pinTrigger,pinEcho, timeOut);
}

void US::init(int pinTrigger, int pinEcho, unsigned long timeOut)
{
  _pinTrigger = pinTrigger;
  _pinEcho = pinEcho;
  _timeOut = timeOut;
  pinMode( _pinTrigger , OUTPUT );
  pinMode( _pinEcho , INPUT );
}

long US::TP_init()
{
    pinMode(_pinTrigger,OUTPUT); // this is required for those cases in which echo and trigger pin are the same
    digitalWrite(_pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pinTrigger, LOW);
    pinMode(_pinEcho,INPUT); // this is required for those cases in which echo and trigger pin are the same
    long microseconds = pulseIn(_pinEcho,HIGH,_timeOut);
    delay(29);
    return microseconds;
}

float US::read(){
  long microseconds = US::TP_init();
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = _timeOut/29/2;
  }
  return distance;
}

void US::setTimeOut(unsigned long timeOut){
  _timeOut = timeOut;
}
