// #include <Arduino.h>

// // Contador com display de 7 segmentos
// int segE = 19;
// int segD = 18;
// int segC = 5;
// int segB = 23;
// int segA = 15;
// int segF = 21;
// int segG = 22;

// void acende(int numero) {
//     switch(numero) {
//         case 0:
//             digitalWrite(segE, LOW);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, HIGH);
//             break;
            
//         case 1:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, HIGH);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, HIGH);
//             digitalWrite(segF, HIGH);
//             digitalWrite(segG, HIGH);
//             break;
            
//         case 2:
//             digitalWrite(segE, LOW);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, HIGH);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, HIGH);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 3:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, HIGH);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 4:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, HIGH);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, HIGH);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 5:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, HIGH);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 6:
//             digitalWrite(segE, LOW);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, HIGH);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 7:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, HIGH);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, HIGH);
//             digitalWrite(segG, HIGH);
//             break;
            
//         case 8:
//             digitalWrite(segE, LOW);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, LOW);
//             break;
            
//         case 9:
//             digitalWrite(segE, HIGH);
//             digitalWrite(segD, LOW);
//             digitalWrite(segC, LOW);
//             digitalWrite(segB, LOW);
//             digitalWrite(segA, LOW);
//             digitalWrite(segF, LOW);
//             digitalWrite(segG, LOW);
//             break;
//     }
// }

// void setup() {
//     pinMode(segA, OUTPUT);
//     pinMode(segB, OUTPUT);
//     pinMode(segC, OUTPUT);
//     pinMode(segD, OUTPUT);
//     pinMode(segE, OUTPUT);
//     pinMode(segF, OUTPUT);
//     pinMode(segG, OUTPUT);

//     Serial.begin(9600);
// }

// void loop() {
//     for (int i = 0; i < 10; i++) {
//         acende(i);
//         delay(1000);
//     }
// }
