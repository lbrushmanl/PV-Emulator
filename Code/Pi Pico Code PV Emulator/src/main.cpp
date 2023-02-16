//Trying this panel we have at uni https://www.farnell.com/datasheets/41421.pdf

#include <Arduino.h>
#include <SPI.h>

#define VOLTAGE A0
#define CS 17

#define CONV 0.01074402363 //40V = 3V

#define Voc 21.5f
#define Isc 0.6f
#define Vm 17.0f
#define Im 0.55f

double C2Voc  = 0;
double C1 = 0;

void setup() 
{
  pinMode(CS, OUTPUT);
  analogReadResolution(12);
  SPI.begin();

  double C2 = ((Vm/Voc) - 1) / (log(1 - (Im / Isc)));
  C1 = (1 - (Im / Isc)) * exp((-Vm) / (C2 * Voc));
	C2Voc = C2 * Voc;
}

void loop()
{
  double outputCurrent = Isc * (1 - C1 * (exp((analogRead(VOLTAGE) * CONV) / C2Voc) - 1));

  digitalWrite(CS, LOW);
  SPI.transfer16(0x3000 | (uint16_t) (outputCurrent * 1240.9));
  digitalWrite(CS, HIGH);
}

//With no calculations 0.6us
//With double based calculations 8.5us