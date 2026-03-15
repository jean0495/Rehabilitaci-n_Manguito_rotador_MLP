// controller/LectorSerial.h
#pragma once
#include <Arduino.h>

class LectorSerial {
public:
    void iniciar();
    bool hayDatos();
    uint8_t leer();

private:
    static const uint32_t BAUDRATE = 9600;
};