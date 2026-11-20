#include <ESP32Servo.h>

const int TRIG_PIN = 12; //TODO: Move this away from a bootstrapping pin
const int ECHO_PIN = 34;
const int BOOT_BUTTON = 0;

const int LED_PIN = 2;

Servo servo;
const int SERVO_PIN = 13;
int servoPos;

const float SPEED_OF_SOUND = 0.0343; // cm / μs
const float MIN_THRESHOLD_CM = 2;
const float MAX_THRESHOLD_CM = 6;

float duration, distance;
bool gateClosed;

unsigned long buttonTime, lastReadTime;
const int BUTTON_WAIT_TIME = 1000;
const int DISTANCE_WAIT_TIME = 200;


void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BOOT_BUTTON, INPUT_PULLUP);

  servo.setPeriodHertz(50);
  servo.attach(SERVO_PIN, 500, 2500);
  setServo(0);

  buttonTime = 0;
  lastReadTime = 0;
  gateClosed = false;

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BOOT_BUTTON) == LOW && millis() - buttonTime > BUTTON_WAIT_TIME) {
    buttonTime = millis();
    reset();
  }

  if(millis() - lastReadTime > DISTANCE_WAIT_TIME){
    lastReadTime = millis();
    readDistance();
  }

  if (!gateClosed && distance > MIN_THRESHOLD_CM && distance < MAX_THRESHOLD_CM) {
    closeGate(); // TODO: Potentially require multiple detections to avoid false outliers
  }

  if(gateClosed) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

void readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distance = duration * SPEED_OF_SOUND / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}

void closeGate() {
  gateClosed = true;
  setServo(90);
  delay(2000);
  setServo(0);
}

// TODO: Add Reset Button
void reset() {
  if (servoPos == 0) {
    setServo(90);
  } else if (servoPos == 90) {
    setServo(0);
    gateClosed = false;
  }
}

void setServo(int position){
  servo.write(position);
  servoPos = position;
}