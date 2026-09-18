#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

long cm, duration;
const int echoPin = 7;
const int trigPin = 6;
const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;

void setup() {
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("ROBOT READY");
  delay(1000);
}

void loop() {
  // Get distance from ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration * 0.034 / 2;
  
  Serial.print("Distance: cm ");
  Serial.println(cm);

  // Obstacle logic
  if (cm < 20) {
    stop_bot();
    delay(2000);
    go_back();
    delay(2000);
    stop_again();
    delay(1000);
    go_left();
    delay(1000);
  } else {
    go_straight();
    delay(1000);
  }
}

void go_straight() {
  lcd.setCursor(0, 1);
  lcd.print("Moving Forward");
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}

void go_back() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TAKING REVERSE");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  digitalWrite(lm2, HIGH);
  digitalWrite(lm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(rm1, LOW);
}

void stop_bot() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Something Ahead");
  lcd.setCursor(0, 1);
  lcd.print("STOP!!");
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}

void stop_again() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BREAK FOR TURN");
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}

void go_left() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turning left");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}

void go_right() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turning Right");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}
