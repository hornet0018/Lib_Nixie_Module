// Nixie Tube Dynamic Driver Library for Nixie Clock bu Fablab Kannai

#include <Arduino.h>

#define MODE_NORMAL 0
#define MODE_BLINK 1
#define TMODE_NORMAL 100
#define TMODE_FADE 101
#define TMODE_SHUFFLE 102

#define PCA9685_SUBADR1 0x02
#define PCA9685_SUBADR2 0x03
#define PCA9685_SUBADR3 0x04

#define PCA9685_MODE1 0x00
#define PCA9685_PRESCALE 0xFE

#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09

#define ALLLED_ON_L 0xFA
#define ALLLED_ON_H 0xFB
#define ALLLED_OFF_L 0xFC
#define ALLLED_OFF_H 0xFD

class NixieModule_IN_12
{
  public:
    NixieModule_IN_12(uint8_t i2caddr = 0x4F);
    void init();
    void reset();
    void setPWMFreq(float freq);
    void setPWM(uint8_t num, uint16_t on, uint16_t off);
    void setOffset(uint16_t off);
    void setBrightness(float b);
    void setTransitionMode(uint8_t tmode);
    void setNumber(uint8_t newNum, uint16_t tStep);
    void dot(uint8_t onoff);
    void update();
    void blank();
    uint8_t read8(uint8_t addr);
    void doTransition(uint8_t num, float b);
    uint8_t mapNumToPin(uint8_t num);

  private:
    uint8_t _mode;
    uint8_t _i2caddr;
    uint8_t _num;
    uint8_t _newNum;
    uint8_t _step;
    uint8_t _stepCount;
    uint8_t _isTran;
    uint16_t _offset;

    float _brightness;

    void write8(uint8_t addr, uint8_t d);
};
