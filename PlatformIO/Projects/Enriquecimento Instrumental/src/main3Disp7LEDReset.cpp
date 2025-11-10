// #include <Arduino.h>

// // Contador com display de 7 segmentos com incremento de LDR e botão de reset
// int segE = 19;
// int segD = 18;
// int segC = 5;
// int segB = 23;
// int segA = 15;
// int segF = 21;
// int segG = 22;
// int botaoReset = 12; // botao que reseta o display
// int sensorLDR = 4; // sensor de luz
// float valorLuz; // valor do sensor de luz
// int n = 0; // numero a ser impresso no display (inicia em 0)
// bool escuroAnterior = false;

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
//     pinMode(botaoReset, INPUT);
//     pinMode(sensorLDR, INPUT);

//     Serial.begin(9600);
// }

// void loop() {
//     valorLuz = analogRead(sensorLDR); // Lê o valor do sensor (0 a 4095)
    
//     Serial.print(valorLuz); // Exibe o valor lido no monitor serial
//     Serial.print("\n");     // Nova linha
    
//         // Verifica botão de resetar
//     if (digitalRead(botaoReset) == HIGH) {
//         delay(50); // Debounce
//         if (digitalRead(botaoReset) == HIGH) {
//             n = 0;
//             while(digitalRead(botaoReset) == HIGH); // Espera soltar o botão
//         }
//     }
    
//     // Se o valor for menor que 2048 (menos luz ambiente)
//     bool escuroAtual = (valorLuz < 2048);
//     if (escuroAtual && !escuroAnterior) {
//         if (n < 9) {
//             n++; 
//         } else {
//             n = 0;
//         }
//     }
//     escuroAnterior = escuroAtual;

//     acende(n);
//     delay(100); // Pequena pausa entre leituras (100ms)
// }
