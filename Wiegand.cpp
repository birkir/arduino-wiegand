/*
  Wiegand.h - Library for reading RFID Wiegand protocol.
  Created by Birkir R Gudjonsson, July 16, 2012.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Wiegand.h"

// long Reader
volatile long Reader = 0;

// int ReaderCount
volatile int ReaderCount = 0;

/**
 * Wiegand init
 *
 * @return void
 */
Wiegand::Wiegand(int Data0, int Data1, int ValidSiteCodes[], int ValidSerialNumbers[])
{
	// Data pins
	_Data0 = Data0;
	_Data1 = Data1;

	// Set valid numbers
	ValidSiteCodes[] = ValidSiteCodes;
	ValidSerialNumbers[] = ValidSerialNumbers;
}

/**
 * Setup
 *
 * @return void
 */
void Wiegand::Setup()
{
	// delay 10ms
	delay(10);

	// send some stuff to Data0
	pinMode(Data0, OUTPUT);
	digitalWrite(Data0, HIGH);
	digitalWrite(Data0, LOW);
	pinMode(Data0, INPUT);
	pinMode(Data0, HIGH);

	// send some stuff to Data1
	pinMode(Data1, OUTPUT);
	digitalWrite(Data1, HIGH);
	digitalWrite(Data1, LOW);
	pinMode(Data1, INPUT);
	pinMode(Data1, HIGH);

	// delay 10ms
	delay(10);

	// Reset reader and reader count
	Reader = 0;
	ReaderCount = 0;
}

/**
 * Read from protocol
 *
 * @return bool
 */
bool Wiegand::Read()
{
	if (ReaderCount >=26)
	{
		int SerialNumber = (Reader >> 1) & 0x3fff;
		int SiteCode = (Reader >> 17) & 0x3ff;

		Reader = 0;
		ReaderCount = 0;

		if (Wiegand::IsTagValid(SiteCode, SerialNumber))
		{
			return true;
		}

		return false;
	}
}

/**
 * Check if tag is valid
 *
 * @param int
 * @param int
 * @return bool
 */
bool Wiegand::IsTagValid(int siteCode, int serialNumber)
{
	boolean valid = false;

	int validTagCount = sizeof(validSiteCodes) / sizeof(int);

	for (int t = 0; t < validTagCount; t++)
	{
		if (validSiteCodes[t] == siteCode && validSerialNumbers[t] == serialNumber)
		{
			valid = true;
			break;
		}
   }

   return valid;
}

/**
 * Read One bit
 *
 * @return void
 */
void Wiegand::ReaderOne(void)
{
	ReaderCount++;
	Reader = Reader << 1;
	Reader |= 1;
}

/**
 * Read Zero bit
 *
 * @return void
 */
void Wiegand::ReaderZero(void)
{
	ReaderCount++;
	Reader = Reader << 1;
}
