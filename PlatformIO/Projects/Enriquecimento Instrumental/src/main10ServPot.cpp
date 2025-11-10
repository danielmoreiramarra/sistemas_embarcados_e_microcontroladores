// #include <Arduino.h>
// #include <ESP32Servo.h>

// Servo meuServo;
// int pinoPot = 4;
// int pinoServo = 5;
// int valorPot = 0;
// int angulo = 0;

// void setup() {
//     meuServo.attach(pinoServo);
//     Serial.begin(9600);
// }

// void loop() {
//     valorPot = analogRead(pinoPot);
//     Serial.print(valorPot);
//     Serial.print("    ");
    
//     // Mapeia valores de 0 a 4095 para ângulos de 0 a 180 graus
//     angulo = map(valorPot, 0, 4095, 0, 180);
//     meuServo.write(angulo);
//     Serial.println(angulo);
//     delay(15);
// }