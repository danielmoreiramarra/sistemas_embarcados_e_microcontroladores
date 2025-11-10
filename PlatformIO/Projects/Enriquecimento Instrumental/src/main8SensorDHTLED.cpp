// #include <Arduino.h>

// // Leitura da temperatura e umidade com o sensor DHT11
// #include <DHT.h> // Biblioteca do sensor

// #define DHTPIN 4     // Pino conectado ao sensor
// #define DHTTYPE DHT11 // Tipo do sensor utilizado
// DHT dht(DHTPIN, DHTTYPE); // Define o objeto dht

// const int LED_VERMELHO = 5;
// const int LED_VERDE = 18;

// void setup() {
//     Serial.begin(9600); // Inicializa a comunicação serial
//     Serial.print("Teste do sensor DHT11");
//     Serial.print("\n"); // Quebra de linha
//     dht.begin(); // Inicializa o sensor
//     pinMode(LED_VERMELHO, OUTPUT);
//     pinMode(LED_VERDE, OUTPUT);
// }

// void loop() {
//     // Aguarda um tempo entre medidas
//     delay(2000);
    
//     // Faz a leitura da umidade
//     float h = dht.readHumidity();
    
//     // Lê a temperatura em Celsius
//     float t = dht.readTemperature();
    
//     // Verifica se houve falha na leitura e repete a leitura
//     if (isnan(h) || isnan(t)) {
//         Serial.println("Falha na leitura do sensor DHT11!");
//         return;
//     }

//     if (t >= 20 && t <=24) {
//         digitalWrite(LED_VERDE, HIGH);
//         digitalWrite(LED_VERMELHO, LOW);
//     } else {
//         digitalWrite(LED_VERDE, LOW);
//         digitalWrite(LED_VERMELHO, HIGH);
//     }
    
//     // Exibe os dados no monitor serial
//     Serial.print("Umidade: ");
//     Serial.print(h);
//     Serial.print("% Temperatura: ");
//     Serial.print(t);
//     Serial.print("°C");
//     Serial.println(); // Adiciona quebra de linha para próxima leitura
// }