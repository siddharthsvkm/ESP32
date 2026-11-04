#include <Keypad.h>
#include <LiquidCrystal_I2C.h>


int[] alarmStatusLight = {12, 13, 14};
int[] alarmLight = {10, 11};

int servoPin = 6;
int buzzerPin = 48;

int columnPins[] = {18, 8, 3, 46};
int rowPins[] = {7, 15, 16, 17};

Keypad alarmKeypad = ;


void setup() {
  for (int i = 0; i < (sizeof(alarmStatusLight) / sizeof(alarmStatusLight[0])); i++) {
    pinMode(alarmStatusLight[i], OUTPUT);
  }
  for (int i = 0; i < (sizeof(alarmLight) / sizeof(alarmLight[0])); i++) {
    pinMode(alarmLight[i], OUTPUT);
  }

  lcd.begin(16, 2);

  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
}

void loop() {
  delay(10); // this speeds up the simulation
}


void printTimeDate() {

}

void printLCD(String statement1, String statement2, int delayTime) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(statement1);
  lcd.setCursor(1, 0);
  lcd.print(statement2);

  delay(delayTime);
}
