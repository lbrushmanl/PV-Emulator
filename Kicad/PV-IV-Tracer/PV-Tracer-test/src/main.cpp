#include <Arduino.h>
#include <SPI.h>

#define CS 11

#define CURRENT_ADC A0
#define VOLTAGE_ADC A1

void write(uint16_t);

int main()
{
  init();

  pinMode(CS, OUTPUT);
  Serial.begin(9600);
  SPI.begin();

  uint16_t level = 0;
  uint16_t  freq = 1000;
  uint32_t  period = 0;

  while(1)
  {
    // uint32_t now = micros();
    // uint32_t t = now % period;

    // uint32_t  period = 1e6 / freq;
    // write(t * 4095 / period);
    // Serial.println(level);
    level++;

    write(level);
    if (level == 4095) {
      level = 0;
      delay(10);
    }
  }

  return 0;
}

void write(uint16_t data)
{
  digitalWrite(CS, LOW);
  SPI.transfer16(0x3000 | data);
  digitalWrite(CS, HIGH);
}