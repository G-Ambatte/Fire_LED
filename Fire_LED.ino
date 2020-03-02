#include <Adafruit_NeoPixel.h>
#include "parameters.h"

// Create the LED Strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Create a timer
unsigned long timer;

void setup() {

  strip.begin();
  strip.setBrightness(128);

}

void loop() {

  // If the timer has expired
  if ( millis() > timer ) {

    // Set a new timer
    timer = millis() + random(TIMER_MIN, TIMER_MAX);

    // Update the strip with a new set of randomised colors
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i,
                          random(LED_R_MIN, LED_R_MAX),
                          random(LED_G_MIN, LED_G_MAX),
                          random(LED_B_MIN, LED_B_MAX)
                         );
    }
    strip.show();
  }
}
