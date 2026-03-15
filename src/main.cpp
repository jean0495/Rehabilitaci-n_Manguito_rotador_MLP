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
        rutinas.despachar(id, &driver);
    }
}
