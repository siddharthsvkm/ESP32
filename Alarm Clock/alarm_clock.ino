#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Wire.h>

RTC_DS1307 myRTC;
LiquidCrystal_I2C lcd(0x27, 20, 2);

int alarmStatus[] = {12, 13, 14};
int alarmLight[] = {10, 11};

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
  for (int i = 0; i < (sizeof(alarmStatus) / sizeof(alarmStatus[0])); i++) {
    pinMode(alarmStatus[i], OUTPUT);
  }
  for (int i = 0; i < (sizeof(alarmLight) / sizeof(alarmLight[0])); i++) {
    pinMode(alarmLight[i], OUTPUT);
  }

  Wire.begin();
  // Wire1.begin(47,21);
  myRTC.begin();


  
  lcd.init();
  lcd.backlight();
  printLCD("  Alarm Clock  ", "", 3000);


}

void loop() {
  printTimeDate();
}


void printTimeDate() {
  DateTime myClock = myRTC.now();
  String timeStatement = "    ";
  String dateStatement = "    ";

  int hour = myClock.hour();
  if (hour < 10) {
    timeStatement += "0";
  }
  timeStatement += String(hour) + ":";

  int minute = myClock.minute();
  if (minute < 10) {
    timeStatement += "0";
  }
  timeStatement += String(minute) + ":";

  int second = myClock.second();
  if (second < 10) {
    timeStatement += "0";
  }
  timeStatement += String(second) + ":";

  int month = myClock.month();
  if (month < 10) {
    dateStatement += "0";
  }
  dateStatement += String(month) + "/";

  int day = myClock.day();
  if (day < 10) {
    dateStatement += "0";
  }
  dateStatement += String(day) + "/";

  int year = myClock.year();
  dateStatement += String(year);
  

  printLCD(dateStatement, timeStatement, 900);
  // Serial.print(dateStatement);
  // Serial.print(timeStatement);
}

void printLCD(String statement1, String statement2, int delayTime) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(statement1);
  lcd.setCursor(1, 0);
  lcd.print(statement2);
  delay(delayTime);
}

