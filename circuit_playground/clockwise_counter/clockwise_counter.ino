// Clockwise_counter
// basics of a clock function.
//
// Based off mega_demo by Tony DiCola
//
// Author: Nymunariya
// License: GNU GPLv3 (http://www.gnu.org/licenses/gpl-3.0.txt)

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>

int counter = 0;
int ticker = 0;

static int clockwise[10] = {9,8,7,6,5,4,3,2,1,0};

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(2);
}

void loop() {
  Serial.print("Counter: "); Serial.println(counter);
  Serial.print("Ticker: "); Serial.println(ticker);
  
  if( counter > 0 ) CircuitPlayground.setPixelColor(clockwise[counter - 1], 0xFF00FF);

  if( ticker != counter -1 ) CircuitPlayground.setPixelColor(clockwise[ticker], 0x0000FF);
  else CircuitPlayground.setPixelColor(clockwise[ticker], 0x00FF00);

  delay(1000);
  CircuitPlayground.clearPixels();
  
  if( ticker == 9 ) {
     ticker = 0;
     if( counter == 10 ) counter = 0;
     else counter++;
  } else ticker++;
}
