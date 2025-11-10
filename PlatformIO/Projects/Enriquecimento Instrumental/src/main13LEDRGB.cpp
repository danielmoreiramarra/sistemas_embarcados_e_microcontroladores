// #include <WiFi.h>
// #include <WebServer.h>

// /* Put your SSID & Password */
// const char* ssid = "iPhone de Daniel (2)";  // Enter SSID here
// const char* password = "12345678";  // Enter Password here

// WebServer server(80);

// // Pins for ESP32 (ajuste conforme seu hardware)
// uint8_t pinR = 18;
// uint8_t pinG = 19;
// uint8_t pinB = 21;

// // PWM properties for ESP32
// const int freq = 5000;
// const int resolution = 8;  // 8 bits (0-255)

// bool LEDstatus = LOW;
// int valR = 0, valG = 0, valB = 0;

// // Protótipos de função
// void handle_OnConnect();
// void handle_ledON();
// void handle_ledOFF();
// void handle_NotFound();
// String SendHTML(bool ledstat);

// void setup() {
//   Serial.begin(9600);
//   delay(1000);

//   // Configure PWM for ESP32
//   ledcSetup(0, freq, resolution);  // Canal 0 para vermelho
//   ledcSetup(1, freq, resolution);  // Canal 1 para verde
//   ledcSetup(2, freq, resolution);  // Canal 2 para azul
  
//   ledcAttachPin(pinR, 0);
//   ledcAttachPin(pinG, 1);
//   ledcAttachPin(pinB, 2);

//   Serial.println("Connecting to WiFi...");
//   WiFi.begin(ssid, password);
  
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   server.on("/", handle_OnConnect);
//   server.on("/ledon", handle_ledON);
//   server.on("/ledoff", handle_ledOFF);
//   server.onNotFound(handle_NotFound);
  
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
  
//   if(LEDstatus) {
//     ledcWrite(0, valR);  // Canal 0 (vermelho)
//     ledcWrite(1, valG);  // Canal 1 (verde)
//     ledcWrite(2, valB);  // Canal 2 (azul)
//   } else {
//     ledcWrite(0, 0);
//     ledcWrite(1, 0);
//     ledcWrite(2, 0);
//   }
// }

// void handle_OnConnect() {
//   LEDstatus = LOW;
//   Serial.println("LED Status: OFF");
//   server.send(200, "text/html", SendHTML(LEDstatus)); 
// }

// void handle_NotFound() {
//   server.send(404, "text/plain", "Not found");
// }

// void handle_ledON() {
//   LEDstatus = HIGH;
//   valR = (server.hasArg("r")) ? server.arg("r").toInt() : 255;
//   valG = (server.hasArg("g")) ? server.arg("g").toInt() : 255;
//   valB = (server.hasArg("b")) ? server.arg("b").toInt() : 255;
  
//   Serial.println("LED Status: ON");
//   Serial.printf("Color values - R: %d, G: %d, B: %d\n", valR, valG, valB);
//   server.send(200, "text/html", SendHTML(HIGH)); 
// }

// void handle_ledOFF() {
//   LEDstatus = LOW;
//   Serial.println("LED Status: OFF");
//   server.send(200, "text/html", SendHTML(LOW)); 
// }

// String SendHTML(bool ledstat) {
//   String ptr = "<!DOCTYPE html> <html>";

//   ptr += "<head>";
//   ptr += "<meta charset=\"utf-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
//   ptr += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\">";
//   ptr += "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jscolor/2.0.4/jscolor.min.js\"></script>";
  
//   ptr += "<style>";
//   ptr += "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
//   ptr += "body { margin-top: 50px; }";
//   ptr += "h1 { color: #444444; margin: 50px auto 30px; }";
//   ptr += "h3 { color: #444444; margin-bottom: 50px; }";
//   ptr += ".button { display: block; width: 80px; background-color: #1abc9c; border: none; color: white; padding: 13px 30px; text-decoration: none; font-size: 25px; margin: 0px auto 35px; cursor: pointer; border-radius: 4px; }";
//   ptr += ".button-on { background-color: #1abc9c; }";
//   ptr += ".button-on:active { background-color: #16a085; }";
//   ptr += ".button-off { background-color: #34495e; }";
//   ptr += ".button-off:active { background-color: #2c3e50; }";
//   ptr += "p { font-size: 14px; color: #888; margin-bottom: 10px; }";
//   ptr += "</style>";
  
//   ptr += "</head>";
//   ptr += "<body><div class=\"container\"><div class=\"row\"><h1>ESP32 Color Picker</h1>";

//   if(ledstat) {
//     ptr += "<p>LED Status: <a class=\"button button-on\" href=\"/ledoff\">ON</a></p>";
//     ptr += "<a id=\"change_color\" href=\"#\" class=\"btn btn-primary\">Change Color</a>";
//     ptr += "<input class=\"jscolor {onFineChange:'update(this)'}\" id=\"rgb\">";
//   } else {
//     ptr += "<p>LED Status: <a class=\"button button-off\" href=\"/ledon\">OFF</a></p>";
//   }
  
//   ptr += "</div></div>";
//   ptr += "<script>";
//   ptr += "function update(picker) {";
//   ptr += "document.getElementById('rgb').innerHTML = Math.round(picker.rgb[0]) + ', ' + Math.round(picker.rgb[1]) + ', ' + Math.round(picker.rgb[2]);";
//   ptr += "document.getElementById('change_color').href='/ledon?r=' + Math.round(picker.rgb[0]) + '&g=' + Math.round(picker.rgb[1]) + '&b=' + Math.round(picker.rgb[2]);";
//   ptr += "}";
//   ptr += "</script>";
//   ptr += "</body></html>";

//   return ptr;
// }