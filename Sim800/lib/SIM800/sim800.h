#ifndef sim800_h
#define sim800_h

#include <Arduino.h>
#include <SoftwareSerial.h>

#define DEF_RX_PIN  7
#define DEF_TX_PIN  8
#define DEF_SPEED   19200

class SIM800 {
public:
  SIM800();
  void on_off();
  void serial_directo();
  void modo_texto();
  void leer();
  void borrar_mensajes();
  void enviar(String Numero, String Mensaje);
  bool leer_buscar(String Mensaje, String txt);
  bool disponible();
  String leer_str();
  String leer_mensaje();


private:
};

#endif
