// controller/LectorSerial.cpp
#include "Lector.h"

void LectorSerial::iniciar() {
    Serial.begin(BAUDRATE);
}

bool LectorSerial::hayDatos() {
    return Serial.available() > 0;
}

uint8_t LectorSerial::leer() {
    String linea = Serial.readStringUntil('\n');
    linea.trim();
    if (linea.length() == 0) return 255;  // valor inválido
    return (uint8_t)linea.toInt();
}