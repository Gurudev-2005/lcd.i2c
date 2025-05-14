#include "MyLCD.h"

MyLCD::MyLCD(uint8_t addr, uint8_t cols, uint8_t rows)
  : lcd(addr, cols, rows) {}

void MyLCD::begin() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void MyLCD::showWelcomeMessage(const char* line1, const char* line2) {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void MyLCD::clearDisplay() {
  lcd.clear();
}
