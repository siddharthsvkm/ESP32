// Siddharth Sivakumar
// November 11, 2026
// ESP32 (SunFounder)
// The purpose of this programis to use a switch to 
//light up an LED and let the computer know that the 
//switch is pressed without the use of multiple GPIO connections.

int switchPin = 36;

void setup() {
  pinMode(switchPin, INPUT);
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
}

void loop() {
  if (digitalRead(switchPin) == HIGH) { // 
    Serial.println("Button is pressed");
  } else { // 
    Serial.println("Button is not pressed");
  }
  delay(30); // Prevent from
}
