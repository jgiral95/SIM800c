#include <Arduino.h>
#include <sim800.h>
#include <SoftwareSerial.h>

SoftwareSerial sim (DEF_RX_PIN, DEF_TX_PIN);

SIM800::SIM800(){
  sim.begin(DEF_SPEED);
}

void SIM800::serial_directo(){
  if (Serial.available()) {
    sim.write(Serial.read());
  }
  if (sim.available()) {
    Serial.print((char)sim.read());
  }
}

void SIM800::on_off(){
  digitalWrite(9,HIGH);
  delay(2000);
  digitalWrite(9,LOW);
}

void SIM800::modo_texto(){
  delay(500);
  sim.println("AT");
  delay(500);
  sim.println("AT+CNMI=2,2,0,0,0");
  delay(500);
  sim.println("AT+CMGF=1");
  delay(500);
  leer();
  Serial.println("Modo texto activado");
}

void SIM800::leer(){
  while (sim.available()) {
    Serial.print((char)sim.read());
  }
}

void SIM800::enviar(String Numero, String Mensaje){
  String num = "AT+CMGS=" + Numero;
  sim.println(num);
  delay(1000);
  sim.println(Mensaje);
  delay(1000);
  sim.write(0x1A);
  Serial.println("enviado");
}

void SIM800::borrar_mensajes(){
  delay(500);
  sim.println("AT+CMGD=1");
  delay(500);
  sim.println("AT+CMGD=2");
  delay(500);
  sim.println("AT+CMGD=3");
  delay(500);
  sim.println("AT+CMGD=4");
  delay(500);
  leer();
  Serial.println("Los mensajes han sido borrados");
}

String SIM800::leer_str(){
  if (sim.available()) {
    String str = "";
    while(sim.available()) {
      str += ((char)sim.read());
    }
    Serial.print(str);
    return(str);
  }
  else{}
}

bool SIM800::leer_buscar(String Mensaje, String txt){ //txt = texto a buscar

  int index = Mensaje.indexOf(txt);
  if (index >= 0)
  {
    return true;
  }
  else{
    return false;
  }
}

bool SIM800::disponible(){

  if (sim.available() > 0)
  {
    return true;
  }
  else{
    return false;
  }
}
