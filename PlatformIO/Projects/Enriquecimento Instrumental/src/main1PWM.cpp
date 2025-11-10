// #include <Arduino.h>

// // Definição dos pinos PWM
// const int LED_VERMELHO = 5; // LED Vermelho no pino D5 (PWM)
// const int LED_VERDE = 18; // LED Verde no pino D18 (PWM)
// const int BOTAO_VERMELHO = 2; // Botão para LED Vermelho no D2
// const int BOTAO_VERDE = 17; // Botão para LED Verde no D17

// // Estados dos LEDs
// bool ledVermelhoLigado = false;
// bool ledVerdeLigado = false;

// // Variáveis de brilho PWM
// int brilhoVermelho = 0;
// int brilhoVerde = 0;

// // Configurações
// const int PASSO_BRILHO = 5; // Incremento/decremento do brilho
// const int ATRASO_TRANSICAO = 20; // Tempo entre mudanças (ms)

// void setup() {
//   pinMode(LED_VERMELHO, OUTPUT);
//   pinMode(LED_VERDE, OUTPUT);
//   pinMode(BOTAO_VERMELHO, INPUT);
//   pinMode(BOTAO_VERDE, INPUT);
//   // Inicia LEDs desligados
//   analogWrite(LED_VERMELHO, 0);
//   analogWrite(LED_VERDE, 0);
// }

// void loop() {
//   // Verifica botão do LED Vermelho
//   if (botaoPressionado(BOTAO_VERMELHO)) {
//     ledVermelhoLigado = !ledVermelhoLigado;
//   }
//   // Verifica botão do LED Verde
//   if (botaoPressionado(BOTAO_VERDE)) {
//     ledVerdeLigado = !ledVerdeLigado;
//   }
//   // Controle gradual do LED Vermelho
//     if (ledVermelhoLigado) {
//       if (brilhoVermelho < 255) {
//         brilhoVermelho = min(brilhoVermelho + PASSO_BRILHO, 255);
//       }
//     } else {
//       if (brilhoVermelho > 0) {
//         brilhoVermelho = max(brilhoVermelho - PASSO_BRILHO, 0);
//       }
//     }
//   analogWrite(LED_VERMELHO, brilhoVermelho);

//   // Controle gradual do LED Verde
//   if (ledVerdeLigado) {
//     if (brilhoVerde < 255) {
//       brilhoVerde = min(brilhoVerde + PASSO_BRILHO, 255);
//     }
//   } else {
//     if (brilhoVerde > 0) {
//       brilhoVerde = max(brilhoVerde - PASSO_BRILHO, 0);
//     }
//   }
//   analogWrite(LED_VERDE, brilhoVerde);
// delay(ATRASO_TRANSICAO);
// }

// // Função para detectar pressionamento com debounce
// bool botaoPressionado(int pino) {
//   if (digitalRead(pino) == HIGH) {
//     delay(50); // Debounce
//     if (digitalRead(pino) == HIGH) {
//       while(digitalRead(pino) == HIGH); // Espera soltar
//       return true;
//     }
//   }
// return false;
// }
