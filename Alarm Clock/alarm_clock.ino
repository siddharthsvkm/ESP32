#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>


LiquidCrystal_I2C myLCD(0x27, 16, 2);
RTC_DS1307 myRTC;

int alarmStatus[] = {14, 13, 12};
int alarmLight[] = {15, 16};

int buzzerPin = 17;

const int rows = 4, columns = 4;
char keys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
uint8_t columnPins[columns] = {21, 20, 19, 18};
uint8_t rowPins[rows] = {35, 34, 33, 26};

Keypad alarmKeypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);



void setup() {
  for (int i = 0; i < (sizeof(alarmStatus) / sizeof(alarmStatus[0])); i++) {
    pinMode(alarmStatus[i], OUTPUT);
  }
  for (int i = 0; i < (sizeof(alarmLight) / sizeof(alarmLight[0])); i++) {
    pinMode(alarmLight[i], OUTPUT);
  }


  Wire.begin(8,9);
  myRTC.begin();
  myLCD.init();
  myLCD.backlight();

  printLCD("  Alarm Clock  ", "   Prototype", 3000);
}

void loop() {
  //printTimeDate();
}

void printTimeDate() {
  DateTime myClock = myRTC.now();
  int prevSec = -1;

  char dateStatement[17];
  char timeStatement[17];

  while (true) {
    myClock = myRTC.now();

    if (myClock.second() != prevSec) {

      snprintf(dateStatement, sizeof(dateStatement), "%02d/%02d/%02d", myClock.month(), myClock.day(), myClock.year());
      snprintf(timeStatement, sizeof(timeStatement), "%02d:%02d:%02d", myClock.hour(), myClock.minute(), myClock.second());
      printLCD(dateStatement, timeStatement, 45);

    } else {
      delay(45);
    }
  }



  
}





void printLCD(String statement1, String statement2, int delayTime) {
  myLCD.clear();
  myLCD.setCursor(0, 0);
  myLCD.print(statement1);
  myLCD.setCursor(0, 1);
  myLCD.print(statement2);
  delay(delayTime);
}
