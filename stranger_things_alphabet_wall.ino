// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      26

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int halfSecond = 500; // delay for half a second
int twoSeconds = 2000;
int twoMinutes = 120000; // delay for 2 seconds
int fifteenMinutes = 900000; // delay for 15 minutes

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

// Defining the word to be spelled
// SNAKE = 18,13,0,10,4
int arr[] = {18, 11, 0, 14, 4};

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  while(true) {
    for(int letter: arr){
        pixels.setPixelColor(letter, pixels.Color(255,255,255));
        pixels.show();
        delay(twoSeconds);
        pixels.setPixelColor(letter, pixels.Color(0,0,0));
    }
 
    // delay(twoMinutes);
    allLightsOn();
    delay(fifteenMinutes);
    allLightsOff();
    delay(halfSecond);
    allLightsOn();
    delay(halfSecond);
    allLightsOff();
    delay(halfSecond);
    allLightsOn();
    delay(halfSecond);
    allLightsOff();
    delay(halfSecond);
    allLightsOn();
    delay(halfSecond);
    allLightsOff();
    delay(twoSeconds);
  }
}

void displayWord() {
  for(int letter: arr){
        pixels.setPixelColor(letter, pixels.Color(255,255,255));
        pixels.show();
        delay(twoSeconds);
        pixels.setPixelColor(letter, pixels.Color(0,0,0));
    }
}

// Turn on all lights on for wait time
void allLightsOn(){
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(155,155,155)); // Moderately bright white color.
    pixels.show();
  }
  // pixels.show(); // This sends the updated pixel color to the hardware.
  // delay(wait); // Delay for a period of time (in milliseconds).

}

// Turn on all lights off for wait time
void allLightsOff(){
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, 0); // No color.
    pixels.show();
  }
  // pixels.show(); // This sends the updated pixel color to the hardware.
  // delay(wait); // Delay for a period of time (in milliseconds).

}
