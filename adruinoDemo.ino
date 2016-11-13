#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

char text[] = "HELLO NICK";

//declare the matrix (height, width, pin ...
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, 6,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  //rainbow colors
  matrix.Color(148, 0, 211), //violet
  matrix.Color(0, 0, 255), //blue
  matrix.Color(0, 255, 0), //green
  matrix.Color(255, 255, 0), //yellow
  matrix.Color(255, 127, 0), //orange
  matrix.Color(255, 0, 0) //red
};

/* 
  ramdom colors -- work in progress
  const uint16_t colors[] = {
  matrix.Color(random(0, 255), random(0, 255), random(0, 255))
  }
*/

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(5);
  matrix.setTextColor(colors[0]);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(text);
  //6 pixels per character
  if(--x < -66) {
    x = matrix.width();
    //reset if at end of array
    //hard coded because sizeof doesn't work??? int sizeOfColors = sizeof(colors) - 1;
    if(++pass >= 6) {
      pass = 0;
    }
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  Serial.print(sizeof(colors));
  delay(50);
}
