// Dr CADIC Philippe
// Source code for the AI-Thinker RD-03
// For the dev board we use a ESP32S3 dev board
// UART0 is the default uart interface to read the data with  Arduino IDE serial monitor
// UART1 is the interface to receive the RD03 signal -  ESP32 RX = GPIO 41, ESP32 TX = GPIO 42
// RD03 PIN TX -- ESP32S3 RX (GPIO41)
// RD03 PIN OT1 -- ESP32S3 TX (GPIO42)


#include <HardwareSerial.h>

// Déclaration des objets Serial pour UART0 et UART1
HardwareSerial SerialUART0(0);  // Port UART0
HardwareSerial SerialUART1(1);  // Port UART1

void setup() {
  // Démarrage des ports série avec les vitesses de bauds appropriées
  SerialUART0.begin(115200);  // Port UART0
  SerialUART1.begin(115200, SERIAL_8N1, 41, 42);  // Port UART1, GPIO 16 (RX) et GPIO 17 (TX)
  //Serial1.begin(115200, SERIAL_8N1, 41, 42);
  // Attente pour permettre la connexion du port série
  delay(1000);

  // Envoi du message d'initialisation sur UART0
  SerialUART0.println("Initialisation OK");
}

void loop() {
  // Si des données sont disponibles sur UART1 (GPIO RX)
  if (SerialUART1.available()) {
    // Lecture des données reçues
    char receivedData = SerialUART1.read();

    // Envoi des données lues via UART0
    SerialUART0.write(receivedData);
  }
}
