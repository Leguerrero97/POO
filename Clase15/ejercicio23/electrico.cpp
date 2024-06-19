#include "electrico.h"

Electrico::Electrico(int voltaje) : voltaje(voltaje) {}

Electrico::~Electrico() {
    qDebug() << "Desenchufado";
}

int Electrico::getVoltaje() const {
    return voltaje;
}

void Electrico::setVoltaje(int v) {
    voltaje = v;
}
