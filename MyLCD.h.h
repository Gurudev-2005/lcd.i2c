#ifndef MY_LCD_H
#define MY_LCD_H

#include <LiquidCrystal_I2C.h>

class MyLCD {
  public:
    MyLCD(uint8_t addr, uint8_t cols, uint8_t rows);
    void begin();
    void showWelcomeMessage(const char* line1, const char* line2);
    void clearDisplay();

  private:
    LiquidCrystal_I2C lcd;
};

#endif
