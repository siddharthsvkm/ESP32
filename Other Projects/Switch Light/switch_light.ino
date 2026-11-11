// Siddharth Sivakumar
// November 11, 2026
// ESP32 (SunFounder)
// The purpose of this programis to use a switch to 
// light up an LED and let the computer know that the 
// switch is pressed without the use of multiple GPIO connections.

int switchPin = 36; // Pin used to connect 

void setup() { // Function that executes first - runs once 
  pinMode(switchPin, INPUT); // Set GPIO pin to read input
  Serial.begin(115200); // Start serial monitor
  Serial.println("Hello, ESP32-S2!"); // Starting output on serial monitor
}

void loop() { // Function that repeats after setup() many (infinite) times until program stops
  if (digitalRead(switchPin) == HIGH) { // Check if switch is pressed by reading voltage input
    Serial.println("Button is pressed"); // Log when switch is pressed
  } else { // Alternative if switch is not pressed
    Serial.println("Button is not pressed"); // Log when switch is not pressed
  }
  delay(30); // Slow down serial monitor output
}
