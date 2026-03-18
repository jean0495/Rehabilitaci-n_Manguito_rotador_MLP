// src/main.cpp
#include "Lector.h"
#include "Rutinas.h"
#include "Driver.h"

Driver driver;
Rutinas rutinas;
LectorSerial lectorSerial;

void setup() {
    lectorSerial.iniciar();
    driver.iniciar();
}

void loop() {
    if (lectorSerial.hayDatos()) {
        uint8_t id = lectorSerial.leer();
        if (id != 255) {
            rutinas.despachar(id, &driver);
        }
    }
}