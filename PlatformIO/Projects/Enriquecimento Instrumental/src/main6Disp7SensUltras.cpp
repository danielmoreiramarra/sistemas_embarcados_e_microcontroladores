// #include <Arduino.h>

// // Pinos do display de 7 segmentos (ajuste conforme seu circuito)
// const int segA = 15;
// const int segB = 5;
// const int segC = 18;
// const int segD = 19;
// const int segE = 21;
// const int segF = 22;
// const int segG = 23;

// // Pinos do sensor ultrassônico
// const int PINO_TRIG = 4;
// const int PINO_ECHO = 2;

// int i = 0; // Contador
// bool objetoDetectado = false; // Flag para debounce

// // Função para acender o display
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
//     // Configura os pinos do display
//     pinMode(segA, OUTPUT);
//     pinMode(segB, OUTPUT);
//     pinMode(segC, OUTPUT);
//     pinMode(segD, OUTPUT);
//     pinMode(segE, OUTPUT);
//     pinMode(segF, OUTPUT);
//     pinMode(segG, OUTPUT);

//     // Configura o sensor ultrassônico
//     pinMode(PINO_TRIG, OUTPUT);
//     pinMode(PINO_ECHO, INPUT);

//     Serial.begin(9600);
//     acende(i); // Inicializa o display com 0
// }

// void loop() {
//     // Ativa o sensor
//     digitalWrite(PINO_TRIG, LOW);
//     delayMicroseconds(2);
//     digitalWrite(PINO_TRIG, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(PINO_TRIG, LOW);

//     // Mede a distância
//     long duracao = pulseIn(PINO_ECHO, HIGH);
//     float distancia = (duracao * 0.0340) / 2;

//     // Detecta objeto a ≤10 cm (com debounce)
//     if (distancia <= 10 && !objetoDetectado) {
//         objetoDetectado = true;
//         if (i < 9) {
//             i++;
//         } else {
//             i = 0;
//         }
//         acende(i); // Atualiza o display imediatamente
//         Serial.print("Objeto detectado! Contagem: ");
//         Serial.println(i);
//     } else if (distancia > 10) {
//         objetoDetectado = false; // Reseta a flag quando o objeto sai
//     }

//     Serial.print("Distância: ");
//     Serial.print(distancia);
//     Serial.println(" cm");

//     delay(200); // Delay
// }
