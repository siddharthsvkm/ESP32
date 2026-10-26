int redPin = 20;
int bluePin = 19;
int greenPin = 18;


int redPot = 11;
int greenPot = 12;
int bluePot = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // pinMode(redPot, INPUT);
  // pinMode(greenPot, INPUT);
  // pinMode(bluePot, INPUT);
  
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int redVal = analogRead(redPot) / 8191.0 * 255.0;
  int greenVal = analogRead(greenPot) / 8191.0 * 255.0;
  int blueVal = analogRead(bluePot) / 8191.0 * 255.0;
  String statement = "Red: " + String(redVal) + ", Green: " + String(greenVal) + ", Blue: " + String(blueVal);

  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
  Serial.println(statement);
  delay(15); // this speeds up the simulation
}

