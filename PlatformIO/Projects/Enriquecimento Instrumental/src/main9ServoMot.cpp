// #include <Arduino.h>
// #include <ESP32Servo.h>

// static const int servoPin = 5;

// Servo servol;

// void setup() {
//     Serial.begin(9600);
//     servol.attach(servoPin);
// }

// void loop() {
//     for(int posDegrees = 0; posDegrees <= 180; posDegrees=posDegrees+10) {
//         servol.write(posDegrees);
//         Serial.println(posDegrees);
//         delay(100);
//     }

//     for(int posDegrees = 180; posDegrees >= 0; posDegrees=posDegrees-10) {
//         servol.write(posDegrees);
//         Serial.println(posDegrees);
//         delay(100);
//     }
// }