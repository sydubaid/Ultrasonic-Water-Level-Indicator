#include <LiquidCrystal.h>

// Define pins for LCD and ultrasonic sensor
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin
long pulseDuration;     // Time for the ultrasonic pulse to return
float distance;         // Calculated distance
float depth;            // User-defined depth of the water tank
int level;              // Percentage of water level
const String depthPrompt = "Enter depth of water tank in cm:";

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Prompt user to enter the depth of the tank
  lcd.setCursor(0, 0);
  lcd.print("Set tank depth:");
  lcd.setCursor(0, 1);
  lcd.print("via Serial...");
  Serial.println(depthPrompt);

  // Wait for user input via Serial
  while (Serial.available() == 0) {}
  depth = Serial.parseFloat(); // Read and store depth
  if (depth <= 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid depth!");
    while (true); // Stop execution for invalid input
  }
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure pulse duration
  pulseDuration = pulseIn(echoPin, HIGH);

  // Calculate distance (in cm) using speed of sound (343 m/s)
  distance = (pulseDuration * 0.0343) / 2;

  // Calculate water level percentage
  level = (1 - distance / depth) * 100;
  if (level < 0) level = 0; // Handle edge cases
  if (level > 100) level = 100;

  // Display water level on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tank is ");
  lcd.print(level);
  lcd.print("% full");

  // Print level to Serial Monitor
  Serial.print("Water level: ");
  Serial.print(level);
  Serial.println("%");

  delay(1000); // Update every second
}
