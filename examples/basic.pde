#include <Wiegand.h>

// door lock open
#define DoorLockPin 13;

// wiegand reader pins
#define ReaderData0 2;
#define Readerdata1 3;

// wiegand library
Wiegand wiegand(ReaderData0, ReaderData1, { 196, 452 }, { 15809, 3285 });

// setup
void setup()
{
	// attach interrupts to wiegand reader
	attachInterrupt(ReaderData0, wzero, RISING);
	attachInterrupt(ReaderData1, wone, RISING);

	// setup wiegand reader
	wiegand.Setup();
}

// setup passthrough interrupt
void wzero(){ wiegand.ReadZero(); }
void wone(){ wiegand.ReadOne(); }

// the loop
void loop()
{
	if (wiegand.Read())
	{
		digitalWrite(DoorLockPin, HIGH);

		delay(2000);

		digitalWrite(DoorLockPin, LOW);
	}
}


