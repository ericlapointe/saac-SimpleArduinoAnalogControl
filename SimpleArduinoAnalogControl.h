/*
  SimpleArduinoAnalogControl.h - 
  Created by Eric Lapointe, February 2, 2015
*/

#ifndef SimpleArduinoAnalogControl_h
#define SimpleArduinoAnalogControl_h

#define MODE_ASC  0
#define MODE_DESC 1

#include "Arduino.h"

class SimpleArduinoAnalogControl
  {
  public:
    SimpleArduinoAnalogControl();
    SimpleArduinoAnalogControl(int pin, float maxValue, int mode);
    void InitSaac(int pin, float maxValue, int mode);
    void InitSaac(int pin, float maxValue, int mode, char c1, char c2, char c3);
    float Read();
    void SetSensorName(char c1, char c2, char c3);
    void EnableDebug();
    void DisableDebug();

  private:
    int mSimpleArduinoAnalogControl;
    char cSensorName[4];
    float mMaxValue;
    byte mDebug;
    byte mMode;
    int mLastRead;
  };

#endif //SimpleArduinoAnalogControl_h

