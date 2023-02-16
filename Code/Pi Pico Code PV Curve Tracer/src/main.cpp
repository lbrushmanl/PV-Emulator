#include <Arduino.h>
#include <SPI.h>

//Conversion Factors
#define CURRENT_CONVERSION_FACTOR 0.0008058608
//Pins
#define CURRENT_ADC A0
#define VOLTAGE_ADC A1
#define CS 17

uint16_t level = 0;
uint16_t  freq = 1000;
uint32_t  period = 0;

void write(uint16_t data);

void setup() 
{
  pinMode(CS, OUTPUT);
  analogReadResolution(12);
  SPI.begin();
}

void loop() 
{
  uint32_t now = micros();
  uint32_t t = now % period;

  period = 1e6 / freq;
  write(t * 4095 / period);
  level++;

  if (level == 4095) {
    level = 0;
    delay(1);
  }
}

void write(uint16_t data)
{
  digitalWrite(CS, LOW);
  SPI.transfer16(0x3000 | data);
  digitalWrite(CS, HIGH);
}

void setup1() 
{
  Serial.begin(9600);
}

void loop1()
{
  double current = analogRead(CURRENT_ADC) * CURRENT_CONVERSION_FACTOR;
  Serial.print(current);
  Serial.print("\n");
}