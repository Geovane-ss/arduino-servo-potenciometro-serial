#include <Servo.h>
Servo servoA; 
Servo servoB; 
int potPin = A0; 
int servoAPin = 9; 
int servoBPin = 10; 
int angleA = 0; 
int angleB = 0; 
void setup() {
 servoA.attach(servoAPin);
 servoB.attach(servoBPin);
 servoA.write(0);
 servoB.write(0);
 Serial.begin(9600);
}
void loop() {
 
 int potValue = analogRead(potPin);
 angleA = map(potValue, 0, 1023, 0, 180);
 servoA.write(angleA);
 
 Serial.print("Servo A: ");
 Serial.print(angleA);
 Serial.print("° | ");
 
 if (Serial.available() > 0) {
 int input = Serial.parseInt(); 
 if (input >= 0 && input <= 180) {
 angleB = input;
 servoB.write(angleB);
 } else {
 Serial.println("Informe um valor válido");
 }
 }
 
 Serial.print("Servo B: ");
 Serial.print(angleB);
 Serial.println("°");
 delay(100);
}