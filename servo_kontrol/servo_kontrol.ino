#include <Servo.h>
Servo motor;

const int trigPin = 6;
const int echoPin = 7;
long mesafe = 0;
long sure = 0;
int aci;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motor.attach(8);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure / 2) / 29.1;

  if (mesafe > 4 && mesafe < 9) {
    for (aci = 0; aci <= 180; aci += 10) {
      motor.write(aci);
      delay(100);
    }
  }

  if (mesafe > 8) {
    for (aci = 180; aci >= 0; aci -= 10) {
      motor.write(aci);
      delay(100);
    }
  }

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  delay(100);
}