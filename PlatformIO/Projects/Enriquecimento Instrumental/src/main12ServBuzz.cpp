// #include <Arduino.h>
// #include <ESP32Servo.h>

// // Definição dos pinos
// #define SERVO_PIN 15
// #define BUZZER_PIN 18
// #define PINO_TRIG 5  // Pino D5 conectado ao TRIG do HC-SR04
// #define PINO_ECHO 2  // Pino D2 conectado ao ECHO do HC-SR04
// #define MAX_DISTANCE 50 // Distância máxima em cm para detecção

// Servo meuServo;

// // Posições do servo
// #define POS_FECHADO 0
// #define POS_ABERTO 90

// void abrirCancela();
// void fecharCancela();
// void sinalBuzzer();
 
// void setup() {
//   Serial.begin(9600);
//   meuServo.attach(SERVO_PIN);
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(PINO_TRIG, OUTPUT);
//   pinMode(PINO_ECHO, INPUT);
//   meuServo.write(POS_FECHADO); // Inicia com a cancela fechada
// }

// void loop() {
//     // Envia pulso ultrassônico
//     digitalWrite(PINO_TRIG, LOW);
//     delayMicroseconds(2);
//     digitalWrite(PINO_TRIG, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(PINO_TRIG, LOW);
  
//     long duracao = pulseIn(PINO_ECHO, HIGH); // Mede o tempo de resposta do ECHO
//     float distancia = (duracao * 0.0343) / 2; // Calcula a distância (0.0343 cm/μs)
  
//     if (distancia > 0 && distancia < 30) { // Se objeto detectado a menos de 30cm
//         abrirCancela();
//         delay(3000); // Mantém aberto por 3 segundos
//         fecharCancela();
//     }
//     delay(100); // Pequeno delay entre verificações
// }

// void abrirCancela() {
//     sinalBuzzer();
//     // Abre a cancela
//     for (int pos = POS_FECHADO; pos <= POS_ABERTO; pos++) {
//         meuServo.write(pos);
//         delay(15);
//     }
//     Serial.println("Cancela aberta!");
// }

// void sinalBuzzer() {
//     // Toca o buzzer (bipe curto)
//     digitalWrite(BUZZER_PIN, HIGH);
//     delay(100);  // Aumentado para 100ms para melhor audição
//     digitalWrite(BUZZER_PIN, LOW);
// }

// void fecharCancela() {
//     sinalBuzzer();
//     // Fecha a cancela
//     for (int pos = POS_ABERTO; pos >= POS_FECHADO; pos--) {
//         meuServo.write(pos);
//         delay(15);
//     }
//     Serial.println("Cancela fechada!");
// }