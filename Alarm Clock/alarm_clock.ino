#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 20, 4);

int alarmStatusLight[] = {12, 13, 14};
int alarmLight[] = {10, 11};

int servoPin = 6;
int buzzerPin = 48;

const int rows = 4, columns = 4;
char keys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
uint8_t columnPins[columns] = {18, 8, 3, 46};
uint8_t rowPins[rows] = {7, 15, 16, 17};

Keypad alarmKeypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);


void setup() {
  for (int i = 0; i < (sizeof(alarmStatusLight) / sizeof(alarmStatusLight[0])); i++) {
    pinMode(alarmStatusLight[i], OUTPUT);
  }
  for (int i = 0; i < (sizeof(alarmLight) / sizeof(alarmLight[0])); i++) {
    pinMode(alarmLight[i], OUTPUT);
  }

  lcd.init();
  lcd.backlight();
  printLCD("Alarm Clock", "", 3000, 1);
}

void loop() {
  delay(10); // this speeds up the simulation
}


void printTimeDate() {

}

void printLCD(String statement1, String statement2, int delayTime, int mode) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(statement1);
  lcd.setCursor(1, 0);
  lcd.print(statement2);
  delay(delayTime);
}
