#include "libNixieModule.h"
#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define ADDR0 0x4C
#define PIN_LED 5

NixieModule_IN_14 nix = NixieModule_IN_14(ADDR0);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN_LED, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("nix module IN-14 Single Tube Demo");
  nix.init();
  nix.setTransitionMode(TMODE_NORMAL);

}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t step = 100;
  Serial.println("Normal transition mode");

  nix.setTransitionMode(TMODE_NORMAL);
  for(int i=0; i<10; i++){
    Serial.println(i);
    nix.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix.update();
      delay(10);
    }
  }

  Serial.println("Crossfade mode");
  delay(1000);
  nix.setTransitionMode(TMODE_FADE);

  for(int i=0; i<10; i++){
    Serial.println(i);
    nix.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix.update();
      delay(10);
    }
  }

  step = 50;
  Serial.println("Shuffle mode");
  delay(1000);

  nix.setTransitionMode(TMODE_SHUFFLE);
  for(int i=0; i<10; i++){
    Serial.println(i);
    nix.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix.update();
      delay(4);
    }

    delay(500);
  }

  delay(1000);
}
