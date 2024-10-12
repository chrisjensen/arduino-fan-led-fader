#include <FastLED.h>

// How many leds in 1 fan
// If you chain multiple fans they will have their 8 LED's in sync
#define NUM_LEDS 8

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN

// Which PIN on the Arduino is sending data?
#define DATA_PIN 3
#define CLOCK_PIN 13
#define LED_TYPE WS2811

// Hues
// Below are some different hue groups to choose from, or define your own
// See reference for colour values:
// https://github.com/FastLED/FastLED/wiki/Pixel-reference#setting-hsv-colors-

// Greenish
// #define MIN_HUE 40
// #define MAX_HUE 130
// #define HUE_OFFSET 0

// Warm and cool colours
// #define MIN_HUE 60
// #define MAX_HUE 255
// #define HUE_OFFSET 60

// Warm colours
#define MIN_HUE 110
#define MAX_HUE 255
#define HUE_OFFSET 80

// Ice
// #define MIN_HUE 130
// #define MAX_HUE 192
// #define HUE_OFFSET 0

// Higher means slower change in colours
#define BLEND_SPEED_MS 125

// Define the array of leds
CRGB leds[NUM_LEDS];
// For cross fading we need to know the colours 
// we're going from and to
// Start value of the fade
CHSV start[NUM_LEDS];
// End value of the fade
CHSV target[NUM_LEDS];

// Each LED can cross fade at different timings
// This array holds what step of the fade each LED is at
unsigned short steps[NUM_LEDS];

// How many steps should an LED increment each cycle?
unsigned short increment[NUM_LEDS];

unsigned short brightness;
unsigned short saturation;
static uint8_t hue = 0;


void setup() {
  Serial.begin(57600);
  Serial.println("resetting");
  // Setup the LED library
  FastLED.addLeds<LED_TYPE, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

  for (int i = 0; i < NUM_LEDS; i++) {
    target[i] = CHSV(random(MIN_HUE, MAX_HUE) + HUE_OFFSET, 255, 255);
    reset(i);
  }
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); }
}

/**
 * Set a new crossfade target for the LED at index i
 */
void reset(int i) {
  // Serial.println("resetting " +String(start[i].h) + ' ' + String(target[i].h));
  start[i] = target[i];

  brightness = 255;
  // Randomise brightness (results in dimmer lights)
  // if (random(0,8) < 1) {
  //   brightness = random(190,255);
  // }
  saturation = 255;
  // saturation = random(120,255);

  // Choose the target hue
  hue = random(MIN_HUE, MAX_HUE) + HUE_OFFSET;
  
  target[i] = CHSV(hue, saturation, brightness);

  // Reset to step 0 in the crossfade
  steps[i] = 0;
  // Select how many steps will be taken each cyle
  // (higher number = faster cross fade)
  increment[i] = random(1, 15);
  // Serial.println(String(start[i].h)+ ' ' + String(target[i].h));
}

void loop() {
  // Serial.print("x");
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++) {

    // If the LED has reached the last step
    // set a new target for it
    if (steps[i] == 255) reset(i);

    // Choose the colour that is steps[i] of the way between
    // start and target colours
    leds[i] = blend(start[i], target[i], steps[i], SHORTEST_HUES);

    // Increment to the next step
    // but don't go over 255 or we'll wrap around to 0
    // and the crossfade will get jumpy
    steps[i] = min(255, steps[i] + increment[i]);
    // Serial.println(String(steps[i]));
  }
  // Update all the LED values
  FastLED.show();
  delay(BLEND_SPEED_MS);
}
