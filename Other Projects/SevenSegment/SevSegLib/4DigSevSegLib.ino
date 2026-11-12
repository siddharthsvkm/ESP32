#include <SevSeg.h>
SevSeg mySevSeg;
int count = 0;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {36, 39, 40, 19};
  byte segmentPins[] = {37, 41, 21, 33, 34, 38, 20, 26};
  bool resistorsOnSeg = false;
  byte hardwConfig = COMMON_ANODE;
  bool updateWithDelays = false;
  bool leadingZeros = true;
  bool disableDecPoint = false;
  mySevSeg.begin(hardwConfig, numDigits, digitPins, segmentPins, resistorsOnSeg, updateWithDelays, leadingZeros, disableDecPoint);
  mySevSeg.setBrightness(90);

  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
}

void loop() {
  count += 1;
  mySevSeg.setNumber(count, 1);
  mySevSeg.refreshDisplay();
  delay(1000); // this speeds up the simulation
}
