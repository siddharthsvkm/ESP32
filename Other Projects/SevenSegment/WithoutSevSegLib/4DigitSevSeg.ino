int count = 0;

void setup() {
  byte digitPins[] = {36, 39, 40, 19};
  byte segmentPins[] = {37, 41, 21, 33, 34, 38, 20, 26};
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
}

void loop() {
  count += 1;
  delay(1000); // this speeds up the simulation
}
