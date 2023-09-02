// This #include statement was automatically added by the Particle IDE.
#include <SPI.h>
#include <Arduino.h>
#include <StreamUtils.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <Adafruit_NeoPixel.h>
#include "arduino_secrets.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

////// Setting looping for checking API ///////
unsigned long previousMillis = 0;
unsigned long currentMillis = millis();
unsigned long period = 120000; // two minutes


////// Declaring NeoPixel variables. ///////////
#define ONBOARD_LED_PIN 18
#define ONBOARD_LED_COUNT 1
Adafruit_NeoPixel onboard_pixel(ONBOARD_LED_COUNT, ONBOARD_LED_PIN, NEO_GRB + NEO_KHZ800);
#define LED_PIN 17
#define LED_COUNT 11
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t LED_RED    = pixels.Color( 255, 0, 0);
const uint32_t LED_GREEN  = pixels.Color( 0, 255, 0);
const uint32_t LED_BLUE   = pixels.Color( 0, 0, 255);
const uint32_t LED_PURPLE = pixels.Color( 153, 0, 153);
const uint32_t LED_WHITE  = pixels.Color( 255, 255, 255);
const uint32_t LED_BROWN  = pixels.Color( 139, 69, 19);
const uint32_t LED_YELLOW = pixels.Color( 255, 255, 0);
const uint32_t LED_GRAY   = pixels.Color( 143, 188, 143);
const uint32_t LED_BLACK  = pixels.Color( 0, 0, 0);
uint32_t LED_BRIGHTNESS = 50; // 1-100
uint32_t LED_BRIGHTNESS_OFF = 0; // 1-100
uint32_t LED_HEALTH_BRIGHTNESS = 50; // 1-100
uint32_t LED_HEALTH_COLOR = LED_GREEN;
uint32_t LED_GROUND_COLOR = LED_GREEN;

// MAIN SETUP:
void setup() {
  // Serial port out: USED with <particle serial monitor>
  Serial.begin(115200);

  // Init ONBOARD_LED Strip of Pixels
  onboard_pixel.begin();
  onboard_pixel.show();
  // Init LED Strip of Pixels
  pixels.begin();
  pixels.show();
}

// MAIN LOOP:
int counter = 0;
void loop() {
  currentMillis = millis();
  Serial.println(++counter);
  ShowOnbaordPixel();
  ShowLEDPixels();
  delay(1000);
}

void ShowOnbaordPixel() {
  onboard_pixel.clear();
  onboard_pixel.setPixelColor(0, HEALTH_COLOR());
  onboard_pixel.setBrightness(LED_HEALTH_BRIGHTNESS);
  onboard_pixel.show();
}


void ShowLEDPixels() {
  pixels.clear();
  pixels.setPixelColor(0, GROUND_COLOR());
  GROUND_COLOR();
  pixels.setPixelColor(1, GROUND_COLOR());
  pixels.setBrightness(LED_BRIGHTNESS);
  pixels.show();
}

uint32_t GROUND_COLOR() {
  LED_GROUND_COLOR = (LED_GROUND_COLOR == LED_GREEN) ? LED_BLUE : LED_GREEN;
  return LED_GROUND_COLOR;
}

uint32_t HEALTH_COLOR() {
  LED_HEALTH_COLOR = (LED_HEALTH_COLOR == LED_GREEN) ? LED_BLACK : LED_GREEN;
  return LED_HEALTH_COLOR;
}
