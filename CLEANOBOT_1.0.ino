#include <Arduino.h>

// Pin Definitions
const int trigPins[] = {2, 8, 10, 12}; // Trig pins of HC-SR04
const int echoPins[] = {3, 9, 11, 13}; // Echo pins of HC-SR04
const int motorPins[] = {4, 5, 6, 7};  // Motor pins of L298N
const int pumpPin = 23;
// Constants
const float SPEED_OF_SOUND_CM_PER_US = 0.0343;
const int MIN_DISTANCE_CM = 4;
const int TURN_DISTANCE_CM = 6;

// Function Prototypes
float readDistance(int trigPin, int echoPin);
void stopMotors();
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    pinMode(motorPins[i], OUTPUT);
  }
  pinMode(pumpPin, OUTPUT);
}

void loop() {
 // digitalWrite(pumpPin, LOW);
  //delay(50);
  //digitalWrite(pumpPin, HIGH);
  //delay(10);
  float distances[4];
  for (int i = 0; i < 4; i++) {
    distances[i] = readDistance(trigPins[i], echoPins[i]);
  }

  if (distances[0] < MIN_DISTANCE_CM) {
    if (distances[2] > distances[3] && distances[2] > TURN_DISTANCE_CM) {
      moveLeft();
      Serial.println("Left turn");
    } else if (distances[3] > distances[2] && distances[3] > TURN_DISTANCE_CM) {
      moveRight();
       Serial.println("Right turn");
    } else if (distances[1] > TURN_DISTANCE_CM) {
      moveBackward();
       Serial.println("Back turn");
    } else {
      stopMotors();
       Serial.println("Stop");
    }
  } else if (distances[2] > TURN_DISTANCE_CM && distances[3] > TURN_DISTANCE_CM) {
    moveForward();
     Serial.println("Forward turn");
  } else {
    if (distances[2] < TURN_DISTANCE_CM && distances[1] > TURN_DISTANCE_CM && distances[3] > TURN_DISTANCE_CM) {
      moveRight();
       Serial.println("Right turn");
    } else if (distances[3] < TURN_DISTANCE_CM && distances[1] > TURN_DISTANCE_CM && distances[2] > TURN_DISTANCE_CM) {
      moveLeft();
      Serial.println("Left turn");
    } else if (distances[1] > TURN_DISTANCE_CM) {
      moveBackward();
      Serial.println("Back turn");
    } else {
      stopMotors();
       Serial.println("Stop");
    }
  }
  delay(10);
}

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * SPEED_OF_SOUND_CM_PER_US / 2.0;
}

void stopMotors() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(motorPins[i], LOW);
  }
}

void moveForward() {
  digitalWrite(motorPins[0], HIGH);
  digitalWrite(motorPins[1], LOW);
  digitalWrite(motorPins[2], HIGH);
  digitalWrite(motorPins[3], LOW);
}

void moveBackward() {
  digitalWrite(motorPins[0], LOW);
  digitalWrite(motorPins[1], HIGH);
  digitalWrite(motorPins[2], LOW);
  digitalWrite(motorPins[3], HIGH);
}

void moveLeft() {
  digitalWrite(motorPins[0], HIGH);
  digitalWrite(motorPins[1], LOW);
  digitalWrite(motorPins[2], LOW);
  digitalWrite(motorPins[3], HIGH);
}

void moveRight() {
  digitalWrite(motorPins[0], LOW);
  digitalWrite(motorPins[1], HIGH);
  digitalWrite(motorPins[2], HIGH);
  digitalWrite(motorPins[3], LOW);
}
