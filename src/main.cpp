#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#define AOUT_PIN 35
#define PUMP_PIN 18

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup()
{
  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  pinMode(18, OUTPUT);

  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
}

void loop()
{

  int value = analogRead(AOUT_PIN);
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Moisture value: ");

  // set cursor to first column, second row
  lcd.setCursor(0, 1);
  lcd.print(value);

  if (value > 2500)
  {
    digitalWrite(PUMP_PIN, 1);
    lcd.setCursor(5, 1);
    lcd.print("- PUMP ON");
  }
  else
  {
    digitalWrite(PUMP_PIN, 0);
    lcd.setCursor(5, 1);
    lcd.print("- PUMP OFF");
  }

  delay(2000);

  lcd.clear();
  delay(500);
}