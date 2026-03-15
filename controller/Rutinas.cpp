// controller/Rutinas.cpp
#include "Rutinas.h"

void Rutinas::despachar(uint8_t classId, Driver* driver) {
    if (!_gestoValido(classId)) {
        Serial.print("[ERROR] classId invalido: ");
        Serial.println(classId);
        return;
    }

    for (uint8_t i = 0; i < NUM_SERVOS; i++) {
        driver->moverServo(i, TABLA_GESTOS[classId][i]);
    }
}

bool Rutinas::_gestoValido(uint8_t classId) {
    return classId < NUM_GESTOS;
}