// controller/LectorSerial.cpp
#include "Lector.h"

void LectorSerial::iniciar() {
    Serial.begin(BAUDRATE);
}

bool LectorSerial::hayDatos() {
    return Serial.available() > 0;
}

uint8_t LectorSerial::leer() {
    uint8_t classId = (uint8_t)Serial.parseInt();
    Serial.print("[OK] classId recibido: ");
    Serial.println(classId);
    return classId;
}