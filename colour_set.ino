// Colour_set
// Set the rgb colour, based on capacitative inputs
// on pins 3 (red), 1 (green), and 12 (blue)
//
// Based off mega_demo by Tony DiCola, and color_sense by Limor Fried & Tony DiCola
//
// Author: Nymunariya
// License: GNU GPLv3 (http://www.gnu.org/licenses/gpl-3.0.txt)

#include <Adafruit_CircuitPlayground.h>

int red = 0;
int green = 0;
int blue = 0;
uint8_t pixeln = 0;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  
}

void loop() {
  /************* TEST CAPTOUCH */
  Serial.print("Red: "); Serial.println(CircuitPlayground.readCap(3));
  //Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  
  //Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  Serial.print("Green: "); Serial.println(CircuitPlayground.readCap(1));

  
  Serial.print("Blue #12: "); Serial.println(CircuitPlayground.readCap(12));
  //Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  
  //Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));

  if( CircuitPlayground.readCap(3) > 255 ) {
     red = 255;
  } else {
     red = CircuitPlayground.readCap(3);
  }

  if( CircuitPlayground.readCap(1) > 255 ) {
     green = 255;
  } else {
     green = CircuitPlayground.readCap(1);
  }

  if( CircuitPlayground.readCap(12) > 255 ) {
     blue = 255;
  } else {
     blue = CircuitPlayground.readCap(12);
  }
  
  for (int i=0; i<10; ++i) {                                    //for smooth colouring
    CircuitPlayground.strip.setPixelColor(i, red, green, blue);
  }
  CircuitPlayground.strip.show();
  
  //CircuitPlayground.setPixelColor(pixeln++, red, green, blue);  //for erratic colouring
  //if (pixeln == 11) {
  //  pixeln = 0;
  //  CircuitPlayground.clearPixels();
  //}

}
