#include <LiquidCrystal_I2C.h>


int redPin = 20;
int bluePin = 19;
int greenPin = 18;

LiquidCrystal_I2C lcd(0x27,16,2);

int redPot = 11;
int greenPot = 12;
int bluePot = 13;

int redOrig = 0;
int greenOrig = 0;
int blueOrig = 0;

int redVal;
int greenVal;
int blueVal;
String statement1;
String statement2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Wire.begin(1, 2);
  lcd.init();
  lcd.backlight();
  printLCD("LED Light Color", "Controller", 3000);
}

void loop() {
  redVal = analogRead(redPot) / 8191.0 * 255.0;
  greenVal = analogRead(greenPot) / 8191.0 * 255.0;
  blueVal = analogRead(bluePot) / 8191.0 * 255.0;
  statement1 = "R: " + String(redVal) + " G: " + String(greenVal);
  statement2 = "B: " + String(blueVal);
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
  printLCD(statement1, statement2, 150);
  delay(15);
}

void printLCD(String statement1, String statement2, int delayTime) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(statement1);
  lcd.setCursor(0,1);
  lcd.print(statement2);
  delay(delayTime);
}
