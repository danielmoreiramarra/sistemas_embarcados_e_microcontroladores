// #include <Arduino.h>

// // Leitura da temperatura e umidade com o sensor DHT11
// #include <DHT.h> // Biblioteca do sensor

// #define DHTPIN 4     // Pino conectado ao sensor
// #define DHTTYPE DHT11 // Tipo do sensor utilizado
// DHT dht(DHTPIN, DHTTYPE); // Define o objeto dht

// void setup() {
//     Serial.begin(9600); // Inicializa a comunicação serial
//     Serial.print("Teste do sensor DHT11");
//     Serial.print("\n"); // Quebra de linha
//     dht.begin(); // Inicializa o sensor
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
    
//     // Exibe os dados no monitor serial
//     Serial.print("Umidade: ");
//     Serial.print(h);
//     Serial.print("% Temperatura: ");
//     Serial.print(t);
//     Serial.print("°C");
//     Serial.println(); // Adiciona quebra de linha para próxima leitura
// }// #include <Arduino.h>

// // Leitura da temperatura e umidade com o sensor DHT11
// #include <DHT.h> // Biblioteca do sensor

// #define DHTPIN 4     // Pino conectado ao sensor
// #define DHTTYPE DHT11 // Tipo do sensor utilizado
// DHT dht(DHTPIN, DHTTYPE); // Define o objeto dht

// void setup() {
//     Serial.begin(9600); // Inicializa a comunicação serial
//     Serial.print("Teste do sensor DHT11");
//     Serial.print("\n"); // Quebra de linha
//     dht.begin(); // Inicializa o sensor
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
    
//     // Exibe os dados no monitor serial
//     Serial.print("Umidade: ");
//     Serial.print(h);
//     Serial.print("% Temperatura: ");
//     Serial.print(t);
//     Serial.print("°C");
//     Serial.println(); // Adiciona quebra de linha para próxima leitura
// }