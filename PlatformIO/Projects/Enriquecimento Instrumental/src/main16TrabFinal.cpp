#include <Arduino.h>
#include <ESP32Servo.h>

#define POS_FECHADO 0
#define POS_ABERTO 90

Servo servol;

// Pinos do display de 7 segmentos (ajuste conforme seu circuito)
const int segA = 15;
const int segB = 5;
const int segC = 18;
const int segD = 19;
const int segE = 21;
const int segF = 22;
const int segG = 23;

// Pinos do sensor ultrassônico
const int PINO_TRIG = 4;
const int PINO_ECHO = 2;

// Pino do servomotor
const int PINO_SERV = 13;

// Pino do buzzer
const int PINO_BUZ = 12;

// Pinos dos LEDs verde e vermelho
const int LED_VRM = 14;
const int LED_VRD = 27;

// Botão de reset do estacionamento
const int PINO_RES = 26;

// Botão de abrir o portão para sair
const int PINO_EXIT = 25;

int i = 0; // Contador
bool objetoDetectado = false; // Flag para debounce

// Função para acender o display
void acende(int numero) {
    switch(numero) {
        case 0:
            digitalWrite(segE, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, HIGH);
            break;
            
        case 1:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, HIGH);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, HIGH);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, HIGH);
            break;
            
        case 2:
            digitalWrite(segE, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segC, HIGH);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, LOW);
            break;
            
        case 3:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, LOW);
            break;
            
        case 4:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, HIGH);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, HIGH);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
            
        case 5:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, HIGH);
            digitalWrite(segA, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
            
        case 6:
            digitalWrite(segE, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, HIGH);
            digitalWrite(segA, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
            
        case 7:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, HIGH);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, HIGH);
            digitalWrite(segG, HIGH);
            break;
            
        case 8:
            digitalWrite(segE, LOW);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
            
        case 9:
            digitalWrite(segE, HIGH);
            digitalWrite(segD, LOW);
            digitalWrite(segC, LOW);
            digitalWrite(segB, LOW);
            digitalWrite(segA, LOW);
            digitalWrite(segF, LOW);
            digitalWrite(segG, LOW);
            break;
    }
}

void sinalBuzzer() {
    digitalWrite(LED_VRD, LOW);
    digitalWrite(LED_VRM, HIGH);
    // Toca o buzzer (bipe curto)
    digitalWrite(PINO_BUZ, HIGH);
    delay(50);  // Aumentado para 50ms para melhor audição
    digitalWrite(PINO_BUZ, LOW);
}

void abrirPortao() {
    sinalBuzzer();
    // Abre o portão
    for (int pos = POS_FECHADO; pos <= POS_ABERTO; pos++) {
        servol.write(pos);
        delay(50);
    }
    Serial.println("Portão aberto!");
}

void fecharPortao() {
    sinalBuzzer();
    // Fecha o portão
    for (int pos = POS_ABERTO; pos >= POS_FECHADO; pos--) {
        servol.write(pos);
        delay(50);
    }
    Serial.println("Portão fechado!");
}

void setup() {
    // Configura os pinos do display
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);

    // Configura o sensor ultrassônico
    pinMode(PINO_TRIG, OUTPUT);
    pinMode(PINO_ECHO, INPUT);

    // Configura o buzzer
    pinMode(PINO_BUZ, OUTPUT);
    
    // Configura os LEDs
    pinMode(LED_VRM, OUTPUT);
    pinMode(LED_VRD, OUTPUT);

    // Configura o servomotor
    servol.attach(PINO_SERV);

    // Configura os botões de reset e saída
    pinMode(PINO_RES, INPUT);
    pinMode(PINO_EXIT, INPUT);

    Serial.begin(9600);
    acende(i); // Inicializa o display com 0
}

void loop() {
    // Inicializa os LEDs
    digitalWrite(LED_VRD, HIGH);
    digitalWrite(LED_VRM, LOW);

    // Ativa o sensor
    digitalWrite(PINO_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PINO_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PINO_TRIG, LOW);

    // Mede a distância
    long duracao = pulseIn(PINO_ECHO, HIGH);
    float distancia = (duracao * 0.0340) / 2;

    // Detecta objeto a ≤10 cm (com debounce)
    if (distancia <= 10 && !objetoDetectado) {
        objetoDetectado = true;
        if (i < 9) {
            i++;
        } else {
            i = 0;
        }
        acende(i); // Atualiza o display imediatamente
        abrirPortao();
        Serial.print("Carro entrando do estacionamento! Carros no estacionamento: ");
        Serial.println(i);
        delay(5000);
        fecharPortao();
    } else if (distancia > 10) {
        objetoDetectado = false; // Reseta a flag quando o objeto sai
    }

    // Botão de resetar o sistema do estacionamento
    if (digitalRead(PINO_RES) == HIGH) {
        delay(50); // Debounce
        if (digitalRead(PINO_RES) == HIGH) {
            i = 0;
            acende(i);
            while(digitalRead(PINO_RES) == HIGH); // Espera soltar o botão
        }
    }

    // Botão para saída de carros do estacionamento
    if (digitalRead(PINO_EXIT) == HIGH) {
        delay(50); // Debounce
        if (i > 0) {
            i--;
        } else {
            i = 0;
        }
        acende(i); // Atualiza o display imediatamente
        abrirPortao();
        Serial.print("Carro saindo do estacionamento! Carros no estacionamento: ");
        Serial.println(i);
        delay(5000);
        fecharPortao();
    }

    delay(200); // Delay
}
