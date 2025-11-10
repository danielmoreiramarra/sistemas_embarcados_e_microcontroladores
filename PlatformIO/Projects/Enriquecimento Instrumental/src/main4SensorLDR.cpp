// #include <Arduino.h>

// // LED acende quando luz ambiente diminui
// // Leitura do pino D4 como entrada analógica

// int pinoled = 21;          // Pino do LED
// int pinoSensorLuz = 4;     // Pino do sensor de luz (analógico)
// int valorLuz = 0;          // Variável para armazenar o valor lido do sensor

// void setup() {
//     Serial.begin(9600);     // Inicia a comunicação serial
//     pinMode(pinoled, OUTPUT); // Configura o pino do LED como saída
// } 

// void loop() {
//     valorLuz = analogRead(pinoSensorLuz); // Lê o valor do sensor (0 a 4095)
    
//     Serial.print(valorLuz); // Exibe o valor lido no monitor serial
//     Serial.print("\n");     // Nova linha
    
//     // Se o valor for menor que 2048 (menos luz ambiente)
//     if(valorLuz < 2048) {
//         digitalWrite(pinoled, HIGH); // Acende o LED
//     }
//     else {
//         digitalWrite(pinoled, LOW);  // Apaga o LED
//     }
    
//     delay(100); // Pequena pausa entre leituras (100ms)
// }