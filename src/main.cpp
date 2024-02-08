#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const char *welcome = "welcome";

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(3, 0);
  lcd.print("welcome");
  delay(1000);
  lcd.clear();
}

void loop()
{
  for (int i = 6; i > 0; i--)
  {
    lcd.setCursor(0, 0);
    lcd.print((welcome + i));
    delay(300);
  }
  for (int i = 0; i < 20; i++)
  {
    lcd.setCursor(i, 0);
    lcd.print("welcome");

    if (i > 12)
    {
      for (int j = 0; j < 20; j++)
      {
        lcd.setCursor(j, 2);
        lcd.print(" ");
      }
    }
    delay(300);
    lcd.clear();
  }
}