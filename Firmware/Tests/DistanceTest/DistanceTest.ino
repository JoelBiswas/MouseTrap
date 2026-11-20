const int trigPin = 12;
const int echoPin = 34;
const int BOOT_PIN = 0;
const float SPEED_OF_SOUND = 0.0343;
float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BOOT_BUTTON, INPUT_PULLUP);
  buttonTimer = 0;
  distanceTimer = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * SPEED_OF_SOUND / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
