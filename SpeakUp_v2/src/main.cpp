#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

const int buttonPin = D3;     // the number of the pushbutton pin

int buttonState = 0;         // variable for reading the pushbutton status

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // I2C Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay(); 
  display.setTextSize(1);                    // Set for small font
  display.setTextColor(WHITE);
  display.setCursor(0,0);                    // Set cursor to upper left
  display.println("Please click the");
  display.println("button to get a");
  display.println("phone number");

  display.display();
}

void loop() {

    buttonState = digitalRead(buttonPin);

Serial.println(buttonState);

  if (buttonState == 0) {
    display.println("     (719)838-4828");
    display.display();
  } 

  delay(100);
}