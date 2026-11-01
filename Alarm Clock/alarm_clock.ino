#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

int rgb_r = 12;
int rgb_g = 13;
int rgb_b = 14;

int redPin1 = 10;
int redPin2 = 11;

int servoPin = 6;
int buzzerPin = 48;

int columnPins[] = {18, 8, 3, 46};
int rowPins[] = {7, 15, 16, 17};


void setup() {
  pinMode(rgb_r, OUTPUT);
  pinMode(rgb_g, OUTPUT);
  pinMode(rgb_b, OUTPUT);

  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);

  lcd.begin(16, 2);
  lcd.init();

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
