// controller/Rutinas.cpp
#include "Rutinas.h"

void Rutinas::despachar(uint8_t classId, Driver* driver) {
    if (!_gestoValido(classId)) {
        Serial.print("[ERROR] classId invalido: ");
        Serial.println(classId);
        return;
    }

    if (classId == _ultimaClase) return;  // misma clase, no hacer nada

    _ultimaClase = classId;

    for (uint8_t i = 0; i < NUM_SERVOS; i++) {
        driver->moverServo(i, TABLA_GESTOS[classId][i]);
    }

    Serial.print("[OK] Gesto ");
    Serial.println(classId);
}

bool Rutinas::_gestoValido(uint8_t classId) {
    return classId < NUM_GESTOS;
}