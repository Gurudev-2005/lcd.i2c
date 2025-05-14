#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Initialize the serial monitor for debugging
  Serial.begin(9600);
  
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Display a welcome message
  lcd.setCursor(0, 0);
  lcd.print("Distance Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  delay(2000);  // Wait for 2 seconds
}

void loop() {
  long duration, distance;
  
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);  // Ensure the trigger pin is low
  delayMicroseconds(2);        // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Send a pulse
  delayMicroseconds(10);       // Pulse length
  digitalWrite(trigPin, LOW);  // End the pulse
  
  // Read the time taken for the pulse to return
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (in cm)
  distance = (duration / 2) / 29.1;  // Divide by 2 for the round trip, divide by 29.1 to convert to cm
  
  // Display the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
  
  // Print the distance to the serial monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);  // Wait for half a second before taking another reading
}

