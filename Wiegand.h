/*
  Wiegand.h - Library for reading RFID Wiegand protocol.
  Created by Birkir R Gudjonsson, July 16, 2012.
  Released into the public domain.
*/
#ifndef Wiegand_h
#define Wiegand_h

#include "Arduino.h"

class Wiegand
{
  public:
    Wiegand(int Data0, int Data1, int ValidSiteCodes[], int ValidSerialNumbers[]);
    void Setup;
    void ReaderOne;
    void ReaderZero;
    bool Read;
    bool IsTagValid;
  private:
    long Reader;
    int ReaderCount;
    int _Data0;
    int _Data1;
    int _ValidSiteCodes[];
    int _ValidSerialNumbers[];
};

#endif
