#include "libNixieModule.h"
#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define ADDR0 0x4E
#define ADDR1 0x4C
#define PIN_LED 5

NixieModule_IN_12 nix0 = NixieModule_IN_12(ADDR0);
NixieModule_IN_14 nix1 = NixieModule_IN_14(ADDR1);

// NixieModule_IN_12 nix1 = NixieModule_IN_14(ADDR1);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN_LED, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("nix module IN-12 Single Tube Demo");
  nix0.init();
  nix0.setTransitionMode(TMODE_NORMAL);
  nix0.setBrightness(0.3);
 
  nix1.init();
  nix1.setTransitionMode(TMODE_NORMAL);
  nix1.setBrightness(0.3);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t step = 100;
  Serial.println("Normal transition mode");

  nix0.setTransitionMode(TMODE_NORMAL);
  nix1.setTransitionMode(TMODE_NORMAL);
  for(int i=0; i<10; i++){
    Serial.println(i);
    nix0.setNumber(i, step);
    nix1.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix0.update();
      nix1.update();
      delay(10);
    }
  }

  Serial.println("Crossfade mode");
  delay(1000);
  nix0.setTransitionMode(TMODE_FADE);
  nix1.setTransitionMode(TMODE_FADE);

  for(int i=0; i<10; i++){
    Serial.println(i);
    nix0.setNumber(i, step);
    nix1.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix0.update();
      nix1.update();
      delay(10);
    }
  }

  step = 50;
  Serial.println("Shuffle mode");
  delay(1000);

  nix0.setTransitionMode(TMODE_SHUFFLE);
  nix1.setTransitionMode(TMODE_SHUFFLE);
  for(int i=0; i<10; i++){
    Serial.println(i);
    nix0.setNumber(i, step);
    nix1.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix0.update();
      nix1.update();
      delay(4);
    }

    delay(500);
  }

  delay(1000);
}
