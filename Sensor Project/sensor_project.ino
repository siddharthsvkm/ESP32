#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal lcd1(19, 20, 38, 39, 40, 41);



int servoPin = 3;
Servo.begin();

void setup() {
  lcd1.begin();
  lcd1.init();
  

  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
}

void loop() {
  
  delay(10);
}
