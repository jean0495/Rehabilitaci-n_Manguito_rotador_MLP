// lib/Driver.h
#pragma once
#include <Adafruit_PWMServoDriver.h>

class Driver {
public:
    Driver(uint8_t direccion = 0x40);
    void iniciar();
    void moverServo(uint8_t canal, uint8_t angulo);

private:
    Adafruit_PWMServoDriver _pca;

    static const uint16_t PULSO_MIN  = 150;
    static const uint16_t PULSO_MAX  = 600;
    static const uint16_t FRECUENCIA = 50;

    uint16_t _anguloAPulso(uint8_t angulo);
};