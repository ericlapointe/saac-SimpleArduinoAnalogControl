/*
  SimpleArduinoAnalogControl.cpp - Return the value of an analog input based on the maximum
  Created by Eric Lapointe, February 2, 2015
*/

#include "Arduino.h"
#include "SimpleArduinoAnalogControl.h"

SimpleArduinoAnalogControl::SimpleArduinoAnalogControl()
  {
  }

SimpleArduinoAnalogControl::SimpleArduinoAnalogControl(int pin, float maxValue, int mode)
  {
  pinMode(pin, INPUT);
  mSimpleArduinoAnalogControl = pin;
  mMaxValue = maxValue;
  mDebug = 0;
  mMode = mode;
  SetSensorName('x', 'y', 'z');
  }

void SimpleArduinoAnalogControl::InitSaac(int pin, float maxValue, int mode)
  {
  pinMode(pin, INPUT);
  mSimpleArduinoAnalogControl = pin;
  mMaxValue = maxValue;
  mDebug = 0;
  mMode = mode;
  SetSensorName('x', 'y', 'z');
  }

void SimpleArduinoAnalogControl::InitSaac(int pin, float maxValue, int mode, char c1, char c2, char c3)
  {
  pinMode(pin, INPUT);
  mSimpleArduinoAnalogControl = pin;
  mMaxValue = maxValue;
  mDebug = 0;
  mMode = mode;
  SetSensorName(c1, c2, c3);
  }

float SimpleArduinoAnalogControl::Read()
  {
  float fRead;
  mLastRead = analogRead(mSimpleArduinoAnalogControl);
  if (mDebug)
    {
    Serial.print("Reading ");
    Serial.print(cSensorName);
    Serial.print(" (Atmel Pin ");
    Serial.print(mSimpleArduinoAnalogControl);
    Serial.print("), RAW value is: ");
    Serial.print(" ");
    Serial.print(mLastRead);
    Serial.print("\n");
    delay(10);
    }
  fRead = mLastRead * (mMaxValue / 1023.0);
  if (mMode == MODE_DESC)
    {
    fRead = mMaxValue - fRead;
    }
  if (mDebug)
    {
    Serial.print("Reading ");
    Serial.print(cSensorName);
    Serial.print(" (Atmel Pin ");
    Serial.print(mSimpleArduinoAnalogControl);
    Serial.print("), Ajusted value is: ");
    Serial.print(" ");
    Serial.print(fRead);
    Serial.print("\n");
    delay(10);
    }
  return fRead;
  }

void SimpleArduinoAnalogControl::SetSensorName(char c1, char c2, char c3)
  {
  cSensorName[0] = c1;
  cSensorName[1] = c2;
  cSensorName[2] = c3;
  cSensorName[3] = 0;
  }

void SimpleArduinoAnalogControl::EnableDebug()
  {
  mDebug = 1;
  Serial.begin(9600);
  }

void SimpleArduinoAnalogControl::DisableDebug()
  {
  mDebug = 0;
  }

