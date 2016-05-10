#include <Arduino.h>
#include <TM1637Display.h>

// read a poti on A0 and give out the value U[V]

#define CLK 2
#define DIO 3
#define TEST_DELAY   2000



TM1637Display display(CLK, DIO);
int cnt;
int led = 13;
const int analogInPin = A0; 
int sensorValue = 0;

void setup()
{
    pinMode(led, OUTPUT);
    display.setBrightness(0x0f);
    display.showNumberDec(7234, false, 4, 0);
    cnt=0;
    
}

void loop()
{
  sensorValue = analogRead(analogInPin); 
  cnt = map(sensorValue, 0, 1023, 0, 500); 
  
  digitalWrite(led, HIGH);   
  delay(300);          
  display.showNumberDec(cnt, false, 4, 0);
  digitalWrite(led, LOW);   
  delay(300);                
}
