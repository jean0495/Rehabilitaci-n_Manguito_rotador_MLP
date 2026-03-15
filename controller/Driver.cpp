
#include "Driver.h"

Driver::Driver(uint8_t direccion) : _pca(direccion) {}

void Driver::iniciar() {
    _pca.begin();
    _pca.setPWMFreq(FRECUENCIA);
}

void Driver::moverServo(uint8_t canal, uint8_t angulo) {
    uint16_t pulso = _anguloAPulso(angulo);
    _pca.setPWM(canal, 0, pulso);
}

uint16_t Driver::_anguloAPulso(uint8_t angulo) {
    return map(angulo, 0, 180, PULSO_MIN, PULSO_MAX);
}