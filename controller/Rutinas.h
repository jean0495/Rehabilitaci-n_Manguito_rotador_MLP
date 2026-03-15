// controller/Rutinas.h
#pragma once
#include <Arduino.h>
#include "Driver.h"
#include "gesto.h"

class Rutinas {
public:
    void despachar(uint8_t classId, Driver* driver);

private:
    bool _gestoValido(uint8_t classId);
};