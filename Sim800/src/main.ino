#include <Arduino.h>
#include <SoftwareSerial.h>
#include <sim800.h>

#define LED  10
int index = 0, index2 = 0;
String Mensaje = "";
String Numero = "\"+573112301574\"";

SIM800 sim1 = SIM800();

void setup() {

  Serial.begin(DEF_SPEED);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  sim1.modo_texto();
}

void loop() {

  if (sim1.disponible())
  {
    Mensaje = sim1.leer_str();
    index = sim1.leer_buscar(Mensaje, "On");
    index2 = sim1.leer_buscar(Mensaje, "Off");
  }

  if (index == 1){
    digitalWrite(LED, HIGH);
    index = 0;
    sim1.enviar(Numero, "LED prendido");
  }
  if (index2 == 1){
    digitalWrite(LED, LOW);
    index2 = 0;
    sim1.enviar(Numero, "LED apagado");
  }
}
