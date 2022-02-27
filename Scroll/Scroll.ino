#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void setup()
{
  lcd.begin();

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" WELCOME TO really long message on first row");
}

void loop()
{
  lcd.setCursor(16, 1);
  lcd.autoscroll();
  lcd.print(" ");
  delay(700);
}
